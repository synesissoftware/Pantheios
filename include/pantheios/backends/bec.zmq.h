/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/backends/bec.zmq.h
 *
 * Purpose:     Declaration of the Pantheios ZeroMQ Back-end API.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file pantheios/backends/bec.zmq.h
 *
 * [C, C++] Pantheios ZeroMQ Back-end Common API
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_ZMQ_SRC
#define PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_ZMQ_SRC

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ZMQ_MAJOR    0
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ZMQ_MINOR    0
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ZMQ_REVISION 1
# define PANTHEIOS_VER_PANTHEIOS_BACKENDS_H_BEC_ZMQ_EDIT     0
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */
#ifndef PANTHEIOS_INCL_PANTHEIOS_H_BACKEND
# include <pantheios/backend.h>
#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_BACKEND */

/* /////////////////////////////////////////////////////////////////////////
 * Documentation
 */

/** \defgroup group__backend__stock_backends__zmq Pantheios ZeroMQ Stock Back-end
 * \ingroup group__backend__stock_backends
 *  Back-end library built on top of the <b>zmq</b> API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** \defgroup group__backend__stock_backends__zmq__flags Pantheios ZeroMQ Back-end Flags
 * \ingroup group__backend__stock_backends__zmq
 *  Flags for the \ref group__backend__stock_backends__zmq
 *
****************** * These flags are passed as the <code>options</code> parameter to the
 * ZeroMQ API function <code>openlog()</code> during back-end
 6 initialisation.
 */

/** \def PANTHEIOS_BE_ZMQ_F_NDELAY
 * \ingroup group__backend__stock_backends__zmq__flags
 *
 * \note To be implemented.
 */

#define PANTHEIOS_BE_ZMQ_F_NDELAY    (0x00100000)

enum socket_attach_method_t {
    PANTHEIOS_BE_ZMQ_SOCKET_METHOD_CONNECT = 0,
    PANTHEIOS_BE_ZMQ_SOCKET_METHOD_BIND = 1
};

/** Structure to specify a ZeroMQ socket connection
 */

struct pan_be_zmq_socket_init_t
{
#if !defined(PANTHEIOS_DOCUMENTATION_SKIP_SECTION) && \
    !defined(PANTHEIOS_NO_NAMESPACE)
    typedef pantheios::pan_uint8_t  pan_uint8_t;
    typedef pantheios::pan_uint16_t pan_uint16_t;
    typedef pantheios::pan_uint32_t pan_uint32_t;
    typedef pantheios::pan_char_t   pan_char_t;
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION && !PANTHEIOS_NO_NAMESPACE */

    pan_uint8_t     socket_type;           /*!< Socket type, ZMQ_PUB most likely. (from include:zmq.h). */
    pan_uint8_t     socket_attach_method;  /*!< Use bind or connect. enum socket_attach_method_t. */
    pan_char_t*     socket_addr;           /*!< Socket address string, tcp:// *1234 most likely. */

#ifdef __cplusplus
public: /* Construction */
# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
    pan_be_zmq_socket_init_t();
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */
};
#if !defined(__cplusplus)
typedef struct pan_be_zmq_socket_init_t     pan_be_zmq_socket_init_t;
#endif /* !__cplusplus */


/** Structure used for specifying initialisation information to the
 *    be.zmq library.
 * \ingroup group__backend__stock_backends__zmq
 */
struct pan_be_zmq_init_t
{
#if !defined(PANTHEIOS_DOCUMENTATION_SKIP_SECTION) && \
    !defined(PANTHEIOS_NO_NAMESPACE)
    typedef pantheios::pan_uint8_t  pan_uint8_t;
    typedef pantheios::pan_uint16_t pan_uint16_t;
    typedef pantheios::pan_uint32_t pan_uint32_t;
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION && !PANTHEIOS_NO_NAMESPACE */

    pan_uint32_t    version;    /*!< Must be initialised to the value of PANTHEIOS_VER */
    pan_uint32_t    flags;      /*!<  \ref group__backend__stock_backends__zmq__flags "Flags" that control the information displayed. */
    pan_uint32_t    options;    /*!<  Options passed to <code>openlog()</code>. Will be overridden by \link pan_be_zmq_init_t::flags flags\endlink. */
    pan_uint8_t     facility;   /*!<  The facility used by the process. Must be <= 124. Defaults to LOG_USER */
    pan_uint32_t    sleep_microsecs_at_start; /*!< If using PUB/SUB messaging, solve "slow joiners" problem. */
                                         /*!< Please see http://zguide.zeromq.org/page:all#Getting-the-Message-Out ("slow joiner" syndrome). */
                                         /*!< 100000 => Sleep for 0.1 seconds. */
    pan_be_zmq_socket_init_t    zmq_socket; /*!< Socket, initilized by default. */

#ifdef __cplusplus
public: /* Construction */
# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
    pan_be_zmq_init_t();
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */
};
#if !defined(__cplusplus)
typedef struct pan_be_zmq_init_t     pan_be_zmq_init_t;
#endif /* !__cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * Application-defined functions
 */

