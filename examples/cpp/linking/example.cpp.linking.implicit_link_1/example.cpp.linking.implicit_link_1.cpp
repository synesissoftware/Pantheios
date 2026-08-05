/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/linking/example.cpp.linking.implicit_link_1/example.cpp.linking.implicit_link_1.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of implicit linking to bind in front-end and back-end
 *
 * Created: 31st August 2006
 * Updated: 5th August 2026
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
#include <pantheios/pantheios.hpp>                  // Pantheios C++ main header
#include <pantheios/implicit_link/core.h>           // Implicitly link the core
#include <pantheios/implicit_link/fe.simple.h>      // Implicitly link the stock front-end fe.simple
#include <pantheios/implicit_link/be.AnsiConsole.h> // Implicitly link the stock back-end be.AnsiConsole

/* Standard C/C++ header files */
#include <string>                               // for std::string
#include <stdlib.h>                             // for exit codes


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.linking.implicit_link_1");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
  pantheios::log_INFORMATIONAL(PANTHEIOS_LITERAL_STRING("Hello!"));

  return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

