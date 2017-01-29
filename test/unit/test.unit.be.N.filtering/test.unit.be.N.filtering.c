/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.be.N.filtering/test.unit.be.N.filtering.cpp
 *
 * Purpose:     Implementation file for the test.unit.be.N.filtering project.
 *
 * Created:     28th June 2016
 * Updated:     27th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2016-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/backends/be.N.h>
#include <pantheios/backends/bec.test.h>
#include <pantheios/init_codes.h>

#include <xtests/xtests.h>

#include <stlsoft/stlsoft.h>        /* for STLSOFT_NUM_ELEMENTS */

#include <stdio.h>                  /* for fprintf() */
#include <stdlib.h>                 /* for EXIT_SUCCESS, EXIT_FAILURE */


PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.be.N.filtering");

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

struct results_t
{
    unsigned    counts[5 + 1][8];
};
typedef struct results_t    results_t;

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define DECLARE_BACK_END_IMPL_N_(n)                                         \
                                                                            \
    PANTHEIOS_CALL(int) pantheios_be_N_test_ ## n ## _init(                 \
        PAN_CHAR_T const*   processIdentity                                 \
    ,   int                 backEndId                                       \
    ,   void*               init                                            \
    ,   void*               reserved                                        \
    ,   void**              ptoken                                          \
    );                                                                      \
    PANTHEIOS_CALL(void) pantheios_be_N_test_ ## n ## _uninit(void* token); \
    PANTHEIOS_CALL(int) pantheios_be_N_test_ ## n ## _logEntry(             \
        void*               beToken                                         \
    ,   void*               feToken                                         \
    ,   int                 severity                                        \
    ,   PAN_CHAR_T const*   entry                                           \
    ,   size_t              cchEntry                                        \
    );                                                                      \
                                                                            \
    PANTHEIOS_CALL(int) pantheios_be_N_test_ ## n ## _init(                 \
        PAN_CHAR_T const*   processIdentity                                 \
    ,   int                 backEndId                                       \
    ,   void*               init                                            \
    ,   void*               reserved                                        \
    ,   void**              ptoken                                          \
    )                                                                       \
    {                                                                       \
        STLSOFT_SUPPRESS_UNUSED(processIdentity);                           \
        STLSOFT_SUPPRESS_UNUSED(backEndId);                                 \
        STLSOFT_SUPPRESS_UNUSED(init);                                      \
        STLSOFT_SUPPRESS_UNUSED(reserved);                                  \
        STLSOFT_SUPPRESS_UNUSED(ptoken);                                    \
                                                                            \
        return 0;                                                           \
    }                                                                       \
                                                                            \
    PANTHEIOS_CALL(void) pantheios_be_N_test_ ## n ## _uninit(void* token)  \
    {                                                                       \
        STLSOFT_SUPPRESS_UNUSED(token);                                     \
    }                                                                       \
                                                                            \
    PANTHEIOS_CALL(int) pantheios_be_N_test_ ## n ## _logEntry(             \
        void*               beToken                                         \
    ,   void*               feToken                                         \
    ,   int                 severity                                        \
    ,   PAN_CHAR_T const*   entry                                           \
    ,   size_t              cchEntry                                        \
    )                                                                       \
    {                                                                       \
        STLSOFT_SUPPRESS_UNUSED(beToken);                                   \
        STLSOFT_SUPPRESS_UNUSED(feToken);                                   \
        STLSOFT_SUPPRESS_UNUSED(severity);                                  \
        STLSOFT_SUPPRESS_UNUSED(entry);                                     \
        STLSOFT_SUPPRESS_UNUSED(cchEntry);                                  \
                                                                            \
        results.counts[n][severity & 0x7] += 1;                             \
                                                                            \
        return 0;                                                           \
    }

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# define pan_strlen_            wcslen
#else
# define pan_strlen_            strlen
#endif

#define LOG_ENTRY(token, severity, message)                                 \
                                                                            \
        pantheios_be_logEntry(NULL, (token), (severity), (message), pan_strlen_((message)))

/* /////////////////////////////////////////////////////////////////////////
 * backends
 */

#define NUM_BACKENDS    (5)

static results_t results;

DECLARE_BACK_END_IMPL_N_(1)
DECLARE_BACK_END_IMPL_N_(2)
DECLARE_BACK_END_IMPL_N_(3)
DECLARE_BACK_END_IMPL_N_(4)
DECLARE_BACK_END_IMPL_N_(5)

