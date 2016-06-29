/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/inserters/windows/status_code.hpp
 *
 * Purpose:     Selective format string inserter for Windows status codes.
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


/** \file pantheios/inserters/windows/status_code.hpp
 *
 * [C++ only] Definition of the pantheios::windows::status_code inserter
 *   class, for selective format string inserter for Windows status codes.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE
#define PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE_MAJOR    1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE_MINOR    0
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE_REVISION 1
# define PANTHEIOS_VER_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE_EDIT     6
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_INTEGER
# include <pantheios/inserters/integer.hpp>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_HPP_INTEGER */

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

/** Class for inserting Windows status codes, either Windows API
 * <code>DWORD</code> values (from <code>GetLastError()</code>), which will
 * be rendered as plain integers, or COM <code>HRESULT</code> values, which
 * will be rendered as 0xYYYYYYYY.
 *
 * \ingroup group__application_layer_interface__inserters
 *
 */
class status_code
    : public PANTHEIOS_NS_QUAL(integer)
{
public: // Types
    /// This type
    typedef status_code                 class_type;
    /// The parent class type
    typedef PANTHEIOS_NS_QUAL(integer)  parent_class_type;

public: // Construction
    /// Constructs an instance
    explicit
    status_code(
        DWORD e
    )
        : parent_class_type(e, get_width_(e), get_format_(e))
    {}
    /// Constructs an instance
    explicit
    status_code(
        int e
    )
        : parent_class_type(e, get_width_(e), get_format_(e))
    {}
    /// Constructs an instance
    explicit
    status_code(
        LONG e
    )
        : parent_class_type(e, get_width_(e), get_format_(e))
    {}

private:
    template <typename I>
    static int get_width_(I e)
    {
        if(0 != (0x80000000 & e))
        {
            return 8;
        }

        return 0;
    }
    template <typename I>
    static int get_format_(I e)
    {
        if(0 != (0x80000000 & e))
        {
            return fmt::fullHex;
        }

        return 0;
    }
};

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

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INSERTERS_WINDOWS_HPP_STATUS_CODE */

/* ///////////////////////////// end of file //////////////////////////// */
