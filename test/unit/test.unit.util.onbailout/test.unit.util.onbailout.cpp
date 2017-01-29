/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.util.onbailout/test.unit.util.onbailout.cpp
 *
 * Purpose:     Implementation file for the test.unit.util.onbailout project.
 *
 * Created:     29th April 2008
 * Updated:     27th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#define PANTHEIOS_NO_NAMESPACE

#define PANTHEIOS_BAILOUT_NO_OPERATING_SYSTEM_SPECIFICS
#define PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG
#define PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG

#define PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE     (200)

#ifdef UNIX
# define _WINSOCKAPI_
# define _WINSOCK2API_
# define _WINSOCK2_H
#endif

#include <pantheios/pantheios.h>
#include <pantheios/internal/lean.h>
#include <pantheios/init_codes.h>

#include <xtests/xtests.h>

#include <shwild/shwild.hpp>

#include <stlsoft/shims/access/string/fwd.h>
#include <stlsoft/shims/access/string/std/basic_string.hpp>
#include <platformstl/platformstl.h>

#include <string>
#include <vector>

#include <stdlib.h>
#if defined(PLATFORMSTL_OS_IS_UNIX)
# undef _WINSOCKAPI_
# undef _WINSOCK2API_
# undef _WINSOCK2_H
# include <sys/time.h>                          // for gettimeofday()
#endif /* PLATFORMSTL_OS_IS_UNIX */

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * xTests extensions
 */

