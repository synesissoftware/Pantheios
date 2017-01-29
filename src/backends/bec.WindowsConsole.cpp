/* /////////////////////////////////////////////////////////////////////////
 * File:        src/backends/bec.WindowsConsole.cpp
 *
 * Purpose:     Implementation of the Pantheios Windows-Console Stock Back-end API.
 *
 * Created:     17th July 2006
 * Updated:     13th January 2017
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2006-2017, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/pantheios.h>

#include <pantheios/internal/nox.h>
#include <pantheios/internal/winlean.h>
#define PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
#include <pantheios/backends/bec.WindowsConsole.h>
#include <pantheios/internal/safestr.h>

#include <pantheios/util/string/snprintf.h>

#include <pantheios/init_codes.h>
#include <pantheios/quality/contract.h>
#include <pantheios/util/core/apidefs.hpp>
#include <pantheios/util/backends/arguments.h>
#include <pantheios/util/backends/context.hpp>

/* Compiler warnings
 */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1300 && _MSC_VER < 1400
# pragma warning(disable : 4702)
#endif /* compiler */

/* STLSoft header files */
#include <pantheios/util/memory/auto_buffer_selector.hpp>
#include <stlsoft/synch/lock_scope.hpp>

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# include <winstl/dl/dl_call.hpp>
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#include <winstl/memory/processheap_allocator.hpp>
#include <winstl/synch/process_mutex.hpp>
/* #include <winstl/synch/thread_mutex.hpp> */
#include <winstl/system/console_colour_scope.hpp>

