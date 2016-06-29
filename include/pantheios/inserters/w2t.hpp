/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/w2t.hpp
 *
 * Purpose:     Inserter class for inserting wide strings.
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


/** \file pantheios/inserters/w2t.hpp
 *
 * [C++ only] Inserter class for inserting wide strings.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_W2T
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_W2T

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2T_MAJOR    1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2T_MINOR    0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2T_REVISION 0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_W2T_EDIT     2
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
#  include <stlsoft/shims/access/string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */
# include <pantheios/inserters/w2m.hpp>
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

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

#ifdef PANTHEIOS_USE_WIDE_STRINGS

struct w2t
    : public pan_slice_t
{
public: // Types
    typedef pan_slice_t     parent_class_type;
    typedef w2t             class_type;

public:
    explicit
    w2t(wchar_t const* s)
      : parent_class_type(-1, s)
    {}
    w2t(wchar_t const* s, size_t cch)
      : parent_class_type(s, cch)
    {}
    template <typename S>
    explicit
    w2t(S const& s)
      : parent_class_type(stlsoft::c_str_data_w(s), stlsoft::c_str_len_w(s))
    {}
};
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

typedef w2m         w2t;
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_W2T */

/* ///////////////////////////// end of file //////////////////////////// */
