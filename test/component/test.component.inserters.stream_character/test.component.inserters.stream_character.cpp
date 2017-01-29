/* /////////////////////////////////////////////////////////////////////////
 * File:        test/component/test.component.inserters.stream_character/test.component.inserters.stream_character.cpp
 *
 * Purpose:     Implementation file for the test.component.inserters.stream_character project.
 *
 * Created:     9th May 2014
 * Updated:     27th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014-2017, Synesis Software Pty Ltd.
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
#include <pantheios/inserters/stream_character.hpp>  // for pantheios::stream_character
#include <pantheios/backends/bec.test.h>

/* STLSoft header files */
#include <stlsoft/util/limit_traits.h>

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

static void test_plain_characters();
static void test_special_characters_1();
static void test_1_03();
static void test_1_04();
static void test_1_05();
static void test_1_06();
static void test_1_07();
static void test_1_08();
static void test_1_09();
static void test_1_10();

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.stream_character");

/* ////////////////////////////////////////////////////////////////////// */

#define PSTR(x)         PANTHEIOS_LITERAL_STRING(x)

/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL       XTESTS_TEST_WIDE_STRING_EQUAL

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL       XTESTS_TEST_MULTIBYTE_STRING_EQUAL

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.inserters.integer", verbosity))
    {
        XTESTS_RUN_CASE(test_plain_characters);
        XTESTS_RUN_CASE(test_special_characters_1);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_RUN_CASE(test_1_07);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);
        XTESTS_RUN_CASE(test_1_10);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

static void test_plain_characters()
{
    static char const plain_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+[{]}|;:\",<.>/?";

    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for(size_t i = 0; STLSOFT_NUM_ELEMENTS(plain_characters) - 1 != i; ++i)
    {
        PAN_CHAR_T const ch = plain_characters[i];

        pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(ch), PSTR("}"));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(plain_characters) - 1, results.size());

    { for(size_t i = 0; STLSOFT_NUM_ELEMENTS(plain_characters) - 1 != i; ++i)
    {
        PAN_CHAR_T const    ch      =   plain_characters[i];
        PAN_CHAR_T          sz[4]   =   { '{', ch, '}', '\0' };

        XTESTS_TEST_STRING_EQUAL(sz, results[i].statement);
    }}
}

static void test_special_characters_1()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(0), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(1), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(2), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(3), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(4), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(5), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(6), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(7), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(8), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(9), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(10), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(11), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(12), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(13), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(14), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(15), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(16), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(17), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(18), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(19), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(20), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(21), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(22), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(23), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(24), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(25), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(26), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(27), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(28), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(29), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(30), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(31), PSTR("}"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(127), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_TEST_INTEGER_EQUAL(33u, results.size());

    XTESTS_TEST_STRING_EQUAL(PSTR("{NUL}"), results[0].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{SOH}"), results[1].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{STX}"), results[2].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{ETX}"), results[3].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{EOT}"), results[4].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{ENQ}"), results[5].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{ACK}"), results[6].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{BEL}"), results[7].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{BS}"), results[8].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{HT}"), results[9].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{LF}"), results[10].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{VT}"), results[11].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{FF}"), results[12].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{CR}"), results[13].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{SO}"), results[14].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{SI}"), results[15].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{DLE}"), results[16].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{DC1}"), results[17].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{DC2}"), results[18].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{DC3}"), results[19].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{DC4}"), results[20].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{NAK}"), results[21].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{SYN}"), results[22].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{ETB}"), results[23].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{CAN}"), results[24].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{EM}"), results[25].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{SUB}"), results[26].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{ESC}"), results[27].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{FS}"), results[28].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{GS}"), results[29].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{RS}"), results[30].statement);
    XTESTS_TEST_STRING_EQUAL(PSTR("{US}"), results[31].statement);

    XTESTS_TEST_STRING_EQUAL(PSTR("{DEL}"), results[32].statement);
}

static void test_1_03()
{
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

static void test_1_10()
{
}

/* ///////////////////////////// end of file //////////////////////////// */
