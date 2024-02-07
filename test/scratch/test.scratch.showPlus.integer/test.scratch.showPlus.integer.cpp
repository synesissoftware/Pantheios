/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.WideString/test.scratch.WideString.cpp
 *
 * Purpose: Implementation file for the test.scratch.showPlus.integer project.
 *
 * Updated: 7th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/pan.hpp>
#include <pantheios/inserters/i.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.showPlus.integer");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main()
{
    pan::log_INFORMATIONAL("log -10:");
    pan::log_INFORMATIONAL("without showPlus: '", pan::i(-10), "'");
    pan::log_INFORMATIONAL("with    showPlus: '", pan::i(-10, 0, pan::fmt::showPlus), "'");
    pan::log_INFORMATIONAL("----------\n");

    pan::log_INFORMATIONAL("log +10:");
    pan::log_INFORMATIONAL("without showPlus: '", pan::i(+10), "'");
    pan::log_INFORMATIONAL("with    showPlus: '", pan::i(+10, 0, pan::fmt::showPlus), "'");
    pan::log_INFORMATIONAL("----------\n");


    pan::log_INFORMATIONAL("log -10 into 10-width:");
    pan::log_INFORMATIONAL("without showPlus: '", pan::i(-10, 10, 0), "'");
    pan::log_INFORMATIONAL("with    showPlus: '", pan::i(-10, 10, pan::fmt::showPlus), "'");
    pan::log_INFORMATIONAL("----------\n");

    pan::log_INFORMATIONAL("log +10 into 10-width:");
    pan::log_INFORMATIONAL("without showPlus: '", pan::i(+10, 10, 0), "'");
    pan::log_INFORMATIONAL("with    showPlus: '", pan::i(+10, 10, pan::fmt::showPlus), "'");
    pan::log_INFORMATIONAL("----------\n");


    pan::log_INFORMATIONAL("log -10 into 10-width left-justified:");
    pan::log_INFORMATIONAL("without showPlus: '", pan::i(-10, -10, 0), "'");
    pan::log_INFORMATIONAL("with    showPlus: '", pan::i(-10, -10, pan::fmt::showPlus), "'");
    pan::log_INFORMATIONAL("----------\n");

    pan::log_INFORMATIONAL("log +10 into 10-width left-justified:");
    pan::log_INFORMATIONAL("without showPlus: '", pan::i(+10, -10, 0), "'");
    pan::log_INFORMATIONAL("with    showPlus: '", pan::i(+10, -10, pan::fmt::showPlus), "'");
    pan::log_INFORMATIONAL("----------\n");


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

