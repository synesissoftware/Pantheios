/* /////////////////////////////////////////////////////////////////////////
 * File:        inserters/stream_character.cpp
 *
 * Purpose:     Implementation of the inserter classes.
 *
 * Created:     4th July 2011
 * Updated:     29th June 2016
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2011-2016, Matthew Wilson and Synesis Software
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

#include <pantheios/inserters/stream_character.hpp>
#include <pantheios/quality/contract.h>
#include <pantheios/internal/safestr.h>
#include <pantheios/util/memory/memcopy.h>
#include <pantheios/util/string/snprintf.h>

#include <ctype.h>
#include <string.h>

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
 * implementation
 */

namespace ximpl_stream_character
{
    struct known_map_entry_t
    {
        pan_char_t          ch;
        pan_char_t const*   name;
    };

    static known_map_entry_t s_entries[] =
    {
        { 0,    PANTHEIOS_LITERAL_STRING("NUL") },
        { 1,    PANTHEIOS_LITERAL_STRING("SOH") },
        { 2,    PANTHEIOS_LITERAL_STRING("STX") },
        { 3,    PANTHEIOS_LITERAL_STRING("ETX") },
        { 4,    PANTHEIOS_LITERAL_STRING("EOT") },
        { 5,    PANTHEIOS_LITERAL_STRING("ENQ") },
        { 6,    PANTHEIOS_LITERAL_STRING("ACK") },
        { 7,    PANTHEIOS_LITERAL_STRING("BEL") },
        { 8,    PANTHEIOS_LITERAL_STRING("BS")  },
        { 9,    PANTHEIOS_LITERAL_STRING("HT")  },
        { 10,   PANTHEIOS_LITERAL_STRING("LF")  },
        { 11,   PANTHEIOS_LITERAL_STRING("VT")  },
        { 12,   PANTHEIOS_LITERAL_STRING("FF")  },
        { 13,   PANTHEIOS_LITERAL_STRING("CR")  },
        { 14,   PANTHEIOS_LITERAL_STRING("SO")  },
        { 15,   PANTHEIOS_LITERAL_STRING("SI")  },
        { 16,   PANTHEIOS_LITERAL_STRING("DLE") },
        { 17,   PANTHEIOS_LITERAL_STRING("DC1") },
        { 18,   PANTHEIOS_LITERAL_STRING("DC2") },
        { 19,   PANTHEIOS_LITERAL_STRING("DC3") },
        { 20,   PANTHEIOS_LITERAL_STRING("DC4") },
        { 21,   PANTHEIOS_LITERAL_STRING("NAK") },
        { 22,   PANTHEIOS_LITERAL_STRING("SYN") },
        { 23,   PANTHEIOS_LITERAL_STRING("ETB") },
        { 24,   PANTHEIOS_LITERAL_STRING("CAN") },
        { 25,   PANTHEIOS_LITERAL_STRING("EM")  },
        { 26,   PANTHEIOS_LITERAL_STRING("SUB") },
        { 27,   PANTHEIOS_LITERAL_STRING("ESC") },
        { 28,   PANTHEIOS_LITERAL_STRING("FS")  },
        { 29,   PANTHEIOS_LITERAL_STRING("GS")  },
        { 30,   PANTHEIOS_LITERAL_STRING("RS")  },
        { 31,   PANTHEIOS_LITERAL_STRING("US")  },
        { 32,   PANTHEIOS_LITERAL_STRING("SP")  },
        { 127,  PANTHEIOS_LITERAL_STRING("DEL") },
    };

} /* namespace ximpl_stream_character */

/* /////////////////////////////////////////////////////////////////////////
 * stream_character
 */

void stream_character::construct_() const
{
    const_cast<class_type*>(this)->construct_();
}

void stream_character::construct_()
{
    using namespace ximpl_stream_character;

    STLSOFT_ASSERT(0 == m_len);

    if(isgraph(m_ch))
    {
        m_sz[0] = static_cast<pan_char_t>(m_ch);
        m_sz[1] = '\0';

        m_len = 1;
    }
    else
    {
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_entries); ++i)
        {
            if(m_ch == s_entries[i].ch)
            {
                m_len = pan_strlen_(s_entries[i].name);

                STLSOFT_ASSERT(m_len < STLSOFT_NUM_ELEMENTS(m_sz));

                PANTHEIOS_char_copy(&m_sz[0], &s_entries[i].name[0], (1 + m_len));

                return;
            }
        }}

        m_len = pantheios_util_snprintf(m_sz, STLSOFT_NUM_ELEMENTS(m_sz), PANTHEIOS_LITERAL_STRING("0x%04x"), m_ch);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
