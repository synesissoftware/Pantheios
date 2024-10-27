/* /////////////////////////////////////////////////////////////////////////
 * File:    test/performance/test.performance.util.date_elements_to_string/test.performance.util.date_elements_to_string.cpp
 *
 * Purpose: Implementation file for the test.performance.util.date_elements_to_string project.
 *
 * Created: 13th November 2016
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */

#include <pantheios/util/string/date_elements_to_string.h>

/* STLSoft header files */
#include <platformstl/performance/performance_counter.hpp>
#include <stlsoft/stlsoft.h>
#ifdef _STLSOFT_VER_1_10_1_B18
# include <stlsoft/time/fast_strftime.hpp>
#endif
#include <pantheios/internal/safestr.h>

/* Standard C++ header files */
#include <exception>

/* Standard C header files */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef _DEBUG

const int       ITERATIONS  =   1000;
const int       NUM_WARMUPS =   2;
#else /* ? _DEBUG */

const int       ITERATIONS  =   1000000;
const int       NUM_WARMUPS =   2;
#endif /* _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[]    =   PANTHEIOS_LITERAL_STRING("test.performance.util.date_elements_to_string");


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
# define P_strcmp                                           ::wcscmp
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define P_strcmp                                           ::strcmp
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#if 0
typedef std::string                                         string_t;
#endif /* 0 */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static
int
format_with_date_elements_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
);

static
int
format_with_sprintf_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
);

static
int
format_with_strftime_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
);

#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

static
int
format_with_fast_strftime_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
);
#endif

