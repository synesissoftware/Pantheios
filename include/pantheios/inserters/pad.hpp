/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/pad.hpp
 *
 * Purpose:     padding of arguments of arbitrary type.
 *
 * Created:     29th June 2009
 * Updated:     16th December 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2009-2019, Matthew Wilson and Synesis Software
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


/** \file pantheios/inserters/pad.hpp
 *
 * [c++ only] definition of the pantheios::pad string inserter for
 *   for providing padding of arguments of arbitrary type.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_PAD
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_PAD


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_MAJOR    1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_MINOR    0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_REVISION 4
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_HPP_PAD_EDIT     7
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

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
 * macros
 */

/** \def PANTHEIOS_LPAD(var, minWidth)
 *
 * \ingroup group__application_layer_interface__inserters
 *
 * Inserts a variable with a minimum width, padding to the left with spaces
 *
 * \param var The variable to be inserted
 * \param minWidth The minimum width of the inserted variable
 */
#define PANTHEIOS_LPAD(var, minWidth)   ( ::pantheios::pad(var, minWidth)), (var)

/** \def PANTHEIOS_RPAD(var, minWidth)
 *
 * \ingroup group__application_layer_interface__inserters
 *
 * Inserts a variable with a minimum width, padding to the right with spaces
 *
 * \param var The variable to be inserted
 * \param minWidth The minimum width of the inserted variable
 */
#define PANTHEIOS_RPAD(var, minWidth)   (var), ( ::pantheios::pad(var, minWidth))


/* /////////////////////////////////////////////////////////////////////////
 * inserter functions
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

template <typename S>
inline const pan_slice_t pad(S const& arg, size_t minimumWidth)
{
    const size_t len = stlsoft::c_str_len(arg);

    if(len < minimumWidth)
    {
        size_t                          actualWidth;
        pantheios_char_t const* const   padding = pantheios::core::pantheios_getPad(minimumWidth - len, &actualWidth);

        return pan_slice_t(padding, actualWidth);
    }

    return pan_slice_t();
}

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */


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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_PAD */

/* ///////////////////////////// end of file //////////////////////////// */