/** \ref page__backend__callbacks "Callback" function defined by
 *    the application, invoked when the
 *    API is initialised with a NULL <code>init</code> parameter.
 * \ingroup group__backend__stock_backends__zmq
 *
 * \note This function is only required when the
 *   \ref page__backend__callbacks "callback" version of the library is
 *   used.
 */
PANTHEIOS_CALL(void) pantheios_be_zmq_getAppInit(
    int                     backEndId
,   pan_be_zmq_init_t*   init
) /* throw() */;

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

/** Fills out a copy of the initialisation structure with default
 *    values (representative of the default behaviour of the library),
 *    ready to be customised and passed to the API initialiser function
 *    pantheios_be_zmq_init().
 * \ingroup group__backend__stock_backends__zmq
 *
 * \note This function should <b>not</b> be called on an
 *   already-initialised instance, as is the case in the implementation
 *   of the pantheios_be_zmq_getAppInit() function, as it will
 *   already have been called by pantheios_be_zmq_init() prior
 *   to the callback.
 */
PANTHEIOS_CALL(void) pantheios_be_zmq_getDefaultAppInit(
    pan_be_zmq_init_t* init
) /* throw() */;

/** Implements the functionality for pantheios_be_init() over the ZeroMQAPI.
 * \ingroup group__backend__stock_backends__zmq
 */
PANTHEIOS_CALL(int) pantheios_be_zmq_init(
    PAN_CHAR_T const*           processIdentity
,   int                         backEndId
,   pan_be_zmq_init_t const* init
,   void*                       reserved
,   void**                      ptoken
);

/** Implements the functionality for pantheios_be_uninit() over the ZeroMQ API.
 * \ingroup group__backend__stock_backends__zmq
 */
PANTHEIOS_CALL(void) pantheios_be_zmq_uninit(
    void* token
);

/** Implements the functionality for pantheios_be_logEntry() over the ZeroMQ API.
 * \ingroup group__backend__stock_backends__zmq
 */
PANTHEIOS_CALL(int) pantheios_be_zmq_logEntry(
    void*               feToken
,   void*               beToken
,   int                 severity
,   PAN_CHAR_T const*   entry
,   size_t              cchEntry
);

/** Parses the be.zmq back-end flags
 *
 * \ingroup group__backend
 *
 * Processes an argument list in the same way as
 * pantheios_be_parseStockArgs(), filling out the
 * pan_be_COMErrorObject_init_t in accordance with the arguments
 * found.
 *
 * Recognises the following standard argument names:
 * - "showProcessId"            (Boolean)
 * - "showTime"                 (Boolean)
 * - "showSeverity"             (Boolean)
 * - "useSystemTime"            (Boolean)
 * - "showDetailsAtStart"       (Boolean)
 * - "useUnixFormat"            (Boolean)
 * - "showDate"                 (Boolean)
 * - "showTime"                 (Boolean)
 * - "highResolution"           (Boolean)
 * - "lowResolution"            (Boolean)
 *
 * Recognises the following back-end specific argument names:
 * - "connectImmediately"       (Boolean)
 */
PANTHEIOS_CALL(int) pantheios_be_zmq_parseArgs(
    size_t                          numArgs
#ifdef PANTHEIOS_NO_NAMESPACE
,   struct pan_slice_t* const       args
#else /* ? PANTHEIOS_NO_NAMESPACE */
,   pantheios::pan_slice_t* const   args
#endif /* PANTHEIOS_NO_NAMESPACE */
,   pan_be_zmq_init_t*           init
);


/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
# ifndef PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT
inline pan_be_zmq_init_t::pan_be_zmq_init_t()
{
    pantheios_be_zmq_getDefaultAppInit(this);
}
# endif /* !PANTHEIOS_BE_INIT_NO_CPP_STRUCT_INIT */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* PANTHEIOS_INCL_PANTHEIOS_BACKENDS_H_ZMQ_SRC */

/* ///////////////////////////// end of file //////////////////////////// */
