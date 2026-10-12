/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/util/date_elements_to_string/entry.cpp
 *
 * Purpose: Unit-tests for date component formatting functions.
 *
 * Created: 13th November 2016
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/internal/lean.h>
#include <pantheios/util/string/date_elements_to_string.h>
#include <pantheios/util/string/snprintf.h>

#include <pantheios/pantheios.h>

#include <xtests/terse-api.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* ////////////////////////////////////////////////////////////////////// */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ
# define TEST_STRING_EQ_N                                   TEST_WS_EQ_N
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ
# define TEST_STRING_EQ_N                                   TEST_MS_EQ_N
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void TEST_pantheios_util_formatYearToString4_ZERO();
static void TEST_pantheios_util_formatYearToString4_VALID_RANGE();
static void TEST_pantheios_util_formatYearToString4_OUT_OF_RANGE();
static void TEST_pantheios_util_formatMonthToString2_ZERO();
static void TEST_pantheios_util_formatMonthToString2_VALID_RANGE();
static void TEST_pantheios_util_formatMonthToString2_OUT_OF_RANGE();
static void TEST_pantheios_util_formatDayToString2_ZERO();
static void TEST_pantheios_util_formatDayToString2_VALID_RANGE();
static void TEST_pantheios_util_formatDayToString2_OUT_OF_RANGE();
static void TEST_pantheios_util_formatHourToString2_ZERO();
static void TEST_pantheios_util_formatHourToString2_VALID_RANGE();
static void TEST_pantheios_util_formatHourToString2_OUT_OF_RANGE();
static void TEST_pantheios_util_formatMinuteOrSecondToString2_ZERO();
static void TEST_pantheios_util_formatMinuteOrSecondToString2_VALID_RANGE();
static void TEST_pantheios_util_formatMinuteOrSecondToString2_OUT_OF_RANGE();
static void TEST_pantheios_util_formatMillisecondToString3_ZERO();
static void TEST_pantheios_util_formatMillisecondToString3_VALID_RANGE();
static void TEST_pantheios_util_formatMillisecondToString3_OUT_OF_RANGE();
static void TEST_pantheios_util_formatMicrosecondToString6_ZERO();
static void TEST_pantheios_util_formatMicrosecondToString6_VALID_RANGE();
static void TEST_pantheios_util_formatMicrosecondToString6_OUT_OF_RANGE();
static void TEST_pantheios_util_date_formatting_COMPOSITE();
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
        XTESTS_RUN_CASE(TEST_pantheios_util_formatYearToString4_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatYearToString4_VALID_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatYearToString4_OUT_OF_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMonthToString2_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMonthToString2_VALID_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMonthToString2_OUT_OF_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatDayToString2_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatDayToString2_VALID_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatDayToString2_OUT_OF_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatHourToString2_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatHourToString2_VALID_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatHourToString2_OUT_OF_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMinuteOrSecondToString2_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMinuteOrSecondToString2_VALID_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMinuteOrSecondToString2_OUT_OF_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMillisecondToString3_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMillisecondToString3_VALID_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMillisecondToString3_OUT_OF_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMicrosecondToString6_ZERO);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMicrosecondToString6_VALID_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_formatMicrosecondToString6_OUT_OF_RANGE);
        XTESTS_RUN_CASE(TEST_pantheios_util_date_formatting_COMPOSITE);
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


static void TEST_pantheios_util_formatYearToString4_ZERO()
{
    PAN_CHAR_T  sz[4];

    pantheios_util_formatYearToString4(0, &sz);

    TEST_STRING_EQ_N(PSTR("0000"), sz, 4);
}

static void TEST_pantheios_util_formatYearToString4_VALID_RANGE()
{
    PAN_CHAR_T  sz[4];

    for (unsigned year = 1; year != 1000; ++year)
    {
        pantheios_util_formatYearToString4(year, &sz);

        PAN_CHAR_T  expected[5];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%04d"), year);

        TEST_STRING_EQ_N(expected, sz, 4);
    }
}

