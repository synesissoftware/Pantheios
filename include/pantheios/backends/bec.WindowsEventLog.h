/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/backends/bec.WindowsEventLog.h
 *
 * Purpose:     Declaration of the Pantheios WindowsEventLog Stock Back-end API.
 *
 * Created:     8th May 2006
 * Updated:     7th December 2016
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


/** \file pantheios/backends/bec.WindowsEventLog.h
 *
 * [C, C++] Pantheios Windows EventLog Back-end Common API
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_WINDOWSEVENTLOG
#define PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_WINDOWSEVENTLOG

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_WINDOWSEVENTLOG_MAJOR       1
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_WINDOWSEVENTLOG_MINOR       4
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_WINDOWSEVENTLOG_REVISION    1
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_WINDOWSEVENTLOG_EDIT        31
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */
#ifndef PANTHEIOS_INCL_PANTHEIOS_H_BACKEND
# include <pantheios/backend.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_BACKEND */

/* /////////////////////////////////////////////////////////////////////////
 * documentation
 */

/** \defgroup group__backend__stock_backends__WindowsEventLog Pantheios Windows EventLog Stock Back-end
 * \ingroup group__backend__stock_backends
 *  Back-end library that writes to the Windows event log.
 */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

/** \defgroup group__backend__stock_backends__WindowsEventLog__flags Pantheios Windows EventLog Stock Back-end Flags
 * \ingroup group__backend__stock_backends__WindowsEventLog
 *  Flags for the \ref group__backend__stock_backends__WindowsEventLog
 */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Structure used for specifying initialisation information to the
 *    be.WindowsEventLog library.
 * \ingroup group__backend__stock_backends__WindowsEventLog
 */
struct pan_be_WindowsEventLog_init_t
{
#if 0
    pantheios_uint32_t      sizeofInit;         /*!< Must be set to the size of the stucture */
#endif
    pantheios_uint32_t      version;            /*!< Must be initialised to the value of PANTHEIOS_VER */
    pantheios_uint32_t      flags;              /*!< \ref group__backend__stock_backends__WindowsEventLog__flags "Flags" that control the information displayed. */
    pantheios_uint16_t    (*pfnMapSev)(int);    /*!!< Function that maps severity to Event Log Type */


#ifdef __cplusplus
public: /* Construction */
# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
    pan_be_WindowsEventLog_init_t();
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */
};
#ifndef __cplusplus
typedef struct pan_be_WindowsEventLog_init_t     pan_be_WindowsEventLog_init_t;
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Application-defined Functions
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

struct Pantheios_be_WindowsEventLog_no_longer_uses_the_symbol_BE_WINDOWSEVENTLOG_EVENTID_it_now_uses_the_function_pantheios_be_WindowsEventLog_calcCategoryAndEventId_;
# define BE_WINDOWSEVENTLOG_EVENTID Pantheios_be_WindowsEventLog_no_longer_uses_the_symbol_BE_WINDOWSEVENTLOG_EVENTID_it_now_uses_the_function_pantheios_be_WindowsEventLog_calcCategoryAndEventId_()

struct Pantheios_be_WindowsEventLog_no_longer_uses_the_symbol_pantheios_be_WindowsEventLog_calcCategory_it_now_uses_the_function_pantheios_be_WindowsEventLog_calcCategoryAndEventId_;
# define pantheios_be_WindowsEventLog_calcCategory  struct Pantheios_be_WindowsEventLog_no_longer_uses_the_symbol_pantheios_be_WindowsEventLog_calcCategory_it_now_uses_the_function_pantheios_be_WindowsEventLog_calcCategoryAndEventId_

struct Pantheios_be_WindowsEventLog_no_longer_uses_the_symbol_pantheios_be_WindowsEventLog_calcEventId_it_now_uses_the_function_pantheios_be_WindowsEventLog_calcCategoryAndEventId_;
# define pantheios_be_WindowsEventLog_calcEventId struct Pantheios_be_WindowsEventLog_no_longer_uses_the_symbol_pantheios_be_WindowsEventLog_calcEventId_it_now_uses_the_function_pantheios_be_WindowsEventLog_calcCategoryAndEventId_

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */


/** Evaluates the appropriate category and event identifiers for a given
 *   back-end identifier and Pantheios severity level just prior to
 *   emitting the log entry to the event log.
 *
 * \note This is an application-specified function.
 *
 * \ingroup group__backend__stock_backends__WindowsEventLog
 *
 * \param backEndId The back-end identifier
 * \param severity The severity associated with the event
 * \param category A pointer to a variable to receive the Event Log category
 *   to be used
 * \param eventId A pointer to a variable to receive the Event Log event
 *   identifier to be used
 *
 * \note As of Pantheios 1.0.1 beta-215, if the values of
 *   <code>*category</code> and <code>*eventId</code> are set to the
 *   maximum limit for those types - 0xFFFF and 0xFFFFFFFF, respectively -
 *   then no statement is emitted. When the function is called, these
 *   values are preset. Note that this is an inefficient way of filtering
 *   messages, and users should prefer to filter via a suitable front-end.
 */
