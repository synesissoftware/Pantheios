/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.bec.WindowsSyslog/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.bec.WindowsSyslog project.
 *
 * Created: 17th October 2008
 * Updated: 25th January 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/backends/bec.WindowsSyslog.h>

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <winstl/conversion/char_conversions.hpp>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.bec.WindowsSyslog");


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_getDefaultAppInit();
    static void test_initialisation();
    static void test_1_2();
    static void test_1_3();
    static void test_1_4();
    static void test_1_5();
    static void test_1_6();
    static void test_1_7();
    static void test_1_8();
    static void test_1_9();
    static void test_1_10();
    static void test_1_11();
    static void test_1_12();
    static void test_1_13();
    static void test_1_14();
    static void test_1_15();
    static void test_1_16();
    static void test_1_17();
    static void test_1_18();
    static void test_1_19();

    static void TEST_pantheios_be_WindowsSyslog_WITH_ALL_STOCK_true();
    static void TEST_pantheios_be_WindowsSyslog_WITH_ALL_STOCK_false();
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int     retCode     =   EXIT_SUCCESS;
    int     verbosity   =   2;
    WSADATA wsadata;
    WORD    version     =   MAKEWORD(2, 2);

    int r = ::WSAStartup(version, &wsadata);

    if (0 != r)
    {
        fprintf(stderr, "failed to initialise the WinSock2 library: %d\n", r);

        retCode = EXIT_FAILURE;
    }
    else
    {
        stlsoft::scoped_handle<void>    scoper(::WSACleanup);

        XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

        if (XTESTS_START_RUNNER("test.unit.bec.WindowsSyslog", verbosity))
        {
            XTESTS_RUN_CASE(test_getDefaultAppInit);
            XTESTS_RUN_CASE(test_initialisation);
            XTESTS_RUN_CASE(test_1_2);
            XTESTS_RUN_CASE(test_1_3);
            XTESTS_RUN_CASE(test_1_4);
            XTESTS_RUN_CASE(test_1_5);
            XTESTS_RUN_CASE(test_1_6);
            XTESTS_RUN_CASE(test_1_7);
            XTESTS_RUN_CASE(test_1_8);
            XTESTS_RUN_CASE(test_1_9);
            XTESTS_RUN_CASE(test_1_10);
            XTESTS_RUN_CASE(test_1_11);
            XTESTS_RUN_CASE(test_1_12);
            XTESTS_RUN_CASE(test_1_13);
            XTESTS_RUN_CASE(test_1_14);
            XTESTS_RUN_CASE(test_1_15);
            XTESTS_RUN_CASE(test_1_16);
            XTESTS_RUN_CASE(test_1_17);
            XTESTS_RUN_CASE(test_1_18);
            XTESTS_RUN_CASE(test_1_19);

            XTESTS_RUN_CASE(TEST_pantheios_be_WindowsSyslog_WITH_ALL_STOCK_true);
            XTESTS_RUN_CASE(TEST_pantheios_be_WindowsSyslog_WITH_ALL_STOCK_false);
        }

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


static void test_getDefaultAppInit()
{
    pan_be_WindowsSyslog_init_t init;

    pantheios_be_WindowsSyslog_getDefaultAppInit(&init);

    XTESTS_TEST_INTEGER_EQUAL(0u, unsigned(init.flags));
    XTESTS_TEST_INTEGER_EQUAL(4u, init.addrSize);
    XTESTS_TEST_INTEGER_EQUAL(255u, init.bytes[0]);
    XTESTS_TEST_INTEGER_EQUAL(255u, init.bytes[1]);
    XTESTS_TEST_INTEGER_EQUAL(255u, init.bytes[2]);
    XTESTS_TEST_INTEGER_EQUAL(255u, init.bytes[3]);
    XTESTS_TEST_POINTER_EQUAL(static_cast<char const*>(NULL), init.hostName);
    XTESTS_TEST_INTEGER_EQUAL(514u, init.port);
    XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_SYSLOG_FAC_USER, init.facility);
}

