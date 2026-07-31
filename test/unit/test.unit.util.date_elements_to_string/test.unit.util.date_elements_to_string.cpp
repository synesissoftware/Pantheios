/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.util.date_elements_to_string/test.unit.util.date_elements_to_string.cpp
 *
 * Purpose: Unit-tests for date component formatting functions.
 *
 * Created: 13th November 2016
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/internal/lean.h>
#include <pantheios/util/string/date_elements_to_string.h>
#include <pantheios/util/string/snprintf.h>

#include <pantheios/pantheios.h>

#include <xtests/xtests.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* ////////////////////////////////////////////////////////////////////// */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N                         XTESTS_TEST_WIDE_STRING_EQUAL_N
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N                         XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void test_formatYearToString2_01();
static void test_formatYearToString2_02();
static void test_formatYearToString2_03();
static void test_formatYearToString2_04();
static void test_formatYearToString2_05();
static void test_formatYearToString2_06();
static void test_formatYearToString2_07();
static void test_formatYearToString2_08();
static void test_formatYearToString2_09();

static void test_formatMonthToString2_01();
static void test_formatMonthToString2_02();
static void test_formatMonthToString2_03();
static void test_formatMonthToString2_04();
static void test_formatMonthToString2_05();
static void test_formatMonthToString2_06();
static void test_formatMonthToString2_07();
static void test_formatMonthToString2_08();
static void test_formatMonthToString2_09();

static void test_formatDayToString2_01();
static void test_formatDayToString2_02();
static void test_formatDayToString2_03();
static void test_formatDayToString2_04();
static void test_formatDayToString2_05();
static void test_formatDayToString2_06();
static void test_formatDayToString2_07();
static void test_formatDayToString2_08();
static void test_formatDayToString2_09();

static void test_formatHourToString2_01();
static void test_formatHourToString2_02();
static void test_formatHourToString2_03();
static void test_formatHourToString2_04();
static void test_formatHourToString2_05();
static void test_formatHourToString2_06();
static void test_formatHourToString2_07();
static void test_formatHourToString2_08();
static void test_formatHourToString2_09();

static void test_formatMinuteOrSecondToString2_01();
static void test_formatMinuteOrSecondToString2_02();
static void test_formatMinuteOrSecondToString2_03();
static void test_formatMinuteOrSecondToString2_04();
static void test_formatMinuteOrSecondToString2_05();
static void test_formatMinuteOrSecondToString2_06();
static void test_formatMinuteOrSecondToString2_07();
static void test_formatMinuteOrSecondToString2_08();
static void test_formatMinuteOrSecondToString2_09();

static void test_formatMillisecondToString3_01();
static void test_formatMillisecondToString3_02();
static void test_formatMillisecondToString3_03();
static void test_formatMillisecondToString3_04();
static void test_formatMillisecondToString3_05();
static void test_formatMillisecondToString3_06();
static void test_formatMillisecondToString3_07();
static void test_formatMillisecondToString3_08();
static void test_formatMillisecondToString3_09();

static void test_formatMicrosecondToString6_01();
static void test_formatMicrosecondToString6_02();
static void test_formatMicrosecondToString6_03();
static void test_formatMicrosecondToString6_04();
static void test_formatMicrosecondToString6_05();
static void test_formatMicrosecondToString6_06();
static void test_formatMicrosecondToString6_07();
static void test_formatMicrosecondToString6_08();
static void test_formatMicrosecondToString6_09();

