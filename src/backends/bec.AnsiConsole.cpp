/* /////////////////////////////////////////////////////////////////////////
 * File:    src/backends/bec.AnsiConsole.cpp
 *
 * Purpose: Implementation of the Pantheios ANSI-Console Stock Back-end API.
 *
 * Created: 20th October 2024
 * Updated: 30th January 2025
 *
 * Home:    http://www.pantheios.org/
 *
 * Copyright (c) 2024-2025, Matthew Wilson and Synesis Information Systems
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
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
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
#define PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
#include <pantheios/backends/bec.AnsiConsole.h>
#include <pantheios/internal/safestr.h>

#include <pantheios/init_codes.h>
#include <pantheios/util/core/apidefs.hpp>
#include <pantheios/util/backends/arguments.h>
#include <pantheios/util/backends/context.hpp>

#include <stlsoft/stlsoft.h>
#include <platformstl/system/console_functions.h>

#include <utility>

#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * string encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define pan_fprintf_                                       ::fwprintf
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define pan_fprintf_                                       ::fprintf
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace {

#if !defined(PANTHEIOS_NO_NAMESPACE)
    using ::pantheios::pan_slice_t;
    using ::pantheios::pantheios_getStockSeverityStringSlice;
    using ::pantheios::util::backends::Context;
#endif /* !PANTHEIOS_NO_NAMESPACE */
#if !defined(PLATFORMSTL_NO_NAMESPACE)
    using platformstl::platformstl_C_isatty_stm;
#endif /* !PLATFORMSTL_NO_NAMESPACE */

    struct AnsiConsole_Context
        : public Context
    {
    public: // types
        typedef Context                                         parent_class_type;
        typedef AnsiConsole_Context                             class_type;


    public: // constants
        enum
        {
            severityMask    =   0x0f
        };


    public: // construction
        AnsiConsole_Context(
            PAN_CHAR_T const*                   processIdentity
        ,   int                                 backEndId
        ,   pan_be_AnsiConsole_init_t const*    init
        );
        ~AnsiConsole_Context() throw();//STLSOFT_NOEXCEPT;
    private:
        AnsiConsole_Context(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
        void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;


    private: // overrides
        virtual int
        rawLogEntry(
            int                 severity4
        ,   int                 severityX
        ,   pan_slice_t const (&ar)[rawLogArrayDimension]
        ,   size_t              cchTotal
        );
        virtual int
        rawLogEntry(
            int                 severity4
        ,   int                 severityX
        ,   PAN_CHAR_T const*   entry
        ,   size_t              cchEntry
        );


    private: // implementation
        static
        std::pair<
            char const*
        ,   char const*
        >
        severity_to_ansi_strings_(
            FILE*               stm
        ,   pantheios_uint32_t  flags
        ,   int                 severity4
        ) STLSOFT_NOEXCEPT;


    private: // fields
        FILE* const                 m_stm;
        pantheios_uint32_t const    m_flags;
    };
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

PANTHEIOS_CALL(void)
pantheios_be_AnsiConsole_getDefaultAppInit(
    pan_be_AnsiConsole_init_t* init
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialisation structure pointer may not be null");

    init->version   =   PANTHEIOS_VER;
    init->flags     =   0;

#if 0

    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(init->colours); ++i)
    {
        size_t const    index_from  =   i;
        size_t const    index_to    =   i;

        init->colours[index_to] = s_infos[index_from].consoleAttributes;
    }}

    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(init->colours2); ++i)
    {
        size_t const    index_from  =   i + STLSOFT_NUM_ELEMENTS(init->colours);
        size_t const    index_to    =   i;

        init->colours2[index_to] = s_infos[index_from].consoleAttributes;
    }}
#endif
}

