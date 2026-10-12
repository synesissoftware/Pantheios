/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/stream_character/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.stream_character project.
 *
 * Created: 9th May 2014
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

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

static void TEST_pantheios_stream_character_PLAIN_CHARACTERS();
static void TEST_pantheios_stream_character_SPECIAL_CHARACTERS();
/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.stream_character");


/* ////////////////////////////////////////////////////////////////////// */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inserters.stream_character", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_stream_character_PLAIN_CHARACTERS);
        XTESTS_RUN_CASE(TEST_pantheios_stream_character_SPECIAL_CHARACTERS);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_stream_character_PLAIN_CHARACTERS()
{
    static char const plain_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+[{]}|;:\",<.>/?";

    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    { for (size_t i = 0; STLSOFT_NUM_ELEMENTS(plain_characters) - 1 != i; ++i)
    {
        PAN_CHAR_T const ch = plain_characters[i];

        pantheios::log_NOTICE(PSTR("{"), pantheios::stream_character(ch), PSTR("}"));
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(plain_characters) - 1, results.size());

    { for (size_t i = 0; STLSOFT_NUM_ELEMENTS(plain_characters) - 1 != i; ++i)
    {
        PAN_CHAR_T const    ch      =   plain_characters[i];
        PAN_CHAR_T          sz[4]   =   { '{', ch, '}', '\0' };

        TEST_STRING_EQ(sz, results[i].statement);
    }}
}

static void TEST_pantheios_stream_character_SPECIAL_CHARACTERS()
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

    TEST(!results.empty());
    TEST_INT_EQ(33u, results.size());

    TEST_STRING_EQ(PSTR("{NUL}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{SOH}"), results[1].statement);
    TEST_STRING_EQ(PSTR("{STX}"), results[2].statement);
    TEST_STRING_EQ(PSTR("{ETX}"), results[3].statement);
    TEST_STRING_EQ(PSTR("{EOT}"), results[4].statement);
    TEST_STRING_EQ(PSTR("{ENQ}"), results[5].statement);
    TEST_STRING_EQ(PSTR("{ACK}"), results[6].statement);
    TEST_STRING_EQ(PSTR("{BEL}"), results[7].statement);
    TEST_STRING_EQ(PSTR("{BS}"), results[8].statement);
    TEST_STRING_EQ(PSTR("{HT}"), results[9].statement);
    TEST_STRING_EQ(PSTR("{LF}"), results[10].statement);
    TEST_STRING_EQ(PSTR("{VT}"), results[11].statement);
    TEST_STRING_EQ(PSTR("{FF}"), results[12].statement);
    TEST_STRING_EQ(PSTR("{CR}"), results[13].statement);
    TEST_STRING_EQ(PSTR("{SO}"), results[14].statement);
    TEST_STRING_EQ(PSTR("{SI}"), results[15].statement);
    TEST_STRING_EQ(PSTR("{DLE}"), results[16].statement);
    TEST_STRING_EQ(PSTR("{DC1}"), results[17].statement);
    TEST_STRING_EQ(PSTR("{DC2}"), results[18].statement);
    TEST_STRING_EQ(PSTR("{DC3}"), results[19].statement);
    TEST_STRING_EQ(PSTR("{DC4}"), results[20].statement);
    TEST_STRING_EQ(PSTR("{NAK}"), results[21].statement);
    TEST_STRING_EQ(PSTR("{SYN}"), results[22].statement);
    TEST_STRING_EQ(PSTR("{ETB}"), results[23].statement);
    TEST_STRING_EQ(PSTR("{CAN}"), results[24].statement);
    TEST_STRING_EQ(PSTR("{EM}"), results[25].statement);
    TEST_STRING_EQ(PSTR("{SUB}"), results[26].statement);
    TEST_STRING_EQ(PSTR("{ESC}"), results[27].statement);
    TEST_STRING_EQ(PSTR("{FS}"), results[28].statement);
    TEST_STRING_EQ(PSTR("{GS}"), results[29].statement);
    TEST_STRING_EQ(PSTR("{RS}"), results[30].statement);
    TEST_STRING_EQ(PSTR("{US}"), results[31].statement);

    TEST_STRING_EQ(PSTR("{DEL}"), results[32].statement);
}


/* ///////////////////////////// end of file //////////////////////////// */

