/* /////////////////////////////////////////////////////////////////////////
 * File:        inserters/threadid.cpp
 *
 * Purpose:     Implementation of the inserter classes.
 *
 * Created:     16th October 2006
 * Updated:     16th December 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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

#include <pantheios/inserters/threadid.hpp>

#include <pantheios/util/memory/memcopy.h>
#include <pantheios/util/system/threadid.h>

#include <stlsoft/conversion/integer_to_string.hpp>

/* Standard C header files */
#if defined(STLSOFT_COMPILER_IS_BORLAND)
# include <memory.h>
#endif /* compiler */
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8008
# pragma warn -8066
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

struct threadId_t const* threadId   =   0;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace inserters
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inserter classes
 */

// thread_id_t

inline void thread_id_t::construct_() const
{
    const_cast<class_type*>(this)->construct_();
}

void thread_id_t::construct_()
{
    pantheios_char_t        sz[21]; // This is large enough for any number up to 64-bits
#ifdef PANTHEIOS_STLSOFT_1_10_B01_OR_LATER
    pantheios_char_t const* num = stlsoft::integer_to_decimal_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), pantheios_getCurrentThreadId(), &m_len);
#else /* ? STLSoft version */
    pantheios_char_t const* num = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), pantheios_getCurrentThreadId(), &m_len);
#endif /* STLSoft version */

    PANTHEIOS_char_copy(&m_value[0], num, (m_len + 1));
}

thread_id_t::thread_id_t()
    : m_len(0)
{
    m_value[0] = '\0';
}

thread_id_t::operator size_t () const
{
    if('\0' == m_value[0])
    {
        construct_();
    }

    return m_len;
}
thread_id_t::operator pantheios_char_t const* () const
{
    if('\0' == m_value[0])
    {
        construct_();
    }

    return m_value;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace inserters */

} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