static int
pantheios_be_AnsiConsole_init_(
    PAN_CHAR_T const*                   processIdentity
,   int                                 backEndId
,   pan_be_AnsiConsole_init_t const*    init
,   void*                               reserved
,   void**                              ptoken
)
{
    STLSOFT_SUPPRESS_UNUSED(processIdentity);
    STLSOFT_SUPPRESS_UNUSED(init);
    STLSOFT_SUPPRESS_UNUSED(reserved);
    STLSOFT_SUPPRESS_UNUSED(ptoken);

    /* (i) apply Null Object (Variable) pattern */

    pan_be_AnsiConsole_init_t init_;

    if (NULL == init)
    {
        pantheios_be_AnsiConsole_getDefaultAppInit(&init_);

#ifdef PANTHEIOS_BE_USE_CALLBACK
        pantheios_be_AnsiConsole_getAppInit(backEndId, &init_);
#endif /* PANTHEIOS_BE_USE_CALLBACK */

        init = &init_;
    }

    /* (ii) verify the version */

    if (init->version < 0x010001da)
    {
        return PANTHEIOS_BE_INIT_RC_OLD_VERSION_NOT_SUPPORTED;
    }
    else if (init->version > PANTHEIOS_VER)
    {
        return PANTHEIOS_BE_INIT_RC_FUTURE_VERSION_REQUESTED;
    }

    /* (iii) create the context */

    AnsiConsole_Context* ctxt = new AnsiConsole_Context(processIdentity, backEndId, init);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC

    if (NULL == ctxt ||
        NULL == ctxt->getProcessIdentity())
    {
        delete ctxt;

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */

    *ptoken = ctxt;

    return 0;
}

PANTHEIOS_CALL(int)
pantheios_be_AnsiConsole_init(
    PAN_CHAR_T const*                   processIdentity
,   int                                 backEndId
,   pan_be_AnsiConsole_init_t const*    init
,   void*                               reserved
,   void**                              ptoken
)
{
    return pantheios_call_be_X_init<pan_be_AnsiConsole_init_t>(pantheios_be_AnsiConsole_init_, processIdentity, backEndId, init, reserved, ptoken, "be.AnsiConsole");
}

PANTHEIOS_CALL(void)
pantheios_be_AnsiConsole_uninit(void* token)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != token, "token must be non-null");

    AnsiConsole_Context* const ctxt = static_cast<AnsiConsole_Context*>(token);

    delete ctxt;
}

static int
pantheios_be_AnsiConsole_logEntry_(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != beToken, "back-end token must be non-null");

    STLSOFT_SUPPRESS_UNUSED(feToken);

    AnsiConsole_Context* const ctxt = static_cast<AnsiConsole_Context*>(beToken);

    return ctxt->logEntry(severity, entry, cchEntry);
}

PANTHEIOS_CALL(int)
pantheios_be_AnsiConsole_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    return pantheios_call_be_logEntry(pantheios_be_AnsiConsole_logEntry_, feToken, beToken, severity, entry, cchEntry, "be.AnsiConsole");
}


PANTHEIOS_CALL(int)
pantheios_be_AnsiConsole_parseArgs(
    size_t                      numArgs
,   pantheios_slice_t           args[]
,   pan_be_AnsiConsole_init_t*  init
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API((NULL != args || 0 == numArgs), "argument pointer must be non-null, or number of arguments must be 0");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialisation structure pointer may not be null");

    pantheios_be_AnsiConsole_getDefaultAppInit(init);

    // 1. Parse the stock arguments
    int res = pantheios_be_parseStockArgs(numArgs, args, &init->flags);
    int r;

    if (res >= 0)
    {
        // 2. Parse the custom argument: "showColours"
        r = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("noColours"), true, PANTHEIOS_BE_ANSICONSOLE_F_NO_COLOURS, &init->flags);

        if (0 == r)
        {
            r = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("noColors"), true, PANTHEIOS_BE_ANSICONSOLE_F_NO_COLOURS, &init->flags);
        }

        if (r < 0)
        {
            res = r;
        }
        else
        {
            res += r;
        }
    }

    if (res >= 0)
    {
        // Parse the custom argument: "forceAnsiEscapeSequences"
        r = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("forceAnsiEscapeSequences"), false, PANTHEIOS_BE_ANSICONSOLE_F_FORCE_ANSI_ESCAPE_SEQUENCES, &init->flags);

        if (r < 0)
        {
            res = r;
        }
        else
        {
            res += r;
        }
    }

    if (res >= 0)
    {
        // Parse the custom argument: "colourWholePrefix"
        r = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("colourWholePrefix"), false, PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_WHOLE_PREFIX, &init->flags);

        if (0 == r)
        {
            r = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("colorWholePrefix"), false, PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_WHOLE_PREFIX, &init->flags);
        }

        if (r < 0)
        {
            res = r;
        }
        else
        {
            res += r;
        }
    }

    if (res >= 0)
    {
        // Parse the custom argument: "colourMessage"
        r = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("colourMessage"), false, PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_MESSAGE, &init->flags);

        if (0 == r)
        {
            r = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("colorMessage"), false, PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_MESSAGE, &init->flags);
        }

        if (r < 0)
        {
            res = r;
        }
        else
        {
            res += r;
        }
    }

    return res;
}


