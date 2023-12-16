/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.be.syslog.WithCallback/test.scratch.be.syslog.WithCallback.cpp
 *
 * Purpose:     C++ example program for Pantheios. Demonstrates:
 *
 *                - use of custom severity level information for tabbing output
 *                - definition of a custom back-end that supports tabbed output
 *                - use of pantheios::logputs() in bail-out conditions
 *
 * Created:     10th November 2010
 * Updated:     16th December 2023
 *
 * www:         http://www.pantheios.org/
 *
 * License:     This source code is placed into the public domain 2010
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 *              This software is provided "as is", and any warranties,
 *              express or implied, of any kind and for any purpose, are
 *              disclaimed.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* This inclusion required for suppressing warnings during NoX (No eXception-support) configurations. */
#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/backend.h>
#include <pantheios/backends/bec.syslog.h>

/* STLSoft header files */
#include <platformstl/synch/sleep_functions.h>

/* UNIX header files */
#include <syslog.h>

/* Standard C/C++ header files */
#include <exception>                        // for std::exception
#include <string>                           // for std::string
#include <stdio.h>                          // for fprintf()
#include <stdlib.h>                         // for exit codes
#include <string.h>                         // for memset()

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>

/* ////////////////////////////////////////////////////////////////////// */

// Define the fe.simple process identity, so that it links when using fe.simple
PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.speech");

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_CALL(void) pantheios_be_syslog_getAppInit(
    int                     /* backEndId */
,   pan_be_syslog_init_t*   init
) /* throw() */
{
    // Suppress perror
    init->options   &=  ~PANTHEIOS_BE_SYSLOG_F_PERROR;

    // Log to LOCAL1 (instead of USER)
    init->facility  =   LOG_LOCAL1;
}

/* ////////////////////////////////////////////////////////////////////// */

int main()
{
    unsigned shortPause = 1250;

    try
    {

        pantheios::log_NOTICE("Hi!");

        platformstl::micro_sleep(shortPause);

        pantheios::log_NOTICE("This is your logger, calling.");

        platformstl::micro_sleep(shortPause);

        pantheios::log_NOTICE("Here come some diagnostic logging statements ...");

        platformstl::micro_sleep(shortPause);

        pantheios::log_DEBUG("just being pedantic");

        platformstl::micro_sleep(shortPause);

        pantheios::log_INFORMATIONAL("you can ignore this");

        platformstl::micro_sleep(shortPause);

        pantheios::log_NOTICE("this is noteworthy");

        platformstl::micro_sleep(shortPause);

        pantheios::log_WARNING("there may be a problem");

        platformstl::micro_sleep(shortPause);

        pantheios::log_ERROR("there is a problem");

        platformstl::micro_sleep(shortPause);

        pantheios::log_CRITICAL("there is a serious problem");

        platformstl::micro_sleep(shortPause);

        pantheios::log_ALERT("there is a very serious problem");

        platformstl::micro_sleep(shortPause);

        pantheios::log_EMERGENCY("aargh! I'm operating in contradiction to my design!");

        platformstl::micro_sleep(90000);

        return EXIT_SUCCESS;
    }
    catch(std::bad_alloc &)
    {
        pantheios::log_CRITICAL("out of memory");
    }
    catch(std::exception &x)
    {
        pantheios::log_ALERT("Exception: ", x);
    }
    catch(...)
    {
        pantheios::logputs(pantheios::emergency, "Unexpected unknown error");
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */

