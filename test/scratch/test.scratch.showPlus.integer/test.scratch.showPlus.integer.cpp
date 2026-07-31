/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.WideString/test.scratch.WideString.cpp
 *
 * Purpose: Implementation file for the test.scratch.showPlus.integer project.
 *
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/pan.hpp>
#include <pantheios/inserters/i.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PSTR                                                PANTHEIOS_LITERAL_STRING


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.showPlus.integer");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
    pan::log_INFORMATIONAL(PSTR("log -10:"));
    pan::log_INFORMATIONAL(PSTR("without showPlus: '"), pan::i(-10), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("with    showPlus: '"), pan::i(-10, 0, pan::fmt::showPlus), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("----------\n"));

    pan::log_INFORMATIONAL(PSTR("log +10:"));
    pan::log_INFORMATIONAL(PSTR("without showPlus: '"), pan::i(+10), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("with    showPlus: '"), pan::i(+10, 0, pan::fmt::showPlus), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("----------\n"));


    pan::log_INFORMATIONAL(PSTR("log -10 into 10-width:"));
    pan::log_INFORMATIONAL(PSTR("without showPlus: '"), pan::i(-10, 10, 0), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("with    showPlus: '"), pan::i(-10, 10, pan::fmt::showPlus), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("----------\n"));

    pan::log_INFORMATIONAL(PSTR("log +10 into 10-width:"));
    pan::log_INFORMATIONAL(PSTR("without showPlus: '"), pan::i(+10, 10, 0), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("with    showPlus: '"), pan::i(+10, 10, pan::fmt::showPlus), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("----------\n"));


    pan::log_INFORMATIONAL(PSTR("log -10 into 10-width left-justified:"));
    pan::log_INFORMATIONAL(PSTR("without showPlus: '"), pan::i(-10, -10, 0), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("with    showPlus: '"), pan::i(-10, -10, pan::fmt::showPlus), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("----------\n"));

    pan::log_INFORMATIONAL(PSTR("log +10 into 10-width left-justified:"));
    pan::log_INFORMATIONAL(PSTR("without showPlus: '"), pan::i(+10, -10, 0), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("with    showPlus: '"), pan::i(+10, -10, pan::fmt::showPlus), PSTR("'"));
    pan::log_INFORMATIONAL(PSTR("----------\n"));


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

