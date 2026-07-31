/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/test.component.inserters.windows.hive/test.component.inserters.windows.hive.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.windows.hive project.
 *
 * Created: 26th January 2017
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>                  // Pantheios C++ main header
#include <pantheios/inserters/windows/hive.hpp>     // for pantheios::windows::hive
#include <pantheios/backends/bec.test.h>

/* STLSoft header files */
#include <stlsoft/util/limit_traits.h>
#include <stlsoft/string/simple_string.hpp>

/* Standard C++ header files */
#include <exception>
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_00();
static void test_1_01();
static void test_1_02();
static void test_1_03();
static void test_1_04();
static void test_1_05();
static void test_1_06();
static void test_1_07();
static void test_1_08();
static void test_1_09();
static void test_1_10();
static void test_1_11();
static void test_1_12();
static void test_1_13();
static void test_1_14();
static void test_1_15();
static void test_1_21();
static void test_1_22();
static void test_1_23();
static void test_1_24();


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.windows.hive");


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PSTR(x)                                              PANTHEIOS_LITERAL_STRING(x)

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inserters.windows.hive", verbosity))
    {
        XTESTS_RUN_CASE(test_1_00);
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_RUN_CASE(test_1_07);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void test_1_00()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_CLASSES_ROOT));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(n, results.size()));
    XTESTS_TEST_STRING_EQUAL(PSTR("hive is HKEY_CLASSES_ROOT"), results[0].statement);
}

static void test_1_01()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_CURRENT_USER));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(n, results.size()));
    XTESTS_TEST_STRING_EQUAL(PSTR("hive is HKEY_CURRENT_USER"), results[0].statement);
}

static void test_1_02()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_LOCAL_MACHINE));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(n, results.size()));
    XTESTS_TEST_STRING_EQUAL(PSTR("hive is HKEY_LOCAL_MACHINE"), results[0].statement);
}

static void test_1_03()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_USERS));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(n, results.size()));
    XTESTS_TEST_STRING_EQUAL(PSTR("hive is HKEY_USERS"), results[0].statement);
}

static void test_1_04()
{
#ifdef HKEY_PERFORMANCE_DATA
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_PERFORMANCE_DATA));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(n, results.size()));
    XTESTS_TEST_STRING_EQUAL(PSTR("hive is HKEY_PERFORMANCE_DATA"), results[0].statement);
#endif
}

static void test_1_05()
{
#ifdef HKEY_CURRENT_CONFIG
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_CURRENT_CONFIG));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(n, results.size()));
    XTESTS_TEST_STRING_EQUAL(PSTR("hive is HKEY_CURRENT_CONFIG"), results[0].statement);
#endif
}

static void test_1_06()
{
#ifdef HKEY_DYN_DATA
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_DYN_DATA));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(n, results.size()));
    XTESTS_TEST_STRING_EQUAL(PSTR("hive is HKEY_DYN_DATA"), results[0].statement);
#endif
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

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_21()
{
}

static void test_1_22()
{
}

static void test_1_23()
{
}

static void test_1_24()
{
}


/* ///////////////////////////// end of file //////////////////////////// */

