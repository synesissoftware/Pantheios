
/* Pantheios header files */
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.simple.h>
#include <pantheios/implicit_link/be.lrsplit.h>
#include <pantheios/implicit_link/bel.WindowsConsole.h>
#include <pantheios/implicit_link/bec.speech.WithCallback.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif


/* ///////////////////////////// end of file //////////////////////////// */

