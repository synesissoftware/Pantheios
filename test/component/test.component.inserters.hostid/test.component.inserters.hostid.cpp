/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/test.component.inserters.hostid/test.component.inserters.hostid.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.hostid project.
 *
 * Created: 14th April 2008
 * Updated: 27th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/inserters/hostid.hpp>   // for pantheios::hostId
#include <pantheios/backends/bec.test.h>

/* STLSoft header files */
#include <stlsoft/conversion/integer_to_string.hpp>
#include <platformstl/platformstl.h>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>                         // for exit codes
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <unistd.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <windows.h>
#else /* ? OS */
# error Not discriminated for platforms other than UNIX and Windows
#endif /* OS */


#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

typedef std::basic_string<PAN_CHAR_T>   string_t;


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_01();

static string_t pan_get_hid_();

/* ////////////////////////////////////////////////////////////////////// */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.hostid");


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define pantheios_GetComputerName_                         ::GetComputerNameW
# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define pantheios_GetComputerName_                         ::GetComputerNameA
# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inserters.hostid", verbosity))
    {
        XTESTS_RUN_CASE(test_1_01);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

static void test_1_01()
{
    // 1. Setup

    PAN_CHAR_T const  prefix[]  = PSTR("host: ");
    const string_t    hid       = pan_get_hid_();
    const string_t    stmt      = prefix + hid;



    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::hostId);
    pantheios::log_NOTICE(prefix, pantheios::hostId);


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_TEST_INTEGER_EQUAL(2, results.size());
    XTESTS_TEST_STRING_EQUAL(hid, results[0].statement);
    XTESTS_TEST_STRING_EQUAL(stmt, results[1].statement);
}

static string_t pan_get_hid_()
{
#if defined(PLATFORMSTL_OS_IS_UNIX)

    PAN_CHAR_T  szHostName[1001];

    if (0 != ::gethostname(&szHostName[0], STLSOFT_NUM_ELEMENTS(szHostName)))
    {
        return PANTHEIOS_LITERAL_STRING("localhost");
    }
    else
    {
        return szHostName;
    }

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    PAN_CHAR_T  szHostName[1001];
    DWORD       cchHostName = STLSOFT_NUM_ELEMENTS(szHostName);

    if (!pantheios_GetComputerName_(&szHostName[0], &cchHostName))
    {
        return PANTHEIOS_LITERAL_STRING("localhost");
    }
    else
    {
        return string_t(szHostName, static_cast<size_t>(cchHostName));
    }

#else /* ? OS */

# error Not discriminated for platforms other than UNIX and Windows

#endif /* OS */
}


/* ///////////////////////////// end of file //////////////////////////// */

