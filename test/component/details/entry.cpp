/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/details/entry.cpp
 *
 * Purpose: Component test of details permutations.
 *
 * Created: 27th October 2024
 * Updated: 10th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/backends/bec.test.h>
#include <pantheios/frontends/stock.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.details");


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
 * typedefs
 */

typedef std::basic_string<PAN_CHAR_T>                       string_t;


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_01();
static void test_02();
/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.details", verbosity))
    {
        XTESTS_RUN_CASE(test_01);
        XTESTS_RUN_CASE(test_02);
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

static void test_01()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST_BOOLEAN_TRUE(results.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, results.size());
}

static void test_02()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log(pantheios::notice, PSTR("the message details"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST_BOOLEAN_FALSE(results.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, results.size());
    XTESTS_TEST_STRING_EQUAL(PSTR("the message details"), results[0].statement);
    XTESTS_TEST(pantheios::notice == results[0].severity);
}


/* ///////////////////////////// end of file //////////////////////////// */

