/* /////////////////////////////////////////////////////////////////////////
 * File:        src/util/core.apidefs.cpp
 *
 * Purpose:     Utility functions for use in Pantheios back- and front-
 *              ends.
 *
 * Created:     19th August 2007
 * Updated:     29th June 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2007-2016, Matthew Wilson and Synesis Software
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/pantheios.h>
#include <pantheios/util/core/apidefs.hpp>
#include <pantheios/init_codes.h>

#include <pantheios/backend.h>
#include <pantheios/quality/contract.h>

#include <exception>
#include <new>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace
{
#if !defined(PANTHEIOS_NO_NAMESPACE)

    using ::pantheios::util::pantheios_onBailOut6;

#endif /* !PANTHEIOS_NO_NAMESPACE */

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

/* /////////////////////////////////////
 * Front-end functions
 */

PANTHEIOS_CALL(int) pantheios_call_fe_init(
    pantheios_fe_X_init_pfn_t   pfn
,   void*                       reserved
,   void**                      ptoken
,   char const*                 feName
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != ptoken, "token pointer may not be null");

    try
    {
        return pfn(reserved, ptoken);
    }
    catch(std::bad_alloc&)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "front-end initialisation failed", NULL, "out of memory", feName, NULL);

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception& x)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "front-end initialisation failed", NULL, x.what(), feName, NULL);

        return PANTHEIOS_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
# ifdef PANTHEIOS_USE_CATCHALL
    catch(...)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_EMERGENCY, "front-end initialisation failed", NULL, "unknown failure", feName, NULL);

#  if defined(PANTHEIOS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS_TO_FAILURE_CODE)
        return PANTHEIOS_INIT_RC_UNKNOWN_FAILURE;
#  elif defined(PANTHEIOS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios_exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_USE_CATCHALL */
}

PANTHEIOS_CALL(int) pantheios_call_fe_uninit(
    pantheios_fe_X_uninit_pfn_t pfn
,   void*                       token
,   char const*                 feName
)
{
    try
    {
        return pfn(token);
    }
    catch(std::bad_alloc&)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "front-end uninitialisation failed", NULL, "out of memory", feName, NULL);

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception& x)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "front-end uninitialisation failed", NULL, x.what(), feName, NULL);

        return PANTHEIOS_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
# ifdef PANTHEIOS_USE_CATCHALL
    catch(...)
    {
        pantheios_onBailOut3(PANTHEIOS_SEV_EMERGENCY, "front-end uninitialisation failed", NULL, "unknown failure", feName, NULL);

#  if defined(PANTHEIOS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS_TO_FAILURE_CODE)
        return PANTHEIOS_INIT_RC_UNKNOWN_FAILURE;
#  elif defined(PANTHEIOS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios_exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_USE_CATCHALL */
}

#if 0
PANTHEIOS_CALL(PAN_CHAR_T const*) pantheios_call_fe_getProcessIdentity(
    pantheios_fe_X_getProcessIdentity_pfn_t pfn
,   void*                                   token
,   char const*                             feName
)
{
    try
    {
        return pfn(token);
    }
#error Do separately for std::exception
# ifdef PANTHEIOS_USE_CATCHALL
    catch(...)
    {
        return PANTHEIOS_LITERAL_STRING("");
    }
# endif /* PANTHEIOS_USE_CATCHALL */
}

PANTHEIOS_CALL(int) pantheios_call_fe_isSeverityLogged(
    pantheios_fe_X_isSeverityLogged_pfn_t   pfn
,   void*                                   token
,   int                                     severity
,   int                                     backEndId
,   char const*                             feName
)
{
    try
    {
        return pfn(token, severity, backEndId);

#error This is wrong
    }
    catch(std::bad_alloc&)
    {
        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return PANTHEIOS_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
# ifdef PANTHEIOS_USE_CATCHALL
    catch(...)
    {
        return PANTHEIOS_INIT_RC_UNKNOWN_FAILURE;
    }
# endif /* PANTHEIOS_USE_CATCHALL */
}
#endif /* 0 */

/* /////////////////////////////////////
 * Back-end functions
 */

PANTHEIOS_CALL(int) pantheios_call_be_void_init(
    pantheios_be_X_init_pfn_t   pfn
,   PAN_CHAR_T const*           processIdentity
,   int                         backEndId
,   void const*                 init
,   void*                       reserved
,   void**                      ptoken
,   char const*                 beName
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != ptoken, "token pointer may not be null");

    try
    {
        return pfn(processIdentity, backEndId, init, reserved, ptoken);
    }
    catch(std::bad_alloc&)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "back-end initialisation failed", NULL, "out of memory", NULL, beName);

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception& x)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "back-end initialisation failed", NULL, x.what(), NULL, beName);

        return PANTHEIOS_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
# ifdef PANTHEIOS_USE_CATCHALL
    catch(...)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_EMERGENCY, "back-end initialisation failed", NULL, "unknown failure", NULL, beName);

#  if defined(PANTHEIOS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS_TO_FAILURE_CODE)
        return PANTHEIOS_INIT_RC_UNKNOWN_FAILURE;
#  elif defined(PANTHEIOS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios_exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_USE_CATCHALL */
}

PANTHEIOS_CALL(int) pantheios_call_be_uninit(
    pantheios_be_X_uninit_pfn_t pfn
,   void*                       token
,   char const*                 beName
)
{
    try
    {
        return pfn(token);
    }
    catch(std::bad_alloc&)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "back-end uninitialisation failed", NULL, "out of memory", NULL, beName);

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception& x)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "back-end uninitialisation failed", NULL, x.what(), NULL, beName);

        return PANTHEIOS_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
# ifdef PANTHEIOS_USE_CATCHALL
    catch(...)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_EMERGENCY, "back-end uninitialisation failed", NULL, "unknown failure", NULL, beName);

#  if defined(PANTHEIOS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS_TO_FAILURE_CODE)
        return PANTHEIOS_INIT_RC_UNKNOWN_FAILURE;
#  elif defined(PANTHEIOS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios_exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_USE_CATCHALL */
}

PANTHEIOS_CALL(int) pantheios_call_be_logEntry(
    pantheios_be_X_logEntry_pfn_t   pfn
,   void*                           feToken
,   void*                           beToken
,   int                             severity
,   PAN_CHAR_T const*               entry
,   size_t                          cchEntry
,   char const*                     beName
)
{
    try
    {
        return pfn(feToken, beToken, severity, entry, cchEntry);
    }
    catch(std::bad_alloc&)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_CRITICAL, "back-end failed to log entry", NULL, "out of memory", NULL, beName);

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception& x)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_CRITICAL, "back-end failed to log entry", NULL, x.what(), NULL, beName);

        return PANTHEIOS_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
# ifdef PANTHEIOS_USE_CATCHALL
    catch(...)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_EMERGENCY, "back-end failed to log entry", NULL, "unknown failure", NULL, beName);

#  if defined(PANTHEIOS_CATCHALL_TRANSLATE_UNKNOWN_EXCEPTIONS_TO_FAILURE_CODE)
        return PANTHEIOS_INIT_RC_UNKNOWN_FAILURE;
#  elif defined(PANTHEIOS_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
        throw;
#  else
        pantheios_exitProcess(EXIT_FAILURE);
#  endif
    }
# endif /* PANTHEIOS_USE_CATCHALL */
}

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

/* ///////////////////////////// end of file //////////////////////////// */