pan_be_N_t PAN_BE_N_BACKEND_LIST[] =
{
    /* NOTE: The flags in this one are ignored, as they're set up every time
     * by the reset_state_() function (below) and the test setup code.
     */

    PANTHEIOS_BE_N_STDFORM_ENTRY(       1,  pantheios_be_N_test_1,                                                              0),
    PANTHEIOS_BE_N_FILTERED_ENTRY(      2,  pantheios_be_N_test_2,                              PANTHEIOS_SEV_NOTICE,           0),
    PANTHEIOS_BE_N_FILTERED_ENTRY_FLOOR(3,  pantheios_be_N_test_3,  PANTHEIOS_SEV_CRITICAL,     PANTHEIOS_SEV_INFORMATIONAL,    0),
    PANTHEIOS_BE_N_STDFORM_ENTRY(       4,  pantheios_be_N_test_4,                                                              0),
    PANTHEIOS_BE_N_FILTERED_ENTRY_FLOOR(5,  pantheios_be_N_test_5,  PANTHEIOS_SEV_EMERGENCY,    PANTHEIOS_SEV_ERROR,            0),

    PANTHEIOS_BE_N_TERMINATOR_ENTRY
};

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_CALL(int) pantheios_getNextBackEndId(void)
{
    static int s_nextId = 1000;

    return ++s_nextId;
}

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);


    if(XTESTS_START_RUNNER("test.unit.be.N.filtering", verbosity))
    {
        /* Test-SeverityCeiling */
        if(XTESTS_CASE_BEGIN("Test-SeverityCeiling", "Verify that the severity floor works"))
        {
            void*       token;
            int const   res = pantheios_be_init(PANTHEIOS_FE_PROCESS_IDENTITY, &results, &token);

            if(0 == res)
            {

                int         i;
                for(i = 0; i != 10; ++i)
                {
                    LOG_ENTRY(token, PANTHEIOS_SEV_DEBUG, PANTHEIOS_LITERAL_STRING("debug"));
                    LOG_ENTRY(token, PANTHEIOS_SEV_INFORMATIONAL, PANTHEIOS_LITERAL_STRING("informational"));
                    LOG_ENTRY(token, PANTHEIOS_SEV_NOTICE, PANTHEIOS_LITERAL_STRING("notice"));
                    LOG_ENTRY(token, PANTHEIOS_SEV_WARNING, PANTHEIOS_LITERAL_STRING("warning"));
                    LOG_ENTRY(token, PANTHEIOS_SEV_ERROR, PANTHEIOS_LITERAL_STRING("error"));
                    LOG_ENTRY(token, PANTHEIOS_SEV_CRITICAL, PANTHEIOS_LITERAL_STRING("critical"));
                    LOG_ENTRY(token, PANTHEIOS_SEV_ALERT, PANTHEIOS_LITERAL_STRING("alert"));
                    LOG_ENTRY(token, PANTHEIOS_SEV_EMERGENCY, PANTHEIOS_LITERAL_STRING("emergency"));
                }

                pantheios_be_uninit(token);

                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_DEBUG]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_INFORMATIONAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_NOTICE]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_WARNING]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_ERROR]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_CRITICAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_ALERT]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[1][PANTHEIOS_SEV_EMERGENCY]);

                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[2][PANTHEIOS_SEV_DEBUG]);
                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[2][PANTHEIOS_SEV_INFORMATIONAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[2][PANTHEIOS_SEV_NOTICE]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[2][PANTHEIOS_SEV_WARNING]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[2][PANTHEIOS_SEV_ERROR]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[2][PANTHEIOS_SEV_CRITICAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[2][PANTHEIOS_SEV_ALERT]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[2][PANTHEIOS_SEV_EMERGENCY]);

                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[3][PANTHEIOS_SEV_DEBUG]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[3][PANTHEIOS_SEV_INFORMATIONAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[3][PANTHEIOS_SEV_NOTICE]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[3][PANTHEIOS_SEV_WARNING]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[3][PANTHEIOS_SEV_ERROR]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[3][PANTHEIOS_SEV_CRITICAL]);
                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[3][PANTHEIOS_SEV_ALERT]);
                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[3][PANTHEIOS_SEV_EMERGENCY]);

                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_DEBUG]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_INFORMATIONAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_NOTICE]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_WARNING]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_ERROR]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_CRITICAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_ALERT]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[4][PANTHEIOS_SEV_EMERGENCY]);

                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[5][PANTHEIOS_SEV_DEBUG]);
                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[5][PANTHEIOS_SEV_INFORMATIONAL]);
                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[5][PANTHEIOS_SEV_NOTICE]);
                XTESTS_TEST_INTEGER_EQUAL( 0u, results.counts[5][PANTHEIOS_SEV_WARNING]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[5][PANTHEIOS_SEV_ERROR]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[5][PANTHEIOS_SEV_CRITICAL]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[5][PANTHEIOS_SEV_ALERT]);
                XTESTS_TEST_INTEGER_EQUAL(10u, results.counts[5][PANTHEIOS_SEV_EMERGENCY]);

                XTESTS_CASE_END("Test-SeverityCeiling");
            }
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ///////////////////////////// end of file //////////////////////////// */
