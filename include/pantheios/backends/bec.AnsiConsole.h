/* /////////////////////////////////////////////////////////////////////////
 * File:    pantheios/backends/bec.AnsiConsole.h
 *
 * Purpose: Declaration of the Pantheios AnsiConsole Stock Back-end API.
 *
 * Created: 20th October 2024
 * Updated: 28th January 2025
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


/** \file pantheios/backends/bec.AnsiConsole.h
 *
 * [C, C++] Pantheios ANSI Console Back-end Common API
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_ANSICONSOLE
#define PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_ANSICONSOLE


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ANSICONSOLE_MAJOR       1
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ANSICONSOLE_MINOR       0
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ANSICONSOLE_REVISION    3
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ANSICONSOLE_EDIT        3
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

/** \defgroup group__backend__stock_backends__AnsiConsole Pantheios ANSI Console Stock Back-end
 * \ingroup group__backend__stock_backends
 *  Back-end library that sets the calling threads's COM error object.
 */


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

/** \defgroup group__backend__stock_backends__AnsiConsole__flags Pantheios ANSI Console Stock Back-end Flags
 * \ingroup group__backend__stock_backends__AnsiConsole
 *  Flags for the \ref group__backend__stock_backends__AnsiConsole
 */

/** \def PANTHEIOS_BE_ANSICONSOLE_F_NO_COLOURS
 *  Causes the \ref group__backend__stock_backends__AnsiConsole to
 *   emit log statements without colouring based on severity.
 * \ingroup group__backend__stock_backends__AnsiConsole__flags
 */

#define PANTHEIOS_BE_ANSICONSOLE_F_NO_COLOURS                       (0x10000000)
#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_BE_ANSICONSOLE_F_NO_COLORS                       PANTHEIOS_BE_ANSICONSOLE_F_NO_COLOURS
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/** \def PANTHEIOS_BE_ANSICONSOLE_F_FORCE_ANSI_ESCAPE_SEQUENCES
 *  Causes the \ref group__backend__stock_backends__AnsiConsole
 *   to write ANSI escape sequences regardless of the console/terminal mode,
 *   i.e. even if the output is being redirected. Ignored when
 *   PANTHEIOS_BE_ANSICONSOLE_F_NO_COLOURS is specified.
 * \ingroup group__backend__stock_backends__AnsiConsole__flags
 */

#define PANTHEIOS_BE_ANSICONSOLE_F_FORCE_ANSI_ESCAPE_SEQUENCES      (0x20000000)

/** \def PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_WHOLE_PREFIX
 *  Causes the \ref group__backend__stock_backends__AnsiConsole to
 *   colour the whole prefix (date, time, etc.) rather than just the
 *   severity.
 * \ingroup group__backend__stock_backends__AnsiConsole__flags
 */

#define PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_WHOLE_PREFIX              (0x00010000)

/** \def PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_MESSAGE
 *  Causes the \ref group__backend__stock_backends__AnsiConsole to
 *   colour the message, in addition to whatever parts of the prefix are
 *   coloured.
 * \ingroup group__backend__stock_backends__AnsiConsole__flags
 */

#define PANTHEIOS_BE_ANSICONSOLE_F_COLOUR_MESSAGE                   (0x00020000)


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** Structure used for specifying initialisation information to the
 *    be.AnsiConsole library.
 * \ingroup group__backend__stock_backends__AnsiConsole
 */
struct pan_be_AnsiConsole_init_t
{
    pantheios_uint32_t      version;    /*!< Must be initialised to the value of PANTHEIOS_VER */
    pantheios_uint32_t      flags;      /*!< \ref group__backend__stock_backends__AnsiConsole__flags "Flags" that control the information displayed. */

#ifdef __cplusplus
public: /* Construction */
# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
    pan_be_AnsiConsole_init_t();
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */
};
#ifndef __cplusplus
typedef struct pan_be_AnsiConsole_init_t                    pan_be_AnsiConsole_init_t;
#endif /* !__cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * Application-defined functions
 */

/** Callback function defined by the application, invoked when the
 *    API is initialised with a NULL <code>init</code> parameter.
 *
 * \note When using explicit initialisation, this function must be defined,
 *   but will not be invoked.
 */
PANTHEIOS_CALL(void)
pantheios_be_AnsiConsole_getAppInit(
    int                         backEndId
,   pan_be_AnsiConsole_init_t*  init
) /* throw() */;


/* /////////////////////////////////////////////////////////////////////////
 * API
 */

/** Fills out a copy of the initialisation structure with default
 *    values (representative of the default behaviour of the library),
 *    ready to be customised and passed to the API initialiser function
 *    pantheios_be_AnsiConsole_init().
 */
PANTHEIOS_CALL(void)
pantheios_be_AnsiConsole_getDefaultAppInit(
    pan_be_AnsiConsole_init_t* init
) /* throw() */;

/** Implements the functionality for pantheios_be_init() over the ANSI Console API.
 * \ingroup group__backend__stock_backends__AnsiConsole
 */
PANTHEIOS_CALL(int)
pantheios_be_AnsiConsole_init(
    PAN_CHAR_T const*                   processIdentity
,   int                                 id
,   pan_be_AnsiConsole_init_t const*    init
,   void*                               reserved
,   void**                              ptoken
);

/** Implements the functionality for pantheios_be_uninit() over the ANSI Console API.
 * \ingroup group__backend__stock_backends__AnsiConsole
 */
PANTHEIOS_CALL(void)
pantheios_be_AnsiConsole_uninit(void* token);

/** Implements the functionality for pantheios_be_logEntry() over the ANSI Console API.
 * \ingroup group__backend__stock_backends__AnsiConsole
 */
PANTHEIOS_CALL(int)
pantheios_be_AnsiConsole_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
);

/** Parses the be.AnsiConsole back-end flags
 *
 * \ingroup group__backend
 *
 * Processes an argument list in the same way as
 * pantheios_be_parseStockArgs(), filling out the
 * pan_be_AnsiConsole_init_t in accordance with the arguments
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
 * - "noColours" / "noColors"   (Boolean)
 * - "forceAnsiEscapeSequences" (Boolean)
 * - "colourWholePrefix"        (Boolean)
 * - "colourMessage"            (Boolean)
 */
PANTHEIOS_CALL(int)
pantheios_be_AnsiConsole_parseArgs(
    size_t                      numArgs
,   pantheios_slice_t           args[]
,   pan_be_AnsiConsole_init_t*  init
);


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifdef __cplusplus

# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT

inline
pan_be_AnsiConsole_init_t::pan_be_AnsiConsole_init_t()
{
    pantheios_be_AnsiConsole_getDefaultAppInit(this);
}
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

#endif /* PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_ANSICONSOLE */

/* ///////////////////////////// end of file //////////////////////////// */

