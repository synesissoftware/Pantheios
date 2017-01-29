/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/windows/hive.hpp
 *
 * Purpose:     Selective format string inserter for Windows Registry hives.
 *
 * Created:     22nd May 2016
 * Updated:     26th January 2017
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2016-2017, Matthew Wilson and Synesis Software
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


/** \file pantheios/inserters/windows/hive.hpp
 *
 * [C++ only] Definition of the pantheios::windows::hive inserter
 *   class, for selective format string insertion for Windows Registry
 *   hives.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_HIVE
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_HIVE

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_HIVE_MAJOR       1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_HIVE_MINOR       0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_HIVE_REVISION    1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_HIVE_EDIT        2
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_HEX_PTR
# include <pantheios/inserters/hex_ptr.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_HEX_PTR */

#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
#endif /* !PANTHEIOS_NO_NAMESPACE */
namespace windows
{

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/** Class for inserting Windows Registry library key handles (HKEY), which
 * will be rendered as the hive name if identified as a known hive,
 * otherwise will be rendered as 0xYYYYYYYY (or 0xYYYYYYYYYYYYYYYY on 64).
 *
 * \ingroup group__application_layer_interface__inserters
 *
 */
class hive
    : public PANTHEIOS_NS_QUAL(hex_ptr)
{
public: // Types
    /// This type
    typedef hive                        class_type;
    /// The parent class type
    typedef PANTHEIOS_NS_QUAL(hex_ptr)  parent_class_type;

public: // Construction
    /// Constructs an instance
    explicit
    hive(
        HKEY hive
    )
        : parent_class_type(hive)
    {}

public:
    /// A possibly non-nul-terminated non-null pointer to the c-style string representation of the pointer
    pan_char_t const*   data() const;
    /// A nul-terminated non-null pointer to the c-style string representation of the pointer
    pan_char_t const*   c_str() const;
    /// The length of the c-style string representation of the pointer
    size_t              length() const;

private:
// TODO: put into implementation file
    static
    size_t
    lookup_hive_(
        void const volatile*    value
    ,   pan_char_t const**      ptr
    )
    {
#ifdef HKEY_CLASSES_ROOT
        if(HKEY_CLASSES_ROOT == value)
        {
            static pan_char_t const s_name[] = PANTHEIOS_LITERAL_STRING(STLSOFT_STRINGIZE_DIRECT(HKEY_CLASSES_ROOT));

            *ptr = s_name;

            return STLSOFT_NUM_ELEMENTS(s_name) - 1;
        }
#endif
#ifdef HKEY_CURRENT_USER
        if(HKEY_CURRENT_USER == value)
        {
            static pan_char_t const s_name[] = PANTHEIOS_LITERAL_STRING(STLSOFT_STRINGIZE_DIRECT(HKEY_CURRENT_USER));

            *ptr = s_name;

            return STLSOFT_NUM_ELEMENTS(s_name) - 1;
        }
#endif
#ifdef HKEY_LOCAL_MACHINE
        if(HKEY_LOCAL_MACHINE == value)
        {
            static pan_char_t const s_name[] = PANTHEIOS_LITERAL_STRING(STLSOFT_STRINGIZE_DIRECT(HKEY_LOCAL_MACHINE));

            *ptr = s_name;

            return STLSOFT_NUM_ELEMENTS(s_name) - 1;
        }
#endif
#ifdef HKEY_USERS
        if(HKEY_USERS == value)
        {
            static pan_char_t const s_name[] = PANTHEIOS_LITERAL_STRING(STLSOFT_STRINGIZE_DIRECT(HKEY_USERS));

            *ptr = s_name;

            return STLSOFT_NUM_ELEMENTS(s_name) - 1;
        }
#endif
#ifdef HKEY_PERFORMANCE_DATA
        if(HKEY_PERFORMANCE_DATA == value)
        {
            static pan_char_t const s_name[] = PANTHEIOS_LITERAL_STRING(STLSOFT_STRINGIZE_DIRECT(HKEY_PERFORMANCE_DATA));

            *ptr = s_name;

            return STLSOFT_NUM_ELEMENTS(s_name) - 1;
        }
#endif
#ifdef HKEY_CURRENT_CONFIG
        if(HKEY_CURRENT_CONFIG == value)
        {
            static pan_char_t const s_name[] = PANTHEIOS_LITERAL_STRING(STLSOFT_STRINGIZE_DIRECT(HKEY_CURRENT_CONFIG));

            *ptr = s_name;

            return STLSOFT_NUM_ELEMENTS(s_name) - 1;
        }
#endif
#ifdef HKEY_DYN_DATA
        if(HKEY_DYN_DATA == value)
        {
            static pan_char_t const s_name[] = PANTHEIOS_LITERAL_STRING(STLSOFT_STRINGIZE_DIRECT(HKEY_DYN_DATA));

            *ptr = s_name;

            return STLSOFT_NUM_ELEMENTS(s_name) - 1;
        }
#endif

        return 0;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

inline
pan_char_t const*
hive::c_str() const
{
    pan_char_t const*   p;
    size_t const        r = lookup_hive_(get_value(), &p);

    return (0u == r) ? parent_class_type::c_str() : p;
}

inline
pan_char_t const*
hive::data() const
{
    pan_char_t const*   p;
    size_t const        r = lookup_hive_(get_value(), &p);

    return (0u == r) ? parent_class_type::data() : p;
}

inline
size_t
hive::length() const
{
    pan_char_t const*   p;
    size_t const        r = lookup_hive_(get_value(), &p);

    return (0u == r) ? parent_class_type::length() : r;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace windows */

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
    windows::hive const& h
)
{
    return h.data();
}
inline
pan_char_t const*
c_str_data(
    windows::hive const& h
)
{
    return h.data();
}

inline
size_t
PANTHEIOS_c_str_len_name_(
    windows::hive const& h
)
{
    return h.length();
}
inline
size_t
c_str_len(
    windows::hive const& h
)
{
    return h.length();
}

inline
PAN_CHAR_T const*
PANTHEIOS_c_str_ptr_name_(
    windows::hive const& h
)
{
    return h.c_str();
}
inline
pan_char_t const*
c_str_ptr(
    windows::hive const& h
)
{
    return h.c_str();
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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_HIVE */

/* ///////////////////////////// end of file //////////////////////////// */
