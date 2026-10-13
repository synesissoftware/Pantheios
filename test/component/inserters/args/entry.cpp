/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/args/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.args project.
 *
 * Created: 19th October 2006
 * Updated: 14th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>      // Pantheios C++ main header
#include <pantheios/inserters/args.hpp> // for pantheios::args
#include <pantheios/backends/bec.test.h>

/* Standard C++ header files */
#include <exception>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

#ifndef PANTHEIOS_USE_WIDE_STRINGS

static void TEST_pantheios_args_EMPTY_NULL_argv();
static void TEST_pantheios_args_ONE_ARG();
static void TEST_pantheios_args_TWO_ARGS();
static void TEST_pantheios_args_FOUR_ARGS();
static void TEST_pantheios_args_alwaysQuoteArgs();
static void TEST_pantheios_args_neverQuoteArgs_WITH_SPACES();
static void TEST_pantheios_args_quoteArgsWithSpaces();
static void TEST_pantheios_args_alwaysQuoteArgs_WITH_SPACES();
static void TEST_pantheios_args_EMPTY_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_ONE_ARG_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_TWO_ARGS_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_FOUR_ARGS_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_alwaysQuoteArgs_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_neverQuoteArgs_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_quoteArgsWithSpaces_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_alwaysQuoteArgs_WITH_SPACES_CUSTOM_SEPARATOR();
static void TEST_pantheios_args_ONE_ARG_WITH_ARG0_HAVING_DIRECTORY();
static void TEST_pantheios_args_ONE_ARG_WITH_ARG0_HAVING_DIRECTORY_arg0FileOnly();
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.args");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inserters.args", verbosity))
    {
#ifndef PANTHEIOS_USE_WIDE_STRINGS

        XTESTS_RUN_CASE(TEST_pantheios_args_EMPTY_NULL_argv);
        XTESTS_RUN_CASE(TEST_pantheios_args_ONE_ARG);
        XTESTS_RUN_CASE(TEST_pantheios_args_TWO_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_args_FOUR_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_args_alwaysQuoteArgs);
        XTESTS_RUN_CASE(TEST_pantheios_args_neverQuoteArgs_WITH_SPACES);
        XTESTS_RUN_CASE(TEST_pantheios_args_quoteArgsWithSpaces);
        XTESTS_RUN_CASE(TEST_pantheios_args_alwaysQuoteArgs_WITH_SPACES);
        XTESTS_RUN_CASE(TEST_pantheios_args_EMPTY_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_ONE_ARG_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_TWO_ARGS_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_FOUR_ARGS_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_alwaysQuoteArgs_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_neverQuoteArgs_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_quoteArgsWithSpaces_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_alwaysQuoteArgs_WITH_SPACES_CUSTOM_SEPARATOR);
        XTESTS_RUN_CASE(TEST_pantheios_args_ONE_ARG_WITH_ARG0_HAVING_DIRECTORY);
        XTESTS_RUN_CASE(TEST_pantheios_args_ONE_ARG_WITH_ARG0_HAVING_DIRECTORY_arg0FileOnly);
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef PANTHEIOS_USE_WIDE_STRINGS

static void TEST_pantheios_args_EMPTY_NULL_argv()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::args(0, static_cast<char**>(NULL)));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("", results[0].statement);
}

static void TEST_pantheios_args_ONE_ARG()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
       "abc"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc", results[0].statement);
}

static void TEST_pantheios_args_TWO_ARGS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc, def", results[0].statement);
}

static void TEST_pantheios_args_FOUR_ARGS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def"
        ,   "ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc, def, ghi, jkl", results[0].statement);
}

static void TEST_pantheios_args_alwaysQuoteArgs()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def"
        ,   "ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::alwaysQuoteArgs));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("\"abc\", \"def\", \"ghi\", \"jkl\"", results[0].statement);
}

static void TEST_pantheios_args_neverQuoteArgs_WITH_SPACES()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::neverQuoteArgs));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc, def ghi, jkl", results[0].statement);
}

static void TEST_pantheios_args_quoteArgsWithSpaces()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::quoteArgsWithSpaces));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc, \"def ghi\", jkl", results[0].statement);
}

static void TEST_pantheios_args_alwaysQuoteArgs_WITH_SPACES()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::alwaysQuoteArgs));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("\"abc\", \"def ghi\", \"jkl\"", results[0].statement);
}


static void TEST_pantheios_args_EMPTY_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::args(0, static_cast<char**>(NULL), pantheios::args::quoteArgsWithSpaces, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("", results[0].statement);
}

static void TEST_pantheios_args_ONE_ARG_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
       "abc"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::quoteArgsWithSpaces, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc", results[0].statement);
}

static void TEST_pantheios_args_TWO_ARGS_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::quoteArgsWithSpaces, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc|def", results[0].statement);
}

static void TEST_pantheios_args_FOUR_ARGS_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def"
        ,   "ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::quoteArgsWithSpaces, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc|def|ghi|jkl", results[0].statement);
}

static void TEST_pantheios_args_alwaysQuoteArgs_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def"
        ,   "ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::alwaysQuoteArgs, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("\"abc\"|\"def\"|\"ghi\"|\"jkl\"", results[0].statement);
}

static void TEST_pantheios_args_neverQuoteArgs_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::neverQuoteArgs, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc|def ghi|jkl", results[0].statement);
}

static void TEST_pantheios_args_quoteArgsWithSpaces_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::quoteArgsWithSpaces, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc|\"def ghi\"|jkl", results[0].statement);
}

static void TEST_pantheios_args_alwaysQuoteArgs_WITH_SPACES_CUSTOM_SEPARATOR()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
            "abc"
        ,   "def ghi"
        ,   "jkl"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::alwaysQuoteArgs, "|"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("\"abc\"|\"def ghi\"|\"jkl\"", results[0].statement);
}

static void TEST_pantheios_args_ONE_ARG_WITH_ARG0_HAVING_DIRECTORY()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
       "dir1/dir2/abc"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("dir1/dir2/abc", results[0].statement);
}

static void TEST_pantheios_args_ONE_ARG_WITH_ARG0_HAVING_DIRECTORY_arg0FileOnly()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    char const* argv[] =
    {
       "dir1/dir2/abc"
    };

    pantheios::log_NOTICE(pantheios::args(STLSOFT_NUM_ELEMENTS(argv), argv, pantheios::args::arg0FileOnly));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(1, results.size());
    TEST_MS_EQ("abc", results[0].statement);
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* ///////////////////////////// end of file //////////////////////////// */

