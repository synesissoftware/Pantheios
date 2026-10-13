/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/util/strnlen/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.util.strnlen project.
 *
 * Created: 17th April 2009
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>
#include <pantheios/internal/lean.h>
#include <pantheios/init_codes.h>

#include <xtests/terse-api.h>

#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/util/limit_traits.h>
#include <stlsoft/util/minmax.hpp>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void test_length_passed_through();
static void test_length_via_strlen();
static void test_length_calculated_forwards();
static void test_length_calculated_backwards();
static void test_strnlen_with_negatives();
} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.util.strnlen");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.strnlen", verbosity))
    {
        XTESTS_RUN_CASE(test_length_passed_through);
        XTESTS_RUN_CASE(test_length_via_strlen);
        XTESTS_RUN_CASE(test_length_calculated_forwards);
        XTESTS_RUN_CASE(test_length_calculated_backwards);
        XTESTS_RUN_CASE(test_strnlen_with_negatives);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{
    using ::pantheios::util::pantheios_util_strnlen;

    PAN_CHAR_T const* strings[] =
    {
            PANTHEIOS_LITERAL_STRING("")
        ,   PANTHEIOS_LITERAL_STRING("a")
        ,   PANTHEIOS_LITERAL_STRING("ab")
        ,   PANTHEIOS_LITERAL_STRING("abc")
        ,   PANTHEIOS_LITERAL_STRING("abcd")
        ,   PANTHEIOS_LITERAL_STRING("abcde")
        ,   PANTHEIOS_LITERAL_STRING("abcdef")
        ,   PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz")
        ,   PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789")
    };

    inline size_t get_min_max(size_t minLen, size_t maxLen)
    {
        return pantheios::pan_slice_t::get_lazy_length(minLen, maxLen);
    }

static void test_length_passed_through()
{
    /* Verify that when the top two bits are not set, the length returned
     * is the length given
     */

    size_t iterations = stlsoft::minimum(size_t(65536u * 16u), size_t(stlsoft::limit_traits<size_t>::maximum() / 4000));

    { for (size_t i = 0; i < iterations; ++i)
    {
        TEST_INT_EQ(i, pantheios_util_strnlen(PANTHEIOS_LITERAL_STRING(""), i));
    }}
}

static void test_length_via_strlen()
{
    /* Verify that when the size given is size_t(-1) that the string length
     * is calculated
     */
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
    {
        PAN_CHAR_T const* const string = strings[i];

        TEST_INT_EQ(stlsoft::c_str_len(string), pantheios_util_strnlen(string, ~size_t(0)));
    }}
}

static void test_length_calculated_forwards()
{
    /* Verify that when the size has the top-bit set, then the string length
     * is calculated between the given limits
     */

    PAN_CHAR_T const string[] = PANTHEIOS_LITERAL_STRING("abcdefghijklm\0nop\0qrs\0tuvwxyz"); // lengths: 13, 17, 21

    TEST_INT_EQ( 0u, pantheios_util_strnlen(string, get_min_max( 0,  0)));
    TEST_INT_EQ( 1u, pantheios_util_strnlen(string, get_min_max( 0,  1)));
    TEST_INT_EQ( 2u, pantheios_util_strnlen(string, get_min_max( 0,  2)));
    TEST_INT_EQ( 3u, pantheios_util_strnlen(string, get_min_max( 0,  3)));
    TEST_INT_EQ( 4u, pantheios_util_strnlen(string, get_min_max( 0,  4)));
    TEST_INT_EQ( 5u, pantheios_util_strnlen(string, get_min_max( 0,  5)));
    TEST_INT_EQ( 6u, pantheios_util_strnlen(string, get_min_max( 0,  6)));
    TEST_INT_EQ( 7u, pantheios_util_strnlen(string, get_min_max( 0,  7)));
    TEST_INT_EQ( 8u, pantheios_util_strnlen(string, get_min_max( 0,  8)));
    TEST_INT_EQ( 9u, pantheios_util_strnlen(string, get_min_max( 0,  9)));
    TEST_INT_EQ(10u, pantheios_util_strnlen(string, get_min_max( 0, 10)));
    TEST_INT_EQ(11u, pantheios_util_strnlen(string, get_min_max( 0, 11)));
    TEST_INT_EQ(12u, pantheios_util_strnlen(string, get_min_max( 0, 12)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 13)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 14)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 15)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 16)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 17)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 18)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 19)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 20)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 21)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 22)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 23)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 24)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 25)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 26)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 27)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max( 0, 28)));

    TEST_INT_EQ(10u, pantheios_util_strnlen(string, get_min_max(10, 10)));
    TEST_INT_EQ(11u, pantheios_util_strnlen(string, get_min_max(10, 11)));
    TEST_INT_EQ(12u, pantheios_util_strnlen(string, get_min_max(10, 12)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(10, 13)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(10, 14)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(10, 15)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(10, 16)));

    TEST_INT_EQ(14u, pantheios_util_strnlen(string, get_min_max(14, 14)));
    TEST_INT_EQ(15u, pantheios_util_strnlen(string, get_min_max(14, 15)));
    TEST_INT_EQ(16u, pantheios_util_strnlen(string, get_min_max(14, 16)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(14, 17)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(14, 18)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(14, 19)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(14, 20)));

    TEST_INT_EQ(18u, pantheios_util_strnlen(string, get_min_max(18, 18)));
    TEST_INT_EQ(19u, pantheios_util_strnlen(string, get_min_max(18, 19)));
    TEST_INT_EQ(20u, pantheios_util_strnlen(string, get_min_max(18, 20)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(18, 21)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(18, 22)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(18, 23)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(18, 24)));
}

