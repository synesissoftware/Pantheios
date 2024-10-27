/* /////////////////////////////////////////////////////////////////////////
 * File:    src/backends/bec.test.cpp
 *
 * Purpose: Implementation for the be.test back-end
 *
 * Created: 1st November 2006
 * Updated: 28th October 2024
 *
 * Home:    http://www.pantheios.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* warning suppressions */
#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_MSVC)
# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)
#  pragma warning(disable : 4702)
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* compiler */

/* Pantheios.Test header files */
#include <pantheios/internal/nox.h>
#define PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
#include <pantheios/backends/bec.test.h>

/* Pantheios header files */

#include <pantheios/init_codes.h>
#include <pantheios/frontends/stock.h>
#include <pantheios/backend.h>
#include <pantheios/util/core/apidefs.hpp>
#include <pantheios/quality/contract.h>
#include <pantheios/internal/threading.h>

/* STLSoft header files */

#ifdef PANTHEIOS_MT
# include <platformstl/synch/thread_mutex.hpp>
#else /* ? PANTHEIOS_MT */
# include <stlsoft/synch/null_mutex.hpp>
#endif /* PANTHEIOS_MT */

#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/synch/lock_scope.hpp>

/* Standard C/C++ header files */

#include <vector>

/* warning suppressions */
#if defined(STLSOFT_COMPILER_IS_MSVC)
# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace pantheios
{
namespace be
{
namespace test
{
    /* static */ Time Time::now()
    {
        return Time();
    }

    Entry::Entry(
        int                 severity
    ,   PAN_CHAR_T const*   entry
    ,   size_t              cchEntry
    )
        : time(Time::now())
        , severity(severity)
        , statement(entry, cchEntry)
    {}

    namespace ximpl_be_test
    {
        class Context
        {
        public:
            typedef Context                                     class_type;
            typedef Entry                                       value_type;
            typedef std::vector<value_type>                     entries_type;
        private:
#ifdef PANTHEIOS_MT
            typedef platformstl::thread_mutex                   mutex_type_;
#else /* ? PANTHEIOS_MT */
            typedef stlsoft::null_mutex                         mutex_type_;
#endif /* PANTHEIOS_MT */
        public:
            Context(
                PAN_CHAR_T const*   processIdentity
            ,   int                 backEndId
            )
                : m_processIdentity(processIdentity)
                , m_backEndId(backEndId)
            {}
        private:
            Context(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
            void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

        public:
            void logEntry(
                void*               /* feToken */
            ,   int                 severity
            ,   PAN_CHAR_T const*   entry
            ,   size_t              cchEntry
            )
            {
                stlsoft::lock_scope<mutex_type_> lock(m_mx);

                // Get the time
                // Get the process Id

                m_entries.push_back(Entry(severity, entry, cchEntry));
            }

        public:
            void reset()
            {
                stlsoft::lock_scope<mutex_type_> lock(m_mx);

                entries_type dummy; // Have to use explicit dummy variable, otherwise CW 8 spits (the dummy, that is)

                m_entries.swap(dummy);
            }

        public:
            void lock()
            {
                m_mx.lock();
            }
            void unlock()
            {
                m_mx.unlock();
            }

        public:
            entries_type const& entries() const STLSOFT_NOEXCEPT
            {
                return m_entries;
            }

        private: // member Variables
            Entry::string_type const    m_processIdentity;
            int const                   m_backEndId;
            entries_type                m_entries;
            mutex_type_                 m_mx;
        };

    } /* namespace ximpl_be_test */

    struct Results::ResultsImpl
    {
    public: // types
        typedef ResultsImpl                                     class_type;
        typedef Results::value_type                             value_type;
        typedef std::vector<value_type>                         entries_type;

    public: // construction
        ResultsImpl(entries_type const& entries)
            : m_refCount(1)
            , m_entries(entries)
        {}
    private:
        ResultsImpl(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
        void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

    public: // reference-counting
        void AddRef()
        {
            ++m_refCount;
        }
        void Release()
        {
            if (0 == --m_refCount)
            {
                delete this;
            }
        }

    public: // accessors
        bool
        empty() const STLSOFT_NOEXCEPT
        {
            return m_entries.empty();
        }
        size_t
        size() const STLSOFT_NOEXCEPT
        {
            return m_entries.size();
        }
        value_type const&
        operator [](size_t index) const STLSOFT_NOEXCEPT
        {
            return m_entries[index];
        }
    private:
        stlsoft::int32_t    m_refCount;
        entries_type const  m_entries;
    };

    Results::Results(ResultsImpl* impl)
        : m_impl(impl)
    {
        PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != impl, "implementation class pointer may not be null");
    }

    Results::Results(Results::class_type const& rhs)
        : m_impl(rhs.m_impl)
    {
        PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != rhs.m_impl, "implementation class pointer of rhs may not be null");

        m_impl->AddRef();
    }
    Results::~Results() STLSOFT_NOEXCEPT
    {
        PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != m_impl, "implementation class pointer may not be null");

        m_impl->Release();
    }

    bool
    Results::empty() const STLSOFT_NOEXCEPT
    {
        return m_impl->empty();
    }
    size_t
    Results::size() const STLSOFT_NOEXCEPT
    {
        return m_impl->size();
    }
    Results::value_type const&
    Results::operator [](size_t index) const STLSOFT_NOEXCEPT
    {
        return (*m_impl)[index];
    }
} /* namespace test */
} /* namespace be */
} /* namespace pantheios */