static void test_date_formatting_01();
static void test_1_07();
static void test_1_08();
static void test_1_09();
static void test_1_10();
static void test_1_11();
static void test_1_12();
} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.util.date_elements_to_string");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.date_elements_to_string", verbosity))
    {
        XTESTS_RUN_CASE(test_formatYearToString2_01);
        XTESTS_RUN_CASE(test_formatYearToString2_02);
        XTESTS_RUN_CASE(test_formatYearToString2_03);
        XTESTS_RUN_CASE(test_formatYearToString2_04);
        XTESTS_RUN_CASE(test_formatYearToString2_05);
        XTESTS_RUN_CASE(test_formatYearToString2_06);
        XTESTS_RUN_CASE(test_formatYearToString2_07);
        XTESTS_RUN_CASE(test_formatYearToString2_08);
        XTESTS_RUN_CASE(test_formatYearToString2_09);

        XTESTS_RUN_CASE(test_formatMonthToString2_01);
        XTESTS_RUN_CASE(test_formatMonthToString2_02);
        XTESTS_RUN_CASE(test_formatMonthToString2_03);
        XTESTS_RUN_CASE(test_formatMonthToString2_04);
        XTESTS_RUN_CASE(test_formatMonthToString2_05);
        XTESTS_RUN_CASE(test_formatMonthToString2_06);
        XTESTS_RUN_CASE(test_formatMonthToString2_07);
        XTESTS_RUN_CASE(test_formatMonthToString2_08);
        XTESTS_RUN_CASE(test_formatMonthToString2_09);

        XTESTS_RUN_CASE(test_formatDayToString2_01);
        XTESTS_RUN_CASE(test_formatDayToString2_02);
        XTESTS_RUN_CASE(test_formatDayToString2_03);
        XTESTS_RUN_CASE(test_formatDayToString2_04);
        XTESTS_RUN_CASE(test_formatDayToString2_05);
        XTESTS_RUN_CASE(test_formatDayToString2_06);
        XTESTS_RUN_CASE(test_formatDayToString2_07);
        XTESTS_RUN_CASE(test_formatDayToString2_08);
        XTESTS_RUN_CASE(test_formatDayToString2_09);

        XTESTS_RUN_CASE(test_formatHourToString2_01);
        XTESTS_RUN_CASE(test_formatHourToString2_02);
        XTESTS_RUN_CASE(test_formatHourToString2_03);
        XTESTS_RUN_CASE(test_formatHourToString2_04);
        XTESTS_RUN_CASE(test_formatHourToString2_05);
        XTESTS_RUN_CASE(test_formatHourToString2_06);
        XTESTS_RUN_CASE(test_formatHourToString2_07);
        XTESTS_RUN_CASE(test_formatHourToString2_08);
        XTESTS_RUN_CASE(test_formatHourToString2_09);

        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_01);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_02);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_03);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_04);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_05);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_06);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_07);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_08);
        XTESTS_RUN_CASE(test_formatMinuteOrSecondToString2_09);

        XTESTS_RUN_CASE(test_formatMillisecondToString3_01);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_02);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_03);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_04);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_05);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_06);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_07);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_08);
        XTESTS_RUN_CASE(test_formatMillisecondToString3_09);

        XTESTS_RUN_CASE(test_formatMicrosecondToString6_01);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_02);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_03);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_04);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_05);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_06);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_07);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_08);
        XTESTS_RUN_CASE(test_formatMicrosecondToString6_09);

        XTESTS_RUN_CASE(test_date_formatting_01);
        XTESTS_RUN_CASE(test_1_07);
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
 * function implementations
 */

namespace
{
    using ::pantheios::pantheios_util_snprintf;


static void test_formatYearToString2_01()
{
    PAN_CHAR_T  sz[4];

    pantheios_util_formatYearToString4(0, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("0000"), sz, 4);
}

static void test_formatYearToString2_02()
{
    PAN_CHAR_T  sz[4];

    for (unsigned year = 1; year != 1000; ++year)
    {
        pantheios_util_formatYearToString4(year, &sz);

        PAN_CHAR_T  expected[5];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%04d"), year);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 4);
    }
}

static void test_formatYearToString2_03()
{
    PAN_CHAR_T  sz[4];

    pantheios_util_formatYearToString4(10000, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("??00"), sz, 4);

    for (unsigned year = 10001; year != 12800; ++year)
    {
        pantheios_util_formatYearToString4(year, &sz);

        PAN_CHAR_T  expected[5];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("??%02d"), year % 100);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 4);
    }
}

