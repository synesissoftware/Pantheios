/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/util/string/date_elements_to_string.h
 *
 * Purpose:     Date element to string fragment conversion utilities for
 *              Pantheios API
 *
 * Created:     12th November 2016
 * Updated:     17th December 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2016, Matthew Wilson and Synesis Software
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


/** \file pantheios/util/string/date_elements_to_string.h
 *
 * \brief [C, C++] INTERNAL FILE (AND SUBJECT TO CHANGE): Date element to
 *   string conversion utility functions.
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_UTIL_STRING_H_DATE_ELEMENTS_TO_STRING
#define PANTHEIOS_INCL_PANTHEIOS_UTIL_STRING_H_DATE_ELEMENTS_TO_STRING

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_DATE_ELEMENTS_TO_STRING_MAJOR    1
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_DATE_ELEMENTS_TO_STRING_MINOR    0
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_DATE_ELEMENTS_TO_STRING_REVISION 1
# define PANTHEIOS_VER_PANTHEIOS_UTIL_STRING_H_DATE_ELEMENTS_TO_STRING_EDIT     2
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * API (C)
 */

/** [Currently undocumented] Converts a year to a four-digit, unterminated
 * string form
 *
 * \param year A year value, between 0 and 9999. Number outside this range
 *   are processed (silently) as year % 10000
 *
 * \note The string is NOT nul-terminated by this function
 *
 * \note THIS FUNCTION IS NOT PART OF THE PUBLICLY DOCUMENTED API OF
 *   PANTHEIOS, AND IS SUBJECT TO REMOVAL/CHANGE IN A FUTURE RELEASE
 */
PANTHEIOS_CALL(void)
pantheios_util_formatYearToString4(
    unsigned       year
,   PAN_CHAR_T   (*ar)[4]
) STLSOFT_NOEXCEPT;

PANTHEIOS_CALL(void)
pantheios_util_formatMonthToString2(
    unsigned       month
,   PAN_CHAR_T   (*ar)[2]
) STLSOFT_NOEXCEPT;

PANTHEIOS_CALL(void)
pantheios_util_formatDayToString2(
    unsigned       day
,   PAN_CHAR_T   (*ar)[2]
) STLSOFT_NOEXCEPT;

PANTHEIOS_CALL(void)
pantheios_util_formatHourToString2(
    unsigned       hour
,   PAN_CHAR_T   (*ar)[2]
) STLSOFT_NOEXCEPT;

PANTHEIOS_CALL(void)
pantheios_util_formatMinuteOrSecondToString2(
    unsigned       minOrSecond
,   PAN_CHAR_T   (*ar)[2]
) STLSOFT_NOEXCEPT;

PANTHEIOS_CALL(void)
pantheios_util_formatMillisecondToString3(
    unsigned       millisecond
,   PAN_CHAR_T   (*ar)[3]
) STLSOFT_NOEXCEPT;

PANTHEIOS_CALL(void)
pantheios_util_formatMicrosecondToString6(
    unsigned       microsecond
,   PAN_CHAR_T   (*ar)[6]
) STLSOFT_NOEXCEPT;

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
namespace util
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API (C++)
 */

#ifdef __cplusplus

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace util */
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_INCL_PANTHEIOS_UTIL_STRING_H_DATE_ELEMENTS_TO_STRING */

/* ///////////////////////////// end of file //////////////////////////// */
