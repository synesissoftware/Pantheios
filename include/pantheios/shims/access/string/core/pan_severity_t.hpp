/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/shims/access/string/core/pan_severity_t.hpp
 *
 * Purpose:     Pantheios Core entity string access shims : pan_severity_t.
 *
 * Created:     21st June 2005
 * Updated:     29th June 2016
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


/** \file pantheios/shims/access/string/core/pan_severity_t.hpp
 *
 * [C++ only] Pantheios Core entity string access shims : pan_severity_t.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_SHIMS_ACCESS_STRING_CORE_HPP_PAN_SEVERITY_T
#define PANTHEIOS_INCL_PANTHEIOS_SHIMS_ACCESS_STRING_CORE_HPP_PAN_SEVERITY_T

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_SHIMS_ACCESS_STRING_CORE_HPP_PAN_SEVERITY_T_MAJOR      4
# define PANTHEIOS_VER_PANTHEIOS_SHIMS_ACCESS_STRING_CORE_HPP_PAN_SEVERITY_T_MINOR      0
# define PANTHEIOS_VER_PANTHEIOS_SHIMS_ACCESS_STRING_CORE_HPP_PAN_SEVERITY_T_REVISION   1
# define PANTHEIOS_VER_PANTHEIOS_SHIMS_ACCESS_STRING_CORE_HPP_PAN_SEVERITY_T_EDIT       355
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * validation
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# error This is an internal header file, and must not be included directly
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifndef __cplusplus
# error This file is valid only in C++ compilation units
#endif /* !__cplusplus */

#ifdef PANTHEIOS_NO_STOCK_LEVELS
# error This file cannot be included when stock levels are suppressed
#endif /* PANTHEIOS_NO_STOCK_LEVELS */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS
# include <pantheios/internal/shim_declarations.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

# if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
namespace shims
{
# endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

/* Shims for (pan_severity_t severity) */

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the severity */
inline
pan_char_t const*
PANTHEIOS_c_str_data_name_(
    pan_severity_t severity
)
{
    return pantheios_getStockSeverityString(severity);
}
/** Returns a possibly non-nul-terminated non-NULL C-style string representing the severity */
inline
pan_char_t const*
c_str_data(
    pan_severity_t severity
)
{
    return pantheios_getStockSeverityString(severity);
}

/** Returns the number of characters in the length of the C-style string representing the severity */
inline
size_t
PANTHEIOS_c_str_len_name_(
    pan_severity_t severity
)
{
    return pantheios_getStockSeverityStringLength(severity);
}
/** Returns the number of characters in the length of the C-style string representing the severity */
inline
size_t
c_str_len(
    pan_severity_t severity
)
{
    return pantheios_getStockSeverityStringLength(severity);
}

/** Returns a nul-terminated non-NULL C-style string representing the severity */
inline
pan_char_t const*
PANTHEIOS_c_str_ptr_name_(
    pan_severity_t severity
)
{
    return pantheios_getStockSeverityString(severity);
}
/** Returns a nul-terminated non-NULL C-style string representing the severity */
inline
pan_char_t const*
c_str_ptr(
    pan_severity_t severity
)
{
    return pantheios_getStockSeverityString(severity);
}

/** Returns a nul-terminated potentially null C-style string representing the severity */
inline
pan_char_t const*
PANTHEIOS_c_str_ptr_null_name_(
    pan_severity_t severity
)
{
    pan_char_t const* s = pantheios_getStockSeverityString(severity);

    return ('\0' != *s) ? s : NULL;
}
/** Returns a nul-terminated potentially null C-style string representing the severity */
inline
pan_char_t const*
c_str_ptr_null(
    pan_severity_t severity
)
{
    pan_char_t const* s = pantheios_getStockSeverityString(severity);

    return ('\0' != *s) ? s : NULL;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

# if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace shims */
} /* namespace pantheios */
# endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_SHIMS_ACCESS_STRING_CORE_HPP_PAN_SEVERITY_T */

/* ///////////////////////////// end of file //////////////////////////// */
