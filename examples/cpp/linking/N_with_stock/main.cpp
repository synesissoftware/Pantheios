/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/linking/N_with_stock/main.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - linking be.N with bec.stock so many stock back-end commons
 *              are available from one archive (without naming each bec.*)
 *            - multiplexing to console, file, fprintf, null, syslog (or
 *              Windows Syslog), and, on Windows, the debugger
 *
 * Created: 23rd June 2020
 * Updated: 18th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS // Faster compilation


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/backends/be.N.h>
#include <pantheios/backends/bec.console.h>
#include <pantheios/backends/bec.file.h>
#include <pantheios/backends/bec.fprintf.h>
#include <pantheios/backends/bec.null.h>
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <pantheios/backends/bec.syslog.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <pantheios/backends/bec.WindowsDebugger.h>
# include <pantheios/backends/bec.WindowsSyslog.h>
#else /* ? OS */
# error Operating system not discriminated
#endif /* OS */

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.linking.N_with_stock");

enum
{
    beid_Console  = 1,
    beid_File     = 2,
    beid_Fprintf  = 3,
    beid_Null     = 4,
    beid_Syslog   = 5,
    beid_Debugger = 6
};

PANTHEIOS_EXTERN pan_be_N_t PAN_BE_N_BACKEND_LIST[] =
{
    PANTHEIOS_BE_N_STDFORM_ENTRY(beid_Console, pantheios_be_console, 0),
    PANTHEIOS_BE_N_STDFORM_ENTRY(beid_File, pantheios_be_file, 0),
    PANTHEIOS_BE_N_STDFORM_ENTRY(beid_Fprintf, pantheios_be_fprintf, 0),
    PANTHEIOS_BE_N_STDFORM_ENTRY(beid_Null, pantheios_be_null, 0),
#if defined(PLATFORMSTL_OS_IS_UNIX)

    PANTHEIOS_BE_N_STDFORM_ENTRY(beid_Syslog, pantheios_be_syslog, 0),
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    PANTHEIOS_BE_N_STDFORM_ENTRY(beid_Syslog, pantheios_be_WindowsSyslog, 0),
    PANTHEIOS_BE_N_STDFORM_ENTRY(beid_Debugger, pantheios_be_WindowsDebugger, 0),
#endif

    PANTHEIOS_BE_N_TERMINATOR_ENTRY
};


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
    pantheios_be_file_setFilePath(
        PANTHEIOS_LITERAL_STRING("example.cpp.linking.N_with_stock.log"),
        PANTHEIOS_BE_FILE_F_TRUNCATE,
        PANTHEIOS_BE_FILE_F_TRUNCATE,
        beid_File
    );

    pantheios::log_NOTICE(PANTHEIOS_LITERAL_STRING("Hello from be.N + bec.stock!"));

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

