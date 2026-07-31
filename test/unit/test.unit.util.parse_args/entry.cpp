/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.util.parse_args.cpp
 *
 * Purpose: Unit-test for argument parsing functions.
 *
 * Created: 24th January 2025
 * Updated: 24th January 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <pantheios/util/backends/arguments.h>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* Pantheios header files */
#include <pantheios/backend.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_pantheios_be_parseBooleanArg_NO_ARGS();
static void TEST_pantheios_be_parseBooleanArg_EMPTY_ARG();
static void TEST_pantheios_be_parseBooleanArg_NO_MATCHING_ARGS();
static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_ONLY();
static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_EMPTY_VALUE();
static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_true_VALUE();
static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_false_VALUE();

static void TEST_pantheios_be_parseStringArg_NO_ARGS();
static void TEST_pantheios_be_parseStringArg_EMPTY_ARG();
static void TEST_pantheios_be_parseStringArg_NO_MATCHING_ARGS();
static void TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_NAME_ONLY();
static void TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_EMPTY_VALUE();
static void TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_VALUE();
static void TEST_pantheios_be_parseStringArg_TWO_MATCHING_ARGS();

static void TEST_pantheios_be_parseStockArgs_NO_ARGS();
static void TEST_pantheios_be_parseStockArgs_EMPTY_ARG();
static void TEST_pantheios_be_parseStockArgs_WITH_processId();
static void TEST_pantheios_be_parseStockArgs_WITH_ALL_STOCK_true();
static void TEST_pantheios_be_parseStockArgs_WITH_ALL_STOCK_false();


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.util.parse_args");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.parse_args", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_be_parseBooleanArg_NO_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseBooleanArg_EMPTY_ARG);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseBooleanArg_NO_MATCHING_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_ONLY);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_EMPTY_VALUE);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_true_VALUE);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_false_VALUE);

        XTESTS_RUN_CASE(TEST_pantheios_be_parseStringArg_NO_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStringArg_EMPTY_ARG);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStringArg_NO_MATCHING_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_NAME_ONLY);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_EMPTY_VALUE);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_VALUE);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStringArg_TWO_MATCHING_ARGS);

        XTESTS_RUN_CASE(TEST_pantheios_be_parseStockArgs_NO_ARGS);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStockArgs_EMPTY_ARG);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStockArgs_WITH_processId);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStockArgs_WITH_ALL_STOCK_true);
        XTESTS_RUN_CASE(TEST_pantheios_be_parseStockArgs_WITH_ALL_STOCK_false);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_be_parseBooleanArg_NO_ARGS()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    };

    pantheios_uint32_t  flags   =   0x00;

    int const r = pantheios_be_parseBooleanArg(0, args, "verbose", false, 0x01, &flags);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(0, flags);
}

static void TEST_pantheios_be_parseBooleanArg_EMPTY_ARG()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    };

    pantheios_uint32_t  flags   =   0x00;

    int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", false, 0x01, &flags);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(0, flags);
}

static void TEST_pantheios_be_parseBooleanArg_NO_MATCHING_ARGS()
{
    pantheios_slice_t args[] =
    {
        { 3, "x=1" }
    };

    pantheios_uint32_t  flags   =   0x00;

    int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", false, 0x01, &flags);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(0, flags);
}

static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_ONLY()
{
    pantheios_slice_t args[] =
    {
        { 7, "verbose" }
    };

    pantheios_uint32_t  flags   =   0x00;

    int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", false, 0x01, &flags);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(0x00, flags);

    // NOTE: current functionality is to ignore if not provided with a '=', but there's an argument to default this to true ...
    // TEST_INTEGER_EQUAL(1, r);
    // TEST_INTEGER_EQUAL(0x01, flags);
}

static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_EMPTY_VALUE()
{
    pantheios_slice_t args[] =
    {
        { 8, "verbose=" }
    };

    pantheios_uint32_t  flags   =   0x00;

    int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", false, 0x01, &flags);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(0x00, flags);
}

static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_true_VALUE()
{
    // non-suppressive
    {
        pantheios_slice_t args[] =
        {
            { 12, "verbose=true" }
        };

        pantheios_uint32_t  flags   =   0x00;

        int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", false, 0x01, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(0x01, flags);
    }

    // suppressive
    //
    // in this case, we switch OFF the 'not-verbose' flag (value 0x01) when "verbose" is not present
    {
        pantheios_slice_t args[] =
        {
            { 12, "verbose=true" }
        };

        pantheios_uint32_t  flags   =   0x00;

        int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", true, 0x01, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(0x00, flags);
    }
}