/* Standard C++ header files */
#include <map>
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * string encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define pan_WriteConsole_              ::WriteConsoleW

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define pan_WriteConsole_              ::WriteConsoleA

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace
{

#if !defined(PANTHEIOS_NO_NAMESPACE)

    using ::pantheios::pan_slice_t;
    using ::pantheios::pantheios_util_snprintf;
    using ::pantheios::util::backends::Context;
    using ::pantheios::util::pantheios_onBailOut3;
    using ::pantheios::util::pantheios_onBailOut4;

#endif /* !PANTHEIOS_NO_NAMESPACE */

    using ::winstl::ws_uint32_t;
    using ::winstl::ws_uint64_t;
    using ::winstl::ws_uintptr_t;

    template <ss_typename_param_k T>
    struct buffer_selector_
    {
        typedef ss_typename_type_k
            PANTHEIOS_NS_QUAL_(util, auto_buffer_selector)<
            T
        ,   2048
        ,   winstl::processheap_allocator<T>
        >::type                                 type;
    };

    typedef buffer_selector_<char>::type        buffer_a_t;
    typedef buffer_selector_<wchar_t>::type     buffer_w_t;
    typedef buffer_selector_<PAN_CHAR_T>::type  buffer_t;



    template <size_t N>
    int
    convert_wnd_N_(
        PAN_CHAR_T* buff
    ,   size_t      cchBuff
    ,   HWND        hwnd
    );

    template <>
    int
    convert_wnd_N_<4>(
        PAN_CHAR_T* buff
    ,   size_t      cchBuff
    ,   HWND        hwnd
    )
    {
        ws_uint32_t const u = static_cast< winstl_ns_qual(ws_uint32_t)>(reinterpret_cast< winstl_ns_qual(ws_uintptr_t)>(hwnd) && 0xFFFFFFFF);

        return pantheios_util_snprintf(buff, cchBuff, PANTHEIOS_LITERAL_STRING("%08X"), u);
    }

    template <>
    int
    convert_wnd_N_<8>(
        PAN_CHAR_T* buff
    ,   size_t      cchBuff
    ,   HWND        hwnd
    )
    {
        ws_uint64_t const u = reinterpret_cast< winstl_ns_qual(ws_uint64_t)>(hwnd);
        ws_uint32_t const h = static_cast<ws_uint32_t>(u >> (4 * sizeof(hwnd)));
        ws_uint32_t const l = static_cast<ws_uint32_t>(u & 0xFFFFFFFF);

        return pantheios_util_snprintf(buff, cchBuff, PANTHEIOS_LITERAL_STRING("%08X%08X"), h, l);
    }

    int
    convert_wnd_(
        PAN_CHAR_T* buff
    ,   size_t      cchBuff
    ,   HWND        hwnd
    )
    {
        return  convert_wnd_N_<sizeof(hwnd)>(buff, cchBuff, hwnd);
    }

    static
    int
    print_mxName_(
        PAN_CHAR_T*         buff
    ,   size_t              cchBuff
    ,   HWND                hwnd
    ,   PAN_CHAR_T const*   consoleTitle
    ,   int                 handleId
    )
    {
        // TODO: replace this with integer_to_string<16>, when STLSoft 1.12 is released

        PAN_CHAR_T  wnd[17];
        int const   n = convert_wnd_(wnd, STLSOFT_NUM_ELEMENTS(wnd), hwnd);

        return pantheios_util_snprintf(
                    buff, cchBuff
                ,   PANTHEIOS_LITERAL_STRING("pantheios.org:WindowsConsole:%.*s:%s:%d:MX")
                ,   n, wnd
                ,   consoleTitle
                ,   handleId
                );
    }

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace
{

    struct WindowsConsole_SeverityInfo
    {
        int     severity;
        DWORD   handleId;
        WORD    consoleAttributes;
    };

    struct WindowsConsole_Context
        : public Context
    {
    /// \name Member Types
    /// @{
    public:
        typedef Context                         parent_class_type;
        typedef WindowsConsole_Context          class_type;
        typedef winstl::process_mutex           mutex_type;
    private:
        typedef std::basic_string<
            PAN_CHAR_T
#if !defined(STLSOFT_COMPILER_IS_MWERKS)
        ,   std::char_traits<PAN_CHAR_T>
        ,   winstl::processheap_allocator<PAN_CHAR_T>
#endif /* compiler */
        >                                       string_type_;
        typedef std::map<
            string_type_
        ,   HANDLE
#if !defined(STLSOFT_COMPILER_IS_MWERKS)
        ,   std::less<string_type_>
        ,   winstl::processheap_allocator<string_type_>
#endif /* compiler */
        >                                       map_type_;
    /// @}

    /// \name Member Constants
    /// @{
    public:
        enum
        {
            severityMask    =   0x0f
        };
    /// @}

    /// \name Construction
    /// @{
    public:
        WindowsConsole_Context(
            PAN_CHAR_T const*                   processIdentity
        ,   int                                 backEndId
        ,   pan_be_WindowsConsole_init_t const* init
        );
        ~WindowsConsole_Context() throw();
    private:
        WindowsConsole_Context(class_type const&);  // copy-construction proscribed
        class_type &operator =(class_type const&);  // copy-assignment proscribed
    /// @}

    /// \name Overrides
    /// @{
    private:
        virtual int rawLogEntry(
            int                 severity4
        ,   int                 severityX
        ,   const pan_slice_t (&ar)[rawLogArrayDimension]
        ,   size_t              cchTotal
        );
        virtual int rawLogEntry(
            int                 severity4
        ,   int                 severityX
        ,   PAN_CHAR_T const*   entry
        ,   size_t              cchEntry
        );
    /// @}

    /// \name Implementation
    /// @{
    private:
        int     write_output(HANDLE hStream, PAN_CHAR_T const* entry, int cchEntry);
    #ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        HANDLE  lookupConsoleMx(HANDLE hBuffer);
    #endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        void    lookupSeverityCharacteristics(int severity, HANDLE &hOutput, WORD &attributes);
        WORD    lookupConsoleCharacteristics();
        void    write_reset(HANDLE hOutput);
    /// @}

    /// \name Members
    /// @{
    private:
        WindowsConsole_SeverityInfo m_infos[16];
        map_type_                   m_map;
        WORD const                  m_defaultColours;
    /// @}
    };

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#define FOREGROUND_WHITE    (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define FOREGROUND_YELLOW   (                  FOREGROUND_GREEN | FOREGROUND_RED)
#define FOREGROUND_CYAN     (FOREGROUND_BLUE | FOREGROUND_GREEN)

#define BACKGROUND_WHITE    (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)
#define BACKGROUND_YELLOW   (                  BACKGROUND_GREEN | BACKGROUND_RED)

namespace
{

    static const WindowsConsole_SeverityInfo  s_infos[] =
    {
        /* Stock levels */
            {   PANTHEIOS_SEV_EMERGENCY,     STD_ERROR_HANDLE,   FOREGROUND_BLUE     |   FOREGROUND_INTENSITY   |   BACKGROUND_RED      |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_ALERT,         STD_ERROR_HANDLE,   FOREGROUND_CYAN     |   FOREGROUND_INTENSITY   |   BACKGROUND_RED      |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_CRITICAL,      STD_ERROR_HANDLE,   FOREGROUND_WHITE    |   FOREGROUND_INTENSITY   |   BACKGROUND_RED      |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_ERROR,         STD_ERROR_HANDLE,   FOREGROUND_RED      |   FOREGROUND_INTENSITY   |   BACKGROUND_YELLOW   |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_WARNING,       STD_ERROR_HANDLE,   FOREGROUND_BLUE     |   0                      |   BACKGROUND_YELLOW   |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_NOTICE,        STD_OUTPUT_HANDLE,  FOREGROUND_WHITE    |   FOREGROUND_INTENSITY   |   0                   |   0                       }
        ,   {   PANTHEIOS_SEV_INFORMATIONAL, STD_OUTPUT_HANDLE,  FOREGROUND_WHITE    |   0                      |   0                   |   0                       }
        ,   {   PANTHEIOS_SEV_DEBUG,         STD_OUTPUT_HANDLE,  BACKGROUND_WHITE    |   FOREGROUND_INTENSITY   |   FOREGROUND_BLUE     |   0                       }

        /* Additional levels */
        ,   {   PANTHEIOS_SEV_DEBUG + 1,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   FOREGROUND_INTENSITY   |   BACKGROUND_WHITE    |   0                       }
        ,   {   PANTHEIOS_SEV_DEBUG + 2,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   0                      |   BACKGROUND_WHITE    |   0                       }
        ,   {   PANTHEIOS_SEV_DEBUG + 3,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   0                      |   BACKGROUND_WHITE    |   0                       }
        ,   {   PANTHEIOS_SEV_DEBUG + 4,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   0                      |   BACKGROUND_WHITE    |   0                       }
        ,   {   PANTHEIOS_SEV_DEBUG + 5,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   0                      |   BACKGROUND_WHITE    |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_DEBUG + 6,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   0                      |   BACKGROUND_WHITE    |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_DEBUG + 7,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   0                      |   BACKGROUND_WHITE    |   BACKGROUND_INTENSITY    }
        ,   {   PANTHEIOS_SEV_DEBUG + 8,     STD_OUTPUT_HANDLE,  FOREGROUND_BLUE     |   0                      |   BACKGROUND_WHITE    |   BACKGROUND_INTENSITY    }
    };


} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

PANTHEIOS_CALL(void) pantheios_be_WindowsConsole_getDefaultAppInit(pan_be_WindowsConsole_init_t* init)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialisation structure pointer may not be null");

    init->version   =   PANTHEIOS_VER;
    init->flags     =   0;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(init->colours); ++i)
    {
        size_t const    index_from  =   i;
        size_t const    index_to    =   i;

        init->colours[index_to] = s_infos[index_from].consoleAttributes;
    }}

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(init->colours2); ++i)
    {
        size_t const    index_from  =   i + STLSOFT_NUM_ELEMENTS(init->colours);
        size_t const    index_to    =   i;

        init->colours2[index_to] = s_infos[index_from].consoleAttributes;
    }}
}


