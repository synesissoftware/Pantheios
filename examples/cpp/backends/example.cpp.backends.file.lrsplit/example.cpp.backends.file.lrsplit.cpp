/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/backends/example.cpp.backends.file.lrsplit/example.cpp.backends.file.lrsplit.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of pantheios_be_file_setFilePath()
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 29th November 2006
 * Updated: 15th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS // Faster compilation

/* Pantheios header files */
#include <pantheios/pantheios.hpp>            // Pantheios C++ main header
#include <pantheios/inserters/args.hpp>       // for pantheios::args

#include <pantheios/backends/bec.file.h>      // be.file header

/* Standard C/C++ header files */
#include <exception>                          // for std::exception
#include <new>                                // for std::bad_alloc
#include <string>                             // for std::string
#include <stdlib.h>                           // for exit codes

/* ////////////////////////////////////////////////////////////////////// */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.backends.file.lrsplit");


/* ////////////////////////////////////////////////////////////////////// */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)


/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char **argv)
{
  // Use of be.file involves several steps:
  //
  // 1. Linking to the back-end, either explicitly or implicitly
  // 2. Setting the log file path for the given back-end(s)
  // 3. Making log statements
  // 4. Changing the log file path for the given back-end(s)
  // 5. Closing the log file for the given back-end(s)

  // In this case, linking is performed either by the build makefile or the
  // IDE project file, to the be.lrsplit back-end, the bel.file local
  // back-end, and the ber.file remote back-end.
  //
  // In this case, only one back-end is specified, so the back-end
  // identifier PANTHEIOS_BEID_ALL (=== 0) is used.
  //
  // In this case, the log file path is set to 'log.single', and the file is
  // truncated with the flag and mask PANTHEIOS_BE_FILE_F_TRUNCATE.
  //
  // In this case, we explicitly close the log-file, then open it again,
  // just for illustrative purposes.

  try
  {
#ifndef PANTHEIOS_USE_WIDE_STRINGS
    pantheios::log_DEBUG("main(", pantheios::args(argc, argv), ")");
#else /* ? !PANTHEIOS_USE_WIDE_STRINGS */
    STLSOFT_SUPPRESS_UNUSED(argc); STLSOFT_SUPPRESS_UNUSED(argv);
#endif /* !PANTHEIOS_USE_WIDE_STRINGS */


    pantheios::log_NOTICE(PSTR("stmt 1"));


    // Set the file name for the local back-end, truncating the
    // file's existing contents, if any.
    pantheios_be_file_setFilePath(PSTR("local.log"), PANTHEIOS_BE_FILE_F_TRUNCATE, PANTHEIOS_BE_FILE_F_TRUNCATE, PANTHEIOS_BEID_LOCAL);


    pantheios::log_NOTICE(PSTR("stmt 2"));


    // Set the file name for the remote back-end, not truncating, so that
    // its contents accrue each execution.
    pantheios_be_file_setFilePath(PSTR("remote.log"), PANTHEIOS_BEID_REMOTE);


    pantheios::log_NOTICE(PSTR("stmt 3"));


    // Close all files, by setting the path to NULL.
    pantheios_be_file_setFilePath(NULL, PANTHEIOS_BEID_ALL);


    pantheios::log_NOTICE(PSTR("stmt 4"));


    pantheios::log_DEBUG(PSTR("exiting main()"));

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

