/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/util/string/strlen.h (formerly part of pantheios/pantheios.h)
 *
 * Purpose:     String length functions.
 *
 * Created:     21st June 2005
 * Updated:     29th June 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2005-2016, Matthew Wilson and Synesis Software
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


/** \file pantheios/util/string/strlen.h
 *
 * \brief [C, C++] INTERNAL FILE (AND SUBJECT TO CHANGE): String length functions.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_UTIL_STRING_H_STRLEN
#define PANTHEIOS_INCL_PANTHEIOS_UTIL_STRING_H_STRLEN

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_STRLEN_MAJOR     1
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_STRLEN_MINOR     0
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_STRLEN_REVISION  1
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_STRLEN_EDIT      2
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* Standard C & C++ header files */

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
namespace util
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API (C)
 */

/** [Currently undocumented] Calculates the length of a string, in light of
 * special conditions indicated by special values of the len parameter.
 *
 * \note THIS FUNCTION IS NOT PART OF THE PUBLICLY DOCUMENTED API OF
 *   PANTHEIOS, AND IS SUBJECT TO REMOVAL/CHANGE IN A FUTURE RELEASE.
 */
PANTHEIOS_CALL(size_t) pantheios_util_strnlen(pan_char_t const* s, size_t len);

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
PANTHEIOS_CALL_DEPRECATED(size_t, pantheios_strnlen, pantheios_util_strnlen) pantheios_strnlen(pan_char_t const* s, size_t len);
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API (C++)
 */

#ifdef __cplusplus

#if 0
extern "C++"
inline
size_t
strnlen(
    pan_char_t const*   s
,   size_t              len
)
{
    return pantheios_util_strnlen(s, len);
}
#endif /* 0 */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace util */
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_UTIL_STRING_H_STRLEN */

/* ///////////////////////////// end of file //////////////////////////// */
