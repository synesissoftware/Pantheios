/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.fe.simple.WithCallback/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.scratch.fe.simple.WithCallback project.
 *
 * Created:     15th November 2010
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <platformstl/platformstl.h>
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/be.console.h>
#include <pantheios/implicit_link/fe.simple.WithCallback.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif

/* ///////////////////////////// end of file //////////////////////////// */

