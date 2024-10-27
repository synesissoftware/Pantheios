/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.fe.fail/test.unit.fe.fail.c
 *
 * Purpose: Implementation file for the test.unit.fe.fail project.
 *
 * Created: 14th May 2008
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/frontends/fe.fail.h>
#include <pantheios/init_codes.h>

#include <xtests/xtests.h>

#include <stlsoft/stlsoft.h>        /* for STLSOFT_NUM_ELEMENTS */

#include <stdio.h>                  /* for fprintf() */
#include <stdlib.h>                 /* for EXIT_SUCCESS, EXIT_FAILURE */

PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.fe.fail");

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.fe.fail", verbosity))
    {
        /* Test-1 */
        if (XTESTS_CASE_BEGIN("Test-1", "Verify that the initialisation fails"))
        {
            void*   token;
            int     res;

            res = pantheios_fe_init(NULL, &token);

            XTESTS_TEST_INTEGER_LESS(0, res);
            XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_FE_INIT_RC_INTENDED_FAILURE, res);

            XTESTS_CASE_END("Test-1");
        }


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ///////////////////////////// end of file //////////////////////////// */