static int pantheios_be_WindowsConsole_init_(
    PAN_CHAR_T const*                   processIdentity
,   int                                 backEndId
,   pan_be_WindowsConsole_init_t const* init
,   void*                               reserved
,   void**                              ptoken
)
{
    STLSOFT_SUPPRESS_UNUSED(reserved);

    /* (i) apply Null Object (Variable) pattern */

    pan_be_WindowsConsole_init_t init_;

    if(NULL == init)
    {
        pantheios_be_WindowsConsole_getDefaultAppInit(&init_);

#ifdef PANTHEIOS_BE_USE_CALLBACK
        pantheios_be_WindowsConsole_getAppInit(backEndId, &init_);
#endif /* PANTHEIOS_BE_USE_CALLBACK */

        init = &init_;
    }

    /* (ii) verify the version */

    if(init->version < 0x010001da)
    {
        return PANTHEIOS_BE_INIT_RC_OLD_VERSION_NOT_SUPPORTED;
    }
    else if(init->version > PANTHEIOS_VER)
    {
        return PANTHEIOS_BE_INIT_RC_FUTURE_VERSION_REQUESTED;
    }

    /* (iii) create the context */

    WindowsConsole_Context* ctxt = new WindowsConsole_Context(processIdentity, backEndId, init);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if( NULL == ctxt ||
        NULL == ctxt->getProcessIdentity())
    {
        delete ctxt;

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */

    *ptoken = ctxt;

    return 0;
}

PANTHEIOS_CALL(int) pantheios_be_WindowsConsole_init(
    PAN_CHAR_T const*                   processIdentity
,   int                                 backEndId
,   pan_be_WindowsConsole_init_t const* init
,   void*                               reserved
,   void**                              ptoken
)
{
    return pantheios_call_be_X_init<pan_be_WindowsConsole_init_t>(pantheios_be_WindowsConsole_init_, processIdentity, backEndId, init, reserved, ptoken, "be.WindowsConsole");
}

PANTHEIOS_CALL(void) pantheios_be_WindowsConsole_uninit(void* token)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != token, "token must be non-null");

    WindowsConsole_Context* ctxt = static_cast<WindowsConsole_Context*>(token);

    delete ctxt;
}

