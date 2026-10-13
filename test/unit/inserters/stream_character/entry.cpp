/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/inserters/stream_character/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.inserter.stream_character project.
 *
 * Created: 9th May 2014
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>

#include <pantheios/inserters/stream_character.hpp>

#include <xtests/terse-api.h>

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

# define TEST_STRING_EQ                                     TEST_WS_EQ
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ
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

    TEST_PASSED();
}

static void test_plain_characters()
{
    static char const plain_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+[{]}|;:\",<.>/?";

    { for (size_t i = 0; STLSOFT_NUM_ELEMENTS(plain_characters) - 1 != i; ++i)
    {
        PAN_CHAR_T  ch      =   plain_characters[i];
        PAN_CHAR_T  sz[2]   =   { ch, '\0' };

        TEST_STRING_EQ(sz, pantheios::stream_character(ch));
    }}
}

static void test_special_characters_1()
{
    TEST_STRING_EQ(PSTR("NUL"), pantheios::stream_character(0));
    TEST_STRING_EQ(PSTR("SOH"), pantheios::stream_character(1));
    TEST_STRING_EQ(PSTR("STX"), pantheios::stream_character(2));
    TEST_STRING_EQ(PSTR("ETX"), pantheios::stream_character(3));
    TEST_STRING_EQ(PSTR("EOT"), pantheios::stream_character(4));
    TEST_STRING_EQ(PSTR("ENQ"), pantheios::stream_character(5));
    TEST_STRING_EQ(PSTR("ACK"), pantheios::stream_character(6));
    TEST_STRING_EQ(PSTR("BEL"), pantheios::stream_character(7));
    TEST_STRING_EQ(PSTR("BS"), pantheios::stream_character(8));
    TEST_STRING_EQ(PSTR("HT"), pantheios::stream_character(9));
    TEST_STRING_EQ(PSTR("LF"), pantheios::stream_character(10));
    TEST_STRING_EQ(PSTR("VT"), pantheios::stream_character(11));
    TEST_STRING_EQ(PSTR("FF"), pantheios::stream_character(12));
    TEST_STRING_EQ(PSTR("CR"), pantheios::stream_character(13));
    TEST_STRING_EQ(PSTR("SO"), pantheios::stream_character(14));
    TEST_STRING_EQ(PSTR("SI"), pantheios::stream_character(15));
    TEST_STRING_EQ(PSTR("DLE"), pantheios::stream_character(16));
    TEST_STRING_EQ(PSTR("DC1"), pantheios::stream_character(17));
    TEST_STRING_EQ(PSTR("DC2"), pantheios::stream_character(18));
    TEST_STRING_EQ(PSTR("DC3"), pantheios::stream_character(19));
    TEST_STRING_EQ(PSTR("DC4"), pantheios::stream_character(20));
    TEST_STRING_EQ(PSTR("NAK"), pantheios::stream_character(21));
    TEST_STRING_EQ(PSTR("SYN"), pantheios::stream_character(22));
    TEST_STRING_EQ(PSTR("ETB"), pantheios::stream_character(23));
    TEST_STRING_EQ(PSTR("CAN"), pantheios::stream_character(24));
    TEST_STRING_EQ(PSTR("EM"), pantheios::stream_character(25));
    TEST_STRING_EQ(PSTR("SUB"), pantheios::stream_character(26));
    TEST_STRING_EQ(PSTR("ESC"), pantheios::stream_character(27));
    TEST_STRING_EQ(PSTR("FS"), pantheios::stream_character(28));
    TEST_STRING_EQ(PSTR("GS"), pantheios::stream_character(29));
    TEST_STRING_EQ(PSTR("RS"), pantheios::stream_character(30));
    TEST_STRING_EQ(PSTR("US"), pantheios::stream_character(31));

    TEST_STRING_EQ(PSTR("DEL"), pantheios::stream_character(127));
}

} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

