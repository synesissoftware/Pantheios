/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/real/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.real project.
 *
 * Created: 19th October 2006
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/inserters/real.hpp>     // for pantheios::real
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

static void TEST_pantheios_real_ZERO_float_double_long_double();
static void TEST_pantheios_real_SIGNED_AND_SMALL_MAGNITUDE();
/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.real");


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
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inserters.real", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_real_ZERO_float_double_long_double);
        XTESTS_RUN_CASE(TEST_pantheios_real_SIGNED_AND_SMALL_MAGNITUDE);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_real_ZERO_float_double_long_double()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::real(static_cast<float>(0)));
    pantheios::log_NOTICE(pantheios::real(static_cast<double>(0)));
    pantheios::log_NOTICE(pantheios::real(static_cast<long double>(0)));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(3, results.size());
    TEST_STRING_EQ(PSTR("0"), results[0].statement);
    TEST_STRING_EQ(PSTR("0"), results[1].statement);
    TEST_STRING_EQ(PSTR("0"), results[2].statement);
}

static void TEST_pantheios_real_SIGNED_AND_SMALL_MAGNITUDE()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::real(+1.1));
    pantheios::log_NOTICE(pantheios::real(-1.1));
    pantheios::log_NOTICE(pantheios::real(+0.0000001));
    pantheios::log_NOTICE(pantheios::real(-0.0000001));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(4, results.size());
    TEST_STRING_EQ(PSTR("1.1"), results[0].statement);
    TEST_STRING_EQ(PSTR("-1.1"), results[1].statement);
//    TEST_STRING_EQ(PSTR("0.0000001"), results[2].statement);
//    TEST_STRING_EQ(PSTR("-0.0000001"), results[3].statement);
}


/* ///////////////////////////// end of file //////////////////////////// */