static int pantheios_be_WindowsConsole_logEntry_(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != beToken, "back-end token must be non-null");

    STLSOFT_SUPPRESS_UNUSED(feToken);

    Context* ctxt = static_cast<Context*>(beToken);

    return ctxt->logEntry(severity, entry, cchEntry);
}

PANTHEIOS_CALL(int) pantheios_be_WindowsConsole_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    return pantheios_call_be_logEntry(pantheios_be_WindowsConsole_logEntry_, feToken, beToken, severity, entry, cchEntry, "be.WindowsConsole");
}

PANTHEIOS_CALL(int)
pantheios_be_WindowsConsole_parseArgs(
    size_t                          numArgs
,   pantheios_slice_t               args[]
,   pan_be_WindowsConsole_init_t*   init
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API((NULL != args || 0 == numArgs), "argument pointer must be non-null, or number of arguments must be 0");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialisation structure pointer may not be null");

    pantheios_be_WindowsConsole_getDefaultAppInit(init);

    // 1. Parse the stock arguments
    int res = pantheios_be_parseStockArgs(numArgs, args, &init->flags);

    if(res >= 0)
    {
        // 2. Parse the custom argument: "showColours"
        res = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("showColours"), true, PANTHEIOS_BE_WINDOWSCONSOLE_F_NO_COLOURS, &init->flags);

        if(0 == res)
        {
            res = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("showColors"), true, PANTHEIOS_BE_WINDOWSCONSOLE_F_NO_COLOURS, &init->flags);
        }
    }

    if(res >= 0)
    {
        // Parse the custom argument: "clearAfterEachStatement"
        res = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("clearAfterEachStatement"), false, PANTHEIOS_BE_WINDOWSCONSOLE_F_CLEAR_AFTER_EACH_STATEMENT, &init->flags);
    }

    if(res >= 0)
    {
        // Parse the custom argument: "recognise16Severities"
        res = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("recognise16Severities"), false, PANTHEIOS_BE_WINDOWSCONSOLE_F_RECOGNISE_16_SEVERITIES, &init->flags);
    }

    return res;
}

/* /////////////////////////////////////////////////////////////////////////
 * WindowsConsole_Context
 */

WindowsConsole_Context::WindowsConsole_Context(
    PAN_CHAR_T const*                   processIdentity
,   int                                 backEndId
,   pan_be_WindowsConsole_init_t const* init
)
    : parent_class_type(processIdentity, backEndId, init->flags, WindowsConsole_Context::severityMask)
    , m_map()
    , m_defaultColours(lookupConsoleCharacteristics())
{
    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(m_infos) == STLSOFT_NUM_ELEMENTS(s_infos));

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(m_infos); ++i)
    {
        size_t const    index_from  =   i;
        size_t const    index_to    =   i;

        m_infos[index_from] = s_infos[index_to];
    }}

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(init->colours); ++i)
    {
        size_t const    index_from  =   i;
        size_t const    index_to    =   i;

        m_infos[index_to].consoleAttributes = init->colours[index_from];
    }}

    if(0 != (PANTHEIOS_BE_WINDOWSCONSOLE_F_RECOGNISE_16_SEVERITIES & init->flags))
    {
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(init->colours2); ++i)
        {
            size_t const    index_from  =   i;
            size_t const    index_to    =   i + STLSOFT_NUM_ELEMENTS(init->colours);

            m_infos[index_to].consoleAttributes = init->colours2[index_from];
        }}
    }
}

