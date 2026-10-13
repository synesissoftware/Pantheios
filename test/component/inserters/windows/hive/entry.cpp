/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/windows/hive/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.windows.hive project.
 *
 * Created: 26th January 2017
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

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

static void TEST_pantheios_windows_hive_HKEY_CLASSES_ROOT();
static void TEST_pantheios_windows_hive_HKEY_CURRENT_USER();
static void TEST_pantheios_windows_hive_HKEY_LOCAL_MACHINE();
static void TEST_pantheios_windows_hive_HKEY_USERS();
static void TEST_pantheios_windows_hive_HKEY_PERFORMANCE_DATA();
static void TEST_pantheios_windows_hive_HKEY_CURRENT_CONFIG();
static void TEST_pantheios_windows_hive_HKEY_DYN_DATA();
/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.windows.hive");


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PSTR(x)                                              PANTHEIOS_LITERAL_STRING(x)

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ
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
        XTESTS_RUN_CASE(TEST_pantheios_windows_hive_HKEY_CLASSES_ROOT);
        XTESTS_RUN_CASE(TEST_pantheios_windows_hive_HKEY_CURRENT_USER);
        XTESTS_RUN_CASE(TEST_pantheios_windows_hive_HKEY_LOCAL_MACHINE);
        XTESTS_RUN_CASE(TEST_pantheios_windows_hive_HKEY_USERS);
        XTESTS_RUN_CASE(TEST_pantheios_windows_hive_HKEY_PERFORMANCE_DATA);
        XTESTS_RUN_CASE(TEST_pantheios_windows_hive_HKEY_CURRENT_CONFIG);
        XTESTS_RUN_CASE(TEST_pantheios_windows_hive_HKEY_DYN_DATA);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_windows_hive_HKEY_CLASSES_ROOT()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_CLASSES_ROOT));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    REQUIRE(TEST_INT_EQ(n, results.size()));
    TEST_STRING_EQ(PSTR("hive is HKEY_CLASSES_ROOT"), results[0].statement);
}

static void TEST_pantheios_windows_hive_HKEY_CURRENT_USER()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_CURRENT_USER));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    REQUIRE(TEST_INT_EQ(n, results.size()));
    TEST_STRING_EQ(PSTR("hive is HKEY_CURRENT_USER"), results[0].statement);
}

static void TEST_pantheios_windows_hive_HKEY_LOCAL_MACHINE()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_LOCAL_MACHINE));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    REQUIRE(TEST_INT_EQ(n, results.size()));
    TEST_STRING_EQ(PSTR("hive is HKEY_LOCAL_MACHINE"), results[0].statement);
}

static void TEST_pantheios_windows_hive_HKEY_USERS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    size_t n = 0;

    pantheios::log_NOTICE(PSTR("hive is "), pantheios::windows::hive(HKEY_USERS));
    n += 1;


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    REQUIRE(TEST_INT_EQ(n, results.size()));
    TEST_STRING_EQ(PSTR("hive is HKEY_USERS"), results[0].statement);
}

static void TEST_pantheios_windows_hive_HKEY_PERFORMANCE_DATA()
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

    TEST(!results.empty());
    REQUIRE(TEST_INT_EQ(n, results.size()));
    TEST_STRING_EQ(PSTR("hive is HKEY_PERFORMANCE_DATA"), results[0].statement);
#endif
}

static void TEST_pantheios_windows_hive_HKEY_CURRENT_CONFIG()
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

    TEST(!results.empty());
    REQUIRE(TEST_INT_EQ(n, results.size()));
    TEST_STRING_EQ(PSTR("hive is HKEY_CURRENT_CONFIG"), results[0].statement);
#endif
}

static void TEST_pantheios_windows_hive_HKEY_DYN_DATA()
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

    TEST(!results.empty());
    REQUIRE(TEST_INT_EQ(n, results.size()));
    TEST_STRING_EQ(PSTR("hive is HKEY_DYN_DATA"), results[0].statement);
#endif
}


/* ///////////////////////////// end of file //////////////////////////// */

