/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/inserters/example.cpp.inserter.m2w/example.cpp.inserter.m2w.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios inserters for m2w types
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 25th September 2010
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

// The following four lines are used only to verify that we're compiling for
// wide-strings, and would not be necessary in your program.
#include <pantheios/pantheios.h>
#ifndef PANTHEIOS_USE_WIDE_STRINGS
# error This example only compatible with wide-string builds
#endif /* !PANTHEIOS_USE_WIDE_STRINGS */

/* Pantheios header files */
#include <pantheios/pan.hpp>
#include <pantheios/inserters/args.hpp>
#include <pantheios/inserters/m2w.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = L"example.cpp.inserter.m2w";


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, wchar_t** argv)
{
  try
  {

    pan::log_NOTICE(L"main(", pan::args(argc, argv, pan::args::arg0FileOnly), L")");

    pan::log_NOTICE(L"A multibyte string: ", pan::m2w("plain-old-me"));


    return EXIT_SUCCESS;
  }
  catch (std::bad_alloc&)
  {
    pantheios::log(pantheios::alert, L"out of memory");
  }
  catch (std::exception& x)
  {
    pantheios::log_CRITICAL(L"Exception: ", x);
  }
  catch (...)
  {
    pantheios::logputs(pantheios::emergency, L"Unexpected unknown error");
  }

  return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

