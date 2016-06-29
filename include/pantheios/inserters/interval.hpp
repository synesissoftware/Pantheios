/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/interval.hpp
 *
 * Purpose:     String inserter for time intervals pairs.
 *
 * Created:     19th April 2014
 * Updated:     29th June 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2014-2016, Matthew Wilson and Synesis Software
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


/** \file pantheios/inserters/interval.hpp
 *
 * [C++ only] Definition of the pantheios::interval inserter for
 *   <code>argc+argv</code> pairs.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_INTERVAL
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_INTERVAL

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_INTERVAL_MAJOR       1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_INTERVAL_MINOR       0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_INTERVAL_REVISION    1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_INTERVAL_EDIT        2
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

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

#include <string>

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

/** Class for inserting time interval arguments into Pantheios
 *    diagnostic logging statements.
 *
 * \ingroup group__application_layer_interface__inserters
 *
 *
 */
class interval
{
/// \name Member Types
/// @{
public:
    typedef interval    class_type;
/// @}

/// \name Member Constants
/// @{
public:
    ///  The format flags
    enum units
    {
            microseconds    =   1
        ,   milliseconds    =   2
        ,   seconds         =   3
        ,   minutes         =   4
        ,   hours           =   5
        ,   days            =   6
    };
/// @}

/// \name Construction
/// @{
public:
    interval(int interval, units units);
private:
#if !defined(STLSOFT_COMPILER_IS_GCC)
    interval(class_type const&); // proscribed
#endif /* compiler */
    class_type& operator =(class_type const&); // proscribed
/// @}

/// \name Accessors
/// @{
public:
    ///  A possibly non-nul-terminated non-null pointer to the c-style string representation of the integer
    pan_char_t const*   data() const;
    ///  A nul-terminated non-null pointer to the c-style string representation of the integer
    pan_char_t const*   c_str() const;
    ///  The size of the c-style string representation of the integer
    size_t              size() const;
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
    typedef std::basic_string<pan_char_t> string_type_;

    pan_sint64_t const  m_interval;
    units const         m_units;
    string_type_        m_result;
/// @}
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
    interval const& i
)
{
    return i.data();
}

inline
pan_char_t const*
c_str_data(interval const& i)
{
    return i.data();
}

inline
size_t
PANTHEIOS_c_str_len_name_(
    interval const& i
)
{
    return i.size();
}
inline
size_t
c_str_len(interval const& i)
{
    return i.size();
}

inline
PAN_CHAR_T const*
PANTHEIOS_c_str_ptr_name_(
    interval const& i
)
{
    return i.c_str();
}

inline
pan_char_t const*
c_str_ptr(interval const& i)
{
    return i.c_str();
}

# if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace shims */

#  if defined(STLSOFT_COMPILER_IS_GCC)
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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_INTERVAL */

/* ///////////////////////////// end of file //////////////////////////// */
