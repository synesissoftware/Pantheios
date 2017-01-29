/* /////////////////////////////////////////////////////////////////////////
 * File:        src/backends/bec.WindowsEventLog.cpp
 *
 * Purpose:     Implementation for the WindowsEventLog back-end
 *
 * Created:     8th May 2006
 * Updated:     9th December 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2006-2016, Matthew Wilson and Synesis Software
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
#include <pantheios/internal/winlean.h>
#define PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
#include <pantheios/backends/bec.WindowsEventLog.h>

#include <pantheios/init_codes.h>
#include <pantheios/quality/contract.h>
#include <pantheios/util/core/apidefs.hpp>
#include <pantheios/util/severity/WindowsEventLog.h>

/* STLSoft header files */
#include <winstl/memory/processheap_allocator.hpp>

/* Standard C header files */
#include <stdio.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * compiler features
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND) || \
    defined(STLSOFT_COMPILER_IS_DMC) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1200)
# define PANTHEIOS_NO_PLACEMENT_DELETE_
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * string encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# define pan_RegisterEventSource_       ::RegisterEventSourceW
# define pan_ReportEvent_               ::ReportEventW
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */
# define pan_RegisterEventSource_       ::RegisterEventSourceA
# define pan_ReportEvent_               ::ReportEventA
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace
{
#if !defined(PANTHEIOS_NO_NAMESPACE)

#endif /* !PANTHEIOS_NO_NAMESPACE */
} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace
{
#if !defined(PANTHEIOS_NO_NAMESPACE)

    using ::pantheios::pantheios_severity_to_WindowsEventLog_type;

#endif /* !PANTHEIOS_NO_NAMESPACE */
} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

class WindowsEventLog_Context
{
// types
public:
    typedef WindowsEventLog_Context                         class_type;
    typedef pantheios_uint16_t                            (*pfnMapSev_t)(int);

// construction
public:
    WindowsEventLog_Context(
        int         id
    ,   pfnMapSev_t pfnMapSev
    )
        : hEvLog(NULL)
        , id(id)
        , pfnMapSev(pfnMapSev)
    {
        PANTHEIOS_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL(NULL != pfnMapSev, "mapping function may not be null");
    }

private:
    WindowsEventLog_Context(class_type const&); // copy-construction proscribed
    class_type &operator =(class_type const&);  // copy-assignment proscribed

public:
    int     Register(PAN_CHAR_T const* processIdentity);
    void    Deregister();
    int     ReportEvent(
        int                 severity
    ,   PAN_CHAR_T const*   entry
    ,   size_t              cchEntry
    );

private:
    HANDLE              hEvLog;
    int const           id;
    pfnMapSev_t const   pfnMapSev;
};

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

PANTHEIOS_CALL(void) pantheios_be_WindowsEventLog_getDefaultAppInit(pan_be_WindowsEventLog_init_t* init)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialisation structure pointer may not be null");

    init->version   =   PANTHEIOS_VER;
    init->flags     =   0;

    init->pfnMapSev =   NULL;
}


