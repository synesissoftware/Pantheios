/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/misc/example.cpp.misc.no_namespace/example.cpp.misc.no_namespace.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios with the namespace suppressed
 *
 * Created: 15th March 2008
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios header files */
#define PANTHEIOS_NO_NAMESPACE                            // Suppress the namespace
#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS // Faster compilation
#include <pantheios/pantheios.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>                         // for exit codes


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
extern "C" const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[]    =   PANTHEIOS_LITERAL_STRING("example.cpp.misc.no_namespace");


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
  log_DEBUG(PSTR("debug"));
  log_INFORMATIONAL(PSTR("informational"));
  log_NOTICE(PSTR("notice"));
  log_WARNING(PSTR("warning"));
  log_ERROR(PSTR("error"));
  log_CRITICAL(PSTR("critical"));
  log_ALERT(PSTR("alert"));
  log_EMERGENCY(PSTR("emergency"));

  return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

