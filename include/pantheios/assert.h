/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/assert.h
 *
 * Purpose:     Pantheios Assertion API.
 *
 * Created:     8th May 2009
 * Updated:     30th June 2016
 *
 * Thanks to:   markitus82 for requesting this functionality
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2009-2016, Matthew Wilson and Synesis Software
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


/** \file pantheios/assert.h
 *
 * [C, C++] Include file for the \ref group__assertion
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_ASSERT
#define PANTHEIOS_INCL_PANTHEIOS_H_ASSERT

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_H_ASSERT_MAJOR     1
# define PANTHEIOS_VER_PANTHEIOS_H_ASSERT_MINOR     3
# define PANTHEIOS_VER_PANTHEIOS_H_ASSERT_REVISION  1
# define PANTHEIOS_VER_PANTHEIOS_H_ASSERT_EDIT      12
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */
#ifndef PANTHEIOS_INCL_PANTHEIOS_H_FILELINE
# include <pantheios/fileline.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_FILELINE */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * helper macros
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

# ifdef PANTHEIOS_ASSERT_ABORT_ON_FAILURE
#  define PANTHEIOS_ASSERT_CALL_EXIT_()     PANTHEIOS_NS_QUAL(pantheios_exitProcess)(EXIT_FAILURE)
# else /* ? PANTHEIOS_ASSERT_ABORT_ON_FAILURE */
#  define PANTHEIOS_ASSERT_CALL_EXIT_()     STLSOFT_STATIC_CAST(void, 0)
# endif /* PANTHEIOS_ASSERT_ABORT_ON_FAILURE */

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * assertion features
 */

/** \defgroup group__assertion Pantheios Assertion API
 *
 * Pantheios Assertion API
 *
 * This API allows you to combine traditional assert()-based programming
 * with diagnostic logging, using the PANTHEIOS_ASSERT() macro.
 *
<pre>
  int main()
  {
    PANTHEIOS_ASSERT(false); // Will assert, and will log

    return 0;
  }
</pre>
 */



/** \def PANTHEIOS_ASSERT_SEVERITY_LEVEL
 *
 * The level at which log statements will be submitted by
 * \c PANTHEIOS_ASSERT and \c PANTHEIOS_MESSAGE_ASSERT. This may be
 * overridden by defining the macro to a severity level of the programmer's
 * choosing.
 *
 * Defaults to \c PANTHEIOS_SEV_EMERGENCY, which represents the fact that
 * assertions reflect programmer error.
 *
 * \ingroup group__assertion
 */

#ifndef PANTHEIOS_ASSERT_SEVERITY_LEVEL
# define PANTHEIOS_ASSERT_SEVERITY_LEVEL            PANTHEIOS_SEV_EMERGENCY
#endif /* !PANTHEIOS_ASSERT_SEVERITY_LEVEL */


/** \def PANTHEIOS_ASSERT_IMPL(expr)
 *
 * The underlying assertion that is invoked by \c PANTHEIOS_ASSERT, after
 * it has issued a trace message (via pantheios_logassertfail()), except in
 * the case where \c PANTHEIOS_ASSERT_ABORT_ON_FAILURE is defined.
 *
 * Defaults to \c STLSOFT_ASSERT
 *
 * \ingroup group__assertion
 */

#ifndef PANTHEIOS_ASSERT_IMPL
# define PANTHEIOS_ASSERT_IMPL(expr)                STLSOFT_ASSERT((expr))
#endif /* !PANTHEIOS_ASSERT_IMPL */


/** \def PANTHEIOS_MESSAGE_ASSERT_IMPL(expr, msg)
 *
 * The underlying assertion that is invoked by \c PANTHEIOS_MESSAGE_ASSERT,
 * after it has issued a trace message (via pantheios_logassertfail()),
 * except in the case where \c PANTHEIOS_ASSERT_ABORT_ON_FAILURE is defined.
 *
 * Defaults to \c STLSOFT_MESSAGE_ASSERT
 *
 * \ingroup group__assertion
 */

#ifndef PANTHEIOS_MESSAGE_ASSERT_IMPL
# define PANTHEIOS_MESSAGE_ASSERT_IMPL(expr, msg)   STLSOFT_MESSAGE_ASSERT((msg), (expr))
#endif /* !PANTHEIOS_MESSAGE_ASSERT_IMPL */


