/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/tracing/example.cpp.tracing.standard/example.cpp.tracing.standard.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios Tracing API
 *
 * Created: 18th August 2007
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios header files */
#include <pantheios/pantheios.h>                // Pantheios C main header
#include <pantheios/trace.h>                    // Pantheios Trace API
#include <pantheios/pantheios.hpp>              // Pantheios C++ main header

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
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.tracing.standard");


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
    // Prints "[example.cpp.tracing.standard, 8/18/2007 17:14:08.875 PM; Notice]: example.cpp.tracing.standard.cpp(51): a string '<abc>' and a number 42"

    PANTHEIOS_TRACE_PRINTF(pantheios::notice, PSTR("a string '%s' and a number %d"), PSTR("<abc>"), 42);

    // Prints "[example.cpp.tracing.standard, 8/18/2007 17:14:08.875 PM; Notice]: example.cpp.tracing.standard.cpp(55): a string at NOTICE level"

    PANTHEIOS_TRACE_NOTICE(PSTR("a string at NOTICE level"));

    PANTHEIOS_TRACE_INFORMATIONAL(PSTR("informational"));

    PANTHEIOS_TRACE_ALERT(PSTR("alert"));

    PANTHEIOS_TRACE_WARNING(PSTR("warning"));

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

