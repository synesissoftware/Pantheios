/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/inserters/integer/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.inserter.integer project.
 *
 * Created: 21st December 2010
 * Updated: 29th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>

#include <pantheios/inserters/integer.hpp>

#include <xtests/terse-api.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void TEST_pantheios_integer_ZERO();
static void TEST_pantheios_integer_SIGNED_ONES();
static void TEST_pantheios_integer_SIGNED_ONES_WITH_ZERO_WIDTH_AND_FLAGS();
static void TEST_pantheios_integer_showPlus();
static void TEST_pantheios_integer_NEGATIVE_ONE();
} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

#define PSTR(x)                         PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.inserter.integer");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.inserters.integer", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_integer_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_integer_SIGNED_ONES);
        XTESTS_RUN_CASE(TEST_pantheios_integer_SIGNED_ONES_WITH_ZERO_WIDTH_AND_FLAGS);
        XTESTS_RUN_CASE(TEST_pantheios_integer_showPlus);
        XTESTS_RUN_CASE(TEST_pantheios_integer_NEGATIVE_ONE);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{

static void TEST_pantheios_integer_ZERO()
{
    TEST_STRING_EQ(PSTR("0"), pantheios::integer(0));
}

static void TEST_pantheios_integer_SIGNED_ONES()
{
    TEST_STRING_EQ(PSTR("-1"), pantheios::integer(-1));
    TEST_STRING_EQ(PSTR( "1"), pantheios::integer(+1));
}

static void TEST_pantheios_integer_SIGNED_ONES_WITH_ZERO_WIDTH_AND_FLAGS()
{
    TEST_STRING_EQ(PSTR("-1"), pantheios::integer(-1, 0, 0));
    TEST_STRING_EQ(PSTR( "1"), pantheios::integer(+1, 0, 0));
}

static void TEST_pantheios_integer_showPlus()
{
    TEST_STRING_EQ(PSTR("+0"), pantheios::integer( 0, 0, pantheios::fmt::showPlus));
    TEST_STRING_EQ(PSTR("-1"), pantheios::integer(-1, 0, pantheios::fmt::showPlus));
    TEST_STRING_EQ(PSTR("+1"), pantheios::integer(+1, 0, pantheios::fmt::showPlus));
}


static void TEST_pantheios_integer_NEGATIVE_ONE()
{
    TEST_STRING_EQ(PSTR("-1"), pantheios::integer(-1));
//    TEST_STRING_EQ(PSTR("+1"), pantheios::integer(+1));
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

