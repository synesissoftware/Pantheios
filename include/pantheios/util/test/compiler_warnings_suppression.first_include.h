/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/util/test/compiler_warnings_suppression.first_include.h
 *
 * Purpose:     #include file to go at the start of a test file's #include
 *              list.
 *
 * Created:     8th December 2007
 * Updated:     16th December 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/** \file pantheios/util/test/compiler_warnings_suppression.first_include.h
 *
 * [C, C++] \#include file to go at the start of a test file's \#include
 *   list.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_UTIL_TEST_H_COMPILER_WARNINGS_SUPPRESSION_FIRST_INCLUDE
#define PANTHEIOS_INCL_PANTHEIOS_UTIL_TEST_H_COMPILER_WARNINGS_SUPPRESSION_FIRST_INCLUDE


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h> /* This will be reported not found if STLSoft version < 1.9 */
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */


/* /////////////////////////////////////////////////////////////////////////
 * warning suppressions
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  pragma warning(disable : 4702)
# endif /* compiler */
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  pragma warning(disable : 4530)
# endif /* compiler */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#if defined(STLSOFT_COMPILER_IS_MSVC)
# if _MSC_VER >= 1400
#  pragma warning(disable : 4996)
# endif /* _MSC_VER >= 1400 */
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_UTIL_TEST_H_COMPILER_WARNINGS_SUPPRESSION_FIRST_INCLUDE */

/* ///////////////////////////// end of file //////////////////////////// */