PANTHEIOS_CALL(void)
pantheios_be_WindowsEventLog_calcCategoryAndEventId(
    int                 backEndId
,   int                 severity
,   pantheios_uint16_t* category
,   pantheios_uint32_t* eventId
) /* throw() */;

/** \ref page__backend__callbacks "Callback" function defined by
 *    the application, invoked when the
 *    API is initialised with a NULL <code>init</code> parameter.
 * \ingroup group__backend__stock_backends__WindowsEventLog
 *
 * \param backEndId The back-end identifier passed to the back-end
 *   during its initialisation.
 * \param init A pointer to an already-initialised instance of
 *   pan_be_WindowsEventLog_init_t.
 *
 * If any application-specific changes are required they can be made to
 * the structure to which <code>init</code> points, which will already
 * have been initialised. These changes will then be incorporated into
 * the back-end state, and reflected in its behaviour.
 *
 * If no changes are required, then the function can be a simple stub,
 * containing no instructions.
 *
 * \note This function is only required when the
 *   \ref page__backend__callbacks "callback" version of the library is
 *   used.
 *
 * \exception "throw()" This function must <b>not</b> throw any exceptions!
 *
 * \warning This function will be called during the initialisation of
 *   Pantheios, and so <b>must not</b> make any calls into Pantheios, either
 *   directly or indirectly!
 */
PANTHEIOS_CALL(void)
pantheios_be_WindowsEventLog_getAppInit(
    int                             backEndId
,   pan_be_WindowsEventLog_init_t*  init
) /* throw() */;

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

/** Fills out a copy of the initialisation structure with default
 *    values (representative of the default behaviour of the library),
 *    ready to be customised and passed to the API initialiser function
 *    pantheios_be_WindowsEventLog_init().
 * \ingroup group__backend__stock_backends__WindowsEventLog
 *
 * \note This function should <b>not</b> be called on an
 *   already-initialised instance, as is the case in the implementation
 *   of the pantheios_be_WindowsEventLog_getAppInit() function, as it will
 *   already have been called by pantheios_be_WindowsEventLog_init() prior
 *   to the callback.
 */
PANTHEIOS_CALL(void) pantheios_be_WindowsEventLog_getDefaultAppInit(
    pan_be_WindowsEventLog_init_t* init
) /* throw() */;

/** Implements the functionality for pantheios_be_init() over the Windows EventLog API.
 *
 * \ingroup group__backend__stock_backends__WindowsEventLog
 */
PANTHEIOS_CALL(int)
pantheios_be_WindowsEventLog_init(
    PAN_CHAR_T const*                       processIdentity
,   int                                     id
,   pan_be_WindowsEventLog_init_t const*    init
,   void*                                   param
,   void**                                  ptoken
);

/** Implements the functionality for pantheios_be_uninit() over the Windows EventLog API.
 * \ingroup group__backend__stock_backends__WindowsEventLog
 */
PANTHEIOS_CALL(void)
pantheios_be_WindowsEventLog_uninit(
    void* token
);

/** Implements the functionality for pantheios_be_logEntry() over the Windows EventLog API.
 * \ingroup group__backend__stock_backends__WindowsEventLog
 */
PANTHEIOS_CALL(int)
pantheios_be_WindowsEventLog_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
);


#if 0

/* TODO: Implement these in 1.0.1 beta 162+
 */

/** This helper function can be used to defer 
 */
PANTHEIOS_CALL(void)
pantheios_be_WindowsEventLog_getPantheiosDotComCategoryAndEventId(
    int                 backEndId
,   int                 severity
,   pantheios_uint16_t* category
,   pantheios_uint32_t* eventId
) /* throw() */;

/** Registers an event source for use with Pantheios.COM
 */
PANTHEIOS_CALL(int)
pantheios_be_WindowsEventLog_registerEventSourceUsingPantheiosDotCom(
    PAN_CHAR_T const* sourceName
,   PAN_CHAR_T const* pantheiosDotComPath
);

/** Unregisters an event source for use with Pantheios.COM
 */
PANTHEIOS_CALL(int)
pantheios_be_WindowsEventLog_unregisterEventSourceUsingPantheiosDotCom(
    PAN_CHAR_T const* sourceName
,   PAN_CHAR_T const* pantheiosDotComPath
);

#endif /* 0 */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_WINDOWSEVENTLOG */

/* ///////////////////////////// end of file //////////////////////////// */
