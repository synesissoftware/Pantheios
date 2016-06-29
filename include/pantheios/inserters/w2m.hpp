/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/w2m.hpp
 *
 * Purpose:     Inserter class for incorporating wide strings into a
 *              multibyte string statement.
 *
 * Created:     2nd September 2008
 * Updated:     29th June 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2008-2016, Matthew Wilson and Synesis Software
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


/** \file pantheios/inserters/w2m.hpp
 *
 * [C++ only] Class for inserting wide strings.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_W2M
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_W2M

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2M_MAJOR    1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2M_MINOR    3
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2M_REVISION 3
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2M_EDIT     18
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

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# error You may not include pantheios/inserters/m2w.hpp in wide string compilations; instead, use the new w2t inserter
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

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
 * inserter classes
 */

/** Class for inserting wide strings into Pantheios diagnostic logging
 *   statements.
 *
 * \ingroup group__application_layer_interface__inserters
 *
 * This class converts a w2m variable into a string, thereby enabling
 * it to be inserted into a logging statement. Consider the following
 * statement:
 *
 * \code
  wchar_t     ws  = L"abc";
  char        s[] = "abc";
  std::string str("def");

  pantheios::log(pantheios::notice, "s=", s, ", c=", pantheios::w2m(ws), ", str=", str);
 * \endcode
 *
 * This will produce the output:
 *
 * &nbsp;&nbsp;&nbsp;&nbsp;<b>s=abc, c=abc, str=def</b>
 */

class w2m
{
public: // Member Types
    /// This type
    typedef w2m     class_type;

public: // Construction
    /// Construct from a c-style string
    explicit w2m(wchar_t const* s);
    /// Construct from a pointer to a string and a given length
    w2m(wchar_t const* s, size_t len);
    /// Construct from a widestring of unknown type
    ///
    /// \warning This method must only be used "inline", i.e. in a log
    ///   statement. If you create a separate instance of w2m using this
    ///   constructor and attempt to access its converted value - either
    ///   directly, via c_str()/data(), or indirectly via inserting into a
    ///   log statement - the program will have undefined behaviour.
    template <typename WS>
    explicit w2m(WS const& ws)
    {
        // If the init_() call fails to compile with an error message that
        // mentions
        //  'containing your_wide_type_relies_on_intermediate_shim_conversions_which_are_prohibited_unless_PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES_is_defined'
        // then the (wide) shims for the type WS use intermediate instances
        // of conversion classes, and would cause undefined behaviour if
        // you were to use it any a non-"inline" log statement. If you are
        // sure you are using the inserter correctly, then #define the
        // preprocessor symbol PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES to
        // allow it to compile.

#ifndef PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES
        int unused = 
#endif /* !PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES */
            
            init_(::stlsoft::c_str_data_w(ws), ::stlsoft::c_str_len_w(ws));

#ifndef PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES
        STLSOFT_SUPPRESS_UNUSED(unused);
#endif /* !PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES */
    }
    /// Releases any resources allocated for the conversion
    ~w2m() STLSOFT_NOEXCEPT;

private:
#if 1 && \
    !defined(STLSOFT_COMPILER_IS_CLANG) && \
    !defined(STLSOFT_COMPILER_IS_GCC) && \
    1
    w2m(class_type const&);
#endif /* compiler */
    class_type& operator =(class_type const&);

public: // Accessors
    /// A possibly non-nul-terminated non-null pointer to the c-style string representation of the w2m
    char const* data() const;
    /// A nul-terminated non-null pointer to the c-style string representation of the w2m
    char const* c_str() const;
    /// The length of the c-style string representation of the w2m
    size_t      length() const;

private: // Implementation
    int  init_(wchar_t const* s, size_t n);
#ifndef PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES
    struct your_wide_type_relies_on_intermediate_shim_conversions_which_are_prohibited_unless_PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES_is_defined;
    template <typename T0, typename T1>
    your_wide_type_relies_on_intermediate_shim_conversions_which_are_prohibited_unless_PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES_is_defined init_(T0 const&, T1 const&);
#endif /* !PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES */
    void construct_() const;
    void construct_();
    static size_t sentinelLength_()
    {
        return ~size_t(0);
    }

private: // Member Variables
    // We can't use auto_buffer because GCC is a total dullard, "helpfully"
    // informing us that it can't generate a copy-constructor when we're
    // telling *it* that we're proscribing that very thing.
    //
    // So, we're just going to have to manage our own memory, and use up
    // two more hours that could be more profitably spent on something else
    wchar_t const*  m_source;
    size_t          m_sourceLen;
    char*           m_result;
    size_t          m_length;
};

/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

# if !defined(PANTHEIOS_NO_NAMESPACE)
namespace shims
{
# endif /* !PANTHEIOS_NO_NAMESPACE */


/** \overload c_str_data_a(w2m const&) */
inline
char const*
c_str_data_a(
    w2m const& r
)
{
    return r.data();
}
/** \overload c_str_data(w2m const&) */
inline
pan_char_t const*
c_str_data(
    w2m const& r
)
{
    return r.data();
}

/** \overload c_str_len_a(w2m const&) */
inline
size_t
c_str_len_a(
    w2m const& r
)
{
    return r.length();
}
/** \overload c_str_len(w2m const&) */
inline
size_t
c_str_len(
    w2m const& r
)
{
    return r.length();
}

/** \overload c_str_ptr_a(w2m const&) */
inline
char const*
c_str_ptr_a(
    w2m const& r
)
{
    return r.c_str();
}
/** \overload c_str_ptr(w2m const&) */
inline
pan_char_t const*
c_str_ptr(
    w2m const& r
)
{
    return r.c_str();
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
    using ::pantheios::shims::c_str_data_a;
    using ::pantheios::shims::c_str_data;

    using ::pantheios::shims::c_str_len_a;
    using ::pantheios::shims::c_str_len;

    using ::pantheios::shims::c_str_ptr_a;
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

    using ::pantheios::shims::c_str_data_a;
    using ::pantheios::shims::c_str_data;

    using ::pantheios::shims::c_str_len_a;
    using ::pantheios::shims::c_str_len;

    using ::pantheios::shims::c_str_ptr_a;
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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_W2M */

/* ///////////////////////////// end of file //////////////////////////// */
