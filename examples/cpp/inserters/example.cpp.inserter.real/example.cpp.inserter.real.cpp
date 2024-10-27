/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/inserters/example.cpp.inserter.real/example.cpp.inserter.real.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios inserters for floating-point types
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 25th August 2006
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios header files */
#include <pantheios/pantheios.hpp>            // Pantheios C++ main header
#include <pantheios/inserters/real.hpp>       // for pantheios::real

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
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.inserter.real");


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
    float       f   =   1234.5678f;
    double      d   =   12345678.0123456789;
    long double ld  =   6.142e-23;

    // Log a float; Output: "f: [1234.57]"

    pantheios::log_NOTICE(PSTR("f: ["), pantheios::real(f), PSTR("]"));

    // Log a double; Output: "d: [1.23457e+007]"

    pantheios::log_NOTICE(PSTR("d: ["), pantheios::real(d), PSTR("]"));

    // Log a long double; Output: "ld: [6.142e-023]"

    pantheios::log_NOTICE(PSTR("ld: ["), pantheios::real(ld), PSTR("]"));


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