WindowsConsole_Context::~WindowsConsole_Context() throw()
{
    for(map_type_::iterator b = m_map.begin(); b != m_map.end(); ++b)
    {
        ::CloseHandle((*b).second);
    }
}

int
WindowsConsole_Context::rawLogEntry(
    int                 severity4
,   int                 severityX
,   const pan_slice_t (&ar)[rawLogArrayDimension]
,   size_t              cchTotal
)
{
    HANDLE  hOutput;
    WORD    attributes;

    this->lookupSeverityCharacteristics(severity4, hOutput, attributes);

    // Allocate the buffer

    buffer_t    buff(cchTotal + 1);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(0 == buff.size())
    {
        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    else
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    {
        PANTHEIOS_CONTRACT_ENFORCE_POSTCONDITION_STATE_INTERNAL(buff.size() == cchTotal + 1, "buffer was not correctly initialised");

        size_t nWritten = concatenateSlices(&buff[0], buff.size(), rawLogArrayDimension, &ar[0]);

        PANTHEIOS_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL(nWritten == cchTotal, "Written length differs from allocated length");

        buff[nWritten++] = '\n';

        PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(nWritten == buff.size());

        return this->rawLogEntry(severity4, severityX, buff.data(), nWritten);
    }
}

int WindowsConsole_Context::rawLogEntry(
    int                 severity4
,   int              /* severityX */
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    HANDLE  hOutput;
    WORD    attributes;

    this->lookupSeverityCharacteristics(severity4, hOutput, attributes);

    if(0 != (m_flags & PANTHEIOS_BE_WINDOWSCONSOLE_F_NO_COLOURS))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
uncoloured_write:
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return write_output(hOutput, entry, static_cast<int>(cchEntry));
    }
    else
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        HANDLE  hMx = this->lookupConsoleMx(hOutput);

        if(NULL == hMx)
        {
            goto uncoloured_write;
        }

        WindowsConsole_Context::mutex_type mx(hMx, false);

        { stlsoft::lock_scope<WindowsConsole_Context::mutex_type>  lock(mx);   // Scope access to the console

            try
            {

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

                winstl::console_colour_scope  scope(hOutput, attributes); // Scope the console colour

                int const r = write_output(hOutput, entry, static_cast<int>(cchEntry));

                if(0 != (PANTHEIOS_BE_WINDOWSCONSOLE_F_CLEAR_AFTER_EACH_STATEMENT & m_flags))
                {
                    write_reset(hOutput);
                }

                return r;
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

            }
            catch(winstl::windows_exception&)
            {
                goto uncoloured_write;
            }

        }

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

int WindowsConsole_Context::write_output(HANDLE hStream, PAN_CHAR_T const* entry, int cchEntry)
{
    DWORD dummy;

    if(pan_WriteConsole_(hStream, entry, static_cast<DWORD>(cchEntry), &dummy, NULL))
    {
        return 0;
    }
    else
    {
        // bail-out log of failure to log
        //
        // TODO: work out how to handle wide-string qualifier
        char const* qualifier = NULL;

        STLSOFT_SUPPRESS_UNUSED(qualifier); // Silly old Borland again.

#ifndef PANTHEIOS_USE_WIDE_STRINGS
        qualifier = entry;
#endif /* !PANTHEIOS_USE_WIDE_STRINGS */

        pantheios_onBailOut4(
            PANTHEIOS_SEV_ALERT
        ,   "failed to write message to log file"
#ifndef PANTHEIOS_USE_WIDE_STRINGS
                                                "; given message follows"
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
        ,   NULL
        ,   qualifier
        );

        return PANTHEIOS_BE_LOGENTRY_FAILED;
    }
}

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

HANDLE WindowsConsole_Context::lookupConsoleMx(HANDLE hBuffer)
{
    // The key is based on <console-hwnd>:<console-title>:<buffer-handle>

    HWND        hwndConsole;
    PAN_CHAR_T  consoleTitle[201] = { '\0' };

    // 1. console-hwnd

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
# ifdef WINSTL_OS_IS_WIN64
        hwndConsole = winstl::dl_call<HWND>("KERNEL32", "GetConsoleWindow");
# else /* ? WINSTL_OS_IS_WIN64 */
        hwndConsole = winstl::dl_call<HWND>("KERNEL32", "S:GetConsoleWindow");
# endif /* WINSTL_OS_IS_WIN64 */
    }
    catch(winstl::invalid_calling_convention_exception&)
    {
        pantheios_onBailOut3(PANTHEIOS_SEV_EMERGENCY, "invalid calling convension", NULL);

        throw;
    }
    catch(winstl::missing_entry_point_exception&)
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        hwndConsole = NULL;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::exception& x)
    {
        pantheios_onBailOut4(PANTHEIOS_SEV_EMERGENCY, "failed to lookup console", NULL, x.what());

        throw;
    }

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    // 2. console-title

    if(NULL == hwndConsole)
    {
        size_t const cch = ::GetConsoleTitle(&consoleTitle[0], STLSOFT_NUM_ELEMENTS(consoleTitle) - 1);

        consoleTitle[cch] = '\0';
    }

    // 3. buffer-handle
    int handleId;

    if(::GetStdHandle(STD_OUTPUT_HANDLE) == hBuffer)
    {
        handleId = 1;
    }
    else if(::GetStdHandle(STD_ERROR_HANDLE) == hBuffer)
    {
        handleId = 2;
    }
    else
    {
        handleId = -1;
    }

    PAN_CHAR_T  mxName[100 + STLSOFT_NUM_ELEMENTS(consoleTitle)];
    int const   cch = print_mxName_(
                        &mxName[0], STLSOFT_NUM_ELEMENTS(mxName)
                    ,   hwndConsole
                    ,   consoleTitle
                    ,   handleId);

    if(cch < 0)
    {
        return NULL;
    }

    mxName[cch] = '\0';

    map_type_::iterator it = m_map.find(mxName);

    if(m_map.end() != it)
    {
        return (*it).second;
    }
    else
    {
        std::replace(&mxName[0], &mxName[0] + cch, '\\', ':');

        HANDLE  hMx = ::CreateMutex(NULL, false, mxName);

        if(NULL != hMx)
        {
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER <= 1100

            m_map[mxName] == hMx;

# else /* ? compiler */

            m_map.insert(std::make_pair(&mxName[0], hMx));

# endif /* compiler */
        }

        return hMx;
    }
}

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

