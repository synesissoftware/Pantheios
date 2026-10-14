/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/inserters/pointer/entry.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.pointer project.
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
#include <pantheios/inserters/pointer.hpp>  // for pantheios::pointer
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

static void TEST_pantheios_pointer_NULL_WIDTH_1_cv_QUALIFIERS();
static void TEST_pantheios_pointer_NULL_WIDTH_4_AND_8();
static void TEST_pantheios_pointer_NONNULL_WIDTHS();
static void TEST_pantheios_pointer_NONNULL_hex();
static void TEST_pantheios_pointer_NONNULL_zeroXPrefix();
static void TEST_pantheios_pointer_NONNULL_zeroPad();
static void TEST_pantheios_pointer_NONNULL_zeroPad_zeroXPrefix();
static void TEST_pantheios_pointer_NONNULL_zeroXPrefix_REPEAT();
static void TEST_pantheios_pointer_hex_WIDTHS_COMBINED_FLAGS();
static void TEST_pantheios_pointer_hex_WIDTH_AND_FLAGS_ARGS();
static void TEST_pantheios_pointer_hex_NEGATIVE_WIDTHS();
static void TEST_pantheios_pointer_hex_zeroXPrefix_WIDTHS();
static void TEST_pantheios_pointer_hex_zeroXPrefix_NEGATIVE_WIDTHS();


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.pointer");


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

    if (XTESTS_START_RUNNER("test.component.inserters.pointer", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NULL_WIDTH_1_cv_QUALIFIERS);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NULL_WIDTH_4_AND_8);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NONNULL_WIDTHS);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NONNULL_hex);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NONNULL_zeroXPrefix);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NONNULL_zeroPad);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NONNULL_zeroPad_zeroXPrefix);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_NONNULL_zeroXPrefix_REPEAT);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_hex_WIDTHS_COMBINED_FLAGS);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_hex_WIDTH_AND_FLAGS_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_hex_NEGATIVE_WIDTHS);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_hex_zeroXPrefix_WIDTHS);
        XTESTS_RUN_CASE(TEST_pantheios_pointer_hex_zeroXPrefix_NEGATIVE_WIDTHS);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_pointer_NULL_WIDTH_1_cv_QUALIFIERS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::pointer(static_cast<void*>(0), 1));
    pantheios::log_NOTICE(pantheios::pointer(static_cast<void const*>(0), 1));
    pantheios::log_NOTICE(pantheios::pointer(static_cast<void volatile*>(0), 1));
    pantheios::log_NOTICE(pantheios::pointer(static_cast<void const volatile*>(0), 1));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(4u, results.size());
    TEST_STRING_EQ(PSTR("(null)"), results[0].statement);
    TEST_STRING_EQ(PSTR("(null)"), results[1].statement);
    TEST_STRING_EQ(PSTR("(null)"), results[2].statement);
    TEST_STRING_EQ(PSTR("(null)"), results[3].statement);
}

static void TEST_pantheios_pointer_NULL_WIDTH_4_AND_8()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::pointer(static_cast<void*>(0), 4));
    pantheios::log_NOTICE(pantheios::pointer(static_cast<void*>(0), 8));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(2u, results.size());
    TEST_STRING_EQ(PSTR("(null)"), results[0].statement);
    TEST_STRING_EQ(PSTR("(null)"), results[1].statement);
}