static int pantheios_be_WindowsEventLog_init_(
    PAN_CHAR_T const*                       processIdentity
,   int                                     id
,   pan_be_WindowsEventLog_init_t const*    init
,   void*                                   reserved
,   void**                                  ptoken
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != processIdentity, "process identity may not be NULL");

    STLSOFT_SUPPRESS_UNUSED(reserved);

    /* (i) apply Null Object (Variable) pattern */

    pan_be_WindowsEventLog_init_t init_;

    if(NULL == init)
    {
        pantheios_be_WindowsEventLog_getDefaultAppInit(&init_);

#ifdef PANTHEIOS_BE_USE_CALLBACK
        pantheios_be_WindowsEventLog_getAppInit(id, &init_);
#endif /* PANTHEIOS_BE_USE_CALLBACK */

        init = &init_;
    }

    /* (ii) verify the version */

    if(init->version < 0x010001b8)
    {
        return PANTHEIOS_BE_INIT_RC_OLD_VERSION_NOT_SUPPORTED;
    }
    else if(init->version > PANTHEIOS_VER)
    {
        return PANTHEIOS_BE_INIT_RC_FUTURE_VERSION_REQUESTED;
    }

    /* (iii) create the context */

    // (iii) create the context

    WindowsEventLog_Context::pfnMapSev_t    pfnMapSev   =   (NULL != init->pfnMapSev)
                                                                ? init->pfnMapSev
                                                                : &pantheios_severity_to_WindowsEventLog_type
                                                                ;
    WindowsEventLog_Context* const          ctxt        =   new WindowsEventLog_Context(id, pfnMapSev);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(NULL == ctxt)
    {
        delete ctxt;

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    else
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    {
        int res =   ctxt->Register(processIdentity);

        if(0 != res)
        {
            delete ctxt;

            return res;
        }
    }

    *ptoken = ctxt;

    return 0;
}

PANTHEIOS_CALL(int) pantheios_be_WindowsEventLog_init(
    PAN_CHAR_T const*                       processIdentity
,   int                                     id
,   pan_be_WindowsEventLog_init_t const*    init
,   void*                                   reserved
,   void**                                  ptoken
)
{
    return pantheios_call_be_X_init<pan_be_WindowsEventLog_init_t>(pantheios_be_WindowsEventLog_init_, processIdentity, id, init, reserved, ptoken, "be.WindowsEventLog");
}

PANTHEIOS_CALL(void) pantheios_be_WindowsEventLog_uninit(void* token)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != token, "token must be non-null");

    WindowsEventLog_Context* ctxt = static_cast<WindowsEventLog_Context*>(token);

    delete ctxt;
}

PANTHEIOS_CALL(int) pantheios_be_WindowsEventLog_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    STLSOFT_SUPPRESS_UNUSED(feToken);

    WindowsEventLog_Context* elc = static_cast<WindowsEventLog_Context*>(beToken);

    return elc->ReportEvent(severity, entry, cchEntry);
}

/* /////////////////////////////////////////////////////////////////////////
 * WindowsEventLog_Context
 */

int WindowsEventLog_Context::Register(PAN_CHAR_T const* processIdentity)
{
    this->hEvLog = pan_RegisterEventSource_(NULL, processIdentity);

    return (NULL != this->hEvLog) ? 0 : -static_cast<int>(::GetLastError());
}

void WindowsEventLog_Context::Deregister()
{
    ::DeregisterEventSource(hEvLog);
}

int WindowsEventLog_Context::ReportEvent(
    int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              /* cchEntry */
)
{
    WORD                wType;
    pantheios_uint16_t  category    =   0xFFFF;
    pantheios_uint32_t  eventId     =   0xFFFFFFFF;
    PSID                lpUserSid   =   NULL;
    WORD                wNumStrings =   1;
    DWORD               dwDataSize  =   0;
    LPCTSTR*            lpStrings   =   &entry;
    LPVOID              lpRawData   =   NULL;

    pantheios_be_WindowsEventLog_calcCategoryAndEventId(this->id, severity, &category, &eventId);

    if( 0xFFFF == category &&
        0xFFFFFFFF == eventId)
    {
        return 0;
    }

    severity &= 0xf;    /* This stock back-end ignores any custom severity information. */

    wType = (*this->pfnMapSev)(severity);

    if(!pan_ReportEvent_(
            hEvLog
        ,   wType
        ,   category
        ,   eventId
        ,   lpUserSid
        ,   wNumStrings
        ,   dwDataSize
        ,   lpStrings
        ,   lpRawData
        ))
    {
        return PANTHEIOS_INIT_RC_UNSPECIFIED_FAILURE;
    }

    return 0;
}

/* ///////////////////////////// end of file //////////////////////////// */