static void test_initialisation()
{
    pan_be_WindowsSyslog_init_t init;

    pantheios_be_WindowsSyslog_getDefaultAppInit(&init);

    init.flags      |=  PANTHEIOS_BE_WINDOWSSYSLOG_F_NDELAY;
    init.addrSize   =   0;
    init.hostName   =   PANTHEIOS_LITERAL_STRING("localhost");
    init.port       =   50505;

    void*   token;
    int     r = pantheios_be_WindowsSyslog_init(PANTHEIOS_FE_PROCESS_IDENTITY, 1, &init, NULL, &token);

    if (r < 0)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("could not initialise bec.WindowsSyslog", winstl::t2m(pantheios::getStockSeverityString(r)));
    }
    else
    {
        stlsoft::scoped_handle<void*> scoper(token, pantheios_be_WindowsSyslog_uninit);

        XTESTS_TEST_PASSED();
    }
}

static void test_1_2()
{
    pan_be_WindowsSyslog_init_t init;

    pantheios_be_WindowsSyslog_getDefaultAppInit(&init);

    init.flags      |=  PANTHEIOS_BE_WINDOWSSYSLOG_F_NDELAY;
    init.addrSize   =   0;
    init.hostName   =   PANTHEIOS_LITERAL_STRING("localhost");
    init.port       =   50505;

    void*   token;
    int     r = pantheios_be_WindowsSyslog_init(PANTHEIOS_FE_PROCESS_IDENTITY, 1, &init, NULL, &token);

    if (r < 0)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("could not initialise bec.WindowsSyslog", winstl::t2m(pantheios::getStockSeverityString(r)));
    }
    else
    {
        stlsoft::scoped_handle<void*> scoper(token, pantheios_be_WindowsSyslog_uninit);

        // TODO: create a listening thread, do the statements, stop the thread, verify the elements;

        XTESTS_TEST_PASSED();
    }
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
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

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


static void TEST_pantheios_be_WindowsSyslog_WITH_ALL_STOCK_true()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    /* stock */
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
    /* custom */
    ,   { 18, "useSystemTime=true" }
    ,   { 14, "useStderr=true" }
    ,   { 15, "useConsole=true" }
    ,   { 12, "showPid=true" }
    ,   { 23, "connectImmediately=true" }
    };

    pan_be_WindowsSyslog_init_t init;

    init.flags                      =   0
                                    /* stock */
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
                                    /* custom */
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_USE_SYSTEM_TIME
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PERROR
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_CONS
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PID
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_NDELAY
                                    ;



    int const r = pantheios_be_WindowsSyslog_parseArgs(STLSOFT_NUM_ELEMENTS(args), args, &init);

    TEST_INTEGER_EQUAL(17, r);

    pantheios_uint32_t  expected    =   0
                                    /* stock */
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
                                    /* custom */
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_USE_SYSTEM_TIME
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PERROR
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_CONS
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PID
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_NDELAY
                                    ;

    TEST_INTEGER_EQUAL(expected, init.flags);
}

static void TEST_pantheios_be_WindowsSyslog_WITH_ALL_STOCK_false()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    /* stock */
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
    /* custom */
    ,   { 19, "useSystemTime=false" }
    ,   { 15, "useStderr=false" }
    ,   { 16, "useConsole=false" }
    ,   { 13, "showPid=false" }
    ,   { 24, "connectImmediately=false" }
    };

    pan_be_WindowsSyslog_init_t init;

    init.flags                      =   0
                                    /* stock */
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
                                    /* custom */
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_USE_SYSTEM_TIME
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PERROR
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_CONS
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PID
                                    |   PANTHEIOS_BE_WINDOWSSYSLOG_F_NDELAY
                                    ;

    int const r = pantheios_be_WindowsSyslog_parseArgs(STLSOFT_NUM_ELEMENTS(args), args, &init);

    TEST_INTEGER_EQUAL(17, r);

    pantheios_uint32_t  expected    =   0
                                    /* stock */
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
                                    /* custom */
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_USE_SYSTEM_TIME
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PERROR
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_CONS
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_PID
                                    // |   PANTHEIOS_BE_WINDOWSSYSLOG_F_NDELAY
                                    ;

    TEST_INTEGER_EQUAL(expected, init.flags);
}
} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