#define XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)        \
                                                                    \
    ((0 == shwild::match(pattern, stlsoft::c_str_ptr(value), 0))    \
        ?   XTESTS_TEST_PASSED()                                    \
        :   XTESTS_TEST_FAIL_WITH_QUALIFIER(std::string("the actual value did not match the pattern '") + pattern + "'", value))

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void test_unused_receiver();
static void test_pantheios_onBailOut3();
static void test_pantheios_onBailOut4();
static void test_pantheios_onBailOut6();
static void test_pantheios_onBailOut6_too_long();
static void test_1_06();
static void test_1_07();
static void test_1_08();
static void test_1_09();
static void test_1_10();
static void test_1_11();
static void test_1_12();

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace
{

    class OnBailOutReceiver
    {
    public:
        typedef OnBailOutReceiver           class_type;
        typedef std::string                 string_type;
        struct entry_type
        {
            string_type message;
            string_type processId;
            string_type qualifier;

            entry_type(string_type const& msg, string_type const& prId, string_type const& qual)
                : message(msg)
                , processId(prId)
                , qualifier(qual)
            {}
        };
        typedef std::vector<entry_type>     entries_type;

    public:
        void Clear()
        {
            entries_type().swap(ConsoleResults);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
            entries_type().swap(EventLogResults);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
            entries_type().swap(LoggingBailoutTxtResults);
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
            entries_type().swap(OutputDebugStringResults);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
            entries_type().swap(SyslogResults);
#endif /* PLATFORMSTL_OS_IS_UNIX */
        }

        void onfprintf(string_type const& msg)
        {
            ConsoleResults.push_back(entry_type(msg, "", ""));
        }

#if defined(PLATFORMSTL_OS_IS_WINDOWS)
        void onOutputDebugString(char const* s)
        {
            OutputDebugStringResults.push_back(entry_type(s, "", ""));
        }
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

    public:
        entries_type        ConsoleResults;
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
        entries_type        EventLogResults;
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
        entries_type        LoggingBailoutTxtResults;
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
        entries_type        OutputDebugStringResults;
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
        entries_type        SyslogResults;
#endif /* PLATFORMSTL_OS_IS_UNIX */
    };

    OnBailOutReceiver   receiver;

} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.util.onbailout");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.util.onbailout", verbosity))
    {
        XTESTS_RUN_CASE(test_unused_receiver);
        XTESTS_RUN_CASE(test_pantheios_onBailOut3);
        XTESTS_RUN_CASE(test_pantheios_onBailOut4);
        XTESTS_RUN_CASE(test_pantheios_onBailOut6);
        XTESTS_RUN_CASE(test_pantheios_onBailOut6_too_long);
        XTESTS_RUN_CASE(test_1_06);
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

/* ////////////////////////////////////////////////////////////////////// */

namespace
{

static void test_unused_receiver()
{
    receiver.Clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.ConsoleResults.size());
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.EventLogResults.size());
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.LoggingBailoutTxtResults.size());
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.OutputDebugStringResults.size());
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.SyslogResults.size());
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_pantheios_onBailOut3()
{
    receiver.Clear();

    const char  message[]   =   "hello";
    const char  pattern[]   =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello";

    pantheios_onBailOut3(PANTHEIOS_SEV_DEBUG, message, "process-#1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_pantheios_onBailOut4()
{
    char const  message[]           =   "hello";
    char const  pattern_no_qual[]   =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello";
    char const  qualifier_1[]       =                                                                                               "qualifier";
    char const  pattern_qual_1[]    =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: qualifier";
    char const  qualifier_2[]       =                                                                                               "and now for a much longer qualifier, that will exercise some of the limits of messages that may be passed to the bail-out function(s) as there is a concern that the limits of some of the static buffers may be exceeded by very very very very very very long strings";
#if PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE == 200
    char const  pattern_qual_2[]    =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: and now for a much longer qualifier, that will exercise some of the limits of messages that may be passed to the bail-out function(s) as there is a concern that the limi";//"ts of some of the static buffers may be exceeded by very very very very very very long strings";
#else
# error
#endif


    receiver.Clear();

    pantheios_onBailOut4(PANTHEIOS_SEV_DEBUG, message, "process-#1", NULL);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_no_qual, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_no_qual, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut4(PANTHEIOS_SEV_DEBUG, message, "process-#1", qualifier_1);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_1, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_1, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut4(PANTHEIOS_SEV_DEBUG, message, "process-#1", qualifier_2);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_2, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_2, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_pantheios_onBailOut6()
{
    const char  message[]       =   "hello";
    const char  pattern_none[]  =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: qual-#1";
    const char  pattern_fe[]    =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=fe-#1: qual-#1";
    const char  pattern_be[]    =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: be=be-#1: qual-#1";
    const char  pattern_febe[]  =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=fe-#1, be=be-#1: qual-#1";


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", NULL, NULL);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_none, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_none, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", "fe-#1", NULL);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_fe, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_fe, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", NULL, "be-#1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_be, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_be, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", "fe-#1", "be-#1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_febe, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_febe, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_pantheios_onBailOut6_too_long()
{
    const char  message[]           =   "hello";
    const char  pattern_short[]     =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=fe-#1, be=be-#1: qual-#1";
    const char  pattern_medium_1[]  =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=a-longish-front-end-#1, be=a-longish-back-end-#1: a-longish-qualifier-#1";
    const char  pattern_medium_2[]  =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=a-fair-bit-more-than-fairish-amount-longer-front-end-#1, be=a-fair-bit-more-than-fairish-amount-longer-back-end-#1: a-fair-bit-more-than-fairish-amount-longer-qualifi";
    const char  pattern_long[]      =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=a-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-long-name-for-a-front-end-#1, be=a-very-very-very-very-very-very-very-very-very-very";


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", "fe-#1", "be-#1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_short, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_short, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "a-longish-qualifier-#1", "a-longish-front-end-#1", "a-longish-back-end-#1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_1, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_1, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "a-fair-bit-more-than-fairish-amount-longer-qualifier-#1", "a-fair-bit-more-than-fairish-amount-longer-front-end-#1", "a-fair-bit-more-than-fairish-amount-longer-back-end-#1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_2, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_2, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "a-much-much-much-much-much-much-much-much-longer-qualifier-#1", "a-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-long-name-for-a-front-end-#1", "a-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-long-name-for-a-back-end-#1");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_long, receiver.ConsoleResults[0].message);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
//  XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_long, receiver.ConsoleResults[0].message);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_1_06()
{
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

/* ////////////////////////////////////////////////////////////////////// */

#include <stdio.h>

#if defined(PLATFORMSTL_OS_IS_UNIX)

# include <unistd.h>

# define fprintf                bailout_test_fprintf_
void bailout_test_fprintf_(FILE*, char const*, int, char const*);

# define fopen(fileName, mode)  bailout_test_fopen_()
FILE* bailout_test_fopen_(void);

#endif /* PLATFORMSTL_OS_IS_UNIX */

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

# include <windows.h>

# define OutputDebugStringA     bailout_test_OutputDebugStringA_
void bailout_test_OutputDebugStringA_(char const*);

# define WriteFile              bailout_test_WriteFile_
void bailout_test_WriteFile_(FILE*, char const*, DWORD, DWORD*, void*);
void bailout_test_WriteFile_(HANDLE, char const*, DWORD, DWORD*, void*);

# define GetStdHandle(x)        bailout_test_GetStdHandle_()
FILE* bailout_test_GetStdHandle_(void);

# define CreateFileA            bailout_test_CreateFileA
HANDLE bailout_test_CreateFileA(char const*, DWORD, DWORD, void*, DWORD, DWORD, void*);

#endif /* PLATFORMSTL_OS_IS_WINDOWS */

#include <../src/util/bailout.c>
#include <../src/util/snprintf.c>

/* ////////////////////////////////////////////////////////////////////// */

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

void bailout_test_OutputDebugStringA_(char const* msg)
{
    receiver.onOutputDebugString(msg);
}

void bailout_test_WriteFile_(FILE*, char const* msg, DWORD cchMsg, DWORD*, void*)
{
    receiver.onfprintf(OnBailOutReceiver::string_type(msg, cchMsg - 2));
}

void bailout_test_WriteFile_(HANDLE, char const*, DWORD, DWORD*, void*)
{
}

FILE* bailout_test_GetStdHandle_(void)
{
    return NULL;
}

HANDLE bailout_test_CreateFileA(char const*, DWORD, DWORD, void*, DWORD, DWORD, void*)
{
    return INVALID_HANDLE_VALUE;
}

#endif /* PLATFORMSTL_OS_IS_WINDOWS */

#if defined(PLATFORMSTL_OS_IS_UNIX)

void bailout_test_fprintf_(FILE*, char const*, int cchMsg, char const* msg)
{
    receiver.onfprintf(OnBailOutReceiver::string_type(msg, size_t(cchMsg)));
}

FILE* bailout_test_fopen_(void)
{
    return NULL;
}

#endif /* PLATFORMSTL_OS_IS_UNIX */


/* ////////////////////////////////////////////////////////////////////// */
