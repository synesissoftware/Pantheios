/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/cpp/util/example.cpp.util.strdup/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the example.cpp.util.strdup project.
 *
 * Created:     27th December 2010
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/implicit_link/util.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* _WIN32 || _WIN64 */

/* ///////////////////////////// end of file //////////////////////////// */

