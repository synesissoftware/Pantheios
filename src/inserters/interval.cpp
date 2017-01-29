/* /////////////////////////////////////////////////////////////////////////
 * File:        inserters/interval.cpp
 *
 * Purpose:     Implementation of the inserter classes.
 *
 * Created:     19th April 2014
 * Updated:     17th December 2016
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


#define PANTHEIOS_NO_INCLUDE_STLSOFT_STRING_ACCESS

/* Pantheios header files */
#include <pantheios/pantheios.h>
#include <pantheios/internal/nox.h>

#include <pantheios/inserters/interval.hpp>
#include <pantheios/quality/contract.h>
#include <pantheios/internal/safestr.h>

/* STLSoft header files */
#ifdef PANTHEIOS_STLSOFT_1_10_B01_OR_LATER
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#else /* ? STLSoft version */
# include <stlsoft/conversion/integer_to_string.hpp>
#endif /* STLSoft version */
#include <stlsoft/shims/access/string/std/c_string.h>
#include <platformstl/platformstl.h>

/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8008
# pragma warn -8066
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * string encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# define pan_strlen_                    ::wcslen
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */
# define pan_strlen_                    ::strlen
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * interval
 */

inline void interval::construct_() const
{
    const_cast<class_type*>(this)->construct_();
}

interval::interval(int interval, interval::units units)
    : m_interval(interval)
    , m_units(units)
    , m_result()
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(units >= microseconds && units <= days, "unrecognised units");
}

pan_char_t const* interval::data() const
{
    if(m_result.empty())
    {
        construct_();
    }

    return m_result.data();
}

size_t interval::size() const
{
    if(m_result.empty())
    {
        construct_();
    }

    return m_result.size();
}

void interval::construct_()
{
    m_result.reserve(20);

    interval::units units       =   m_units;
    pan_sint64_t    interval    =   m_interval;

    if(0 == interval)
    {
        static pan_char_t const* const s_zeroes[] =
        {
                NULL
            ,   PANTHEIOS_LITERAL_STRING("0 us")
            ,   PANTHEIOS_LITERAL_STRING("0 ms")
            ,   PANTHEIOS_LITERAL_STRING("0 s")
            ,   PANTHEIOS_LITERAL_STRING("0 mins")
            ,   PANTHEIOS_LITERAL_STRING("0 hrs")
            ,   PANTHEIOS_LITERAL_STRING("0 days")
        };

        pan_char_t const* const ptr =   s_zeroes[units];
        size_t const            len =   pan_strlen_(ptr);

        m_result.assign(ptr, len);
    }
    else
    {
        pan_char_t const* u = NULL;

        switch(units)
        {
            case    microseconds:
                if(0 != (interval % 1000))
                {
                    u = PANTHEIOS_LITERAL_STRING("us");
                }
                else
                {
                    interval /= 1000;

            case    milliseconds:
                    if(0 != (interval % 1000))
                    {
                        u = PANTHEIOS_LITERAL_STRING("ms");
                    }
                    else
                    {
                        interval /= 1000;

            case    seconds:
                        if(0 != (interval % 60))
                        {
                            u = PANTHEIOS_LITERAL_STRING("s");
                        }
                        else
                        {
                            interval /= 60;

            case    minutes:
                            if(0 != (interval % 60))
                            {
                                u = (1 == interval) ? PANTHEIOS_LITERAL_STRING("min") : PANTHEIOS_LITERAL_STRING("mins");
                            }
                            else
                            {
                                interval /= 60;

            case    hours:
                                if(0 != (interval % 24))
                                {
                                    u = (1 == interval) ? PANTHEIOS_LITERAL_STRING("hr") : PANTHEIOS_LITERAL_STRING("hrs");
                                }
                                else
                                {
                                    interval /= 24;

            case    days:
                                    u = (1 == interval) ? PANTHEIOS_LITERAL_STRING("day") : PANTHEIOS_LITERAL_STRING("days");
                                }
                            }
                        }
                    }
                break;
                }
        }

        STLSOFT_ASSERT(NULL != u);

        pan_char_t              buf[21];
        size_t                  cch;
#ifdef PANTHEIOS_STLSOFT_1_10_B01_OR_LATER
        pan_char_t const* const num =   stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), interval, &cch);
#else /* ? STLSoft version */
        pan_char_t const* const num =   stlsoft::integer_to_string(buf, STLSOFT_NUM_ELEMENTS(buf), interval, cch);
#endif /* STLSoft version */

        m_result.assign(num, cch);
        m_result.append(1, ' ');
        m_result.append(u);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
