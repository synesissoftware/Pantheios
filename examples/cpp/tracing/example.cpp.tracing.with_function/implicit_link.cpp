/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/cpp/tracing/example.cpp.tracing.with_function/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the example.cpp.tracing.with_function project.
 *
 * Created:     6th December 2010
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.simple.h>
#include <pantheios/implicit_link/be.console.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* _WIN32 || _WIN64 */

/* ///////////////////////////// end of file //////////////////////////// */

