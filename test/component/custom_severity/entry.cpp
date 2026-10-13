/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/custom_severity/entry.cpp
 *
 * Purpose: Implementation file for the test.component.custom_severity project.
 *
 * Created: 31st October 2005
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

static void TEST_pantheios_log_NOTICE_STOCK();
static void TEST_pantheios_log_NOTICE_CUSTOM_SEVERITY_LEVEL_1();
static void TEST_pantheios_log_NOTICE_CUSTOM_SEVERITY_LEVEL_LARGE();
/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.custom_severity");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.custom_severity", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_log_NOTICE_STOCK);
        XTESTS_RUN_CASE(TEST_pantheios_log_NOTICE_CUSTOM_SEVERITY_LEVEL_1);
        XTESTS_RUN_CASE(TEST_pantheios_log_NOTICE_CUSTOM_SEVERITY_LEVEL_LARGE);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_log_NOTICE_STOCK()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice, PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_STRING_EQ(PSTR("abc"), results[0].statement);
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_NOTICE, results[0].severity);
}

static void TEST_pantheios_log_NOTICE_CUSTOM_SEVERITY_LEVEL_1()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice(1), PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_STRING_EQ(PSTR("abc"), results[0].statement);
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_NOTICE | (1 << 4), results[0].severity);
}

static void TEST_pantheios_log_NOTICE_CUSTOM_SEVERITY_LEVEL_LARGE()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice(0x01234567), PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_STRING_EQ(PSTR("abc"), results[0].statement);
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_NOTICE | (0x01234567 << 4), results[0].severity);
}


/* ///////////////////////////// end of file //////////////////////////// */