static void test_formatYearToString2_04()
{
}

static void test_formatYearToString2_05()
{
}

static void test_formatYearToString2_06()
{
}

static void test_formatYearToString2_07()
{
}

static void test_formatYearToString2_08()
{
}

static void test_formatYearToString2_09()
{
}


static void test_formatMonthToString2_01()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMonthToString2(0, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);
}

static void test_formatMonthToString2_02()
{
    PAN_CHAR_T  sz[2];

    for (unsigned month = 1; month != 13; ++month)
    {
        pantheios_util_formatMonthToString2(month, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), month);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 2);
    }
}

static void test_formatMonthToString2_03()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMonthToString2(13, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("13"), sz, 2);

    pantheios_util_formatMonthToString2(14, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("14"), sz, 2);

    pantheios_util_formatMonthToString2(15, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("15"), sz, 2);

    pantheios_util_formatMonthToString2(16, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);
}

static void test_formatMonthToString2_04()
{
}

static void test_formatMonthToString2_05()
{
}

static void test_formatMonthToString2_06()
{
}

static void test_formatMonthToString2_07()
{
}

static void test_formatMonthToString2_08()
{
}

static void test_formatMonthToString2_09()
{
}


static void test_formatDayToString2_01()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatDayToString2(0, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);
}

static void test_formatDayToString2_02()
{
    PAN_CHAR_T  sz[2];

    for (unsigned month = 1; month != 32; ++month)
    {
        pantheios_util_formatDayToString2(month, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), month);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 2);
    }
}

static void test_formatDayToString2_03()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatDayToString2(32, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);

    pantheios_util_formatDayToString2(33, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("01"), sz, 2);
}

static void test_formatDayToString2_04()
{
}

static void test_formatDayToString2_05()
{
}

static void test_formatDayToString2_06()
{
}

static void test_formatDayToString2_07()
{
}

static void test_formatDayToString2_08()
{
}

static void test_formatDayToString2_09()
{
}


static void test_formatHourToString2_01()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatHourToString2(0, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);
}

static void test_formatHourToString2_02()
{
    PAN_CHAR_T  sz[2];

    for (unsigned hour = 1; hour != 24; ++hour)
    {
        pantheios_util_formatHourToString2(hour, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), hour);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 2);
    }
}

static void test_formatHourToString2_03()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatHourToString2(24, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("24"), sz, 2);

    pantheios_util_formatHourToString2(25, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("25"), sz, 2);

    pantheios_util_formatHourToString2(26, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("26"), sz, 2);

    pantheios_util_formatHourToString2(27, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("27"), sz, 2);

    pantheios_util_formatHourToString2(28, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("28"), sz, 2);

    pantheios_util_formatHourToString2(29, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("29"), sz, 2);

    pantheios_util_formatHourToString2(30, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("30"), sz, 2);

    pantheios_util_formatHourToString2(31, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("31"), sz, 2);

    pantheios_util_formatHourToString2(32, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);
}

static void test_formatHourToString2_04()
{
}

static void test_formatHourToString2_05()
{
}

static void test_formatHourToString2_06()
{
}

static void test_formatHourToString2_07()
{
}

static void test_formatHourToString2_08()
{
}

static void test_formatHourToString2_09()
{
}


static void test_formatMinuteOrSecondToString2_01()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMinuteOrSecondToString2(0, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);
}

static void test_formatMinuteOrSecondToString2_02()
{
    PAN_CHAR_T  sz[2];

    for (unsigned minuteOrSecond = 1; minuteOrSecond != 60; ++minuteOrSecond)
    {
        pantheios_util_formatMinuteOrSecondToString2(minuteOrSecond, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), minuteOrSecond);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 2);
    }
}

