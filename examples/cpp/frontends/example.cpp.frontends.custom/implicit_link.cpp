/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/cpp/frontends/example.cpp.frontends.custom/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the example.cpp.frontends.custom project.
 *
 * Created:     21st October 2008
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/be.console.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* _WIN32 || _WIN64 */

/* ///////////////////////////// end of file //////////////////////////// */

