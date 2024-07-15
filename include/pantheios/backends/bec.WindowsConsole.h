/* /////////////////////////////////////////////////////////////////////////
 * File:    pantheios/backends/bec.WindowsConsole.h
 *
 * Purpose: Declaration of the Pantheios WindowsConsole Stock Back-end API.
 *
 * Created: 17th July 2006
 * Updated: 16th July 2024
 *
 * Home:    http://www.pantheios.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file pantheios/backends/bec.WindowsConsole.h
 *
 * [C, C++] Pantheios Windows Console Back-end Common API
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_BEC_WINDOWSCONSOLE
#define PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_BEC_WINDOWSCONSOLE


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_WINDOWSCONSOLE_MAJOR    5
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_WINDOWSCONSOLE_MINOR    2
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_WINDOWSCONSOLE_REVISION 2
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_WINDOWSCONSOLE_EDIT     29
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

/** \defgroup group__backend__stock_backends__WindowsConsole Pantheios Windows Console Stock Back-end
 * \ingroup group__backend__stock_backends
 *  Back-end library that outputs to the Windows console, colour-coding
 *   based on severity level.
 */


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

/** \defgroup group__backend__stock_backends__WindowsConsole__flags Pantheios Windows Console Stock Back-end Flags
 * \ingroup group__backend__stock_backends__WindowsConsole
 *  Flags for the \ref group__backend__stock_backends__WindowsConsole
 */

/** \def PANTHEIOS_BE_WINDOWSCONSOLE_F_NO_COLOURS
 *  Causes the \ref group__backend__stock_backends__WindowsConsole to
 *   emit log statements without colouring based on severity.
 * \ingroup group__backend__stock_backends__WindowsConsole__flags
 */

#define PANTHEIOS_BE_WINDOWSCONSOLE_F_NO_COLOURS            (0x00100000)

/** \def PANTHEIOS_BE_WINDOWSCONSOLE_F_CLEAR_AFTER_EACH_STATEMENT
 *  Causes the \ref group__backend__stock_backends__WindowsConsole to
 *   a colour reset after each statement.
 * \ingroup group__backend__stock_backends__WindowsConsole__flags
 */

#define PANTHEIOS_BE_WINDOWSCONSOLE_F_CLEAR_AFTER_EACH_STATEMENT    (0x00200000)

/** \def PANTHEIOS_BE_WINDOWSCONSOLE_F_RECOGNISE_16_SEVERITIES
 *  Causes the \ref group__backend__stock_backends__WindowsConsole to
 *   recognise the colours for 16 severities, using the
 *   <code>colours2</code> member.
 * \ingroup group__backend__stock_backends__WindowsConsole__flags
 */

#define PANTHEIOS_BE_WINDOWSCONSOLE_F_RECOGNISE_16_SEVERITIES       (0x00400000)


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Structure used for specifying initialisation information to the
 *    be.WindowsConsole library.
 * \ingroup group__backend__stock_backends__WindowsConsole
 */
struct pan_be_WindowsConsole_init_t
{
    pantheios_uint32_t      version;    /*!< Must be initialised to the value of PANTHEIOS_VER */
    pantheios_uint32_t      flags;      /*!< \ref group__backend__stock_backends__WindowsConsole__flags "Flags" that control the information displayed. */
    pantheios_uint16_t      colours[8]; /*!< Array of colour indexes corresponding to the 8 stock severity levels. */
    pantheios_uint16_t      colours2[8];/*!< Array of colour indexes corresponding to an additional 8 severity levels taking the maximum to . */

#ifdef __cplusplus
public: /* Construction */
# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
    pan_be_WindowsConsole_init_t();
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */
};
#ifndef __cplusplus
typedef struct pan_be_WindowsConsole_init_t     pan_be_WindowsConsole_init_t;
#endif /* !__cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * Application-defined functions
 */

/** \ref page__backend__callbacks "Callback" function defined by
 *    the application, invoked when the
 *    API is initialised with a NULL <code>init</code> parameter.
 * \ingroup group__backend__stock_backends__WindowsConsole
 *
 * \param backEndId The back-end identifier passed to the back-end
 *   during its initialisation.
 * \param init A pointer to an already-initialised instance of
 *   pan_be_WindowsConsole_init_t.
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
PANTHEIOS_CALL(void) pantheios_be_WindowsConsole_getAppInit(
    int                             backEndId
,   pan_be_WindowsConsole_init_t*   init
) /* throw() */;


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Fills out a copy of the initialisation structure with default
 *    values (representative of the default behaviour of the library),
 *    ready to be customised and passed to the API initialiser function
 *    pantheios_be_WindowsConsole_init().
 * \ingroup group__backend__stock_backends__WindowsConsole
 *
 * \note This function should <b>not</b> be called on an
 *   already-initialised instance, as is the case in the implementation
 *   of the pantheios_be_WindowsConsole_getAppInit() function, as it will
 *   already have been called by pantheios_be_WindowsConsole_init() prior
 *   to the callback.
 */
PANTHEIOS_CALL(void) pantheios_be_WindowsConsole_getDefaultAppInit(
    pan_be_WindowsConsole_init_t* init
) /* throw() */;

/** Implements the functionality for pantheios_be_init() over the Windows Console API.
 * \ingroup group__backend__stock_backends__WindowsConsole
 */
PANTHEIOS_CALL(int) pantheios_be_WindowsConsole_init(
    PAN_CHAR_T const*                   processIdentity
,   int                                 id
,   pan_be_WindowsConsole_init_t const* init
,   void*                               param
,   void**                              ptoken
);

/** Implements the functionality for pantheios_be_uninit() over the Windows Console API.
 * \ingroup group__backend__stock_backends__WindowsConsole
 */
PANTHEIOS_CALL(void) pantheios_be_WindowsConsole_uninit(
    void* token
);

/** Implements the functionality for pantheios_be_logEntry() over the Windows Console API.
 * \ingroup group__backend__stock_backends__WindowsConsole
 */
PANTHEIOS_CALL(int) pantheios_be_WindowsConsole_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
);

/** Parses the be.WindowsConsole back-end flags
 *
 * \ingroup group__backend
 *
 * Processes an argument list in the same way as
 * pantheios_be_parseStockArgs(), filling out the
 * pan_be_WindowsConsole_init_t in accordance with the arguments
 * found.
 *
 * Recognises the following standard argument names:
 * - "showProcessId"            (Boolean)
 * - "showTime"                 (Boolean)
 * - "showSeverity"             (Boolean)
 * - "useSystemTime"            (Boolean)
 * - "showDetailsAtStart"       (Boolean)
 * - "useUnixFormat"            (Boolean)
 * - "showDate"                 (Boolean)
 * - "showTime"                 (Boolean)
 * - "highResolution"           (Boolean)
 * - "lowResolution"            (Boolean)
 *
 * Recognises the following back-end specific argument names:
 * - "noColours"                (Boolean)
 * - "noColors"                 (Boolean)
 */
PANTHEIOS_CALL(int) pantheios_be_WindowsConsole_parseArgs(
    size_t                          numArgs
,   pantheios_slice_t               args[]
,   pan_be_WindowsConsole_init_t*   init
);

/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
inline
pan_be_WindowsConsole_init_t::pan_be_WindowsConsole_init_t()
{
    pantheios_be_WindowsConsole_getDefaultAppInit(this);
}
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_BEC_WINDOWSCONSOLE */

/* ///////////////////////////// end of file //////////////////////////// */

