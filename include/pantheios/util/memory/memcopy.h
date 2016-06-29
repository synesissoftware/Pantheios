/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/util/memory/memcopy.h
 *
 * Purpose:     Memory-copying functions.
 *
 * Created:     1st September 2015
 * Updated:     29th June 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2015-2016, Matthew Wilson and Synesis Software
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


/** \file pantheios/util/memory/memcopy.h
 *
 * \brief [C, C++] INTERNAL FILE (AND SUBJECT TO CHANGE): Memory-copying
 *   functions.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_UTIL_MEMORY_H_MEMCOPY
#define PANTHEIOS_INCL_PANTHEIOS_UTIL_MEMORY_H_MEMCOPY

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_UTIL_MEMORY_H_MEMCOPY_MAJOR    1
# define PANTHEIOS_VER_PANTHEIOS_UTIL_MEMORY_H_MEMCOPY_MINOR    0
# define PANTHEIOS_VER_PANTHEIOS_UTIL_MEMORY_H_MEMCOPY_REVISION 1
# define PANTHEIOS_VER_PANTHEIOS_UTIL_MEMORY_H_MEMCOPY_EDIT     5
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
#ifdef __cplusplus
# ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE
#  include <stlsoft/meta/is_character_type.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE */
#endif /* __cplusplus */

#ifdef __cplusplus
# include <string.h>
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
namespace util
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

#if defined(PANTHEIOS_DOCUMENTATION_SKIP_SECTION) || \
    defined(__cplusplus)

/** Copies \c cch characters from \c src to \c dest
 *
 * \param dest Destination
 * \param src The destination
 * \param cch The number of characters
 *
 * \pre (NULL != dest)
 * \pre (NULL != src)
 */
template <typename C>
inline
C*
pantheios_util_memory_copyChars(
    C*                  dest
,   C const*            src
,   size_t              cch
)
{
    STLSOFT_STATIC_ASSERT(stlsoft::is_character_type<C>::value);

    return static_cast<C*>(STLSOFT_NS_GLOBAL(memcpy)(dest, src, sizeof(C) * cch));
}
#endif

#if defined(PANTHEIOS_DOCUMENTATION_SKIP_SECTION) || \
    !defined(__cplusplus)

/** Copies \c cch multibyte characters from \c src to \c dest
 *
 * \param dest Destination
 * \param src The destination
 * \param cch The number of characters
 *
 * \pre (NULL != dest)
 * \pre (NULL != src)
 */
PANTHEIOS_CALL(char const*)
pantheios_util_memory_copyChars_m(
    char*               dest
,   char const*         src
,   size_t              cch
);

/** Copies \c cch wide characters from \c src to \c dest
 *
 * \param dest Destination
 * \param src The destination
 * \param cch The number of characters
 *
 * \pre (NULL != dest)
 * \pre (NULL != src)
 */
PANTHEIOS_CALL(wchar_t const*)
pantheios_util_memory_copyChars_w(
    wchar_t*            dest
,   wchar_t const*      src
,   size_t              cch
);

/** \def pantheios_util_memory_copyChars(dest, src, cch)
 *
 * Copies \c cch parameters from \c src to \c dest
 *
 * \param dest Destination
 * \param src The destination
 * \param cch The number of characters
 *
 * \pre (NULL != dest)
 * \pre (NULL != src)
 */

# define pantheios_util_memory_copyChars(dest, src, cch)   stlsoft_static_cast(PAN_CHAR_T*, memcpy((dest), (src), (cch) * sizeof(PAN_CHAR_T)))
#endif /* __cplusplus */

#ifdef __cplusplus

# ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

#  if defined(PANTHEIOS_NO_NAMESPACE)

#   define pantheios_util_memory_copyChars_     pantheios_util_memory_copyChars
#  else /* PANTHEIOS_NO_NAMESPACE */

#   define pantheios_util_memory_copyChars_     ::pantheios::util::pantheios_util_memory_copyChars
#  endif /* !PANTHEIOS_NO_NAMESPACE */
# endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(PANTHEIOS_NO_NAMESPACE)

# define PANTHEIOS_char_copy(dest, src, cch)    pantheios_util_memory_copyChars(dest, src, cch)
# define PANTHEIOS_char_copy_m(dest, src, cch)  pantheios_util_memory_copyChars(dest, src, cch)
# define PANTHEIOS_char_copy_w(dest, src, cch)  pantheios_util_memory_copyChars(dest, src, cch)
#else /* PANTHEIOS_NO_NAMESPACE */

# define PANTHEIOS_char_copy(dest, src, cch)    ::pantheios::util::pantheios_util_memory_copyChars(dest, src, cch)
# define PANTHEIOS_char_copy_m(dest, src, cch)  ::pantheios::util::pantheios_util_memory_copyChars_m(dest, src, cch)
# define PANTHEIOS_char_copy_w(dest, src, cch)  ::pantheios::util::pantheios_util_memory_copyChars_w(dest, src, cch)

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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_UTIL_MEMORY_H_MEMCOPY */

/* ///////////////////////////// end of file //////////////////////////// */
