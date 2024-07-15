/* /////////////////////////////////////////////////////////////////////////
 * File:        inserters/blob.cpp
 *
 * Purpose:     Implementation of the inserter classes.
 *
 * Created:     21st June 2005
 * Updated:     16th December 2023
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


#define PANTHEIOS_NO_INCLUDE_STLSOFT_STRING_ACCESS

/* Pantheios header files */
#include <pantheios/pantheios.h>

#if defined(STLSOFT_COMPILER_IS_MWERKS)
 /* For some to-be-determined reason, CodeWarrior can't see a whole lot of
  * things in STLSoft header files from <string.h>, even though those
  * files #include it.
  */
# include <string.h>
#endif /* compiler */

#include <pantheios/inserters/blob.hpp>

#include <pantheios/quality/contract.h>

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# include <pantheios/util/memory/auto_buffer_selector.hpp>
# include <stlsoft/conversion/char_conversions.hpp>
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

#include <stlsoft/conversion/byte_format_functions.hpp>

//#include <stlsoft/meta/yesno.hpp> // TODO: Use this to remove "runtime" constant tests in integer::init_()


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

    using ::pantheios::core::pantheios_inserterAllocate;
    using ::pantheios::core::pantheios_inserterDeallocate;

} /* anonymous namespace */

#endif /* !PANTHEIOS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * blob
 */

blob::blob(
    void const* pv
,   size_t      cb
)
    : m_value(NULL)
    , m_len(0)
    , m_pv(pv)
    , m_cb(cb)
    , m_byteGrouping(1)
    , m_groupSeparator(NULL)
    , m_groupsPerLine(-1)
    , m_lineSeparator(NULL)
{}

blob::blob(
    void const*             pv
,   size_t                  cb
,   unsigned                byteGrouping
,   pantheios_char_t const* groupSeparator
)
    : m_value(NULL)
    , m_len(0)
    , m_pv(pv)
    , m_cb(cb)
    , m_byteGrouping(byteGrouping)
    , m_groupSeparator(groupSeparator)
    , m_groupsPerLine(-1)
    , m_lineSeparator(NULL)
{}

blob::blob(
    void const*             pv
,   size_t                  cb
,   unsigned                byteGrouping
,   pantheios_char_t const* groupSeparator
,   int                     groupsPerLine
,   pantheios_char_t const* lineSeparator
)
    : m_value(NULL)
    , m_len(0)
    , m_pv(pv)
    , m_cb(cb)
    , m_byteGrouping(byteGrouping)
    , m_groupSeparator(groupSeparator)
    , m_groupsPerLine(groupsPerLine)
    , m_lineSeparator(lineSeparator)
{}

// TODO: create a Pantheios fast arena

blob::~blob() STLSOFT_NOEXCEPT
{
    pantheios_inserterDeallocate(const_cast<pantheios_char_t*>(m_value));
}


inline void blob::construct_() const
{
    const_cast<class_type*>(this)->construct_();
}

pantheios_char_t const*
blob::data() const
{
    if (NULL == m_value)
    {
        construct_();
    }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(NULL != m_value);

    return m_value;
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    return (NULL != m_value) ? m_value : "";
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

pantheios_char_t const*
blob::c_str() const
{
    return data();
}

size_t blob::length() const
{
    if (NULL == m_value)
    {
        construct_();
    }

    return m_len;
}

void blob::construct_()
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL == m_value, "cannot construct if value is non-null");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(0 == m_len, "cannot construct if length is non-0");

    // TODO: STLSoft: make format_bytes() be widestring

#ifdef PANTHEIOS_USE_WIDE_STRINGS

    stlsoft::w2m        lineSep(m_lineSeparator);
    stlsoft::w2m        grpSep(m_groupSeparator);
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

    char const*         lineSep =   m_lineSeparator;
    char const*         grpSep  =   m_groupSeparator;
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
    size_t              cch     =   stlsoft::format_bytes(m_pv, m_cb, NULL, 0, m_byteGrouping, grpSep, m_groupsPerLine, lineSep);
    pantheios_char_t*   value   =   static_cast<pantheios_char_t*>(pantheios_inserterAllocate(sizeof(pantheios_char_t) * (1 + cch)));

    if (NULL != value)
    {
#ifdef PANTHEIOS_USE_WIDE_STRINGS

        PANTHEIOS_NS_QUAL_(util, auto_buffer_selector)<
            char
        ,   256
        >::type     buff(1 + cch);

        if (buff.empty())
        {
            pantheios_inserterDeallocate(const_cast<pantheios_char_t*>(m_value));

            value   =   NULL;
            cch     =   0;
        }
        else
        {
            cch = stlsoft::format_bytes(m_pv, m_cb, &buff[0], cch, m_byteGrouping, grpSep, m_groupsPerLine, lineSep);
            buff[cch] = '\0';

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1400
#  pragma warning(push)
#  pragma warning(disable : 4996)
# endif
            ::mbstowcs(value, buff.data(), cch);
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER >= 1400
#  pragma warning(pop)
# endif
            value[cch] = '\0';
        }

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

        cch = stlsoft::format_bytes(m_pv, m_cb, value, cch, m_byteGrouping, grpSep, m_groupsPerLine, lineSep);
        value[cch] = '\0';

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

        m_value =   value;
        m_len   =   cch;
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

