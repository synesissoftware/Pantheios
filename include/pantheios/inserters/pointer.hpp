/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/pointer.hpp
 *
 * Purpose:     String inserters for fundamental types
 *
 * Created:     21st June 2005
 * Updated:     16th January 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
 * Copyright (c) 1999-2005, Synesis Software and Matthew Wilson
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


/** \file pantheios/inserters/pointer.hpp
 *
 * [C++ only] Definition of the pantheios::pointer string inserter for
 *   for pointer types.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_POINTER
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_POINTER

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_POINTER_MAJOR    2
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_POINTER_MINOR    5
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_POINTER_REVISION 2
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_POINTER_EDIT     36
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */
#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_FMT
# include <pantheios/inserters/fmt.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_FMT */
#ifndef PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS
# include <pantheios/internal/shim_declarations.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inserter classes
 */

/** Class for inserting pointers into Pantheios diagnostic logging
 *   statements.
 *
 * \ingroup group__application_layer_interface__inserters
 *
 * This class converts a pointer variable into a string, thereby enabling it to be
 * inserted into a logging statement. Consider the following statement
 *
 * \code
  void*       p   = reinterpret_cast<void*>(0x01234567);
  char        s[] = "abc";
  std::string str("def");

  pantheios::log(pantheios::notice, "s=", s, ", p=", pantheios::pointer(p, 8, pantheios::fmt::fullHex), ", str=", str);
 * \endcode
 *
 * This will produce the output:
 *
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>s=abc, p=0x01234567, str=def</b>
 */
class pointer
{
public:
    /// This type
    typedef pointer     class_type;

public:
    /// [DEPRECATED] Construct from a pointer, with width/format specifier
    ///
    /// \param pv The pointer whose value will be inserted
    /// \param widthAndFormat A bitwise combination of width and format. The
    ///   width must be in the range [0, 20]
    ///
    /// \deprecated This constructor form is deprecated, and will be removed
    ///   in a forthcoming release; instead use
    ///   the \link pantheios::pointer::pointer(void const volatile*, int, int) 3-parameter\endlink
    ///   overload.
    ///
    /// \note For backwards-compatibility, specifiying the zeroXPrefix flag
    ///   also causes zeroPad to be assumed
    pointer(void const volatile* pv, int widthAndFormat);

    /// Construct from a pointer, specifying width and format
    ///
    /// \param pv The pointer whose value will be inserted
    /// \param minWidth The minimum width. Must be in the range [-20, 20]
    /// \param format Combination of \link pantheios::fmt format\endlink flags
    ///
    /// \pre (minWidth >= -20 && minWidth <= 20)
    pointer(void const volatile* pv, int minWidth, int format);

public:
    /// A possibly non-nul-terminated non-null pointer to the c-style string representation of the pointer
    pantheios_char_t const* data() const;
    /// A nul-terminated non-null pointer to the c-style string representation of the pointer
    pantheios_char_t const* c_str() const;
    /// The length of the c-style string representation of the pointer
    size_t                  length() const;

private:
    void construct_() const;
    void construct_();

    static int validate_width_(int minWidth);

protected:
    void const volatile* get_value() const
    {
        return m_value;
    }

private:
    void const volatile*    m_value;
    size_t                  m_len;
    const int               m_minWidth;
    const int               m_format;
    pantheios_char_t        m_sz[23];

private:
#if 1 && \
    !defined(STLSOFT_COMPILER_IS_CLANG) && \
    !defined(STLSOFT_COMPILER_IS_GCC) && \
    1
    pointer(class_type const&);
#endif /* compiler */
    class_type& operator =(class_type const&);
};

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
    pointer const& p
)
{
    return p.data();
}
inline
pantheios_char_t const*
c_str_data(
    pointer const& p
)
{
    return p.data();
}

inline
size_t
PANTHEIOS_c_str_len_name_(
    pointer const& p
)
{
    return p.length();
}
inline
size_t
c_str_len(
    pointer const& p
)
{
    return p.length();
}

inline
PAN_CHAR_T const*
PANTHEIOS_c_str_ptr_name_(
    pointer const& p
)
{
    return p.c_str();
}
inline
pantheios_char_t const*
c_str_ptr(
    pointer const& p
)
{
    return p.c_str();
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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_POINTER */

/* ///////////////////////////// end of file //////////////////////////// */

