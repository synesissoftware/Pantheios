/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/pad/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.pad project.
 *
 * Created: 29th June 2009
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/inserters/pad.hpp>      // for pantheios::pad
#include <pantheios/backends/bec.test.h>

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

namespace
{

    static void test_1_01();
    static void test_1_02();
    static void test_1_03();
    static void test_1_04();
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.pad");


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

    if (XTESTS_START_RUNNER_WITH_FLAGS("test.component.inserters.pad", verbosity, XTESTS_NS_C_QUAL(xtestsReportOnlyNonEmptyCases)))
    {
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

namespace
{
    typedef std::basic_string<pantheios::pan_char_t>    string_t;

static void test_1_01()
{
    { for (size_t i = 0; i != 1000; ++i)
    {
        // 1. Setup

        pantheios::be::test::reset();


        // 2. Create test data

        pantheios::log_NOTICE(pantheios::pad("", i));


        // 3. Verification

        pantheios::be::test::Results  results = pantheios::be::test::results();

        TEST(!results.empty());
        TEST_INT_EQ(1u, results.size());
        TEST_INT_EQ(i, results[0].statement.size());
        TEST_STRING_EQ(string_t(i, ' '), results[0].statement);
    }}
}

static void test_1_02()
{
    { for (size_t i = 0; i != 1000; ++i)
    {
        // 1. Setup

        pantheios::be::test::reset();


        // 2. Create test data

        pantheios::log_NOTICE(pantheios::pad(string_t(), i));


        // 3. Verification

        pantheios::be::test::Results  results = pantheios::be::test::results();

        TEST(!results.empty());
        TEST_INT_EQ(1u, results.size());
        TEST_INT_EQ(i, results[0].statement.size());
        TEST_STRING_EQ(string_t(i, ' '), results[0].statement);
    }}
}

static void test_1_03()
{
    { for (size_t i = 0; i != 1/* 000 */; ++i)
    {
        // 1. Setup

        pantheios::be::test::reset();


        // 2. Create test data

        pantheios::log_NOTICE(pantheios::pad(" ", i));


        // 3. Verification

        pantheios::be::test::Results  results = pantheios::be::test::results();

        TEST(!results.empty());
        TEST_INT_EQ(1u, results.size());
        if (i <= 1)
        {
            TEST_INT_EQ(0u, results[0].statement.size());
            TEST_STRING_EQ(PSTR(""), results[0].statement);
        }
        else
        {
            TEST_INT_EQ(i - 1u, results[0].statement.size());
            TEST_STRING_EQ(string_t(i - 1u, ' '), results[0].statement);
        }
    }}
}

static void test_1_04()
{
    { for (size_t i = 0; i != 1000; ++i)
    {
        const string_t value(i, '~');

        STLSOFT_ASSERT(i == value.size());

        { for (size_t j = 0; j != 1000; ++j)
        {
            // 1. Setup

            pantheios::be::test::reset();


            // 2. Create test data

            pantheios::log_NOTICE(pantheios::pad(value, j), value);


            // 3. Verification

            pantheios::be::test::Results  results = pantheios::be::test::results();

            TEST(!results.empty());
            TEST_INT_EQ(1u, results.size());
            if (i < j)
            {
                /* Some padding */
                const string_t stmt = string_t(j - i, ' ') + value;

                TEST_INT_EQ(stmt.size(), results[0].statement.size());
                TEST_STRING_EQ(stmt, results[0].statement);
            }
            else
            {
                /* No padding */

                TEST_INT_EQ(value.size(), results[0].statement.size());
                TEST_STRING_EQ(value, results[0].statement);
            }
        }}
    }}
}


} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