static void TEST_pantheios_util_formatYearToString4_OUT_OF_RANGE()
{
    PAN_CHAR_T  sz[4];

    pantheios_util_formatYearToString4(10000, &sz);

    TEST_STRING_EQ_N(PSTR("??00"), sz, 4);

    for (unsigned year = 10001; year != 12800; ++year)
    {
        pantheios_util_formatYearToString4(year, &sz);

        PAN_CHAR_T  expected[5];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("??%02d"), year % 100);

        TEST_STRING_EQ_N(expected, sz, 4);
    }
}


static void TEST_pantheios_util_formatMonthToString2_ZERO()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMonthToString2(0, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);
}

static void TEST_pantheios_util_formatMonthToString2_VALID_RANGE()
{
    PAN_CHAR_T  sz[2];

    for (unsigned month = 1; month != 13; ++month)
    {
        pantheios_util_formatMonthToString2(month, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), month);

        TEST_STRING_EQ_N(expected, sz, 2);
    }
}

static void TEST_pantheios_util_formatMonthToString2_OUT_OF_RANGE()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMonthToString2(13, &sz);

    TEST_STRING_EQ_N(PSTR("13"), sz, 2);

    pantheios_util_formatMonthToString2(14, &sz);

    TEST_STRING_EQ_N(PSTR("14"), sz, 2);

    pantheios_util_formatMonthToString2(15, &sz);

    TEST_STRING_EQ_N(PSTR("15"), sz, 2);

    pantheios_util_formatMonthToString2(16, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);
}


static void TEST_pantheios_util_formatDayToString2_ZERO()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatDayToString2(0, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);
}

static void TEST_pantheios_util_formatDayToString2_VALID_RANGE()
{
    PAN_CHAR_T  sz[2];

    for (unsigned month = 1; month != 32; ++month)
    {
        pantheios_util_formatDayToString2(month, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), month);

        TEST_STRING_EQ_N(expected, sz, 2);
    }
}

static void TEST_pantheios_util_formatDayToString2_OUT_OF_RANGE()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatDayToString2(32, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);

    pantheios_util_formatDayToString2(33, &sz);

    TEST_STRING_EQ_N(PSTR("01"), sz, 2);
}


static void TEST_pantheios_util_formatHourToString2_ZERO()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatHourToString2(0, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);
}

static void TEST_pantheios_util_formatHourToString2_VALID_RANGE()
{
    PAN_CHAR_T  sz[2];

    for (unsigned hour = 1; hour != 24; ++hour)
    {
        pantheios_util_formatHourToString2(hour, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), hour);

        TEST_STRING_EQ_N(expected, sz, 2);
    }
}

static void TEST_pantheios_util_formatHourToString2_OUT_OF_RANGE()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatHourToString2(24, &sz);

    TEST_STRING_EQ_N(PSTR("24"), sz, 2);

    pantheios_util_formatHourToString2(25, &sz);

    TEST_STRING_EQ_N(PSTR("25"), sz, 2);

    pantheios_util_formatHourToString2(26, &sz);

    TEST_STRING_EQ_N(PSTR("26"), sz, 2);

    pantheios_util_formatHourToString2(27, &sz);

    TEST_STRING_EQ_N(PSTR("27"), sz, 2);

    pantheios_util_formatHourToString2(28, &sz);

    TEST_STRING_EQ_N(PSTR("28"), sz, 2);

    pantheios_util_formatHourToString2(29, &sz);

    TEST_STRING_EQ_N(PSTR("29"), sz, 2);

    pantheios_util_formatHourToString2(30, &sz);

    TEST_STRING_EQ_N(PSTR("30"), sz, 2);

    pantheios_util_formatHourToString2(31, &sz);

    TEST_STRING_EQ_N(PSTR("31"), sz, 2);

    pantheios_util_formatHourToString2(32, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);
}


static void TEST_pantheios_util_formatMinuteOrSecondToString2_ZERO()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMinuteOrSecondToString2(0, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);
}

static void TEST_pantheios_util_formatMinuteOrSecondToString2_VALID_RANGE()
{
    PAN_CHAR_T  sz[2];

    for (unsigned minuteOrSecond = 1; minuteOrSecond != 60; ++minuteOrSecond)
    {
        pantheios_util_formatMinuteOrSecondToString2(minuteOrSecond, &sz);

        PAN_CHAR_T  expected[3];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%02d"), minuteOrSecond);

        TEST_STRING_EQ_N(expected, sz, 2);
    }
}

