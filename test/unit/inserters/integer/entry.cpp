/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/inserters/integer/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.inserter.integer project.
 *
 * Created: 21st December 2010
 * Updated: 10th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>

#include <pantheios/inserters/integer.hpp>

#include <xtests/xtests.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void test_1_01();
static void test_1_02();
static void test_1_03();
static void test_1_04();
static void test_1_06();
} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

#define PSTR(x)                         PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.inserter.integer");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.inserter.integer", verbosity))
    {
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{

static void test_1_01()
{
    XTESTS_TEST_STRING_EQUAL(PSTR("0"), pantheios::integer(0));
}

static void test_1_02()
{
    XTESTS_TEST_STRING_EQUAL(PSTR("-1"), pantheios::integer(-1));
    XTESTS_TEST_STRING_EQUAL(PSTR( "1"), pantheios::integer(+1));
}

static void test_1_03()
{
    XTESTS_TEST_STRING_EQUAL(PSTR("-1"), pantheios::integer(-1, 0, 0));
    XTESTS_TEST_STRING_EQUAL(PSTR( "1"), pantheios::integer(+1, 0, 0));
}

static void test_1_04()
{
    XTESTS_TEST_STRING_EQUAL(PSTR("+0"), pantheios::integer( 0, 0, pantheios::fmt::showPlus));
    XTESTS_TEST_STRING_EQUAL(PSTR("-1"), pantheios::integer(-1, 0, pantheios::fmt::showPlus));
    XTESTS_TEST_STRING_EQUAL(PSTR("+1"), pantheios::integer(+1, 0, pantheios::fmt::showPlus));
}


static void test_1_06()
{
    XTESTS_TEST_STRING_EQUAL(PSTR("-1"), pantheios::integer(-1));
//    XTESTS_TEST_STRING_EQUAL(PSTR("+1"), pantheios::integer(+1));
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