static void test_length_calculated_backwards()
{
    /* Verify that when the size has the top-bit set, then the string length
     * is calculated between the given limits
     */

    PAN_CHAR_T const string[] = PANTHEIOS_LITERAL_STRING("abcdefghijklm\0nop\0qrs\0tuvwxyz"); // lengths: 13, 17, 21

    TEST_INT_EQ( 0u, pantheios_util_strnlen(string, get_min_max( 0,  0)));
    TEST_INT_EQ( 1u, pantheios_util_strnlen(string, get_min_max( 1,  0)));
    TEST_INT_EQ( 2u, pantheios_util_strnlen(string, get_min_max( 2,  0)));
    TEST_INT_EQ( 3u, pantheios_util_strnlen(string, get_min_max( 3,  0)));
    TEST_INT_EQ( 4u, pantheios_util_strnlen(string, get_min_max( 4,  0)));
    TEST_INT_EQ( 5u, pantheios_util_strnlen(string, get_min_max( 5,  0)));
    TEST_INT_EQ( 6u, pantheios_util_strnlen(string, get_min_max( 6,  0)));
    TEST_INT_EQ( 7u, pantheios_util_strnlen(string, get_min_max( 7,  0)));
    TEST_INT_EQ( 8u, pantheios_util_strnlen(string, get_min_max( 8,  0)));
    TEST_INT_EQ( 9u, pantheios_util_strnlen(string, get_min_max( 9,  0)));
    TEST_INT_EQ(10u, pantheios_util_strnlen(string, get_min_max(10,  0)));
    TEST_INT_EQ(11u, pantheios_util_strnlen(string, get_min_max(11,  0)));
    TEST_INT_EQ(12u, pantheios_util_strnlen(string, get_min_max(12,  0)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(13,  0)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(14,  0)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(15,  0)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(16,  0)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(17,  0)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(18,  0)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(19,  0)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(20,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(21,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(22,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(23,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(24,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(25,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(26,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(27,  0)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(28,  0)));

    TEST_INT_EQ(10u, pantheios_util_strnlen(string, get_min_max(10, 10)));
    TEST_INT_EQ(11u, pantheios_util_strnlen(string, get_min_max(11, 10)));
    TEST_INT_EQ(12u, pantheios_util_strnlen(string, get_min_max(12, 10)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(13, 10)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(14, 10)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(15, 10)));
    TEST_INT_EQ(13u, pantheios_util_strnlen(string, get_min_max(16, 10)));

    TEST_INT_EQ(14u, pantheios_util_strnlen(string, get_min_max(14, 14)));
    TEST_INT_EQ(15u, pantheios_util_strnlen(string, get_min_max(15, 14)));
    TEST_INT_EQ(16u, pantheios_util_strnlen(string, get_min_max(16, 14)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(17, 14)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(18, 14)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(19, 14)));
    TEST_INT_EQ(17u, pantheios_util_strnlen(string, get_min_max(20, 14)));

    TEST_INT_EQ(18u, pantheios_util_strnlen(string, get_min_max(18, 18)));
    TEST_INT_EQ(19u, pantheios_util_strnlen(string, get_min_max(19, 18)));
    TEST_INT_EQ(20u, pantheios_util_strnlen(string, get_min_max(20, 18)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(21, 18)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(22, 18)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(23, 18)));
    TEST_INT_EQ(21u, pantheios_util_strnlen(string, get_min_max(24, 18)));
}

static void test_strnlen_with_negatives()
{
    PAN_CHAR_T const abcdefghi[] = PANTHEIOS_LITERAL_STRING("abcdefghi");

    TEST_INT_EQ(9u, pantheios_util_strnlen(abcdefghi, static_cast<size_t>(-1)));

    {
    signed char minus1 = -1;

    TEST_INT_EQ(9u, pantheios_util_strnlen(abcdefghi, static_cast<size_t>(minus1)));
    }

    {
    short   minus1 = -1;

    TEST_INT_EQ(9u, pantheios_util_strnlen(abcdefghi, static_cast<size_t>(minus1)));
    }

    {
    int minus1 = -1;

    TEST_INT_EQ(9u, pantheios_util_strnlen(abcdefghi, static_cast<size_t>(minus1)));
    }

    {
    long    minus1 = -1;

    TEST_INT_EQ(9u, pantheios_util_strnlen(abcdefghi, static_cast<size_t>(minus1)));
    }
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