static void TEST_pantheios_util_formatMinuteOrSecondToString2_OUT_OF_RANGE()
{
    PAN_CHAR_T  sz[2];

    pantheios_util_formatMinuteOrSecondToString2(60, &sz);

    TEST_STRING_EQ_N(PSTR("60"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(61, &sz);

    TEST_STRING_EQ_N(PSTR("61"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(62, &sz);

    TEST_STRING_EQ_N(PSTR("62"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(63, &sz);

    TEST_STRING_EQ_N(PSTR("63"), sz, 2);

    pantheios_util_formatMinuteOrSecondToString2(64, &sz);

    TEST_STRING_EQ_N(PSTR("00"), sz, 2);
}


static void TEST_pantheios_util_formatMillisecondToString3_ZERO()
{
    PAN_CHAR_T  sz[3];

    pantheios_util_formatMillisecondToString3(0, &sz);

    TEST_STRING_EQ_N(PSTR("000"), sz, 3);
}

static void TEST_pantheios_util_formatMillisecondToString3_VALID_RANGE()
{
    PAN_CHAR_T  sz[3];

    for (unsigned microsecond = 1; microsecond != 1000; ++microsecond)
    {
        pantheios_util_formatMillisecondToString3(microsecond, &sz);

        PAN_CHAR_T  expected[4];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%03d"), microsecond);

        TEST_STRING_EQ_N(expected, sz, 3);
    }
}

static void TEST_pantheios_util_formatMillisecondToString3_OUT_OF_RANGE()
{
    PAN_CHAR_T  sz[3];

    pantheios_util_formatMillisecondToString3(1001, &sz);

    TEST_STRING_EQ_N(PSTR("001"), sz, 3);

    pantheios_util_formatMillisecondToString3(1234, &sz);

    TEST_STRING_EQ_N(PSTR("234"), sz, 3);

    pantheios_util_formatMillisecondToString3(12345, &sz);

    TEST_STRING_EQ_N(PSTR("345"), sz, 3);

    pantheios_util_formatMillisecondToString3(123456, &sz);

    TEST_STRING_EQ_N(PSTR("456"), sz, 3);

    pantheios_util_formatMillisecondToString3(1234567, &sz);

    TEST_STRING_EQ_N(PSTR("567"), sz, 3);

    pantheios_util_formatMillisecondToString3(12345678, &sz);

    TEST_STRING_EQ_N(PSTR("678"), sz, 3);

    pantheios_util_formatMillisecondToString3(123456789, &sz);

    TEST_STRING_EQ_N(PSTR("789"), sz, 3);
}


static void TEST_pantheios_util_formatMicrosecondToString6_ZERO()
{
    PAN_CHAR_T  sz[6];

    pantheios_util_formatMicrosecondToString6(0, &sz);

    TEST_STRING_EQ_N(PSTR("000000"), sz, 6);
}

static void TEST_pantheios_util_formatMicrosecondToString6_VALID_RANGE()
{
    PAN_CHAR_T  sz[6];

    for (unsigned microsecond = 1; microsecond != 1000000; ++microsecond)
    {
        pantheios_util_formatMicrosecondToString6(microsecond, &sz);

        PAN_CHAR_T  expected[7];

        pantheios_util_snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), PSTR("%06d"), microsecond);

        TEST_STRING_EQ_N(expected, sz, 6);
    }
}

static void TEST_pantheios_util_formatMicrosecondToString6_OUT_OF_RANGE()
{
    PAN_CHAR_T  sz[6];

    pantheios_util_formatMicrosecondToString6(1000001, &sz);

    TEST_STRING_EQ_N(PSTR("000001"), sz, 6);

    pantheios_util_formatMicrosecondToString6(1234567890, &sz);

    TEST_STRING_EQ_N(PSTR("567890"), sz, 6);
}


static void TEST_pantheios_util_date_formatting_COMPOSITE()
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


    TEST_STRING_EQ(PSTR("2016-11-13 13:45:23"), sz);
}


} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

