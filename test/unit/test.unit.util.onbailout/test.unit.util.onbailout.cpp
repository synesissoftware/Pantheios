/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.util.onbailout/test.unit.util.onbailout.cpp
 *
 * Purpose: Implementation file for the test.unit.util.onbailout project.
 *
 * Created: 29th April 2008
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#define PANTHEIOS_NO_NAMESPACE

#define PANTHEIOS_BAILOUT_NO_OPERATING_SYSTEM_SPECIFICS
#define PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG
#define PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG

#define PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE                 (200)

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
#include <stlsoft/string/trim_functions.hpp>
#include <platformstl/platformstl.h>
#ifdef PANTHEIOS_USE_WIDE_STRINGS

# include <winstl/conversion/w2m.hpp>
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

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

#if _XTESTS_VER < 0x00150000

# define XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)       \
                                                                    \
    ((0 == shwild::match(pattern, stlsoft::c_str_ptr(value), 0))    \
        ?   XTESTS_TEST_PASSED()                                    \
        :   XTESTS_TEST_FAIL_WITH_QUALIFIER(std::string("the actual value did not match the pattern '") + pattern + "'", value))
#endif

#ifdef PANTHEIOS_USE_WIDE_STRINGS

namespace {

    template<
        typename T_pattern
    ,   typename T_string
    >
    inline
    int
    shwild_match_w(
        T_pattern const&    pattern
    ,   T_string const&     string
    ,   int                 flags   =   0
    )
    {
        return shwild::match(
            winstl::w2m(pattern).c_str()
        ,   winstl::w2m(string).c_str()
        ,   flags
        );
    }

} /* anonymous namespace */

#define XTESTS_TEST_WIDE_STRING_MATCHES(pattern, value)             \
                                                                    \
    ((0 == shwild_match_w(pattern, value, 0))                       \
        ?   XTESTS_TEST_PASSED()                                    \
        :   XTESTS_TEST_FAIL_WITH_QUALIFIER(winstl::w2m(std::wstring(L"the actual value did not match the pattern '") + pattern + L"'"), winstl::w2m(value)))

#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * feature selection
 */

#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# define TEST_ODS_
#endif

#if 1
# define TEST_CONSOLE_
#endif

#if 1
# define TEST_LBT_
#endif

#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)
# define TEST_EVLOG_
#endif

#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    !defined(PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG)
# define TEST_SYSLOG_
#endif /* PLATFORMSTL_OS_IS_UNIX */


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
#ifdef PANTHEIOS_USE_WIDE_STRINGS
static void test_pantheios_onBailOut3_w();
static void test_pantheios_onBailOut4_w();
static void test_pantheios_onBailOut6_w();
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
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

    template <typename T_character>
    class basic_OnBailoutReceiver
    {
    public:
        typedef basic_OnBailoutReceiver<T_character>        class_type;
        typedef T_character                                 char_type;
        typedef std::basic_string<
            char_type
        >                                                   string_type;
        struct entry_type
        {
            string_type message;
            string_type processId;
            string_type qualifier;

            entry_type(
                string_type const&  msg
            ,   string_type const&  prId
            ,   string_type const&  qual
            )
                : message(msg)
                , processId(prId)
                , qualifier(qual)
            {}
        };
        typedef std::vector<entry_type>                     entries_type;

    public:
        void Clear()
        {
#ifdef TEST_ODS_
            entries_type().swap(OutputDebugStringResults);
#endif

#ifdef TEST_CONSOLE_
            entries_type().swap(ConsoleResults);
#endif

#ifdef TEST_LBT_
            entries_type().swap(LoggingBailoutTxtResults);
#endif

#if TEST_EVLOG_
            entries_type().swap(EventLogResults);
#endif

#if TEST_SYSLOG_
            entries_type().swap(SyslogResults);
#endif /* PLATFORMSTL_OS_IS_UNIX */
        }

#ifdef TEST_CONSOLE_

        void onConsole(string_type const& msg)
        {
            string_type message(msg);

            stlsoft::trim_right(message);

            ConsoleResults.push_back(entry_type(message, string_type(), string_type()));
        }
#endif

#ifdef TEST_ODS_

        void onOutputDebugString(char_type const* s)
        {
            string_type message(s);

            stlsoft::trim_right(message);

            OutputDebugStringResults.push_back(entry_type(message, string_type(), string_type()));
        }
#endif

#ifdef TEST_LBT_

        void onFILE(string_type const& msg)
        {
            string_type message(msg);

            stlsoft::trim_right(message);

            LoggingBailoutTxtResults.push_back(entry_type(message, string_type(), string_type()));
        }
#endif

    public:
#ifdef TEST_ODS_
        entries_type        OutputDebugStringResults;
#endif

#ifdef TEST_CONSOLE_
        entries_type        ConsoleResults;
#endif

#ifdef TEST_LBT_
        entries_type        LoggingBailoutTxtResults;
#endif

#if TEST_EVLOG_
        entries_type        EventLogResults;
#endif

#if TEST_SYSLOG_
        entries_type        SyslogResults;
#endif /* PLATFORMSTL_OS_IS_UNIX */
    };

    typedef basic_OnBailoutReceiver<char>                   OnBailoutReceiver;
    typedef basic_OnBailoutReceiver<wchar_t>                OnBailoutReceiver_w;

    OnBailoutReceiver   receiver;
    OnBailoutReceiver_w receiver_w;
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.util.onbailout");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.onbailout", verbosity))
    {
        XTESTS_RUN_CASE(test_unused_receiver);
        XTESTS_RUN_CASE(test_pantheios_onBailOut3);
        XTESTS_RUN_CASE(test_pantheios_onBailOut4);
        XTESTS_RUN_CASE(test_pantheios_onBailOut6);
        XTESTS_RUN_CASE(test_pantheios_onBailOut6_too_long);
#ifdef PANTHEIOS_USE_WIDE_STRINGS
        XTESTS_RUN_CASE(test_pantheios_onBailOut3_w);
        XTESTS_RUN_CASE(test_pantheios_onBailOut4_w);
        XTESTS_RUN_CASE(test_pantheios_onBailOut6_w);
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
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


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void test_unused_receiver()
{
    receiver.Clear();

#ifdef TEST_ODS_
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.OutputDebugStringResults.size());
#endif

#ifdef TEST_CONSOLE_
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.ConsoleResults.size());
#endif

