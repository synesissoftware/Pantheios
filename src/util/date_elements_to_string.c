/* /////////////////////////////////////////////////////////////////////////
 * File:        src/util/date_elements_to_string.c
 *
 * Purpose:     Date element to string fragment conversion utilities for
 *              Pantheios API
 *
 * Created:     12th November 2016
 * Updated:     10th January 2017
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


/* Pantheios header files
 *
 * NOTE: We do _not_ include pantheios/pantheios.hpp here, since we are
 *  not using any of the Application Layer.
 */

#include <pantheios/pantheios.h>
#include <pantheios/util/string/strnlen.h>

/* /////////////////////////////////////////////////////////////////////////
 * data
 */

#ifdef __cplusplus
namespace {
#endif /* __cplusplus */

#define PAN_DE2S_0299_  s_pantheios_util_date_elements_to_string_0_to_99
static PAN_CHAR_T const
s_pantheios_util_date_elements_to_string_0_to_99[][2] =
{
    { '0', '0' },
    { '0', '1' },
    { '0', '2' },
    { '0', '3' },
    { '0', '4' },
    { '0', '5' },
    { '0', '6' },
    { '0', '7' },
    { '0', '8' },
    { '0', '9' },

    { '1', '0' },
    { '1', '1' },
    { '1', '2' },
    { '1', '3' },
    { '1', '4' },
    { '1', '5' },
    { '1', '6' },
    { '1', '7' },
    { '1', '8' },
    { '1', '9' },

    { '2', '0' },
    { '2', '1' },
    { '2', '2' },
    { '2', '3' },
    { '2', '4' },
    { '2', '5' },
    { '2', '6' },
    { '2', '7' },
    { '2', '8' },
    { '2', '9' },

    { '3', '0' },
    { '3', '1' },
    { '3', '2' },
    { '3', '3' },
    { '3', '4' },
    { '3', '5' },
    { '3', '6' },
    { '3', '7' },
    { '3', '8' },
    { '3', '9' },

    { '4', '0' },
    { '4', '1' },
    { '4', '2' },
    { '4', '3' },
    { '4', '4' },
    { '4', '5' },
    { '4', '6' },
    { '4', '7' },
    { '4', '8' },
    { '4', '9' },

    { '5', '0' },
    { '5', '1' },
    { '5', '2' },
    { '5', '3' },
    { '5', '4' },
    { '5', '5' },
    { '5', '6' },
    { '5', '7' },
    { '5', '8' },
    { '5', '9' },

    { '6', '0' },
    { '6', '1' },
    { '6', '2' },
    { '6', '3' },
    { '6', '4' },
    { '6', '5' },
    { '6', '6' },
    { '6', '7' },
    { '6', '8' },
    { '6', '9' },

    { '7', '0' },
    { '7', '1' },
    { '7', '2' },
    { '7', '3' },
    { '7', '4' },
    { '7', '5' },
    { '7', '6' },
    { '7', '7' },
    { '7', '8' },
    { '7', '9' },

    { '8', '0' },
    { '8', '1' },
    { '8', '2' },
    { '8', '3' },
    { '8', '4' },
    { '8', '5' },
    { '8', '6' },
    { '8', '7' },
    { '8', '8' },
    { '8', '9' },

    { '9', '0' },
    { '9', '1' },
    { '9', '2' },
    { '9', '3' },
    { '9', '4' },
    { '9', '5' },
    { '9', '6' },
    { '9', '7' },
    { '9', '8' },
    { '9', '9' },

    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },

    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },

    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },
    { '?', '?' },

    { '?', '?' }
};


#ifdef __cplusplus
} /* anonymous namespace */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * util API
 */

