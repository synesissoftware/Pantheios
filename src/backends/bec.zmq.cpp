/* /////////////////////////////////////////////////////////////////////////
 *
 * Purpose:     Implementation for the ZeroMQ back-end
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios Header files */
#include <pantheios/pantheios.h>
#include <pantheios/internal/lean.h>
#include <pantheios/internal/nox.h>
#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif /* !UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS */
#include <pantheios/internal/threading.h>
#define PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
#include <pantheios/backends/bec.file.h>

#include <pantheios/internal/safestr.h>
#include <pantheios/init_codes.h>
#include <pantheios/quality/contract.h>
#include <pantheios/util/core/apidefs.hpp>
#include <pantheios/util/backends/arguments.h>
#include <pantheios/util/backends/context.hpp>
#include <pantheios/util/string/snprintf.h>

/* Pantheios Header Files */
#include <pantheios/pantheios.h>
#define PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
#include <pantheios/backends/bec.zmq.h>

#include <pantheios/init_codes.h>
#include <pantheios/quality/contract.h>
#include <pantheios/util/backends/arguments.h>
#include <pantheios/util/backends/context.hpp>
#include <pantheios/util/string/snprintf.h>

/* STLSoft Header files */
#include <stlsoft/stlsoft.h>
#if _STLSOFT_VER < 0x01096bff
# error This file requires STLSoft 1.9.107 or later
#endif /* _STLSOFT_VER */

/* Compiler warnings
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1300
# pragma warning(disable : 4702)
#endif /* compiler */

#include <pantheios/util/memory/auto_buffer_selector.hpp>

#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/memory/auto_destructor.hpp>
#include <stlsoft/memory/malloc_allocator.hpp>
#include <stlsoft/synch/lock_scope.hpp>

#include <platformstl/platformstl.hpp>
#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/path.hpp>
#include <platformstl/synch/util/features.h>
#include <platformstl/synch/sleep_functions.h>
#ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS
# include <platformstl/synch/spin_mutex.hpp>
#endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
#ifdef PANTHEIOS_MT
# include <platformstl/synch/thread_mutex.hpp>
#else /* ? PANTHEIOS_MT */
# include <stlsoft/synch/null_mutex.hpp>
#endif /* PANTHEIOS_MT */

/* Standard Header Files */
#include <list>
#include <map>
#include <new>
#include <string>
#include <utility>
#include <vector>
#include <string.h>
#include <time.h>

/* ZeroMQ Header Files */
#include <zmq.h>

/* /////////////////////////////////////////////////////////////////////////
 * String encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define pan_strlen_                ::wcslen
# define pan_strstr_                ::wcsstr

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define pan_strlen_                ::strlen
# define pan_strstr_                ::strstr

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace
{

#if !defined(PANTHEIOS_NO_NAMESPACE)

    using ::pantheios::pan_uint32_t;
    using ::pantheios::pan_uint16_t;
    using ::pantheios::pan_uint8_t;
    using ::pantheios::pan_char_t;
    using ::pantheios::pan_slice_t;
    using ::pantheios::pantheios_util_snprintf;
    using ::pantheios::util::backends::Context;
    using ::pantheios::util::pantheios_onBailOut3;
    using ::pantheios::util::pantheios_onBailOut4;

#endif /* !PANTHEIOS_NO_NAMESPACE */

    template <ss_typename_param_k T>
    struct buffer_selector_
    {
        typedef ss_typename_type_k
#if !defined(PANTHEIOS_NO_NAMESPACE)
            pantheios::util::auto_buffer_selector<
#else /* ? !PANTHEIOS_NO_NAMESPACE */
            auto_buffer_selector<
#endif /* !PANTHEIOS_NO_NAMESPACE */
            T
        ,   2048
        ,   stlsoft::malloc_allocator<T>
        >::type                                 type;

        typedef ss_typename_type_k
#if !defined(PANTHEIOS_NO_NAMESPACE)
            pantheios::util::auto_buffer_selector<
#else /* ? !PANTHEIOS_NO_NAMESPACE */
            auto_buffer_selector<
#endif /* !PANTHEIOS_NO_NAMESPACE */
            T
        ,   256
        ,   stlsoft::malloc_allocator<T>
        >::type                                 small_type;
    };

    typedef buffer_selector_<char>::type        buffer_a_t;
    typedef buffer_selector_<wchar_t>::type     buffer_w_t;
    typedef buffer_selector_<pan_char_t>::type  buffer_t;


} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

