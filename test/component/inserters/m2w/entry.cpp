/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/m2w/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.m2w project.
 *
 * Created: 22nd November 2010
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS

#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/pantheios.h>
#ifndef PANTHEIOS_USE_WIDE_STRINGS
# error This program source only valid in wide string builds
#endif /* !PANTHEIOS_USE_WIDE_STRINGS */
#include <stlsoft/string/simple_string.hpp>
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/inserters/m2w.hpp>      // for pantheios::m2w
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

static void TEST_pantheios_m2w_C_STR_EMPTY();
static void TEST_pantheios_m2w_C_STR_SINGLE_CHAR();
static void TEST_pantheios_m2w_C_STR_THREE_CHARS_WITH_BRACKETS();
static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_04();
static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_05();
static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_06();
static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_07();
static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_08();
static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_09();

static void TEST_pantheios_m2w_STD_STRING_EMPTY();
static void TEST_pantheios_m2w_STD_STRING_SINGLE_CHAR();
static void TEST_pantheios_m2w_STD_STRING_THREE_CHARS_WITH_BRACKETS();
static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_04();
static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_05();
static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_06();
static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_07();
static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_08();
static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_09();

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY();
static void TEST_pantheios_m2w_SIMPLE_STRING_SINGLE_CHAR();
static void TEST_pantheios_m2w_SIMPLE_STRING_THREE_CHARS_WITH_BRACKETS();
static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_04();
static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_05();
static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_06();
static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_07();
static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_08();
static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_09();


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = L"test.component.inserters.m2w";

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inserters.m2w", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_EMPTY);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_SINGLE_CHAR);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_THREE_CHARS_WITH_BRACKETS);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_04);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_05);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_06);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_07);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_08);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_09);

        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_EMPTY);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_SINGLE_CHAR);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_THREE_CHARS_WITH_BRACKETS);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_04);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_05);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_06);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_07);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_08);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_09);

        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_EMPTY);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_SINGLE_CHAR);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_THREE_CHARS_WITH_BRACKETS);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_04);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_05);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_06);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_07);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_08);
        XTESTS_RUN_CASE(TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_09);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_m2w_C_STR_EMPTY()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_SINGLE_CHAR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w("a"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"a", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_THREE_CHARS_WITH_BRACKETS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(L"[", pantheios::m2w("abc"), L"]");


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"[abc]", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_04()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_05()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_06()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_07()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_08()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_C_STR_EMPTY_DUPLICATE_09()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_EMPTY()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_SINGLE_CHAR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("a")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"a", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_THREE_CHARS_WITH_BRACKETS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(L"[", pantheios::m2w(std::string("abc")), L"]");


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"[abc]", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_04()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_05()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_06()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_07()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_08()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_STD_STRING_EMPTY_DUPLICATE_09()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(std::string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_SINGLE_CHAR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("a")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"a", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_THREE_CHARS_WITH_BRACKETS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(L"[", pantheios::m2w(stlsoft::simple_string("abc")), L"]");


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"[abc]", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_04()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_05()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_06()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_07()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_08()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

static void TEST_pantheios_m2w_SIMPLE_STRING_EMPTY_DUPLICATE_09()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::m2w(stlsoft::simple_string("")));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_WS_EQ(L"", results[0].statement);
}

/* ///////////////////////////// end of file //////////////////////////// */

