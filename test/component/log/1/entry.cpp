/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/log/1/entry.cpp
 *
 * Purpose: Implementation file for the test.component.log.1 project.
 *
 * Created: 25th November 2007
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/backends/bec.test.h>
#include <pantheios/frontends/stock.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.log.1");


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
 * typedefs
 */

typedef std::basic_string<PAN_CHAR_T>                       string_t;


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_pantheios_log_NO_STATEMENTS();
static void TEST_pantheios_log_EMPTY_STRING();
static void TEST_pantheios_log_SINGLE_STRING();
static void TEST_pantheios_log_TWO_STRINGS();
static void TEST_pantheios_log_THREE_STRINGS();
static void TEST_pantheios_log_TWELVE_STRINGS_ALPHABET();
static void TEST_pantheios_log_TWENTY_SIX_SINGLE_CHARS();
static void TEST_pantheios_log_TWO_STATEMENTS_LOWER_AND_UPPER();
static void TEST_pantheios_log_MANY_STATEMENTS();
static void TEST_pantheios_log_TWO_LARGE_STRINGS_256();
static void TEST_pantheios_log_TWO_LARGE_STRINGS_2560();
/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.log.1", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_log_NO_STATEMENTS);
        XTESTS_RUN_CASE(TEST_pantheios_log_EMPTY_STRING);
        XTESTS_RUN_CASE(TEST_pantheios_log_SINGLE_STRING);
        XTESTS_RUN_CASE(TEST_pantheios_log_TWO_STRINGS);
        XTESTS_RUN_CASE(TEST_pantheios_log_THREE_STRINGS);
        XTESTS_RUN_CASE(TEST_pantheios_log_TWELVE_STRINGS_ALPHABET);
        XTESTS_RUN_CASE(TEST_pantheios_log_TWENTY_SIX_SINGLE_CHARS);
        XTESTS_RUN_CASE(TEST_pantheios_log_TWO_STATEMENTS_LOWER_AND_UPPER);
        XTESTS_RUN_CASE(TEST_pantheios_log_MANY_STATEMENTS);
        XTESTS_RUN_CASE(TEST_pantheios_log_TWO_LARGE_STRINGS_256);
        XTESTS_RUN_CASE(TEST_pantheios_log_TWO_LARGE_STRINGS_2560);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }
    else
    {
        retCode = EXIT_FAILURE;
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_log_NO_STATEMENTS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_BOOLEAN_TRUE(results.empty());
    TEST_INT_EQ(0u, results.size());
}

static void TEST_pantheios_log_EMPTY_STRING()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice, PSTR(""));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_BOOLEAN_FALSE(results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(PSTR(""), results[0].statement);
    TEST(pantheios::notice == results[0].severity);
}

static void TEST_pantheios_log_SINGLE_STRING()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice, PSTR("abc"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_BOOLEAN_FALSE(results.empty());
    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(PSTR("abc"), results[0].statement);
    TEST(pantheios::notice == results[0].severity);
}

static void TEST_pantheios_log_TWO_STRINGS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::informational, PSTR("abc"), PSTR("def"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(PSTR("abcdef"), results[0].statement);
    TEST(pantheios::informational == results[0].severity);
}

static void TEST_pantheios_log_THREE_STRINGS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::informational, PSTR("abc"), PSTR("def"), PSTR("ghi"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(PSTR("abcdefghi"), results[0].statement);
    TEST(pantheios::informational == results[0].severity);
}

static void TEST_pantheios_log_TWELVE_STRINGS_ALPHABET()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::informational, PSTR("abc"), PSTR("def"), PSTR("ghi"), PSTR("jk"), PSTR("lm"), PSTR("no"), PSTR("pq"), PSTR("rs"), PSTR("tu"), PSTR("vw"), PSTR("xy"), PSTR("z"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(PSTR("abcdefghijklmnopqrstuvwxyz"), results[0].statement);
    TEST(pantheios::informational == results[0].severity);
}

static void TEST_pantheios_log_TWENTY_SIX_SINGLE_CHARS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::informational, PSTR("a"), PSTR("b"), PSTR("c"), PSTR("d"), PSTR("e"), PSTR("f"), PSTR("g"), PSTR("h"), PSTR("i"), PSTR("j"), PSTR("k"), PSTR("l"), PSTR("m"), PSTR("n"), PSTR("o"), PSTR("p"), PSTR("q"), PSTR("r"), PSTR("s"), PSTR("t"), PSTR("u"), PSTR("v"), PSTR("w"), PSTR("x"), PSTR("y"), PSTR("z"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(PSTR("abcdefghijklmnopqrstuvwxyz"), results[0].statement);
    TEST(pantheios::informational == results[0].severity);
}


