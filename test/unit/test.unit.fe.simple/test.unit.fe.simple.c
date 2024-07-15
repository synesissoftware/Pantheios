/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.fe.simple/test.unit.fe.simple.c
 *
 * Purpose:     Implementation file for the test.unit.fe.simple project.
 *
 * Created:     14th May 2008
 * Updated:     16th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/frontends/fe.simple.h>
#include <pantheios/init_codes.h>

#include <xtests/xtests.h>

#include <stlsoft/stlsoft.h>        /* for STLSOFT_NUM_ELEMENTS */

#include <stdio.h>                  /* for fprintf() */
#include <stdlib.h>                 /* for EXIT_SUCCESS, EXIT_FAILURE */


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL

#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.fe.simple");


/* /////////////////////////////////////////////////////////////////////////
 * statics and constants
 */

static const int s_severityLevels[] =
{
        PANTHEIOS_SEV_EMERGENCY
    ,   PANTHEIOS_SEV_ALERT
    ,   PANTHEIOS_SEV_CRITICAL
    ,   PANTHEIOS_SEV_ERROR
    ,   PANTHEIOS_SEV_WARNING
    ,   PANTHEIOS_SEV_NOTICE
    ,   PANTHEIOS_SEV_INFORMATIONAL
    ,   PANTHEIOS_SEV_DEBUG
};

static const int s_severityLevelResults[] =
{
        1
    ,   1
    ,   1
    ,   1
    ,   1
    ,   1
#ifdef NDEBUG
    ,   0
    ,   0
#else /* ? NDEBUG */
    ,   1
    ,   1
#endif /* NDEBUG */
};

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(s_severityLevels) == STLSOFT_NUM_ELEMENTS(s_severityLevelResults));

    if (XTESTS_START_RUNNER("test.unit.fe.simple", verbosity))
    {
        /* Test-1 */
        if (XTESTS_CASE_BEGIN("Test-1", "Verify that the initialisation succeeds"))
        {
            void*   token;
            int     res;

            res = pantheios_fe_init(NULL, &token);

            XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_INIT_RC_SUCCESS, res);

            if (PANTHEIOS_INIT_RC_SUCCESS == res)
            {
                pantheios_fe_uninit(token);
            }

            XTESTS_CASE_END("Test-1");
        }


        /* Test-2 */
        if (XTESTS_CASE_BEGIN("Test-2", "Verify the process identity"))
        {
            void*   token;
            int     res;

            res = pantheios_fe_init(NULL, &token);

            if (PANTHEIOS_INIT_RC_SUCCESS == res)
            {
                XTESTS_TEST_STRING_EQUAL(PANTHEIOS_FE_PROCESS_IDENTITY, pantheios_fe_getProcessIdentity(token));

                pantheios_fe_uninit(token);
            }

            XTESTS_CASE_END("Test-2");
        }


        /* Test-3 */
        if (XTESTS_CASE_BEGIN("Test-3", "Verify that simple levels are acceptable"))
        {
            void*   token;
            int     res;

            res = pantheios_fe_init(NULL, &token);

            if (PANTHEIOS_INIT_RC_SUCCESS == res)
            {

                { size_t i; for (i = 0; i != STLSOFT_NUM_ELEMENTS(s_severityLevels); ++i)
                {
                    XTESTS_TEST_INTEGER_EQUAL(s_severityLevelResults[i], pantheios_fe_isSeverityLogged(token, s_severityLevels[i], 0));
                }}

                pantheios_fe_uninit(token);
            }

            pantheios_fe_uninit(token);

            XTESTS_CASE_END("Test-3");
        }


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ///////////////////////////// end of file //////////////////////////// */