namespace
{

    ::pantheios::be::test::ximpl_be_test::Context* s_ctxt;
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * API
 */

namespace pantheios
{
namespace be
{
namespace test
{

    void reset()
    {
        s_ctxt->reset();
    }

    Results results()
    {
        // This `CreateResults` stuff is horrible as all get-out, but does
        // work, so long as we copy-construct `Results` from an instance,
        // and do not slice.

        class CreatableResults
            : public Results
        {
        public:
            typedef Results                             parent_class_type;
            typedef CreatableResults                    class_type;
            typedef Results::ResultsImpl::entries_type  entries_type;

        public:
            CreatableResults(entries_type const& entries)
                : parent_class_type(create_impl_(entries))
            {
            }
        private:
            CreatableResults(class_type const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
            void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

        private:
            static Results::ResultsImpl* create_impl_(entries_type const& entries)
            {
                return new Results::ResultsImpl(entries);
            }
        };

        CreatableResults cr = CreatableResults(s_ctxt->entries());

        Results r = cr;

        return r;
    }
} /* namespace test */
} /* namespace be */
} /* namespace pantheios */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace
{

#if !defined(PANTHEIOS_NO_NAMESPACE)

    using ::pantheios::util::pantheios_onBailOut6;
#endif /* !PANTHEIOS_NO_NAMESPACE */
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * Front-end & Back-end Implementations
 */

static int pantheios_be_test_init_(
    PAN_CHAR_T const*   processIdentity
,   int                 id
,   void const*         unused
,   void*               reserved
,   void**              ptoken
);

PANTHEIOS_CALL(int) pantheios_be_test_init(
    PAN_CHAR_T const*   processIdentity
,   int                 id
,   void*               unused
,   void*               reserved
,   void**              ptoken
)
{
    return pantheios_call_be_void_init(pantheios_be_test_init_, processIdentity, id, unused, reserved, ptoken, "be.test");
}

static int pantheios_be_test_init_(
    PAN_CHAR_T const*   processIdentity
,   int                 id
,   void const*         /* unused */
,   void*               /* reserved */
,   void**              ptoken
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != processIdentity, "process identity may not be the null string");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API('\0' != 0[processIdentity], "process identity may not be the empty string");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != ptoken, "token pointer may not be null");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_STATE_API(NULL == s_ctxt, "pantheios_be_init() can only be called once per-process");

    *ptoken = NULL;

    s_ctxt = new pantheios::be::test::ximpl_be_test::Context(processIdentity, id);

    if (NULL == s_ctxt)
    {
        pantheios_onBailOut6(PANTHEIOS_SEV_ALERT, "failed to initiailse", NULL, "out of memory", NULL, "be.test");

        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }

    return 0;
}

PANTHEIOS_CALL(void) pantheios_be_test_uninit(void* /* token */)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_STATE_API(NULL != s_ctxt, "pantheios_be_init() must be called after pantheios_be_init() has successfully initialised");

    delete s_ctxt;
    s_ctxt = NULL;
}

static int pantheios_be_test_logEntry_(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
);

PANTHEIOS_CALL(int) pantheios_be_test_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    return pantheios_call_be_logEntry(pantheios_be_test_logEntry_, feToken, beToken, severity, entry, cchEntry, "be.test");
}

static int pantheios_be_test_logEntry_(
    void*               feToken
,   void*               /* beToken */
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
)
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_STATE_API(NULL != s_ctxt, "pantheios_fe_init() must be called first");

    s_ctxt->logEntry(feToken, severity, entry, cchEntry);

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