/** \def PANTHEIOS_ASSERT(expr)
 *
 * Defines an assertion construct for runtime verification.
 *
 * \param expr Must be non-zero, or an assertion will be fired
 *
 * If the expression evaluates to false a log statement will be
 * submitted at the PANTHEIOS_ASSERT_SEVERITY_LEVEL severity level, and
 * emitted if that level is currently switched on.
 *
 * If the preprocessor symbol PANTHEIOS_ASSERT_ABORT_ON_FAILURE is
 * defined, then pantheios_exitProcess() will be invoked for a failed
 * expression; if not, the expression will also be subjected to a
 * "standard" assert, via \c PANTHEIOS_ASSERT_IMPL()
 *
 * \ingroup group__assertion
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400

# define PANTHEIOS_ASSERT(expr)                             \
                                                            \
    STLSOFT_STATIC_CAST(void,                               \
        (                                                   \
            (                                               \
                (                                           \
                    (                                       \
                        (expr) ||                           \
                        (                                   \
                            PANTHEIOS_NS_QUAL(pantheios_logassertfail)(PANTHEIOS_ASSERT_SEVERITY_LEVEL, PANTHEIOS_FILELINE_A, "assertion failed: " #expr)   \
                        ,   PANTHEIOS_ASSERT_CALL_EXIT_()   \
                        ,   0                               \
                        )                                   \
                    )                                       \
                ,   0                                       \
                )                                           \
            ,   (                                           \
                    PANTHEIOS_ASSERT_IMPL(expr)             \
                ,   0                                       \
                )                                           \
            ),  0                                           \
        )                                                   \
    )
#else

# define PANTHEIOS_ASSERT(expr)             \
                                            \
    do                                      \
    {                                       \
        if(!(expr))                         \
        {                                   \
            PANTHEIOS_NS_QUAL(pantheios_logassertfail)(PANTHEIOS_ASSERT_SEVERITY_LEVEL, PANTHEIOS_FILELINE_A, "assertion failed: " #expr); \
                                            \
            PANTHEIOS_ASSERT_CALL_EXIT_();  \
        }                                   \
                                            \
        PANTHEIOS_ASSERT_IMPL(expr);        \
    } while(0)
#endif


/** \def PANTHEIOS_MESSAGE_ASSERT(expr, msg)
 *
 * Defines an assertion construct for runtime verification.
 *
 * \param expr Must be non-zero, or an assertion will be fired
 * \param msg The message that will be associated with the output if the assertion fires
 *
 * If the expression evaluates to false a log statement will be
 * submitted at the PANTHEIOS_ASSERT_SEVERITY_LEVEL severity level, and
 * emitted if that level is currently switched on.
 *
 * If the preprocessor symbol PANTHEIOS_ASSERT_ABORT_ON_FAILURE is
 * defined, then pantheios_exitProcess() will be invoked for a failed
 * expression; if not, the expression will also be subjected to a
 * "standard" assert, via \c PANTHEIOS_MESSAGE_ASSERT_IMPL()
 *
 * \ingroup group__assertion
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400

# define PANTHEIOS_MESSAGE_ASSERT(expr, msg)                \
                                                            \
    STLSOFT_STATIC_CAST(void,                               \
        (                                                   \
            (                                               \
                (                                           \
                    (                                       \
                        (expr) ||                           \
                        (                                   \
                            PANTHEIOS_NS_QUAL(pantheios_logassertfail)(PANTHEIOS_ASSERT_SEVERITY_LEVEL, PANTHEIOS_FILELINE_A, "assertion failed: " #expr "; message: " msg) \
                        ,   PANTHEIOS_ASSERT_CALL_EXIT_()   \
                        ,   0                               \
                        )                                   \
                    )                                       \
                ,   0                                       \
                )                                           \
            ,   (                                           \
                    PANTHEIOS_MESSAGE_ASSERT_IMPL(expr, msg)\
                ,   0                                       \
                )                                           \
            ),  0                                           \
        )                                                   \
    )
#else

#define PANTHEIOS_MESSAGE_ASSERT(expr, msg) \
                                            \
    do                                      \
    {                                       \
        if(!(expr))                         \
        {                                   \
            PANTHEIOS_NS_QUAL(pantheios_logassertfail)(PANTHEIOS_ASSERT_SEVERITY_LEVEL, PANTHEIOS_FILELINE_A, "assertion failed: " #expr "; message: " msg); \
                                            \
            PANTHEIOS_ASSERT_CALL_EXIT_();  \
        }                                   \
                                            \
        PANTHEIOS_MESSAGE_ASSERT_IMPL(expr, msg);   \
    } while(0)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_ASSERT */

/* ///////////////////////////// end of file //////////////////////////// */
