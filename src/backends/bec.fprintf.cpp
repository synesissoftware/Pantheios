/* /////////////////////////////////////////////////////////////////////////
 * File:        src/backends/bec.fprintf.cpp
 *
 * Purpose:     Implementation for the fprintf() back-end
 *
 * Created:     26th June 2005
 * Updated:     16th January 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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
#define PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
#include <pantheios/backends/bec.fprintf.h>

#include <pantheios/init_codes.h>
#include <pantheios/quality/contract.h>
#include <pantheios/util/core/apidefs.hpp>
#include <pantheios/util/backends/context.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * string encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# define pan_fprintf_                   ::fwprintf
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */
# define pan_fprintf_                   ::fprintf
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace
{
#if !defined(PANTHEIOS_NO_NAMESPACE)

    using ::pantheios::pan_slice_t;
    using ::pantheios::util::backends::Context;
    using ::pantheios::util::pantheios_onBailOut3;

#endif /* !PANTHEIOS_NO_NAMESPACE */
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

class be_fprintf_Context
    : public Context
{
/// \name Member Types
/// @{
public:
    typedef Context             parent_class_type;
    typedef be_fprintf_Context  class_type;
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
    be_fprintf_Context(
        PAN_CHAR_T const*               processIdentity
    ,   int                             backEndId
    ,   pan_be_fprintf_init_t const*    init
    );
    ~be_fprintf_Context() throw();
private:
    be_fprintf_Context(class_type const&);
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

private: // fields
    FILE* const         m_stm;
};


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

namespace
{
    inline FILE*
    infer_stm_(pan_be_fprintf_init_t const* init)
    {
        if (NULL != init->stm)
        {
            return init->stm;
        }

        return stderr;
    }

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

PANTHEIOS_CALL(void) pantheios_be_fprintf_getDefaultAppInit(pan_be_fprintf_init_t* init)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialisation structure pointer may not be null");

    init->version   =   PANTHEIOS_VER;
    init->flags     =   0;

    init->stm       =   NULL;
}

static int pantheios_be_fprintf_init_(
    PAN_CHAR_T const*               processIdentity
,   int                             backEndId
,   pan_be_fprintf_init_t const*    init
,   void*                           reserved
,   void**                          ptoken
)
{
    STLSOFT_SUPPRESS_UNUSED(reserved);

    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != ptoken, "token pointer may not be null");

    /* (i) apply Null Object (Variable) pattern */

    pan_be_fprintf_init_t init_;

    if(NULL == init)
    {
        pantheios_be_fprintf_getDefaultAppInit(&init_);

        init = &init_;

#ifdef PANTHEIOS_BE_USE_CALLBACK
        pantheios_be_fprintf_getAppInit(backEndId, &init_);
#endif /* PANTHEIOS_BE_USE_CALLBACK */
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

    be_fprintf_Context* ctxt = new be_fprintf_Context(processIdentity, backEndId, init);

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

PANTHEIOS_CALL(int) pantheios_be_fprintf_init(
    PAN_CHAR_T const*               processIdentity
,   int                             backEndId
,   pan_be_fprintf_init_t const*    init
,   void*                           reserved
,   void**                          ptoken
)
{
    return pantheios_call_be_X_init<pan_be_fprintf_init_t>(pantheios_be_fprintf_init_, processIdentity, backEndId, init, reserved, ptoken, "be.fprintf");
}

PANTHEIOS_CALL(void) pantheios_be_fprintf_uninit(void* token)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != token, "token must be non-null");

    be_fprintf_Context* ctxt = static_cast<be_fprintf_Context*>(token);

    delete ctxt;
}

static int pantheios_be_fprintf_logEntry_(
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

PANTHEIOS_CALL(int) pantheios_be_fprintf_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    return pantheios_call_be_logEntry(pantheios_be_fprintf_logEntry_, feToken, beToken, severity, entry, cchEntry, "be.fprintf");
}


/* /////////////////////////////////////////////////////////////////////////
 * be_fprintf_Context
 */

be_fprintf_Context::be_fprintf_Context(
    PAN_CHAR_T const*               processIdentity
,   int                             backEndId
,   pan_be_fprintf_init_t const*    init
)
    : parent_class_type(processIdentity, backEndId, init->flags, be_fprintf_Context::severityMask)
    , m_stm(infer_stm_(init))
{}

be_fprintf_Context::~be_fprintf_Context() throw()
{}

int be_fprintf_Context::rawLogEntry(
    int                     severity4
,   int                  /* severityX */
,   const pan_slice_t (&ar)[rawLogArrayDimension]
,   size_t               /* cchTotal */
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(severity4 >= 0, "severity must be >= 0");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(severity4 < 16, "severity must be < 16");

    STLSOFT_SUPPRESS_UNUSED(severity4);

    // select the stream: stdout for debug/info/notice; stderr for everything else

    const PAN_CHAR_T    fmt[]   =   PANTHEIOS_LITERAL_STRING("%.*s%.*s%.*s%.*s%.*s%.*s%.*s%.*s%.*s%.*s\n");

    STLSOFT_STATIC_ASSERT(4 * rawLogArrayDimension + 2 == STLSOFT_NUM_ELEMENTS(fmt));

    // fprintf the array of slices

#define PAN_BE_GET_SLICE_4_PRINTF(x)    int(x.len), x.ptr

    return pan_fprintf_(m_stm, fmt
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[0])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[1])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[2])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[3])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[4])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[5])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[6])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[7])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[8])
                    ,   PAN_BE_GET_SLICE_4_PRINTF(ar[9]));
}

int be_fprintf_Context::rawLogEntry(
    int                     severity4
,   int                  /* severityX */
,   PAN_CHAR_T const*       entry
,   size_t                  cchEntry
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(severity4 >= 0, "severity must be >= 0");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(severity4 < 16, "severity must be < 16");

    STLSOFT_SUPPRESS_UNUSED(severity4);

    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != m_stm, "stream cannot be null");

    return pan_fprintf_(m_stm, PANTHEIOS_LITERAL_STRING("%.*s\n"), int(cchEntry), entry);
}

/* ///////////////////////////// end of file //////////////////////////// */

