/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/internal/slice.hpp
 *
 * Purpose:     pan_slice_t implementation.
 *
 * Created:     21st June 2005
 * Updated:     17th December 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2005-2016, Matthew Wilson and Synesis Software
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


/** \file pantheios/internal/slice.hpp
 *
 * [C, C++] INTERNAL FILE (AND SUBJECT TO CHANGE): pan_slice_t
 *  implementation.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SLICE
#define PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SLICE

/* /////////////////////////////////////////////////////////////////////////
 * validation
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# error This is an internal header file, and must not be included directly
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifndef __cplusplus
# error This file is valid only in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

# ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

/* /////////////////////////////////////////////////////////////////////////
 * pan_slice_t
 */

inline
/* static */
size_t
pan_slice_t::calc_length_n_(
    pan_char_t const*   s
,   size_t              len
)
{
#if !defined(PANTHEIOS_NO_NAMESPACE)
    using pantheios::util::pantheios_util_strnlen;
#endif /* !PANTHEIOS_NO_NAMESPACE */

    return pantheios_util_strnlen(s, len);
}

inline
pan_slice_t::pan_slice_t()
{
    this->len   =   0;
    this->ptr   =   NULL;
}

inline
pan_slice_t::pan_slice_t(
    pan_char_t const*   p
,   size_t              l
)
{
    static size_t const topBit = size_t(0x01) << (sizeof(size_t) * 8 - 1);

    if(topBit & l)
    {
        this->len = calc_length_n_(p, l);
    }
    else
    {
        this->len = l;
    }

    this->ptr = p;
}

inline
pan_slice_t::pan_slice_t(
    pan_slice_t const& rhs
)
{
    this->len = rhs.len;
    this->ptr = rhs.ptr;
}

inline
pan_slice_t::pan_slice_t(
    pantheios_slice_t const& rhs
)
{
    this->len = rhs.len;
    this->ptr = rhs.ptr;
}

inline
pan_slice_t&
pan_slice_t::operator =(
    pan_slice_t const& rhs
)
{
    this->len = rhs.len;
    this->ptr = rhs.ptr;

    return *this;
}

inline
pan_slice_t&
pan_slice_t::operator =(
    pantheios_slice_t const& rhs
)
{
    this->len = rhs.len;
    this->ptr = rhs.ptr;

    return *this;
}

inline
pan_slice_t::pan_slice_t(
    int                 l
,   pan_char_t const*   p
)
{
    this->len   =   calc_length_n_(p, static_cast<size_t>(l));
    this->ptr   =   p;
}

/* ////////////////////////////////////////////////////////////////////// */

# endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SLICE */

/* ///////////////////////////// end of file //////////////////////////// */
