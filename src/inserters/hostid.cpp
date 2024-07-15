/* /////////////////////////////////////////////////////////////////////////
 * File:        src/inserters/hostid.cpp
 *
 * Purpose:     Implementation of the pantheios::hostId inserter class.
 *
 * Created:     14th April 2008
 * Updated:     16th December 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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
#include <pantheios/inserters/hostid.hpp>

#include <pantheios/util/memory/auto_buffer_selector.hpp>
#include <pantheios/util/string/strdup.h>
#include <pantheios/util/system/hostname.h>
#include <pantheios/internal/safestr.h>

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

namespace
{

} /* anonymous namespace */

#endif /* !PANTHEIOS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

struct hostId_t const* hostId   =   0;


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
namespace inserters
{
#endif /* !PANTHEIOS_NO_NAMESPACE) && !STLSOFT_COMPILER_IS_BORLAND */


/* /////////////////////////////////////////////////////////////////////////
 * inserter classes
 */

// host_id_t

inline void host_id_t::construct_() const
{
    const_cast<class_type*>(this)->construct_();
}

void host_id_t::construct_()
{
    static const pantheios_char_t s_localHost[] = PANTHEIOS_LITERAL_STRING("localhost");

    PANTHEIOS_NS_QUAL_(util, auto_buffer_selector)<
        pantheios_char_t
    ,   256
    >::type             hostName_(256);

    size_t                  cch         =   getHostName(hostName_);
    pantheios_char_t const* hostName    =   hostName_.data();

    if (0 == cch)
    {
        cch         =   STLSOFT_NUM_ELEMENTS(s_localHost) - 1;
        hostName    =   s_localHost;
    }

#ifdef STLSOFT_CF_THROW_BAD_ALLOC
    m_value =   pantheios_util_strdup_throw(hostName);
    m_len   =   cch;
#else /* ? STLSOFT_CF_THROW_BAD_ALLOC */
    m_value =   pantheios_util_strdup_nothrow(hostName);
    m_len   =   (NULL == m_value) ? 0 : cch;
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
}

host_id_t::host_id_t()
    : m_value(NULL)
    , m_len(0)
{}

host_id_t::~host_id_t() STLSOFT_NOEXCEPT
{
    pantheios_util_strfree(const_cast<pantheios_char_t*>(m_value));
}

host_id_t::operator size_t () const
{
    if (NULL == m_value)
    {
        construct_();
    }

    return m_len;
}

host_id_t::operator pantheios_char_t const* () const
{
    if (NULL == m_value)
    {
        construct_();
    }

    return m_value;
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
# if !defined(STLSOFT_COMPILER_IS_BORLAND)
} /* namespace inserters */
# endif /* !STLSOFT_COMPILER_IS_BORLAND */

} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

