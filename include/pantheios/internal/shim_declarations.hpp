/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/internal/shim_declarations.hpp
 *
 * Purpose:     Declarations and definitions of various shim-related
 *              constructs.
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


/** \file pantheios/internal/shim_declarations.hpp
 *
 * [C++ only] INTERNAL FILE: Declarations and definitions of various
 *  shim-related constructs.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS
#define PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS

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
 * shim declarations
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

# ifdef PANTHEIOS_c_str_data_name_
#  undef PANTHEIOS_c_str_data_name_
# endif /* PANTHEIOS_c_str_data_name_ */
# ifdef PANTHEIOS_c_str_len_name_
#  undef PANTHEIOS_c_str_len_name_
# endif /* PANTHEIOS_c_str_len_name_ */
# ifdef PANTHEIOS_c_str_ptr_name_
#  undef PANTHEIOS_c_str_ptr_name_
# endif /* PANTHEIOS_c_str_ptr_name_ */
# ifdef PANTHEIOS_c_str_ptr_null_name_
#  undef PANTHEIOS_c_str_ptr_null_name_
# endif /* PANTHEIOS_c_str_ptr_null_name_ */

# ifdef PANTHEIOS_USE_WIDE_STRINGS
#  define PANTHEIOS_c_str_data_name_                    c_str_data_w
#  define PANTHEIOS_c_str_len_name_                     c_str_len_w
#  define PANTHEIOS_c_str_ptr_name_                     c_str_ptr_w
#  define PANTHEIOS_c_str_ptr_null_name_                c_str_ptr_null_w
# else /* ? PANTHEIOS_USE_WIDE_STRINGS */
#  define PANTHEIOS_c_str_data_name_                    c_str_data_a
#  define PANTHEIOS_c_str_len_name_                     c_str_len_a
#  define PANTHEIOS_c_str_ptr_name_                     c_str_ptr_a
#  define PANTHEIOS_c_str_ptr_null_name_                c_str_ptr_null_a
# endif /* PANTHEIOS_USE_WIDE_STRINGS */

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_INTERNAL_HPP_SHIM_DECLARATIONS */

/* ///////////////////////////// end of file //////////////////////////// */
