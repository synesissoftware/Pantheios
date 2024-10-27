/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/inserters/example.cpp.inserter.b/example.cpp.inserter.b.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios inserters for pointer types
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 12th November 2010
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios header files */
#include <pantheios/pantheios.hpp>            // Pantheios C++ main header
#include <pantheios/inserters/b.hpp>          // for pantheios::b

/* Standard C/C++ header files */
#include <exception>                        // for std::exception
#include <new>                              // for std::bad_alloc
#include <string>                           // for std::string
#include <stdlib.h>                         // for exit codes


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.inserter.b");


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
    // Log true; Output: "true: [true]"

    pantheios::log_NOTICE(PSTR("true: ["), pantheios::b(true), PSTR("]"));

    // Log false; Output: "false: [false]"

    pantheios::log_NOTICE(PSTR("false: ["), pantheios::b(false), PSTR("]"));


    // Change the boolean strings

    pantheios::b::set_value_strings(PSTR("FALSE"), PSTR("TRUE"));


    // Log true; Output: "true: [TRUE]"

    pantheios::log_NOTICE(PSTR("true: ["), pantheios::b(true), PSTR("]"));

    // Log false; Output: "false: [FALSE]"

    pantheios::log_NOTICE(PSTR("false: ["), pantheios::b(false), PSTR("]"));


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

