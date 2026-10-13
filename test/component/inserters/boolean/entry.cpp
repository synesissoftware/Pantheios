/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/boolean/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.boolean project.
 *
 * Created: 7th August 2008
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/inserters/boolean.hpp>  // for pantheios::boolean
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

static void TEST_pantheios_boolean_DEFAULT_false_true();
static void TEST_pantheios_boolean_set_value_strings_NULL_RESTORES_DEFAULT();
static void TEST_pantheios_boolean_set_value_strings_FALSE_TRUE();
static void TEST_pantheios_boolean_CUSTOM_THEN_RESTORE_DEFAULT();
static void TEST_pantheios_boolean_LONG_FALSE_STRING_THEN_RESTORE_DEFAULT();
static void TEST_pantheios_boolean_CUSTOM_DEFAULT_CUSTOM_CYCLE();
static void TEST_pantheios_boolean_CUSTOM_DEFAULT_SHORT_CYCLE();
static void TEST_pantheios_boolean_CUSTOM_DEFAULT_SHORT_CYCLE_REPEAT();
/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.boolean");


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

    if (XTESTS_START_RUNNER("test.component.inserters.boolean", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_boolean_DEFAULT_false_true);
        XTESTS_RUN_CASE(TEST_pantheios_boolean_set_value_strings_NULL_RESTORES_DEFAULT);
        XTESTS_RUN_CASE(TEST_pantheios_boolean_set_value_strings_FALSE_TRUE);
        XTESTS_RUN_CASE(TEST_pantheios_boolean_CUSTOM_THEN_RESTORE_DEFAULT);
        XTESTS_RUN_CASE(TEST_pantheios_boolean_LONG_FALSE_STRING_THEN_RESTORE_DEFAULT);
        XTESTS_RUN_CASE(TEST_pantheios_boolean_CUSTOM_DEFAULT_CUSTOM_CYCLE);
        XTESTS_RUN_CASE(TEST_pantheios_boolean_CUSTOM_DEFAULT_SHORT_CYCLE);
        XTESTS_RUN_CASE(TEST_pantheios_boolean_CUSTOM_DEFAULT_SHORT_CYCLE_REPEAT);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_boolean_DEFAULT_false_true()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(2u, results.size());
    TEST_STRING_EQ(PSTR("{false}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[1].statement);
}

static void TEST_pantheios_boolean_set_value_strings_NULL_RESTORES_DEFAULT()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::boolean::set_value_strings(NULL, NULL);

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(2u, results.size());
    TEST_STRING_EQ(PSTR("{false}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[1].statement);
}

static void TEST_pantheios_boolean_set_value_strings_FALSE_TRUE()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::boolean::set_value_strings(PSTR("FALSE"), PSTR("TRUE"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(2u, results.size());
    TEST_STRING_EQ(PSTR("{FALSE}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{TRUE}"), results[1].statement);
}

static void TEST_pantheios_boolean_CUSTOM_THEN_RESTORE_DEFAULT()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::boolean::set_value_strings(PSTR("FALSE"), PSTR("TRUE"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(NULL, NULL);

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(4u, results.size());
    TEST_STRING_EQ(PSTR("{FALSE}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{TRUE}"), results[1].statement);
    TEST_STRING_EQ(PSTR("{false}"), results[2].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[3].statement);
}

static void TEST_pantheios_boolean_LONG_FALSE_STRING_THEN_RESTORE_DEFAULT()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::boolean::set_value_strings(PSTR("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), PSTR("T"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(NULL, NULL);

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(4u, results.size());
    TEST_STRING_EQ(PSTR("{ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{T}"), results[1].statement);
    TEST_STRING_EQ(PSTR("{false}"), results[2].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[3].statement);
}

static void TEST_pantheios_boolean_CUSTOM_DEFAULT_CUSTOM_CYCLE()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::boolean::set_value_strings(PSTR("FALSE"), PSTR("TRUE"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(NULL, NULL);

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(PSTR("FALSE"), PSTR("TRUE"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(6u, results.size());
    TEST_STRING_EQ(PSTR("{FALSE}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{TRUE}"), results[1].statement);
    TEST_STRING_EQ(PSTR("{false}"), results[2].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[3].statement);
    TEST_STRING_EQ(PSTR("{FALSE}"), results[4].statement);
    TEST_STRING_EQ(PSTR("{TRUE}"), results[5].statement);
}

static void TEST_pantheios_boolean_CUSTOM_DEFAULT_SHORT_CYCLE()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::boolean::set_value_strings(PSTR("FALSE"), PSTR("TRUE"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(NULL, NULL);

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(PSTR("F"), PSTR("T"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(6u, results.size());
    TEST_STRING_EQ(PSTR("{FALSE}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{TRUE}"), results[1].statement);
    TEST_STRING_EQ(PSTR("{false}"), results[2].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[3].statement);
    TEST_STRING_EQ(PSTR("{F}"), results[4].statement);
    TEST_STRING_EQ(PSTR("{T}"), results[5].statement);
}

static void TEST_pantheios_boolean_CUSTOM_DEFAULT_SHORT_CYCLE_REPEAT()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::boolean::set_value_strings(PSTR("FALSE"), PSTR("TRUE"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(NULL, NULL);

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(PSTR("F"), PSTR("T"));

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));

    pantheios::boolean::set_value_strings(NULL, NULL);

    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(false), PSTR("}"));
    pantheios::log_NOTICE(PSTR("{"), pantheios::boolean(true), PSTR("}"));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(8u, results.size());
    TEST_STRING_EQ(PSTR("{FALSE}"), results[0].statement);
    TEST_STRING_EQ(PSTR("{TRUE}"), results[1].statement);
    TEST_STRING_EQ(PSTR("{false}"), results[2].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[3].statement);
    TEST_STRING_EQ(PSTR("{F}"), results[4].statement);
    TEST_STRING_EQ(PSTR("{T}"), results[5].statement);
    TEST_STRING_EQ(PSTR("{false}"), results[6].statement);
    TEST_STRING_EQ(PSTR("{true}"), results[7].statement);
}


/* ///////////////////////////// end of file //////////////////////////// */