#ifdef TEST_LBT_
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.LoggingBailoutTxtResults.size());
#endif

#if TEST_EVLOG_
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.EventLogResults.size());
#endif

#if TEST_SYSLOG_
    XTESTS_TEST_INTEGER_EQUAL(0u, receiver.SyslogResults.size());
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_pantheios_onBailOut3()
{
    receiver.Clear();

    const char  message[]   =   "hello";
    const char  pattern[]   =   "2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello";

    pantheios_onBailOut3(PANTHEIOS_SEV_DEBUG, message, "process-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, receiver.SyslogResults[0].message);
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

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_no_qual, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_no_qual, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_no_qual, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_no_qual, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_no_qual, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut4(PANTHEIOS_SEV_DEBUG, message, "process-#1", qualifier_1);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_1, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_1, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_1, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_1, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_1, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut4(PANTHEIOS_SEV_DEBUG, message, "process-#1", qualifier_2);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_2, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_2, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_2, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_2, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_qual_2, receiver.SyslogResults[0].message);
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

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_none, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_none, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_none, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_none, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_none, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", "fe-#1", NULL);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_fe, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_fe, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_fe, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_fe, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_fe, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", NULL, "be-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_be, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_be, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_be, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_be, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_be, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "qual-#1", "fe-#1", "be-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_febe, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_febe, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_febe, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_febe, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_febe, receiver.SyslogResults[0].message);
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

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_short, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_short, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_short, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_short, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_short, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "a-longish-qualifier-#1", "a-longish-front-end-#1", "a-longish-back-end-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_1, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_1, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_1, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_1, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_1, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "a-fair-bit-more-than-fairish-amount-longer-qualifier-#1", "a-fair-bit-more-than-fairish-amount-longer-front-end-#1", "a-fair-bit-more-than-fairish-amount-longer-back-end-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_2, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_2, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_2, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_2, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_medium_2, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver.Clear();

    pantheios_onBailOut6(PANTHEIOS_SEV_DEBUG, message, "process-#1", "a-much-much-much-much-much-much-much-much-longer-qualifier-#1", "a-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-long-name-for-a-front-end-#1", "a-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-very-long-name-for-a-back-end-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.OutputDebugStringResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_long, receiver.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.ConsoleResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_long, receiver.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_long, receiver.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.EventLogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_long, receiver.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver.SyslogResults.size()));
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern_long, receiver.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

#ifdef PANTHEIOS_USE_WIDE_STRINGS

static void test_pantheios_onBailOut3_w()
{
    receiver.Clear();

    const wchar_t   message[]   =   L"hello";
    const wchar_t   pattern[]   =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello";


    pantheios_onBailOut3_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern, receiver_w.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern, receiver_w.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_pantheios_onBailOut4_w()
{
    wchar_t const   message[]           =   L"hello";
    wchar_t const   pattern_no_qual[]   =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello";
    wchar_t const   qualifier_1[]       =                                                                                                L"qualifier";
    wchar_t const   pattern_qual_1[]    =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: qualifier";
    wchar_t const   qualifier_2[]       =                                                                                                L"and now for a much longer qualifier, that will exercise some of the limits of messages that may be passed to the bail-out function(s) as there is a concern that the limits of some of the static buffers may be exceeded by very very very very very very long strings";
#if PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE == 200
    wchar_t const   pattern_qual_2[]    =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: and now for a much longer qualifier, that will exercise some of the limits of messages that may be passed to the bail-out function(s) as there is a concern that the limi";//"ts of some of the static buffers may be exceeded by very very very very very very long strings";
#else
# error
#endif


    receiver_w.Clear();

    pantheios_onBailOut4_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", NULL);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_no_qual, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_no_qual, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_no_qual, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_no_qual, receiver_w.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_no_qual, receiver_w.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver_w.Clear();

    pantheios_onBailOut4_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", qualifier_1);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_1, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_1, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_1, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_1, receiver_w.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_1, receiver_w.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver_w.Clear();

    pantheios_onBailOut4_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", qualifier_2);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_2, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_2, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_2, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_2, receiver_w.EventLogResults[0].message);
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_qual_2, receiver_w.SyslogResults[0].message);
#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_pantheios_onBailOut6_w()
{
    const wchar_t   message[]           =   L"hello";
    const wchar_t   pattern_noqual[]    =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello";
    const wchar_t   pattern_none[]      =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: qual-#1";
    const wchar_t   pattern_fe[]        =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=fe-#1: qual-#1";
    const wchar_t   pattern_be[]        =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: be=be-#1: qual-#1";
    const wchar_t   pattern_febe[]      =   L"2[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9].[0-9][0-9][0-9]: hello: fe=fe-#1, be=be-#1: qual-#1";


    receiver_w.Clear();

    pantheios_onBailOut6_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", NULL, NULL, NULL);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_noqual, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_noqual, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_noqual, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver_w.Clear();

    pantheios_onBailOut6_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", L"qual-#1", NULL, NULL);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_none, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_none, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_none, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver_w.Clear();

    pantheios_onBailOut6_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", L"qual-#1", L"fe-#1", NULL);

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_fe, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_fe, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_fe, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver_w.Clear();

    pantheios_onBailOut6_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", L"qual-#1", NULL, L"be-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_be, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_be, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_be, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */


    receiver_w.Clear();

    pantheios_onBailOut6_w(PANTHEIOS_SEV_DEBUG, message, L"process-#1", L"qual-#1", L"fe-#1", L"be-#1");

#ifdef TEST_ODS_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.OutputDebugStringResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_febe, receiver_w.OutputDebugStringResults[0].message);
#endif

#ifdef TEST_CONSOLE_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.ConsoleResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_febe, receiver_w.ConsoleResults[0].message);
#endif

#ifdef TEST_LBT_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.LoggingBailoutTxtResults.size()));
    XTESTS_TEST_WIDE_STRING_MATCHES(pattern_febe, receiver_w.LoggingBailoutTxtResults[0].message);
#endif

#if TEST_EVLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.EventLogResults.size()));
#endif

#if TEST_SYSLOG_
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, receiver_w.SyslogResults.size()));
#endif /* PLATFORMSTL_OS_IS_UNIX */
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

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


/* /////////////////////////////////////////////////////////////////////////
 * hook function declarations
 */

#include <stdio.h>

#if defined(PLATFORMSTL_OS_IS_UNIX)

# include <unistd.h>
#endif /* PLATFORMSTL_OS_IS_UNIX */

#define fprintf                                             bailout_test_fprintf_
void bailout_test_fprintf_(FILE*, char const*, int, char const*);

#define fopen(fileName, mode)                               bailout_test_fopen_(fileName, mode)
FILE* bailout_test_fopen_(char const* filename, char const* mode);

#define fclose                                              bailout_fclose_
void bailout_fclose_(FILE* hFile);

#ifdef PANTHEIOS_USE_WIDE_STRINGS

#define fwprintf                                            bailout_test_fwprintf_
void bailout_test_fwprintf_(FILE* f, wchar_t const*, int cchMsg, wchar_t const* msg);

# define _wfopen(fileName, mode)                            bailout_test_fopen_(fileName, mode)
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


#include <pantheios/internal/safestr.h>

#ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS

# define fopen_s(phFile, fileName, mode)                    bailout_test_fopen_s_(phFile, fileName, mode)
int bailout_test_fopen_s_(FILE**, void const*, void const*);


# ifdef PANTHEIOS_USE_WIDE_STRINGS

#  define _wfopen_s(phFile, fileName, mode)                 bailout_test_fopen_s_(phFile, fileName, mode)
# endif /* PANTHEIOS_USE_WIDE_STRINGS */

#endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */



#if defined(PLATFORMSTL_OS_IS_WINDOWS)

# include <windows.h>

# define CreateFileA                                        bailout_test_CreateFileA
HANDLE bailout_test_CreateFileA(char const*, DWORD, DWORD, void*, DWORD, DWORD, void*);

# define GetStdHandle(x)                                    bailout_test_GetStdHandle_()
FILE* bailout_test_GetStdHandle_(void);

# define OutputDebugStringA                                 bailout_test_OutputDebugStringA_
void bailout_test_OutputDebugStringA_(char const*);

# define WriteFile                                          bailout_test_WriteFile_
void bailout_test_WriteFile_(FILE*, char const*, DWORD, DWORD*, void*);
void bailout_test_WriteFile_(HANDLE, char const*, DWORD, DWORD*, void*);

# ifdef PANTHEIOS_USE_WIDE_STRINGS

#  define CreateFileW                                       bailout_test_CreateFileW
HANDLE bailout_test_CreateFileW(wchar_t const*, DWORD, DWORD, void*, DWORD, DWORD, void*);

#  define OutputDebugStringW                                bailout_test_OutputDebugStringW_
void bailout_test_OutputDebugStringW_(wchar_t const*);

void bailout_test_WriteFile_(FILE*, wchar_t const*, DWORD, DWORD*, void*);
void bailout_test_WriteFile_(HANDLE, wchar_t const*, DWORD, DWORD*, void*);
# endif /* PANTHEIOS_USE_WIDE_STRINGS */
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

#include <../src/util/bailout.c>
#include <../src/util/snprintf.c>


/* /////////////////////////////////////////////////////////////////////////
 * hook function implementations
 */

#ifdef TEST_ODS_

void bailout_test_OutputDebugStringA_(char const* msg)
{
    receiver.onOutputDebugString(msg);
}
# ifdef PANTHEIOS_USE_WIDE_STRINGS

void bailout_test_OutputDebugStringW_(wchar_t const* msg)
{
    receiver_w.onOutputDebugString(msg);
}
# endif /* PANTHEIOS_USE_WIDE_STRINGS */
#endif

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

void bailout_test_WriteFile_(FILE*, char const* msg, DWORD cchMsg, DWORD*, void*)
{
    receiver.onConsole(OnBailoutReceiver::string_type(msg, cchMsg - 2));
}

void bailout_test_WriteFile_(HANDLE, char const* msg, DWORD cchMsg, DWORD*, void*)
{
    receiver.onFILE(OnBailoutReceiver::string_type(msg, cchMsg - 2));
}

FILE* bailout_test_GetStdHandle_(void)
{
    return NULL;
}

HANDLE bailout_test_CreateFileA(char const*, DWORD, DWORD, void*, DWORD, DWORD, void*)
{
    return reinterpret_cast<HANDLE>(+1234567);
}

# ifdef PANTHEIOS_USE_WIDE_STRINGS

void bailout_test_WriteFile_(FILE*, wchar_t const* msg, DWORD cchMsg, DWORD*, void*)
{
    receiver_w.onConsole(OnBailoutReceiver_w::string_type(msg, cchMsg - 2));
}

void bailout_test_WriteFile_(HANDLE, wchar_t const* msg, DWORD cchMsg, DWORD*, void*)
{
    receiver_w.onFILE(OnBailoutReceiver_w::string_type(msg, cchMsg - 2));
}

HANDLE bailout_test_CreateFileW(wchar_t const*, DWORD, DWORD, void*, DWORD, DWORD, void*)
{
    return reinterpret_cast<HANDLE>(+1234567);
}
# endif /* PANTHEIOS_USE_WIDE_STRINGS */
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

void bailout_test_fprintf_(FILE* f, char const*, int cchMsg, char const* msg)
{
    if (stderr == f)
    {
        receiver.onConsole(OnBailoutReceiver::string_type(msg, size_t(cchMsg)));
    }
    else
    {
        receiver.onFILE(OnBailoutReceiver::string_type(msg, size_t(cchMsg)));
    }
}

# ifdef PANTHEIOS_USE_WIDE_STRINGS

void bailout_test_fwprintf_(FILE* f, wchar_t const*, int cchMsg, wchar_t const* msg)
{
    if (stderr == f)
    {
        receiver_w.onConsole(OnBailoutReceiver_w::string_type(msg, size_t(cchMsg)));
    }
    else
    {
        receiver_w.onFILE(OnBailoutReceiver_w::string_type(msg, size_t(cchMsg)));
    }
}
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

FILE* bailout_test_fopen_(char const* filename, char const* mode)
{
    STLSOFT_SUPPRESS_UNUSED(filename);
    STLSOFT_SUPPRESS_UNUSED(mode);

    return NULL;
}

int bailout_test_fopen_s_(FILE** phFile, void const*, void const*)
{
    *phFile = NULL;

    return 0;
}

#undef fclose

void bailout_fclose_(FILE* hFile)
{
    if (NULL != hFile)
    {
        fclose(hFile);
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