class be_zmq_Context
    : public Context
{
private:
    typedef Context                             parent_class_type;
#ifdef PANTHEIOS_MT
    typedef platformstl::thread_mutex           mutex_type;
#else /* ? PANTHEIOS_MT */
    typedef stlsoft::null_mutex                 mutex_type;
#endif /* PANTHEIOS_MT */
private:
    typedef std::basic_string<pan_char_t>       string_type;
    typedef std::list<string_type>              strings_type;

public:
    enum {
        severityMask        =   0x0f // All severities 0 - 15
    };
    enum {
        defaultInitFlags    =   0
    };

public:
    be_zmq_Context(
        pan_char_t const*           processIdentity
    ,   int                         backEndId
    ,   pan_be_zmq_init_t const&   init
    );
    ~be_zmq_Context() throw();

public:
    void microSleep(const stlsoft::uint_t microsecs) const;

private:
    virtual int rawLogEntry(
        int                 severity4
    ,   int                 severityX
    ,   const pan_slice_t (&ar)[rawLogArrayDimension]
    ,   size_t              cchTotal
    );
    virtual int rawLogEntry(
        int                 severity4
    ,   int                 severityX
    ,   pan_char_t const*   entry
    ,   size_t              cchEntry
    );
private:
    int     WriteEntry(
        pan_char_t*   entry
    ,   size_t              cchEntry
    ,   void*               socket
    );
    int     OutputEntry(
        pan_char_t*   entry
    ,   size_t              cchEntry
    ,   void*               socket
    );
private:
    pan_uint32_t        m_flags;
    void* context;
    void* socket;
};


/* /////////////////////////////////////////////////////////////////////////
 * API
 *
 */

PANTHEIOS_CALL(void) pantheios_be_zmq_getDefaultAppInit(pan_be_zmq_init_t* init) /* throw() */
{
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialization structure pointer may not be null");

    init->version                 =   PANTHEIOS_VER;
    init->flags                   =   0;
    init->options                 =   0;
    init->facility                =   0;
    init->sleep_microsecs_at_start     =   0;
    init->zmq_socket.socket_type             = ZMQ_PUB;
    init->zmq_socket.socket_attach_method    = PANTHEIOS_BE_ZMQ_SOCKET_METHOD_BIND;
    init->zmq_socket.socket_addr
         = const_cast<char*>("tcp://127.0.0.1:49152"); // First private port (according to IANA.)
}

PANTHEIOS_CALL(int) pantheios_be_zmq_init(
    char const*                 processIdentity
,   int                         backEndId
,   pan_be_zmq_init_t const*    init
,   void*                       reserved
,   void**                      ptoken
)
{
    STLSOFT_SUPPRESS_UNUSED(reserved);
    pan_be_zmq_init_t           init_;

    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != processIdentity, "process identity may not be the null string");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API('\0' != 0[processIdentity], "process identity may not be an empty string");
    STLSOFT_SUPPRESS_UNUSED(backEndId);
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != ptoken, "token pointer may not be null");

    *ptoken = NULL;

    /* (i) apply Null Object (Variable) pattern */

    if(NULL == init) {
        pantheios_be_zmq_getDefaultAppInit(&init_);

#ifdef PANTHEIOS_BE_USE_CALLBACK
        pantheios_be_zmq_getAppInit(backEndId, &init_);
#endif /* PANTHEIOS_BE_USE_CALLBACK */

        init = &init_;
    }

    /* (ii) verify the version */

    if(init->version < 0x010001b8) {
        return PANTHEIOS_BE_INIT_RC_OLD_VERSION_NOT_SUPPORTED;
    }
    else if(init->version > PANTHEIOS_VER) {
        return PANTHEIOS_BE_INIT_RC_FUTURE_VERSION_REQUESTED;
    }

    /* (iii) create the context */
    // This is placed in an auto_destructor because there's the possibility
    // that we may have to discard a correctly initialised context if
    // getProcessIdentity() fails.

    if( NULL == init->zmq_socket.socket_addr
        || strlen(init->zmq_socket.socket_addr) == 0 ) {
        return PANTHEIOS_INIT_RC_UNSPECIFIED_FAILURE;
    }

    stlsoft::auto_destructor<be_zmq_Context> ctxt(new be_zmq_Context(processIdentity, backEndId, *init));

    /* Check it got created ok. */
    if( NULL == ctxt.get() || NULL == ctxt->getProcessIdentity() ) {
        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }

    *ptoken = ctxt.detach();
    return PANTHEIOS_INIT_RC_SUCCESS;
}

PANTHEIOS_CALL(void) pantheios_be_zmq_uninit(void* token) {
    be_zmq_Context* ctxt = static_cast<be_zmq_Context*>(token);

    delete ctxt;
}

