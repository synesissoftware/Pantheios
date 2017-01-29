/* /////////////////////////////////////////////////////////////////////////
 * File:        test/component/test.component.inserters.slice/test.component.inserters.slice.cpp
 *
 * Purpose:     Implementation file for the test.component.inserters.slice project.
 *
 * Created:     14th February 2010
 * Updated:     27th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/inserters/slice.hpp>    // for pantheios::slice
#include <pantheios/backends/bec.test.h>

/* STLSOft header files */
#include <stlsoft/conversion/integer_to_string.hpp>

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

static void test_1_01();
static void test_1_02();
static void test_1_03();
static void test_1_04();
static void test_1_05();
static void test_1_06();
static void test_1_07();
static void test_1_08();
static void test_1_09();

#ifndef PANTHEIOS_NO_NAMESPACE
using pantheios::pan_char_t;
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.slice");

const pan_char_t alphabet[] = PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz");

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# define XTESTS_TEST_STRINGS_EQUAL_     XTESTS_TEST_WIDE_STRING_EQUAL
#else
# define XTESTS_TEST_STRINGS_EQUAL_     XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

typedef std::basic_string<pan_char_t>   string_t;

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.inserters.slice", verbosity))
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

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        XTESTS_TEST_STRINGS_EQUAL_(string_t(alphabet, i), results[i].statement);
    }}
}

static void test_1_02()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i, PANTHEIOS_LITERAL_STRING("str")));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        XTESTS_TEST_STRINGS_EQUAL_(PANTHEIOS_LITERAL_STRING("str=") + string_t(alphabet, i), results[i].statement);
    }}
}

static void test_1_03()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i, PANTHEIOS_LITERAL_STRING("str"), NULL, PANTHEIOS_LITERAL_STRING(":")));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        XTESTS_TEST_STRINGS_EQUAL_(PANTHEIOS_LITERAL_STRING("str:") + string_t(alphabet, i), results[i].statement);
    }}
}

static void test_1_04()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i, PANTHEIOS_LITERAL_STRING("str"), PANTHEIOS_LITERAL_STRING("len")));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pan_char_t num[21];

        XTESTS_TEST_STRINGS_EQUAL_(PANTHEIOS_LITERAL_STRING("str=") + string_t(alphabet, i) + PANTHEIOS_LITERAL_STRING(", len=") + stlsoft::integer_to_string(num, STLSOFT_NUM_ELEMENTS(num), i), results[i].statement);
    }}
}

static void test_1_05()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i, PANTHEIOS_LITERAL_STRING("str"), PANTHEIOS_LITERAL_STRING("len"), PANTHEIOS_LITERAL_STRING(":")));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pan_char_t num[21];

        XTESTS_TEST_STRINGS_EQUAL_(PANTHEIOS_LITERAL_STRING("str:") + string_t(alphabet, i) + PANTHEIOS_LITERAL_STRING(", len:") + stlsoft::integer_to_string(num, STLSOFT_NUM_ELEMENTS(num), i), results[i].statement);
    }}
}

static void test_1_06()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i, PANTHEIOS_LITERAL_STRING("str"), PANTHEIOS_LITERAL_STRING("len"), PANTHEIOS_LITERAL_STRING(":"), PANTHEIOS_LITERAL_STRING("; ")));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pan_char_t num[21];

        XTESTS_TEST_STRINGS_EQUAL_(PANTHEIOS_LITERAL_STRING("str:") + string_t(alphabet, i) + PANTHEIOS_LITERAL_STRING("; len:") + stlsoft::integer_to_string(num, STLSOFT_NUM_ELEMENTS(num), i), results[i].statement);
    }}
}

static void test_1_07()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i, PANTHEIOS_LITERAL_STRING("str"), PANTHEIOS_LITERAL_STRING("len"), PANTHEIOS_LITERAL_STRING(":"), PANTHEIOS_LITERAL_STRING(";")));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pan_char_t num[21];

        XTESTS_TEST_STRINGS_EQUAL_(PANTHEIOS_LITERAL_STRING("str:") + string_t(alphabet, i) + PANTHEIOS_LITERAL_STRING(";len:") + stlsoft::integer_to_string(num, STLSOFT_NUM_ELEMENTS(num), i), results[i].statement);
    }}
}

static void test_1_08()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pantheios::log_NOTICE(pantheios::slice(alphabet, i, PANTHEIOS_LITERAL_STRING("str"), PANTHEIOS_LITERAL_STRING("len"), NULL, PANTHEIOS_LITERAL_STRING(";")));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(27u, results.size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet); ++i)
    {
        pan_char_t num[21];

        XTESTS_TEST_STRINGS_EQUAL_(PANTHEIOS_LITERAL_STRING("str=") + string_t(alphabet, i) + PANTHEIOS_LITERAL_STRING(";len=") + stlsoft::integer_to_string(num, STLSOFT_NUM_ELEMENTS(num), i), results[i].statement);
    }}
}

static void test_1_09()
{
}

/* ///////////////////////////// end of file //////////////////////////// */
