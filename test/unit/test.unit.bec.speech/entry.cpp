/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.bec.speech/entry.cpp
 *
 * Purpose: Unit-test for bec.speech.
 *
 * Created: 25th January 2025
 * Updated: 25th January 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <pantheios/backends/bec.speech.h>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_pantheios_be_speech_WITH_ALL_STOCK_true();
static void TEST_pantheios_be_speech_WITH_ALL_STOCK_false();


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.bec.speech");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.bec.speech", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_be_speech_WITH_ALL_STOCK_true);
        XTESTS_RUN_CASE(TEST_pantheios_be_speech_WITH_ALL_STOCK_false);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

static void TEST_pantheios_be_speech_WITH_ALL_STOCK_true()
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
    ,   { 16, "synchronous=true" }
    ,   { 21, "purgeBeforeSpeak=true" }
    ,   { 21, "speakPunctuation=true" }
    ,   { 26, "synchronousOnCritical=true" }
    };

    pan_be_speech_init_t   init;

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
                                    // |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS
                                    // |   PANTHEIOS_BE_SPEECH_F_PURGE_BEFORE_SPEAK
                                    // |   PANTHEIOS_BE_SPEECH_F_SPEAK_PUNCTUATION
                                    // |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS_ON_CRITICAL
                                    // // |   PANTHEIOS_BE_SPEECH_F_UNINIT_DISCARD_WORKAROUND
                                    ;



    int const r = pantheios_be_speech_parseArgs(STLSOFT_NUM_ELEMENTS(args), args, &init);

    TEST_INTEGER_EQUAL(16, r);

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
                                    |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS
                                    |   PANTHEIOS_BE_SPEECH_F_PURGE_BEFORE_SPEAK
                                    |   PANTHEIOS_BE_SPEECH_F_SPEAK_PUNCTUATION
                                    |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS_ON_CRITICAL
                                    // |   PANTHEIOS_BE_SPEECH_F_UNINIT_DISCARD_WORKAROUND
                                    ;

    TEST_INTEGER_EQUAL(expected, init.flags);
}

static void TEST_pantheios_be_speech_WITH_ALL_STOCK_false()
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
    ,   { 17, "synchronous=false" }
    ,   { 22, "purgeBeforeSpeak=false" }
    ,   { 22, "speakPunctuation=false" }
    ,   { 27, "synchronousOnCritical=false" }
    };

    pan_be_speech_init_t   init;

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
                                    |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS
                                    |   PANTHEIOS_BE_SPEECH_F_PURGE_BEFORE_SPEAK
                                    |   PANTHEIOS_BE_SPEECH_F_SPEAK_PUNCTUATION
                                    |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS_ON_CRITICAL
                                    // |   PANTHEIOS_BE_SPEECH_F_UNINIT_DISCARD_WORKAROUND
                                    ;

    int const r = pantheios_be_speech_parseArgs(STLSOFT_NUM_ELEMENTS(args), args, &init);

    TEST_INTEGER_EQUAL(16, r);

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
                                    // |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS
                                    // |   PANTHEIOS_BE_SPEECH_F_PURGE_BEFORE_SPEAK
                                    // |   PANTHEIOS_BE_SPEECH_F_SPEAK_PUNCTUATION
                                    // |   PANTHEIOS_BE_SPEECH_F_SYNCHRONOUS_ON_CRITICAL
                                    // // |   PANTHEIOS_BE_SPEECH_F_UNINIT_DISCARD_WORKAROUND
                                    ;

    TEST_INTEGER_EQUAL(expected, init.flags);
}


/* ///////////////////////////// end of file //////////////////////////// */

