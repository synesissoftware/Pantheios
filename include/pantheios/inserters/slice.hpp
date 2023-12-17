/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/slice.hpp
 *
 * Purpose:     String inserter for slices of strings.
 *
 * Created:     13th February 2010
 * Updated:     16th December 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file pantheios/inserters/slice.hpp
 *
 * [c++ only] definition of the pantheios::slice string inserter for
 *   for string slices.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_PAD
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_PAD

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_MAJOR    1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_MINOR    0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_REVISION 7
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_EDIT     13
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */
#ifndef PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS
# include <pantheios/internal/shim_declarations.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

#ifdef PANTHEIOS_CF_NAMESPACE_SUPPORT
//namespace inserters
//{
#endif /* PANTHEIOS_CF_NAMESPACE_SUPPORT */

/** Class for inserting string slices into Pantheios diagnostic logging
 *   statements.
 */
class slice_inserter
{
/// \name Member Types
/// @{
public:
    typedef slice_inserter                              class_type;
private:
    typedef stlsoft::auto_buffer<pantheios_char_t, 256> buffer_type_;
/// @}

/// \name Construction
/// @{
public:
    slice_inserter(
        pantheios_char_t const* str
    ,   size_t                  len
    ,   pantheios_char_t const* strName
    ,   pantheios_char_t const* lenName
    ,   pantheios_char_t const* equals
    ,   pantheios_char_t const* separator
    );
#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
    slice_inserter(class_type const& rhs);
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Accessors
/// @{
public:
    ///  A possibly non-nul-terminated non-null pointer to the c-style string representation of the slice
    pantheios_char_t const* data() const;
    ///  A nul-terminated non-null pointer to the c-style string representation of the slice
    pantheios_char_t const* c_str() const;
    ///  The length of the c-style string representation of the slice
    size_t                  length() const;
/// @}

/// \name Implementation
/// @{
private:
    void construct_() const;
    void construct_();
/// @}

/// \name Member Variables
/// @{
private:
    pantheios_char_t const* m_str;
    size_t                  m_len;
    pantheios_char_t const* m_strName;
    pantheios_char_t const* m_lenName;
    pantheios_char_t const* m_equals;
    pantheios_char_t const* m_separator;
    buffer_type_            m_buffer;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type& operator =(class_type const&);
/// @}
};

#ifdef PANTHEIOS_CF_NAMESPACE_SUPPORT
//namespace inserters
//{
#endif /* PANTHEIOS_CF_NAMESPACE_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * inserter functions
 */

/** Defines slice of a string
 *
 * \param str Pointer to the first character in the string to be sliced
 * \param len Number of characters to be sliced
 *
 */
inline pan_slice_t slice(
    pantheios_char_t const* str
,   size_t                  len
)
{
    return pan_slice_t(str, len);
}

/** Defines a slice of string
 *
 * \param str Pointer to the first character in the string to be sliced
 * \param len Number of characters to be sliced
 * \param strName Name of the string parameter
 */
inline slice_inserter slice(
    pantheios_char_t const* str
,   size_t                  len
,   pantheios_char_t const* strName
)
{
    return slice_inserter(str, len, strName, NULL, NULL, NULL);
}

/** Defines a slice of string
 *
 * \param str Pointer to the first character in the string to be sliced
 * \param len Number of characters to be sliced
 * \param strName Name of the string parameter
 * \param lenName Name of the length parameter
 */
inline slice_inserter slice(
    pantheios_char_t const* str
,   size_t                  len
,   pantheios_char_t const* strName
,   pantheios_char_t const* lenName
)
{
    return slice_inserter(str, len, strName, lenName, NULL, NULL);
}

/** Defines a slice of string
 *
 * \param str Pointer to the first character in the string to be sliced
 * \param len Number of characters to be sliced
 * \param strName Name of the string parameter
 * \param lenName Name of the length parameter
 * \param equals The string that separates the name and the value
 */
inline slice_inserter slice(
    pantheios_char_t const* str
,   size_t                  len
,   pantheios_char_t const* strName
,   pantheios_char_t const* lenName
,   pantheios_char_t const* equals
)
{
    return slice_inserter(str, len, strName, lenName, equals, NULL);
}

/** Defines a slice of string
 *
 * \param str Pointer to the first character in the string to be sliced
 * \param len Number of characters to be sliced
 * \param strName Name of the string parameter
 * \param lenName Name of the length parameter
 * \param equals The string that separates the name and the value
 * \param separator The string to be used between the string and length parameters
 */
inline slice_inserter slice(
    pantheios_char_t const* str
,   size_t                  len
,   pantheios_char_t const* strName
,   pantheios_char_t const* lenName
,   pantheios_char_t const* equals
,   pantheios_char_t const* separator
)
{
    return slice_inserter(str, len, strName, lenName, equals, separator);
}

/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

# if !defined(PANTHEIOS_NO_NAMESPACE)
namespace shims
{
# endif /* !PANTHEIOS_NO_NAMESPACE */

inline
PAN_CHAR_T const*
PANTHEIOS_c_str_data_name_(
    slice_inserter const& i
)
{
    return i.data();
}
inline
pantheios_char_t const*
c_str_data(
    slice_inserter const& i
)
{
    return i.data();
}

inline
size_t
PANTHEIOS_c_str_len_name_(
    slice_inserter const& i
)
{
    return i.length();
}
inline
size_t
c_str_len(
    slice_inserter const& i
)
{
    return i.length();
}

inline
PAN_CHAR_T const*
PANTHEIOS_c_str_ptr_name_(
    slice_inserter const& i
)
{
    return i.c_str();
}
inline
pantheios_char_t const*
c_str_ptr(
    slice_inserter const& i
)
{
    return i.c_str();
}

# if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace shims */

#  if 0 || \
      defined(STLSOFT_COMPILER_IS_CLANG) || \
      defined(STLSOFT_COMPILER_IS_GCC) || \
      0
    /* GCC does not seem to correctly handle the phases of
     * processing of C++ templates, so we need to 'use' the
     * shims into the same namespace as the inserter class
     * in order that ADL can suffice instead.
     */
    using ::pantheios::shims::PANTHEIOS_c_str_data_name_;
    using ::pantheios::shims::PANTHEIOS_c_str_len_name_;
    using ::pantheios::shims::PANTHEIOS_c_str_ptr_name_;
    using ::pantheios::shims::c_str_data;
    using ::pantheios::shims::c_str_len;
    using ::pantheios::shims::c_str_ptr;
#  endif /* compiler */

# endif /* !PANTHEIOS_NO_NAMESPACE */

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace pantheios */

namespace stlsoft
{
    // 'Export' the string access shims into the STLSoft namespace
    //
    // c_str_ptr(_a) is not necessary for version 1.0 of Pantheios, but it's
    // defined and exported in order to allow for the case where someone
    // may find a legitimate use for the conversion classes additional to
    // the type-tunneling of the Pantheios API.

    using ::pantheios::shims::PANTHEIOS_c_str_data_name_;
    using ::pantheios::shims::PANTHEIOS_c_str_len_name_;
    using ::pantheios::shims::PANTHEIOS_c_str_ptr_name_;
    using ::pantheios::shims::c_str_data;
    using ::pantheios::shims::c_str_len;
    using ::pantheios::shims::c_str_ptr;
}

#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_PAD */

/* ///////////////////////////// end of file //////////////////////////// */