static
struct tm
iteration_to_tm_(
    int iteration
);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char** /* argv */)
{
    platformstl::performance_counter                counter;
    platformstl::performance_counter::interval_type tm_date_elements    =   0;
    platformstl::performance_counter::interval_type tm_sprintf          =   0;
    platformstl::performance_counter::interval_type tm_strftime         =   0;
#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

    platformstl::performance_counter::interval_type tm_fast_strftime    =   0;
#endif

    // unit test

    { for (int i = 0; i != ITERATIONS; ++i)
    {
        struct tm const tm = iteration_to_tm_(i);

        PAN_CHAR_T  sz_de[20];
        PAN_CHAR_T  sz_sprintf[20];
        PAN_CHAR_T  sz_strftime[20];
#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

        PAN_CHAR_T  sz_fast_strftime[20];
#endif

        format_with_date_elements_(tm, &sz_de);
        format_with_sprintf_(tm, &sz_sprintf);
        format_with_strftime_(tm, &sz_strftime);
#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

        format_with_fast_strftime_(tm, &sz_fast_strftime);
#endif

        if (STLSOFT_ALWAYS_FALSE() ||
            0 != P_strcmp(sz_de, sz_sprintf) ||
            0 != P_strcmp(sz_de, sz_strftime) ||
#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

            0 != P_strcmp(sz_de, sz_fast_strftime) ||
#endif
            STLSOFT_ALWAYS_FALSE())
        {
            fprintf(stderr, "equivalence failed for iteration %d\n" , i);

            return EXIT_FAILURE;
        }
    }}

    int total = 0;

    // performance test

    { for (int WARMUPS = NUM_WARMUPS; 0 != WARMUPS; --WARMUPS)
    {
        counter.start();
        { for (int i = 0; i != ITERATIONS; ++i)
        {
            struct tm const tm = iteration_to_tm_(i);
            PAN_CHAR_T      sz[20];

            total += format_with_date_elements_(tm, &sz);
        }}
        counter.stop();
        tm_date_elements = counter.get_microseconds();
    }}

    { for (int WARMUPS = NUM_WARMUPS; 0 != WARMUPS; --WARMUPS)
    {
        counter.start();
        { for (int i = 0; i != ITERATIONS; ++i)
        {
            struct tm const tm = iteration_to_tm_(i);
            PAN_CHAR_T      sz[20];

            total += format_with_sprintf_(tm, &sz);
        }}
        counter.stop();
        tm_sprintf = counter.get_microseconds();
    }}

    { for (int WARMUPS = NUM_WARMUPS; 0 != WARMUPS; --WARMUPS)
    {
        counter.start();
        { for (int i = 0; i != ITERATIONS; ++i)
        {
            struct tm const tm = iteration_to_tm_(i);
            PAN_CHAR_T      sz[20];

            total += format_with_strftime_(tm, &sz);
        }}
        counter.stop();
        tm_strftime = counter.get_microseconds();
    }}

#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

    { for (int WARMUPS = NUM_WARMUPS; 0 != WARMUPS; --WARMUPS)
    {
        counter.start();
        { for (int i = 0; i != ITERATIONS; ++i)
        {
            struct tm const tm = iteration_to_tm_(i);
            PAN_CHAR_T      sz[20];

            total += format_with_fast_strftime_(tm, &sz);
        }}
        counter.stop();
        tm_fast_strftime = counter.get_microseconds();
    }}
#endif

    fprintf(stdout, "with strftime:     \t%9luus\n", static_cast<unsigned long>(tm_strftime));
    fprintf(stdout, "with sprintf:      \t%9luus\n", static_cast<unsigned long>(tm_sprintf));
#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME
    fprintf(stdout, "with fast_strftime:\t%9.luus\n", static_cast<unsigned long>(tm_fast_strftime));
#endif
    fprintf(stdout, "with date elements:\t%9luus\n", static_cast<unsigned long>(tm_date_elements));

    fprintf(stdout, "\n");

    fprintf(stdout, "     strftime : sprintf:      \t% 9.04f\n", (double)tm_strftime/(double)tm_sprintf);
    fprintf(stdout, "     strftime : date elements:\t% 9.04f\n", (double)tm_strftime/(double)tm_date_elements);
#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME
    fprintf(stdout, "     strftime : fast_strftime:\t% 9.04f\n", (double)tm_strftime/(double)tm_fast_strftime);
#endif

    fprintf(stdout, "\n");

#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME
    fprintf(stdout, "      sprintf : fast_strftime:\t% 9.04f\n", (double)tm_sprintf/(double)tm_fast_strftime);
#endif
    fprintf(stdout, "      sprintf : date elements:\t% 9.04f\n", (double)tm_sprintf/(double)tm_date_elements);

#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME
    fprintf(stdout, "\n");

    fprintf(stdout, "fast_strftime : date elements:\t% 9.04f\n", (double)tm_fast_strftime/(double)tm_date_elements);
#endif

    return (total == INT_MAX) ? 100 : EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#if 0
    { for (size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.performance.util.date_elements_to_string: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch (std::exception& x)
    {
        pantheios::util::onBailOut(PANTHEIOS_SEV_ALERT, "exception", PANTHEIOS_FE_PROCESS_IDENTITY, x.what(), NULL, NULL);

        res = EXIT_FAILURE;
    }
    catch (...)
    {
        pantheios::util::onBailOut(PANTHEIOS_SEV_EMERGENCY, "Unhandled unknown error", PANTHEIOS_FE_PROCESS_IDENTITY, NULL, NULL, NULL);

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* /////////////////////////////////////////////////////////////////////////
 * function implementations
 */

static
int
format_with_date_elements_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
)
{
    char    (&sz)[20] = *ar;

    int const&  year    =   tm.tm_year;
    int const&  month   =   tm.tm_mon + 1;
    int const&  day     =   tm.tm_mday;
    int const&  hour    =   tm.tm_hour;
    int const&  minute  =   tm.tm_min;
    int const&  second  =   tm.tm_sec;

    typedef char (*ar2_t)[2];
    typedef char (*ar4_t)[4];


    pantheios_util_formatYearToString4(year, reinterpret_cast<ar4_t>(&sz[0]));

    sz[4] = '-';
    pantheios_util_formatMonthToString2(month, reinterpret_cast<ar2_t>(&sz[0] + 5));

    sz[7] = '-';
    pantheios_util_formatDayToString2(day, reinterpret_cast<ar2_t>(&sz[0] + 8));

    sz[10] = ' ';
    pantheios_util_formatHourToString2(hour, reinterpret_cast<ar2_t>(&sz[0] + 11));

    sz[13] = ':';
    pantheios_util_formatMinuteOrSecondToString2(minute, reinterpret_cast<ar2_t>(&sz[0] + 14));

    sz[16] = ':';
    pantheios_util_formatMinuteOrSecondToString2(second, reinterpret_cast<ar2_t>(&sz[0] + 17));

    sz[19] = '\0';

    return 20;
}

static
int
format_with_sprintf_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
)
{
#ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS

    return ::_snprintf_s(
                    &(*ar)[0], 20, _TRUNCATE
                ,   "%04d-%02d-%02d %02d:%02d:%02d"
                ,   tm.tm_year
                ,   tm.tm_mon + 1
                ,   tm.tm_mday
                ,   tm.tm_hour
                ,   tm.tm_min
                ,   tm.tm_sec
                );
#else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */

    return ::sprintf(
                    &(*ar)[0]
                ,   "%04d-%02d-%02d %02d:%02d:%02d"
                ,   tm.tm_year
                ,   tm.tm_mon + 1
                ,   tm.tm_mday
                ,   tm.tm_hour
                ,   tm.tm_min
                ,   tm.tm_sec
                );
#endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
}

static
int
format_with_strftime_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
)
{
    struct tm tm2 = tm;

    tm2.tm_year -= 1900;

#if 0

    fprintf(stderr
        ,   "sec=%d, min=%d, hr=%d, mday=%d, mon=%d, year=%d, wday=%d, yday=%d, isdst=%d\n"
        ,   tm.tm_sec
        ,   tm.tm_min
        ,   tm.tm_hour
        ,   tm.tm_mday
        ,   tm.tm_mon
        ,   tm.tm_year
        ,   tm.tm_wday
        ,   tm.tm_yday
        ,   tm.tm_isdst
        );
#endif

    return static_cast<int>(::strftime(&(*ar)[0], sizeof(*ar), "%Y-%m-%d %H:%M:%S", &tm2));
}

#ifdef STLSOFT_INCL_STLSOFT_TIME_HPP_FAST_STRFTIME

static
int
format_with_fast_strftime_(
    struct tm const&    tm
,   PAN_CHAR_T        (*ar)[20]
)
{
    struct tm tm2 = tm;

    tm2.tm_year -= 1900;

    return static_cast<int>(stlsoft::fast_strftime(&(*ar)[0], sizeof(*ar), "%Y-%m-%d %H:%M:%S", &tm2));
}
#endif

static
struct tm
iteration_to_tm_(
    int iteration
)
{
    struct tm   tm = {};

    tm.tm_sec   =      0 + (iteration /      1) % 60;
    tm.tm_min   =      0 + (iteration /     10) % 60;
    tm.tm_hour  =      0 + (iteration /    100) % 24;

    tm.tm_mday  =      1 + (iteration /   1000) % 28;
    tm.tm_mon   =      0 + (iteration /  10000) % 12;
    tm.tm_year  =   2000 + (iteration / 100000) % 100;

    return tm;
}


/* ///////////////////////////// end of file //////////////////////////// */

