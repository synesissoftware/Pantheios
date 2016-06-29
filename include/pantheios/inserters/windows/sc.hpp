/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/windows/sc.hpp
 *
 * Purpose:     Defines shorthand name for pantheios::windows::status_code
 *              inserter class.
 *
 * Created:     5th April 2014
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


/** \file pantheios/inserters/windows/sc.hpp
 *
 * [C++ only] Defines shorthand name for pantheios::windows::status_code
 *  inserter class.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_SC
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_SC

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_SC_MAJOR     1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_SC_MINOR     0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_SC_REVISION  1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_SC_EDIT      3
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE
# include <pantheios/inserters/windows/status_code.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE */

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
 * typedefs
 */

/** Typedef for pantheios::windows::status_code inserter class. */
typedef status_code sc;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace windows */
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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_SC */

/* ///////////////////////////// end of file //////////////////////////// */
