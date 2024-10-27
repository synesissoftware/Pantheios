/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/format/example.cpp.format.pad/example.cpp.format.pad.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios inserters for padding
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 29th June 2009
 * Updated: 28th October 2024
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
#include <pantheios/pantheios.hpp>              // Pantheios C++ main header
#include <pantheios/inserters/pad.hpp>          // for pantheios::pad
#include <pantheios/internal/string_encoding.h> // for PANTHEIOS_LITERAL_STRING

/* Standard C/C++ header files */
#include <exception>                            // for std::exception
#include <new>                                  // for std::bad_alloc
#include <string>                               // for std::string
#include <stdio.h>                              // for printf()
#include <stdlib.h>                             // for exit codes


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.format.pad");


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
    std::basic_string<pantheios::pan_char_t>  name = PANTHEIOS_LITERAL_STRING("John Smith");

    printf("Name: %40s.\n", name.c_str());

    pantheios::log_NOTICE(PSTR("Name: "), PANTHEIOS_LPAD(name, 40), PSTR("."));

    printf("Name: %-40s.\n", name.c_str());

    pantheios::log_NOTICE(PSTR("Name: "), PANTHEIOS_RPAD(name, 40), PSTR("."));

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

