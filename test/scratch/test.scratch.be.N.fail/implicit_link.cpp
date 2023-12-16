/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.be.N.fail/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.scratch.be.N.fail project.
 *
 * Created:     9th January 2007
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.N.h>
#include <pantheios/implicit_link/be.N.h>
#include <pantheios/implicit_link/bec.fail.h>
#include <pantheios/implicit_link/bec.file.h>
#include <pantheios/implicit_link/bec.fprintf.h>
#include <pantheios/implicit_link/bec.null.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* OS */

/* ///////////////////////////// end of file //////////////////////////// */