static void TEST_pantheios_pointer_NONNULL_WIDTHS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(3u, results.size());
    TEST_STRING_EQ(PSTR("1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[1].statement);
    TEST_STRING_EQ(PSTR("    1234"), results[2].statement);
}

static void TEST_pantheios_pointer_NONNULL_hex()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4 | pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8 | pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8 | pantheios::fmt::hex));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(3u, results.size());
    TEST_STRING_EQ(PSTR("1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[1].statement);
    TEST_STRING_EQ(PSTR("    1234"), results[2].statement);
}

static void TEST_pantheios_pointer_NONNULL_zeroXPrefix()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4 | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8 | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8 | pantheios::fmt::zeroXPrefix));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(3u, results.size());
    TEST_STRING_EQ(PSTR("0x1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("0x12345678"), results[1].statement);
    TEST_STRING_EQ(PSTR("0x00001234"), results[2].statement);
}

static void TEST_pantheios_pointer_NONNULL_zeroPad()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4 | pantheios::fmt::zeroPad));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8 | pantheios::fmt::zeroPad));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8 | pantheios::fmt::zeroPad));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(3u, results.size());
    TEST_STRING_EQ(PSTR("1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[1].statement);
    TEST_STRING_EQ(PSTR("00001234"), results[2].statement);
}

static void TEST_pantheios_pointer_NONNULL_zeroPad_zeroXPrefix()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4 | pantheios::fmt::zeroPad | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8 | pantheios::fmt::zeroPad | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8 | pantheios::fmt::zeroPad | pantheios::fmt::zeroXPrefix));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(3u, results.size());
    TEST_STRING_EQ(PSTR("0x1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("0x12345678"), results[1].statement);
    TEST_STRING_EQ(PSTR("0x00001234"), results[2].statement);
}

static void TEST_pantheios_pointer_NONNULL_zeroXPrefix_REPEAT()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4 | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8 | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8 | pantheios::fmt::zeroXPrefix));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(3u, results.size());
    TEST_STRING_EQ(PSTR("0x1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("0x12345678"), results[1].statement);
    TEST_STRING_EQ(PSTR("0x00001234"), results[2].statement);
}

static void TEST_pantheios_pointer_hex_WIDTHS_COMBINED_FLAGS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4  | pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8  | pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p1, 16 | pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8  | pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8  | pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, 16 | pantheios::fmt::hex));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(6u, results.size());
    TEST_STRING_EQ(PSTR("1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("    1234"), results[1].statement);
    TEST_STRING_EQ(PSTR("            1234"), results[2].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[3].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[4].statement);
    TEST_STRING_EQ(PSTR("        12345678"), results[5].statement);
}

static void TEST_pantheios_pointer_hex_WIDTH_AND_FLAGS_ARGS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p1, 16, pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, 16, pantheios::fmt::hex));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(6u, results.size());
    TEST_STRING_EQ(PSTR("1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("    1234"), results[1].statement);
    TEST_STRING_EQ(PSTR("            1234"), results[2].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[3].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[4].statement);
    TEST_STRING_EQ(PSTR("        12345678"), results[5].statement);
}

static void TEST_pantheios_pointer_hex_NEGATIVE_WIDTHS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, -4,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p1, -8,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p1, -16, pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, -8,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, -8,  pantheios::fmt::hex));
    pantheios::log_NOTICE(pantheios::pointer(p2, -16, pantheios::fmt::hex));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(6u, results.size());
    TEST_STRING_EQ(PSTR("1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("1234    "), results[1].statement);
    TEST_STRING_EQ(PSTR("1234            "), results[2].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[3].statement);
    TEST_STRING_EQ(PSTR("12345678"), results[4].statement);
    TEST_STRING_EQ(PSTR("12345678        "), results[5].statement);
}

static void TEST_pantheios_pointer_hex_zeroXPrefix_WIDTHS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, 4,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p1, 8,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p1, 16, pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, 8,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, 16, pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(6u, results.size());
    TEST_STRING_EQ(PSTR("0x1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("    0x1234"), results[1].statement);
    TEST_STRING_EQ(PSTR("            0x1234"), results[2].statement);
    TEST_STRING_EQ(PSTR("0x12345678"), results[3].statement);
    TEST_STRING_EQ(PSTR("0x12345678"), results[4].statement);
    TEST_STRING_EQ(PSTR("        0x12345678"), results[5].statement);
}

static void TEST_pantheios_pointer_hex_zeroXPrefix_NEGATIVE_WIDTHS()
{
    // 1. Setup

    pantheios::be::test::reset();


    // 2. Create test data
    void*   p1 = reinterpret_cast<void*>(0x1234);
    void*   p2 = reinterpret_cast<void*>(0x12345678);

    pantheios::log_NOTICE(pantheios::pointer(p1, -4,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p1, -8,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p1, -16, pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, -8,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, -8,  pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));
    pantheios::log_NOTICE(pantheios::pointer(p2, -16, pantheios::fmt::hex | pantheios::fmt::zeroXPrefix));


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    TEST(!results.empty());
    TEST_INT_EQ(6u, results.size());
    TEST_STRING_EQ(PSTR("0x1234"), results[0].statement);
    TEST_STRING_EQ(PSTR("0x1234    "), results[1].statement);
    TEST_STRING_EQ(PSTR("0x1234            "), results[2].statement);
    TEST_STRING_EQ(PSTR("0x12345678"), results[3].statement);
    TEST_STRING_EQ(PSTR("0x12345678"), results[4].statement);
    TEST_STRING_EQ(PSTR("0x12345678        "), results[5].statement);
}


/* ///////////////////////////// end of file //////////////////////////// */