static void TEST_pantheios_be_parseBooleanArg_ONE_MATCHING_ARG_WITH_NAME_AND_false_VALUE()
{
    // non-suppressive
    {
        pantheios_slice_t args[] =
        {
            { 13, "verbose=false" }
        };

        pantheios_uint32_t  flags   =   0x00;

        int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", false, 0x01, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(0x00, flags);
    }

    // suppressive
    //
    // in this case, we switch ON the "not-verbose" flag (value 0x01) when "verbose" is not present
    {
        pantheios_slice_t args[] =
        {
            { 13, "verbose=false" }
        };

        pantheios_uint32_t  flags   =   0xf0;

        int const r = pantheios_be_parseBooleanArg(STLSOFT_NUM_ELEMENTS(args), args, "verbose", true, 0x01, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(0xf1, flags);
    }
}


static void TEST_pantheios_be_parseStringArg_NO_ARGS()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    };

    pantheios_slice_t   value = { 4, "four" };

    int const r = pantheios_be_parseStringArg(0, args, "processName", &value);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(4, value.len);
    TEST_MULTIBYTE_STRING_EQUAL("four", value.ptr);
}

static void TEST_pantheios_be_parseStringArg_EMPTY_ARG()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    };

    pantheios_slice_t   value = { 4, "four" };

    int const r = pantheios_be_parseStringArg(STLSOFT_NUM_ELEMENTS(args), args, "processName", &value);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(4, value.len);
    TEST_MULTIBYTE_STRING_EQUAL("four", value.ptr);
}

static void TEST_pantheios_be_parseStringArg_NO_MATCHING_ARGS()
{
    pantheios_slice_t args[] =
    {
        { 5, "arg-1" }
    ,   { 9, "arg-2=two" }
    };

    pantheios_slice_t   value = { 4, "four" };

    int const r = pantheios_be_parseStringArg(STLSOFT_NUM_ELEMENTS(args), args, "processName", &value);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(4, value.len);
    TEST_MULTIBYTE_STRING_EQUAL("four", value.ptr);
}

static void TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_NAME_ONLY()
{
    pantheios_slice_t args[] =
    {
        { 5, "arg-1" }
    ,   { 9, "arg-2=two" }
    ,   { 11, "processName" }
    };

    pantheios_slice_t   value = { 4, "four" };

    int const r = pantheios_be_parseStringArg(STLSOFT_NUM_ELEMENTS(args), args, "processName", &value);

    TEST_INTEGER_EQUAL(1, r);

    TEST_INTEGER_EQUAL(0, value.len);
    TEST_POINTER_NOT_EQUAL(NULL, value.ptr);
}

static void TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_EMPTY_VALUE()
{
    pantheios_slice_t args[] =
    {
        { 5, "arg-1" }
    ,   { 9, "arg-2=two" }
    ,   { 12, "processName=" }
    };

    pantheios_slice_t   value = { 4, "four" };

    int const r = pantheios_be_parseStringArg(STLSOFT_NUM_ELEMENTS(args), args, "processName", &value);

    TEST_INTEGER_EQUAL(1, r);

    TEST_INTEGER_EQUAL(0, value.len);
    TEST_POINTER_NOT_EQUAL(NULL, value.ptr);
}

static void TEST_pantheios_be_parseStringArg_ONE_MATCHING_ARG_WITH_VALUE()
{
    pantheios_slice_t args[] =
    {
        { 5, "arg-1" }
    ,   { 9, "arg-2=two" }
    ,   { 17, "processName=tuupa" }
    };

    pantheios_slice_t   value = { 4, "four" };

    int const r = pantheios_be_parseStringArg(STLSOFT_NUM_ELEMENTS(args), args, "processName", &value);

    TEST_INTEGER_EQUAL(1, r);

    TEST_INTEGER_EQUAL(5, value.len);
    TEST_MULTIBYTE_STRING_EQUAL("tuupa", value.ptr);
}

static void TEST_pantheios_be_parseStringArg_TWO_MATCHING_ARGS()
{
    pantheios_slice_t args[] =
    {
        { 5, "arg-1" }
    ,   { 9, "arg-2=two" }
    ,   { 17, "processName=tuupa" }
    ,   { 17, "processName=twopa" }
    };

    pantheios_slice_t   value = { 4, "four" };

    int const r = pantheios_be_parseStringArg(STLSOFT_NUM_ELEMENTS(args), args, "processName", &value);

    TEST_INTEGER_EQUAL(1, r);

    TEST_INTEGER_EQUAL(5, value.len);
    TEST_MULTIBYTE_STRING_EQUAL("tuupa", value.ptr);
}