/* /////////////////////////////////////////////////////////////////////////
 * AnsiConsole_Context
 */

namespace {

    /* static */
    std::pair<
        char const*
    ,   char const*
    >
    AnsiConsole_Context::severity_to_ansi_strings_(
        FILE*               stm
    ,   pantheios_uint32_t  flags
    ,   int                 severity4
    ) STLSOFT_NOEXCEPT
    {
        char const* pre     =   "";
        char const* post    =   "";

        if (0 == (PANTHEIOS_BE_ANSICONSOLE_F_NO_COLOURS & flags))
        {
            if (0 != (PANTHEIOS_BE_ANSICONSOLE_F_FORCE_ANSI_ESCAPE_SEQUENCES & flags) ||
                platformstl_C_isatty_stm(stm))
            {
                switch (severity4 & 0xf)
                {
                case  0: pre = "\033[1;93;41;5m"; break;    // emergency / violation
                case  1: pre = "\033[1;96;41;5m"; break;    // alert
                case  2: pre = "\033[1;97;41m"; break;      // critical
                case  3: pre = "\033[1;31;43m"; break;      // failure / error
                case  4: pre = "\033[1;34;43m"; break;      // warning
                case  5: pre = "\033[1;97;100m"; break;     // notice
                case  6: pre = "\033[1;37;100m"; break;     // info(rmational)
                case  7: pre = "\033[1;37;44m"; break;      // debug
                case  8: pre = "\033[1;37;44m"; break;      // debug-1
                case  9: pre = "\033[0;37;44m"; break;      // debug-2
                case 10: pre = "\033[0;37;44m"; break;      // debug-3
                case 11: pre = "\033[0;37;44m"; break;      // debug-4
                case 12: pre = "\033[0;37;44m"; break;      // debug-5
                case 13: pre = "\033[0;37;44m"; break;      // debug-6
                case 14: pre = "\033[0;37;44m"; break;      // trace
                case 15: pre = "\033[1;36;40m"; break;      // benchmark
                }

                post = "\033[0m";
            }
        }

        return std::make_pair(pre, post);
    }

    AnsiConsole_Context::AnsiConsole_Context(
        PAN_CHAR_T const*                   processIdentity
    ,   int                                 backEndId
    ,   pan_be_AnsiConsole_init_t const*    init
    )
        : parent_class_type(processIdentity, backEndId, init->flags, class_type::severityMask)
        , m_stm(stderr)
        , m_flags(init->flags)
    {}

    AnsiConsole_Context::~AnsiConsole_Context() throw()//STLSOFT_NOEXCEPT
    {}