static void test_formatMinuteOrSecondToString2_03()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMinuteOrSecondToString2(60, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("60"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(61, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("61"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(62, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("62"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(63, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("63"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(64, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("00"), sz, 2);
}

static void test_formatMinuteOrSecondToString2_04()
{
}

static void test_formatMinuteOrSecondToString2_05()
{
}

static void test_formatMinuteOrSecondToString2_06()
{
}

static void test_formatMinuteOrSecondToString2_07()
{
}

static void test_formatMinuteOrSecondToString2_08()
{
}

static void test_formatMinuteOrSecondToString2_09()
{
}



static void test_formatMillisecondToString3_01()
{
    PAN_CHAR_T  sz[3];

    pantheios_util_formatMillisecondToString3(0, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("000"), sz, 3);
}

static void test_formatMillisecondToString3_02()
{
    PAN_CHAR_T  sz[3];

    for (unsigned microsecond = 1; microsecond != 1000; ++microsecond)
    {
        pantheios_util_formatMillisecondToString3(microsecond, &sz);

        PAN_CHAR_T  expected[4];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%03d"), microsecond);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 3);
    }
}

static void test_formatMillisecondToString3_03()
{
    PAN_CHAR_T  sz[3];

    pantheios_util_formatMillisecondToString3(1001, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("001"), sz, 3);

    pantheios_util_formatMillisecondToString3(1234, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("234"), sz, 3);

    pantheios_util_formatMillisecondToString3(12345, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("345"), sz, 3);

    pantheios_util_formatMillisecondToString3(123456, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("456"), sz, 3);

    pantheios_util_formatMillisecondToString3(1234567, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("567"), sz, 3);

    pantheios_util_formatMillisecondToString3(12345678, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("678"), sz, 3);

    pantheios_util_formatMillisecondToString3(123456789, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("789"), sz, 3);
}

static void test_formatMillisecondToString3_04()
{
}

static void test_formatMillisecondToString3_05()
{
}

static void test_formatMillisecondToString3_06()
{
}

static void test_formatMillisecondToString3_07()
{
}

static void test_formatMillisecondToString3_08()
{
}

static void test_formatMillisecondToString3_09()
{
}



static void test_formatMicrosecondToString6_01()
{
    PAN_CHAR_T  sz[6];

    pantheios_util_formatMicrosecondToString6(0, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("000000"), sz, 6);
}

static void test_formatMicrosecondToString6_02()
{
    PAN_CHAR_T  sz[6];

    for (unsigned microsecond = 1; microsecond != 1000000; ++microsecond)
    {
        pantheios_util_formatMicrosecondToString6(microsecond, &sz);

        PAN_CHAR_T  expected[7];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%06d"), microsecond);

        XTESTS_TEST_STRING_EQUAL_N(expected, sz, 6);
    }
}

static void test_formatMicrosecondToString6_03()
{
    PAN_CHAR_T  sz[6];

    pantheios_util_formatMicrosecondToString6(1000001, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("000001"), sz, 6);

    pantheios_util_formatMicrosecondToString6(1234567890, &sz);

    XTESTS_TEST_STRING_EQUAL_N(PSTR("567890"), sz, 6);
}

static void test_formatMicrosecondToString6_04()
{
}

static void test_formatMicrosecondToString6_05()
{
}

static void test_formatMicrosecondToString6_06()
{
}

static void test_formatMicrosecondToString6_07()
{
}

static void test_formatMicrosecondToString6_08()
{
}

static void test_formatMicrosecondToString6_09()
{
}



static void test_date_formatting_01()
{
    // to format as "YYYY-mm-DD HH:MM:SS"

    PAN_CHAR_T  sz[20];

    int const   year    =   2016;
    int const   month   =   11;
    int const   day     =   13;
    int const   hour    =   13;
    int const   minute  =   45;
    int const   second  =   23;

    typedef PAN_CHAR_T (*ar2_t)[2];
    typedef PAN_CHAR_T (*ar4_t)[4];


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


    XTESTS_TEST_STRING_EQUAL(PSTR("2016-11-13 13:45:23"), sz);
}

static void test_1_07()
{
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