static void TEST_pantheios_log_TWO_STATEMENTS_LOWER_AND_UPPER()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::informational, PSTR("a"), PSTR("b"), PSTR("c"), PSTR("d"), PSTR("e"), PSTR("f"), PSTR("g"), PSTR("h"), PSTR("i"), PSTR("j"), PSTR("k"), PSTR("l"), PSTR("m"), PSTR("n"), PSTR("o"), PSTR("p"), PSTR("q"), PSTR("r"), PSTR("s"), PSTR("t"), PSTR("u"), PSTR("v"), PSTR("w"), PSTR("x"), PSTR("y"), PSTR("z"));
    pantheios::log(pantheios::informational, PSTR("A"), PSTR("B"), PSTR("C"), PSTR("D"), PSTR("E"), PSTR("F"), PSTR("G"), PSTR("H"), PSTR("I"), PSTR("J"), PSTR("K"), PSTR("L"), PSTR("M"), PSTR("N"), PSTR("O"), PSTR("P"), PSTR("Q"), PSTR("R"), PSTR("S"), PSTR("T"), PSTR("U"), PSTR("V"), PSTR("W"), PSTR("X"), PSTR("Y"), PSTR("Z"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(2u, results.size());
    TEST_STRING_EQ(PSTR("abcdefghijklmnopqrstuvwxyz"), results[0].statement);
    TEST_STRING_EQ(PSTR("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), results[1].statement);
}

static void TEST_pantheios_log_MANY_STATEMENTS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    const size_t    numEntries  =   1000;

    { for (size_t i = 0; i < numEntries; ++i)
    {
        if (0 == (i % 2))
        {
            pantheios::log(pantheios::informational, PSTR("a"), PSTR("b"), PSTR("c"), PSTR("d"), PSTR("e"), PSTR("f"), PSTR("g"), PSTR("h"), PSTR("i"), PSTR("j"), PSTR("k"), PSTR("l"), PSTR("m"), PSTR("n"), PSTR("o"), PSTR("p"), PSTR("q"), PSTR("r"), PSTR("s"), PSTR("t"), PSTR("u"), PSTR("v"), PSTR("w"), PSTR("x"), PSTR("y"), PSTR("z"));
        }
        else
        {
            pantheios::log(pantheios::informational, PSTR("A"), PSTR("B"), PSTR("C"), PSTR("D"), PSTR("E"), PSTR("F"), PSTR("G"), PSTR("H"), PSTR("I"), PSTR("J"), PSTR("K"), PSTR("L"), PSTR("M"), PSTR("N"), PSTR("O"), PSTR("P"), PSTR("Q"), PSTR("R"), PSTR("S"), PSTR("T"), PSTR("U"), PSTR("V"), PSTR("W"), PSTR("X"), PSTR("Y"), PSTR("Z"));
        }
    }}


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(numEntries, results.size());
    { for (size_t i = 0; i < numEntries; ++i)
    {
        if (0 == (i % 2))
        {
            TEST_STRING_EQ(PSTR("abcdefghijklmnopqrstuvwxyz"), results[i].statement);
        }
        else
        {
            TEST_STRING_EQ(PSTR("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), results[i].statement);
        }
    }}
}


static void TEST_pantheios_log_TWO_LARGE_STRINGS_256()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    string_t msgEl1(256, '~');
    string_t msgEl2(4096, '#');


    pantheios::log(pantheios::informational, msgEl1, msgEl2);


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(msgEl1 + msgEl2, results[0].statement);
    TEST(pantheios::informational == results[0].severity);
}

static void TEST_pantheios_log_TWO_LARGE_STRINGS_2560()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    string_t msgEl1(2560, '~');
    string_t msgEl2(40960, '#');

    pantheios::log(pantheios::informational, msgEl1, msgEl2);


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST_INT_EQ(1u, results.size());
    TEST_STRING_EQ(msgEl1 + msgEl2, results[0].statement);
    TEST(pantheios::informational == results[0].severity);
}


/* ///////////////////////////// end of file //////////////////////////// */

