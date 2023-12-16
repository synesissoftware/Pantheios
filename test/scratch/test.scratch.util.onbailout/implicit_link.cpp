/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.util.onbailout/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.scratch.util.onbailout project.
 *
 * Created:     1st March 2008
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <platformstl/platformstl.h>
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.all.h>
#include <pantheios/implicit_link/be.null.h>

/* UNIXem header files */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* Win32 || Win64 */

/* ///////////////////////////// end of file //////////////////////////// */

