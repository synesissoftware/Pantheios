/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.util.snprintf/test.unit.util.snprintf.cpp
 *
 * Purpose: Implementation file for the test.unit.util.snprintf project.
 *
 * Created: 19th June 2020
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>
#include <pantheios/util/string/snprintf.h>

#include <xtests/xtests.h>

#include <stlsoft/util/minmax.hpp>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void test_pantheios_util_snprintf_a();
#ifdef PANTHEIOS_USE_WIDE_STRINGS

static void test_pantheios_util_snprintf_w();
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
static void test_pantheios_util_snprintf();
static void test_1_08();
static void test_1_09();
static void test_1_10();
static void test_1_11();
static void test_1_12();

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.util.snprintf");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.snprintf", verbosity))
    {
        XTESTS_RUN_CASE(test_pantheios_util_snprintf_a);
#ifdef PANTHEIOS_USE_WIDE_STRINGS

        XTESTS_RUN_CASE(test_pantheios_util_snprintf_w);
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
        XTESTS_RUN_CASE(test_pantheios_util_snprintf);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);

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
    using ::pantheios::pantheios_util_snprintf;
    using ::pantheios::pantheios_util_snprintf_a;
#ifdef PANTHEIOS_USE_WIDE_STRINGS

    using ::pantheios::pantheios_util_snprintf_w;
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

#ifndef XTESTS_TEST_STRING_EQUAL
# ifdef PANTHEIOS_USE_WIDE_STRINGS

#  define XTESTS_TEST_STRING_EQUAL                          XTESTS_TEST_WIDE_STRING_EQUAL
# else

#  define XTESTS_TEST_STRING_EQUAL                          XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# endif
#endif

static void test_pantheios_util_snprintf_a()
{
    // ""

#if defined(__GNUC__) && \
    __GNUC__ >= 9
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wformat-zero-length"
#endif
    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "");

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%s", "");

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
    }
#if defined(__GNUC__) && \
    __GNUC__ >= 9
# pragma GCC diagnostic pop
#endif


    // "a"

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "a");

        XTESTS_TEST_INTEGER_EQUAL(1u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", buff);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%s", "a");

        XTESTS_TEST_INTEGER_EQUAL(1u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", buff);
    }


    // "abc"

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", buff);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%s", "abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", buff);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "a%cc", 'b');

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", buff);
    }


    // "-10"

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%d", -10);

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-10", buff);
    }
}

#ifdef PANTHEIOS_USE_WIDE_STRINGS

static void test_pantheios_util_snprintf_w()
{
    // ""

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"");

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%s", L"");

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
    }


    // "a"

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"a");

        XTESTS_TEST_INTEGER_EQUAL(1u, n);
        XTESTS_TEST_WIDE_STRING_EQUAL(L"a", buff);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%s", L"a");

        XTESTS_TEST_INTEGER_EQUAL(1u, n);
        XTESTS_TEST_WIDE_STRING_EQUAL(L"a", buff);
    }


    // "abc"

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", buff);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%s", L"abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", buff);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"a%cc", 'b');

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", buff);
    }


    // "-10"

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%d", -10);

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_WIDE_STRING_EQUAL(L"-10", buff);
    }
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

static void test_pantheios_util_snprintf()
{
    // ""

#if defined(__GNUC__) && \
    __GNUC__ >= 9
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wformat-zero-length"
#endif
    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING(""));

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%s"), PANTHEIOS_LITERAL_STRING(""));

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
    }
#if defined(__GNUC__) && \
    __GNUC__ >= 9
# pragma GCC diagnostic pop
#endif


    // "a"

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("a"));

        XTESTS_TEST_INTEGER_EQUAL(1u, n);
        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("a"), buff);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%s"), PANTHEIOS_LITERAL_STRING("a"));

        XTESTS_TEST_INTEGER_EQUAL(1u, n);
        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("a"), buff);
    }


    // "abc"

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("abc"));

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("abc"));

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("abc"), buff);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%s"), PANTHEIOS_LITERAL_STRING("abc"));

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("abc"), buff);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("a%cc"), 'b');

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("abc"), buff);
    }


    // "-10"

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%d"), -10);

        XTESTS_TEST_INTEGER_EQUAL(3u, n);
        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("-10"), buff);
    }
}

static void test_1_08()
{
}

static void test_1_09()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}
} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