PANTHEIOS_CALL(void)
pantheios_util_formatYearToString4(
    unsigned       year
,   PAN_CHAR_T    (*ar)[4]
) STLSOFT_NOEXCEPT
{
    unsigned const          century =   year / 100;
    unsigned const          year100 =   year % 100;

    PAN_CHAR_T const* const src_c   =   PAN_DE2S_0299_[century & 0xff];
    PAN_CHAR_T const* const src_y   =   PAN_DE2S_0299_[year100];
    
    (*ar)[0]    =   src_c[0];
    (*ar)[1]    =   src_c[1];
    (*ar)[2]    =   src_y[0];
    (*ar)[3]    =   src_y[1];
}

PANTHEIOS_CALL(void)
pantheios_util_formatMonthToString2(
    unsigned       month
,   PAN_CHAR_T    (*ar)[2]
) STLSOFT_NOEXCEPT
{
    PAN_CHAR_T const* const  src =   PAN_DE2S_0299_[month & 0x0f];
    
    (*ar)[0]    =   src[0];
    (*ar)[1]    =   src[1];
}

PANTHEIOS_CALL(void)
pantheios_util_formatDayToString2(
    unsigned       day
,   PAN_CHAR_T    (*ar)[2]
) STLSOFT_NOEXCEPT
{
    PAN_CHAR_T const* const  src =   PAN_DE2S_0299_[day & 0x1f];
    
    (*ar)[0]    =   src[0];
    (*ar)[1]    =   src[1];
}

PANTHEIOS_CALL(void)
pantheios_util_formatHourToString2(
    unsigned       hour
,   PAN_CHAR_T    (*ar)[2]
) STLSOFT_NOEXCEPT
{
    PAN_CHAR_T const* const  src =   PAN_DE2S_0299_[hour & 0x1f];
    
    (*ar)[0]    =   src[0];
    (*ar)[1]    =   src[1];
}

PANTHEIOS_CALL(void)
pantheios_util_formatMinuteOrSecondToString2(
    unsigned       minOrSecond
,   PAN_CHAR_T    (*ar)[2]
) STLSOFT_NOEXCEPT
{
    PAN_CHAR_T const* const  src =   PAN_DE2S_0299_[minOrSecond & 0x3f];
    
    (*ar)[0]    =   src[0];
    (*ar)[1]    =   src[1];
}

PANTHEIOS_CALL(void)
pantheios_util_formatMillisecondToString3(
    unsigned       millisecond
,   PAN_CHAR_T   (*ar)[3]
) STLSOFT_NOEXCEPT
{
    unsigned const          digits_2_3  =   millisecond % 100;

    millisecond /= 100;

    {
    unsigned const          digit_1     =   millisecond % 10;

    PAN_CHAR_T const* const src_2_3     =   PAN_DE2S_0299_[digits_2_3];
    PAN_CHAR_T const* const src_1       =   PAN_DE2S_0299_[digit_1];
    
    (*ar)[1]    =   src_2_3[0];
    (*ar)[2]    =   src_2_3[1];
    (*ar)[0]    =   src_1[1];
    }
}

PANTHEIOS_CALL(void)
pantheios_util_formatMicrosecondToString6(
    unsigned       microsecond
,   PAN_CHAR_T   (*ar)[6]
) STLSOFT_NOEXCEPT
{
    unsigned const          digits_5_6  =   microsecond % 100;

    microsecond /= 100;

    {
    unsigned const          digits_3_4  =   microsecond % 100;

    microsecond /= 100;

    {
    unsigned const          digits_1_2  =   microsecond % 100;

    PAN_CHAR_T const* const src_5_6     =   PAN_DE2S_0299_[digits_5_6];
    PAN_CHAR_T const* const src_3_4     =   PAN_DE2S_0299_[digits_3_4];
    PAN_CHAR_T const* const src_1_2     =   PAN_DE2S_0299_[digits_1_2];
    
    (*ar)[4]    =   src_5_6[0];
    (*ar)[5]    =   src_5_6[1];
    (*ar)[2]    =   src_3_4[0];
    (*ar)[3]    =   src_3_4[1];
    (*ar)[0]    =   src_1_2[0];
    (*ar)[1]    =   src_1_2[1];
    }
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
namespace util
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * util API
 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace util */
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