static void TEST_pantheios_be_parseStockArgs_NO_ARGS()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    };

    pantheios_uint32_t  flags   =   0x00;

    int const r = pantheios_be_parseStockArgs(0, args, &flags);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(0, flags);
}

static void TEST_pantheios_be_parseStockArgs_EMPTY_ARG()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    };

    pantheios_uint32_t  flags   =   0x00;

    int const r = pantheios_be_parseStockArgs(STLSOFT_NUM_ELEMENTS(args), args, &flags);

    TEST_INTEGER_EQUAL(0, r);

    TEST_INTEGER_EQUAL(0, flags);
}

static void TEST_pantheios_be_parseStockArgs_WITH_processId()
{
    {
        pantheios_slice_t args[] =
        {
            { 18, "showProcessId=true" }
        };

        pantheios_uint32_t  flags   =   0;

        int const r = pantheios_be_parseStockArgs(STLSOFT_NUM_ELEMENTS(args), args, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(0, flags);
    }

    {
        pantheios_slice_t args[] =
        {
            { 18, "showProcessId=true" }
        };

        pantheios_uint32_t  flags   =   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID;

        int const r = pantheios_be_parseStockArgs(STLSOFT_NUM_ELEMENTS(args), args, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(0, flags);
    }

    {
        pantheios_slice_t args[] =
        {
            { 19, "showProcessId=false" }
        };

        pantheios_uint32_t  flags   =   0;

        int const r = pantheios_be_parseStockArgs(STLSOFT_NUM_ELEMENTS(args), args, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(PANTHEIOS_BE_INIT_F_NO_PROCESS_ID, flags);
    }

    {
        pantheios_slice_t args[] =
        {
            { 19, "showProcessId=false" }
        };

        pantheios_uint32_t  flags   =   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID;

        int const r = pantheios_be_parseStockArgs(STLSOFT_NUM_ELEMENTS(args), args, &flags);

        TEST_INTEGER_EQUAL(1, r);

        TEST_INTEGER_EQUAL(PANTHEIOS_BE_INIT_F_NO_PROCESS_ID, flags);
    }
}

static void TEST_pantheios_be_parseStockArgs_WITH_ALL_STOCK_true()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    ,   { 18, "showProcessId=true" }
    ,   { 17, "showThreadId=true" }
    ,   { 17, "showDateTime=true" }
    ,   { 17, "showSeverity=true" }
    ,   { 18, "useSystemTime=true" }
    ,   { 23, "showDetailsAtStart=true" }
    ,   { 18, "useUnixFormat=true" }
    ,   { 13, "showDate=true" }
    ,   { 13, "showTime=true" }
    ,   { 19, "highResolution=true" }
    ,   { 18, "lowResolution=true" }
    ,   { 20, "numericSeverity=true" }
    };

    pantheios_uint32_t  flags       =   0
                                    |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    // |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    // |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    // |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    // |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    ;

    int const r = pantheios_be_parseStockArgs(STLSOFT_NUM_ELEMENTS(args), args, &flags);

    TEST_INTEGER_EQUAL(12, r);

    pantheios_uint32_t  expected    =   0
                                    // |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    // |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    ;

    TEST_INTEGER_EQUAL(expected, flags);
}

static void TEST_pantheios_be_parseStockArgs_WITH_ALL_STOCK_false()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    ,   { 19, "showProcessId=false" }
    ,   { 18, "showThreadId=false" }
    ,   { 18, "showDateTime=false" }
    ,   { 18, "showSeverity=false" }
    ,   { 19, "useSystemTime=false" }
    ,   { 24, "showDetailsAtStart=false" }
    ,   { 19, "useUnixFormat=false" }
    ,   { 14, "showDate=false" }
    ,   { 14, "showTime=false" }
    ,   { 20, "highResolution=false" }
    ,   { 19, "lowResolution=false" }
    ,   { 21, "numericSeverity=false" }
    };

    pantheios_uint32_t  flags       =   0
                                    // |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    // |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    ;

    int const r = pantheios_be_parseStockArgs(STLSOFT_NUM_ELEMENTS(args), args, &flags);

    TEST_INTEGER_EQUAL(12, r);

    pantheios_uint32_t  expected    =   0
                                    |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    // |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    // |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    // |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    // |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    ;

    TEST_INTEGER_EQUAL(expected, flags);
}


/* ///////////////////////////// end of file //////////////////////////// */

