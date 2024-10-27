/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/inserters/example.cpp.inserter.hostid/example.cpp.inserter.hostid.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios inserter for host ids
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 15th April 2008
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios header files */
#include <pantheios/pantheios.hpp>              // Pantheios C++ main header
#include <pantheios/inserters/hostid.hpp>       // for pantheios::hostId

/* Standard C/C++ header files */
#include <exception>                            // for std::exception
#include <new>                                  // for std::bad_alloc
#include <string>                               // for std::string
#include <stdlib.h>                             // for exit codes

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  pragma warning(disable : 4702)
# endif /* compiler */
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.inserter.hostid");


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
  try
  {
    // Log the host Id; Output: "host id: [localhost]"

    pantheios::log_NOTICE(PSTR("host id: ["), pantheios::hostId, PSTR("]"));


    return EXIT_SUCCESS;
  }
  catch (std::bad_alloc&)
  {
    pantheios::log(pantheios::alert, PSTR("out of memory"));
  }
  catch (std::exception& x)
  {
    pantheios::log_CRITICAL(PSTR("Exception: "), x);
  }
  catch (...)
  {
    pantheios::logputs(pantheios::emergency, PSTR("Unexpected unknown error"));
  }

  return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