PANTHEIOS_CALL(int) pantheios_be_zmq_logEntry(
    void*       feToken
,   void*       beToken
,   int         severity
,   char const* entry
,   size_t      cchEntry
)
{
    STLSOFT_SUPPRESS_UNUSED(feToken);
    STLSOFT_SUPPRESS_UNUSED(cchEntry);

    // PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(0 == (severity & 0x08), "be.zmq can only be used with the stock severity levels in the range [0, 8). Levels in the range [8, 16) are not allowed");
    // PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(0 == (severity & 0x0f), "be.zmq can be used with severity levels in the range [0, 16)");

    be_zmq_Context* ctxt = static_cast<be_zmq_Context*>(beToken);

    ctxt->logEntry(severity, entry, cchEntry);
    return 0;
}

PANTHEIOS_CALL(int) pantheios_be_zmq_parseArgs(
    size_t                      numArgs
,   struct pan_slice_t* const   args
,   pan_be_zmq_init_t*       init
)
{
    int res;

    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API((NULL != args || 0 == numArgs), "argument pointer must be non-null, or number of arguments must be 0");
    PANTHEIOS_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != init, "initialisation structure pointer may not be null");

    pantheios_be_zmq_getDefaultAppInit(init);

    /* 1. Parse the stock arguments */
    res = pantheios_be_parseStockArgs(numArgs, args, &init->flags);

    if(res >= 0)
    {
        /* 2.d Parse the custom argument: "immediateConnect" */
        res = pantheios_be_parseBooleanArg(numArgs, args, PANTHEIOS_LITERAL_STRING("immediateConnect"), false, PANTHEIOS_BE_ZMQ_F_NDELAY, &init->flags);
    }

    return res;
}

/* /////////////////////////////////////////////////////////////////////////
 * be_zmq_Context
 */

be_zmq_Context::be_zmq_Context(
    pan_char_t const*           processIdentity
,   int                         backEndId
,   pan_be_zmq_init_t const&   init
)
    : parent_class_type(processIdentity, backEndId, init.flags, be_zmq_Context::severityMask)
    , m_flags(init.flags)
{
    this->context = zmq_ctx_new();

    void* socket = zmq_socket(context, init.zmq_socket.socket_type);
    if( init.zmq_socket.socket_attach_method == PANTHEIOS_BE_ZMQ_SOCKET_METHOD_CONNECT ) {
        zmq_connect(socket, init.zmq_socket.socket_addr);
    }
    else {
        zmq_bind(socket, init.zmq_socket.socket_addr);
    }
    this->socket = socket;

    this->microSleep(init.sleep_microsecs_at_start);
}

be_zmq_Context::~be_zmq_Context() throw() {
    zmq_close( this->socket );
    zmq_ctx_destroy( this->context );
}

void be_zmq_Context::microSleep(const stlsoft::uint_t microsecs) const {
    platformstl::micro_sleep(microsecs);
}

int be_zmq_Context::rawLogEntry(
    int severity4
,   int severityX
,   pan_slice_t const (&ar)[be_zmq_Context::rawLogArrayDimension]
,   size_t cchTotal
)
{
    // Allocate the buffer
    buffer_t buff(cchTotal + 2);
    if(0 == buff.size()) {
        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    else {
        size_t nWritten = concatenateSlices(&buff[0], buff.size(), rawLogArrayDimension, &ar[0]);
        PANTHEIOS_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL(nWritten == cchTotal, "Written length differs from allocated length");
    }
    this->WriteEntry(buff.data(), cchTotal, this->socket);
    return cchTotal;
}

int be_zmq_Context::rawLogEntry(
    int                 severity4
,   int                 severityX
,   pan_char_t const*   entry
,   size_t              cchEntry
)
{
    buffer_t buff(cchEntry);
    if(0 == buff.size()) {
        return PANTHEIOS_INIT_RC_OUT_OF_MEMORY;
    }
    ::memcpy(&buff[0], entry, cchEntry * sizeof(pan_char_t));
    this->WriteEntry(buff.data(), cchEntry, this->socket);
    return cchEntry;
}

int be_zmq_Context::WriteEntry(
    pan_char_t*         entry
,   size_t              cchEntry
,   void*               socket
)
{
    return this->OutputEntry(entry, cchEntry, socket);
}

int be_zmq_Context::OutputEntry(
    pan_char_t*         entry
,   size_t              cchEntry
,   void*               socket
)
{
    // printf( "Sending: '%s'.\n", entry );
    int rc = zmq_send( socket, static_cast<char*>(entry), (int) cchEntry, 0 );
    STLSOFT_SUPPRESS_UNUSED(rc);
    return static_cast<int>(cchEntry);
}

/* ///////////////////////////// end of zmq //////////////////////////// */

