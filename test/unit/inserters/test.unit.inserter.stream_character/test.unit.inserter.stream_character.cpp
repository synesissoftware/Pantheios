/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/inserters/test.unit.inserter.stream_character/test.unit.inserter.stream_character.cpp
 *
 * Purpose: Implementation file for the test.unit.inserter.stream_character project.
 *
 * Created: 9th May 2014
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>

#include <pantheios/inserters/stream_character.hpp>

#include <xtests/xtests.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_type_exists();
    static void test_plain_characters();
    static void test_special_characters_1();
} /* anonymous namespace */


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
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.inserter.stream_character");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.inserter.stream_character", verbosity))
    {
        XTESTS_RUN_CASE(test_type_exists);
        XTESTS_RUN_CASE(test_plain_characters);
        XTESTS_RUN_CASE(test_special_characters_1);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void test_type_exists()
{
    STLSOFT_SUPPRESS_UNUSED(typeid(pantheios::stream_character));

    XTESTS_TEST_PASSED();
}

static void test_plain_characters()
{
    static char const plain_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+[{]}|;:\",<.>/?";

    { for (size_t i = 0; STLSOFT_NUM_ELEMENTS(plain_characters) - 1 != i; ++i)
    {
        PAN_CHAR_T  ch      =   plain_characters[i];
        PAN_CHAR_T  sz[2]   =   { ch, '\0' };

        XTESTS_TEST_STRING_EQUAL(sz, pantheios::stream_character(ch));
    }}
}

static void test_special_characters_1()
{
    XTESTS_TEST_STRING_EQUAL(PSTR("NUL"), pantheios::stream_character(0));
    XTESTS_TEST_STRING_EQUAL(PSTR("SOH"), pantheios::stream_character(1));
    XTESTS_TEST_STRING_EQUAL(PSTR("STX"), pantheios::stream_character(2));
    XTESTS_TEST_STRING_EQUAL(PSTR("ETX"), pantheios::stream_character(3));
    XTESTS_TEST_STRING_EQUAL(PSTR("EOT"), pantheios::stream_character(4));
    XTESTS_TEST_STRING_EQUAL(PSTR("ENQ"), pantheios::stream_character(5));
    XTESTS_TEST_STRING_EQUAL(PSTR("ACK"), pantheios::stream_character(6));
    XTESTS_TEST_STRING_EQUAL(PSTR("BEL"), pantheios::stream_character(7));
    XTESTS_TEST_STRING_EQUAL(PSTR("BS"), pantheios::stream_character(8));
    XTESTS_TEST_STRING_EQUAL(PSTR("HT"), pantheios::stream_character(9));
    XTESTS_TEST_STRING_EQUAL(PSTR("LF"), pantheios::stream_character(10));
    XTESTS_TEST_STRING_EQUAL(PSTR("VT"), pantheios::stream_character(11));
    XTESTS_TEST_STRING_EQUAL(PSTR("FF"), pantheios::stream_character(12));
    XTESTS_TEST_STRING_EQUAL(PSTR("CR"), pantheios::stream_character(13));
    XTESTS_TEST_STRING_EQUAL(PSTR("SO"), pantheios::stream_character(14));
    XTESTS_TEST_STRING_EQUAL(PSTR("SI"), pantheios::stream_character(15));
    XTESTS_TEST_STRING_EQUAL(PSTR("DLE"), pantheios::stream_character(16));
    XTESTS_TEST_STRING_EQUAL(PSTR("DC1"), pantheios::stream_character(17));
    XTESTS_TEST_STRING_EQUAL(PSTR("DC2"), pantheios::stream_character(18));
    XTESTS_TEST_STRING_EQUAL(PSTR("DC3"), pantheios::stream_character(19));
    XTESTS_TEST_STRING_EQUAL(PSTR("DC4"), pantheios::stream_character(20));
    XTESTS_TEST_STRING_EQUAL(PSTR("NAK"), pantheios::stream_character(21));
    XTESTS_TEST_STRING_EQUAL(PSTR("SYN"), pantheios::stream_character(22));
    XTESTS_TEST_STRING_EQUAL(PSTR("ETB"), pantheios::stream_character(23));
    XTESTS_TEST_STRING_EQUAL(PSTR("CAN"), pantheios::stream_character(24));
    XTESTS_TEST_STRING_EQUAL(PSTR("EM"), pantheios::stream_character(25));
    XTESTS_TEST_STRING_EQUAL(PSTR("SUB"), pantheios::stream_character(26));
    XTESTS_TEST_STRING_EQUAL(PSTR("ESC"), pantheios::stream_character(27));
    XTESTS_TEST_STRING_EQUAL(PSTR("FS"), pantheios::stream_character(28));
    XTESTS_TEST_STRING_EQUAL(PSTR("GS"), pantheios::stream_character(29));
    XTESTS_TEST_STRING_EQUAL(PSTR("RS"), pantheios::stream_character(30));
    XTESTS_TEST_STRING_EQUAL(PSTR("US"), pantheios::stream_character(31));

    XTESTS_TEST_STRING_EQUAL(PSTR("DEL"), pantheios::stream_character(127));
}

} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

