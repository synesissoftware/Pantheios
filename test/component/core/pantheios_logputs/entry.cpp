/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/core/pantheios_logputs/entry.cpp
 *
 * Purpose: Implementation file for the test.component.core.pantheios_logputs project.
 *
 * Created: 19th November 2008
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/backends/bec.test.h>

/* Standard C++ header files */
#include <exception>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PANTHEIOS_SEV_LEVELS_EQUAL(x, y)                    TEST_INT_EQ(static_cast<int>(x), static_cast<int>(y))


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_pantheios_logputs_STOCK_SEVERITIES_SIMPLE();
static void TEST_pantheios_logputs_CUSTOM_SEVERITY_LEVEL_1();
static void TEST_pantheios_logputs_CUSTOM_SEVERITY_LEVEL_LARGE();
static void TEST_pantheios_logputs_STOCK_SEVERITIES_MULTIPLE_LENGTHS();
/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.core.pantheios_logputs");

static const int    s_severities[] =
{
        PANTHEIOS_SEV_DEBUG
    ,   PANTHEIOS_SEV_INFORMATIONAL
    ,   PANTHEIOS_SEV_NOTICE
    ,   PANTHEIOS_SEV_WARNING
    ,   PANTHEIOS_SEV_ERROR
    ,   PANTHEIOS_SEV_CRITICAL
    ,   PANTHEIOS_SEV_ALERT
    ,   PANTHEIOS_SEV_EMERGENCY
};


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.core.pantheios_logputs", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_logputs_STOCK_SEVERITIES_SIMPLE);
        XTESTS_RUN_CASE(TEST_pantheios_logputs_CUSTOM_SEVERITY_LEVEL_1);
        XTESTS_RUN_CASE(TEST_pantheios_logputs_CUSTOM_SEVERITY_LEVEL_LARGE);
        XTESTS_RUN_CASE(TEST_pantheios_logputs_STOCK_SEVERITIES_MULTIPLE_LENGTHS);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_logputs_STOCK_SEVERITIES_SIMPLE()
{
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_severities); ++i)
    {
        const int severity = s_severities[i];

        // 1. Setup

        pantheios::be::test::reset();


        // 2. Create test data

        pantheios::pantheios_logputs(severity, PSTR("abc"));


        // 3. Verification

        pantheios::be::test::Results  results = pantheios::be::test::results();

        if (!results.empty()) // Do test here, so will work with any back-end
        {
            TEST_INT_EQ(1, results.size());
            PANTHEIOS_SEV_LEVELS_EQUAL(severity, results[0].severity);
            TEST_STRING_EQ(PSTR("abc"), results[0].statement);
        }
    }}
}

static void TEST_pantheios_logputs_CUSTOM_SEVERITY_LEVEL_1()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::pantheios_logputs(pantheios::error(1), PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_ERROR | (1 << 4), results[0].severity);
    TEST_STRING_EQ(PSTR("abc"), results[0].statement);
}

static void TEST_pantheios_logputs_CUSTOM_SEVERITY_LEVEL_LARGE()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::pantheios_logputs(pantheios::error(0x01234567), PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_ERROR | (0x01234567 << 4), results[0].severity);
    TEST_STRING_EQ(PSTR("abc"), results[0].statement);
}

static void TEST_pantheios_logputs_STOCK_SEVERITIES_MULTIPLE_LENGTHS()
{
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_severities); ++i)
    {
        const int severity = s_severities[i];

        // 1. Setup

        pantheios::be::test::reset();


        // 2. Create test data

        pantheios::pantheios_logputs(severity, PSTR("abc"));
        pantheios::pantheios_logputs(severity, PSTR("def"));
        pantheios::pantheios_logputs(severity, PSTR("abcdefghijklmnopqrstuvwxyz"));
        pantheios::pantheios_logputs(severity, PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"));


        // 3. Verification

        pantheios::be::test::Results  results = pantheios::be::test::results();

        if (!results.empty()) // Do test here, so will work with any back-end
        {
            TEST_INT_EQ(4, results.size());

            PANTHEIOS_SEV_LEVELS_EQUAL(severity, results[0].severity);
            TEST_STRING_EQ(PSTR("abc"), results[0].statement);

            PANTHEIOS_SEV_LEVELS_EQUAL(severity, results[1].severity);
            TEST_STRING_EQ(PSTR("def"), results[1].statement);

            PANTHEIOS_SEV_LEVELS_EQUAL(severity, results[2].severity);
            TEST_STRING_EQ(PSTR("abcdefghijklmnopqrstuvwxyz"), results[2].statement);

            PANTHEIOS_SEV_LEVELS_EQUAL(severity, results[3].severity);
            TEST_STRING_EQ(PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"), results[3].statement);
        }
    }}
}


/* ///////////////////////////// end of file //////////////////////////// */