void WindowsConsole_Context::lookupSeverityCharacteristics(int severity, HANDLE &hOutput, WORD &attributes)
{
//    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(0 == (severity & 0x08), "be.WindowsConsole can only be used with the stock severity levels in the range [0, 8). Levels in the range [8, 16) are not allowed");

    int severityLevel = severity & 0x0f;

    if(0 == (PANTHEIOS_BE_WINDOWSCONSOLE_F_RECOGNISE_16_SEVERITIES & m_flags))
    {
        if(severityLevel > 7)
        {
            severityLevel = 7;
        }
    }

    WindowsConsole_SeverityInfo const* info = &m_infos[severityLevel];

    hOutput     =   ::GetStdHandle(info->handleId);
    attributes  =   info->consoleAttributes;
}

/* static */
WORD
WindowsConsole_Context::lookupConsoleCharacteristics()
{
#if 0
    HANDLE                      hOutput =   ::GetStdHandle(info->handleId);
    CONSOLE_SCREEN_BUFFER_INFO  bufferInfo;

    if(::GetConsoleScreenBufferInfo(hBuffer, &bufferInfo))
    {
        return bufferInfo.wAttributes;
    }
#endif

    return FOREGROUND_WHITE;
}

void
WindowsConsole_Context::write_reset(
    HANDLE hOutput
)
{
    WCHAR   ch      =   L'\0';
    DWORD   dummy;

    ::SetConsoleTextAttribute(hOutput, m_defaultColours);

    ::WriteConsole(hOutput, &ch, 0, &dummy, NULL);
}

/* ///////////////////////////// end of file //////////////////////////// */
