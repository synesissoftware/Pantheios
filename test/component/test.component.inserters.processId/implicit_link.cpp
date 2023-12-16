/* /////////////////////////////////////////////////////////////////////////
 * File:        test/component/test.component.inserters.processId/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.component.ids project.
 *
 * Created:     24th November 2007
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.simple.h>
#include <pantheios/implicit_link/be.test.h>

/* xTests header files */
#include <xtests/implicit_link.h>

/* UNIXem header files */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* PLATFORMSTL_OS_IS_UNIX && _WIN32 */

/* ///////////////////////////// end of file //////////////////////////// */