    int
    AnsiConsole_Context::rawLogEntry(
        int                 severity4
    ,   int              /* severityX */
    ,   pan_slice_t const (&ar)[rawLogArrayDimension]
    ,   size_t           /* cchTotal */
    )
    {
        PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(severity4 >= 0, "severity must be >= 0");
        PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(severity4 < 16, "severity must be < 16");

        std::pair<
            char const*
        ,   char const*
        >   pp = severity_to_ansi_strings_(m_stm, m_flags, severity4);

        char const* b_0 = "";
        char const* a_0 = "";

        char const* b_1 = "";
        char const* a_1 = "";

        char const* b_2 = "";
        char const* a_2 = "";

        char const* b_3 = "";
        char const* a_3 = "";

        char const* b_4 = "";
        char const* a_4 = "";

        char const* b_5 = "";
        char const* a_5 = "";

        char const* b_6 = "";
        char const* a_6 = "";

        char const* b_7 = "";
        char const* a_7 = "";

        char const* b_8 = "";
        char const* a_8 = "";

        char const* b_9 = "";
        char const* a_9 = "";

        if (0 != (PANTHEIOS_BE_INIT_F_DETAILS_AT_START & m_flags))
        {
            if (0 != (PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_WHOLE_PREFIX & m_flags))
            {
                b_2 = pp.first;
            }
            else
            {
                b_8 = pp.first;
            }

            a_8 = pp.second;

            if (0 != (PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_MESSAGE & m_flags))
            {
                b_0 = pp.first;
                a_0 = pp.second;
            }
        }
        else
        {
            if (0 != (PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_WHOLE_PREFIX & m_flags))
            {
                b_1 = pp.first;
            }
            else
            {
                b_7 = pp.first;
            }

            a_7 = pp.second;

            if (0 != (PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_MESSAGE & m_flags))
            {
                b_9 = pp.first;
                a_9 = pp.second;
            }
        }


        const PAN_CHAR_T    fmt[]   =   PANTHEIOS_LITERAL_STRING("%s%.*s%s%s%.*s%s%s%.*s%s%s%.*s%s%s%.*s%s%s%.*s%s%s%.*s%s%s%.*s%s%s%.*s%s%s%.*s%s\n");

        STLSOFT_STATIC_ASSERT(rawLogArrayDimension * (2 + 4 + 2) + 2 == STLSOFT_NUM_ELEMENTS(fmt));

        // fprintf the array of slices

#define PAN_BE_GET_SLICE_4_PRINTF(x)    int(x.len), x.ptr

        return pan_fprintf_(m_stm, fmt
                        ,   b_0, PAN_BE_GET_SLICE_4_PRINTF(ar[0]), a_0
                        ,   b_1, PAN_BE_GET_SLICE_4_PRINTF(ar[1]), a_1
                        ,   b_2, PAN_BE_GET_SLICE_4_PRINTF(ar[2]), a_2
                        ,   b_3, PAN_BE_GET_SLICE_4_PRINTF(ar[3]), a_3
                        ,   b_4, PAN_BE_GET_SLICE_4_PRINTF(ar[4]), a_4
                        ,   b_5, PAN_BE_GET_SLICE_4_PRINTF(ar[5]), a_5
                        ,   b_6, PAN_BE_GET_SLICE_4_PRINTF(ar[6]), a_6
                        ,   b_7, PAN_BE_GET_SLICE_4_PRINTF(ar[7]), a_7
                        ,   b_8, PAN_BE_GET_SLICE_4_PRINTF(ar[8]), a_8
                        ,   b_9, PAN_BE_GET_SLICE_4_PRINTF(ar[9]), a_9
                        );
    }

    int
    AnsiConsole_Context::rawLogEntry(
        int                 severity4
    ,   int              /* severityX */
    ,   PAN_CHAR_T const*   entry
    ,   size_t              cchEntry
    )
    {
        FILE* const stm = m_stm;

        std::pair<
            char const*
        ,   char const*
        >   pp = (0 != (PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_MESSAGE & m_flags)) ? severity_to_ansi_strings_(m_stm, m_flags, severity4) : std::make_pair("", "");

        return pan_fprintf_(
            stm
        ,   "%s%.*s%s\n"
        ,   pp.first
        ,   int(cchEntry), entry
        ,   pp.second
        );
    }
} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

