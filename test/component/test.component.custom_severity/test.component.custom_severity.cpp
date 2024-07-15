/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/test.component.custom_severity/test.component.custom_severity.cpp
 *
 * Purpose: Implementation file for the test.component.custom_severity project.
 *
 * Created: 31st October 2005
 * Updated: 15th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

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

#define PANTHEIOS_SEV_LEVELS_EQUAL(x, y)                    XTESTS_TEST_INTEGER_EQUAL(static_cast<int>(x), static_cast<int>(y))


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_01();
static void test_1_02();
static void test_1_03();
static void test_1_04();
static void test_1_05();
static void test_1_06();
static void test_1_07();
static void test_1_08();
static void test_1_09();


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.custom_severity");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.custom_severity", verbosity))
    {
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_RUN_CASE(test_1_07);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void test_1_01()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice, PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_TEST_INTEGER_EQUAL(1, results.size());
    XTESTS_TEST_STRING_EQUAL(PSTR("abc"), results[0].statement);
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_NOTICE, results[0].severity);
}

static void test_1_02()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice(1), PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_TEST_INTEGER_EQUAL(1, results.size());
    XTESTS_TEST_STRING_EQUAL(PSTR("abc"), results[0].statement);
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_NOTICE | (1 << 4), results[0].severity);
}

static void test_1_03()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice(0x01234567), PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_TEST_INTEGER_EQUAL(1, results.size());
    XTESTS_TEST_STRING_EQUAL(PSTR("abc"), results[0].statement);
    PANTHEIOS_SEV_LEVELS_EQUAL(PANTHEIOS_SEV_NOTICE | (0x01234567 << 4), results[0].severity);
}

static void test_1_04()
{
}

static void test_1_05()
{
}

static void test_1_06()
{
}

static void test_1_07()
{
}

static void test_1_08()
{
}

static void test_1_09()
{
}


/* ///////////////////////////// end of file //////////////////////////// */

