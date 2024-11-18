/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.be.ACE/test.scratch.be.ACE.cpp
 *
 * Purpose: C++ example program for Pantheios with ACE.
 *
 * Created: 26th January 2017
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* This inclusion required for suppressing warnings during NoX (No eXception-support) configurations. */
#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files - 1 */
#include <pantheios/pantheios.h>

/* ACE header files */
#include <ace/OS_main.h>

/* Pantheios header files - 2 */
#include <pantheios/pantheios.hpp>
#include <pantheios/backend.h>
#include <pantheios/backends/bec.ACE.h>

/* STLSoft header files */
#include <platformstl/synch/sleep_functions.h>

/* Standard C/C++ header files */
#include <exception>                        // for std::exception
#include <new>                              // for std::bad_alloc
#include <stdlib.h>                         // for exit codes

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

// Define the fe.simple process identity, so that it links when using fe.simple
PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.be.ACE");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int
ACE_TMAIN(int /* argc */, ACE_TCHAR* /* argv */[])
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
    catch (std::bad_alloc &)
    {
        pantheios::log_CRITICAL("out of memory");
    }
    catch (std::exception &x)
    {
        pantheios::log_ALERT("Exception: ", x);
    }
    catch (...)
    {
        pantheios::logputs(pantheios::emergency, "Unexpected unknown error");
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

