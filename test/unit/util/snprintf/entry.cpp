/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/util/snprintf/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.util.snprintf project.
 *
 * Created: 19th June 2020
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>
#include <pantheios/util/string/snprintf.h>

#include <xtests/terse-api.h>

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

#ifndef TEST_STRING_EQ
# ifdef PANTHEIOS_USE_WIDE_STRINGS

#  define TEST_STRING_EQ                                    TEST_WS_EQ
# else

#  define TEST_STRING_EQ                                    TEST_MS_EQ
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

        TEST_INT_EQ(0u, n);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%s", "");

        TEST_INT_EQ(0u, n);
    }
#if defined(__GNUC__) && \
    __GNUC__ >= 9
# pragma GCC diagnostic pop
#endif


    // "a"

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "a");

        TEST_INT_EQ(1u, n);
        TEST_MS_EQ("a", buff);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%s", "a");

        TEST_INT_EQ(1u, n);
        TEST_MS_EQ("a", buff);
    }


    // "abc"

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "abc");

        TEST_INT_EQ(3u, n);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "abc");

        TEST_INT_EQ(3u, n);
        TEST_MS_EQ("abc", buff);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%s", "abc");

        TEST_INT_EQ(3u, n);
        TEST_MS_EQ("abc", buff);
    }

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "a%cc", 'b');

        TEST_INT_EQ(3u, n);
        TEST_MS_EQ("abc", buff);
    }


    // "-10"

    {
        char            buff[100];

        size_t const    n   =   pantheios_util_snprintf_a(&buff[0], STLSOFT_NUM_ELEMENTS(buff), "%d", -10);

        TEST_INT_EQ(3u, n);
        TEST_MS_EQ("-10", buff);
    }
}

#ifdef PANTHEIOS_USE_WIDE_STRINGS

static void test_pantheios_util_snprintf_w()
{
    // ""

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"");

        TEST_INT_EQ(0u, n);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%s", L"");

        TEST_INT_EQ(0u, n);
    }


    // "a"

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"a");

        TEST_INT_EQ(1u, n);
        TEST_WS_EQ(L"a", buff);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%s", L"a");

        TEST_INT_EQ(1u, n);
        TEST_WS_EQ(L"a", buff);
    }


    // "abc"

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"abc");

        TEST_INT_EQ(3u, n);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"abc");

        TEST_INT_EQ(3u, n);
        TEST_WS_EQ(L"abc", buff);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%s", L"abc");

        TEST_INT_EQ(3u, n);
        TEST_WS_EQ(L"abc", buff);
    }

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"a%cc", 'b');

        TEST_INT_EQ(3u, n);
        TEST_WS_EQ(L"abc", buff);
    }


    // "-10"

    {
        wchar_t         buff[100];

        size_t const    n   =   pantheios_util_snprintf_w(&buff[0], STLSOFT_NUM_ELEMENTS(buff), L"%d", -10);

        TEST_INT_EQ(3u, n);
        TEST_WS_EQ(L"-10", buff);
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

        TEST_INT_EQ(0u, n);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%s"), PANTHEIOS_LITERAL_STRING(""));

        TEST_INT_EQ(0u, n);
    }
#if defined(__GNUC__) && \
    __GNUC__ >= 9
# pragma GCC diagnostic pop
#endif


    // "a"

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("a"));

        TEST_INT_EQ(1u, n);
        TEST_STRING_EQ(PANTHEIOS_LITERAL_STRING("a"), buff);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%s"), PANTHEIOS_LITERAL_STRING("a"));

        TEST_INT_EQ(1u, n);
        TEST_STRING_EQ(PANTHEIOS_LITERAL_STRING("a"), buff);
    }


    // "abc"

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("abc"));

        TEST_INT_EQ(3u, n);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("abc"));

        TEST_INT_EQ(3u, n);
        TEST_STRING_EQ(PANTHEIOS_LITERAL_STRING("abc"), buff);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%s"), PANTHEIOS_LITERAL_STRING("abc"));

        TEST_INT_EQ(3u, n);
        TEST_STRING_EQ(PANTHEIOS_LITERAL_STRING("abc"), buff);
    }

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("a%cc"), 'b');

        TEST_INT_EQ(3u, n);
        TEST_STRING_EQ(PANTHEIOS_LITERAL_STRING("abc"), buff);
    }


    // "-10"

    {
        pantheios_char_t    buff[100];

        size_t const        n   =   pantheios_util_snprintf(&buff[0], STLSOFT_NUM_ELEMENTS(buff), PANTHEIOS_LITERAL_STRING("%d"), -10);

        TEST_INT_EQ(3u, n);
        TEST_STRING_EQ(PANTHEIOS_LITERAL_STRING("-10"), buff);
    }
}


} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

