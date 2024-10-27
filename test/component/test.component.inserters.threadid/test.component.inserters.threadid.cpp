/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/test.component.inserters.threadid/test.component.inserters.threadid.cpp
 *
 * Purpose: Implementation file for the test.component.inserters.threadid project.
 *
 * Created: 17th October 2006
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/inserters/threadid.hpp> // for pantheios::threadId
#include <pantheios/backends/bec.test.h>
#include <pantheios/internal/threading.h>

/* STLSoft header files */
#include <stlsoft/conversion/integer_to_string.hpp>
#include <platformstl/platformstl.h>

/* Standard C header files */
#include <stdlib.h>                     // for exit codes
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <unistd.h>
#endif /* OS */

#ifdef PANTHEIOS_MT
# if defined(PLATFORMSTL_OS_IS_UNIX)
#  include <pthread.h>
# elif defined(PLATFORMSTL_OS_IS_WINDOWS)
#  include <windows.h>
# else /* ? OS */
#  error Not discriminated for platforms other than UNIX and Windows
# endif /* OS */
#endif /* PANTHEIOS_MT */

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_01();

static pantheios::sint64_t pan_get_tid_();


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.component.inserters.threadid");


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.inserters.threadid", verbosity))
    {
        XTESTS_RUN_CASE(test_1_01);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_1_01()
{
    // 1. Setup

    PAN_CHAR_T const  prefix[]    =   PSTR("thread: ");
    PAN_CHAR_T        tid_[21 + STLSOFT_NUM_ELEMENTS(prefix)];
    PAN_CHAR_T const* tid         =   stlsoft::integer_to_string(&tid_[0], STLSOFT_NUM_ELEMENTS(tid_), pan_get_tid_());
    PAN_CHAR_T const* stmt        =   tid - (STLSOFT_NUM_ELEMENTS(prefix) - 1);

    ::memcpy(const_cast<PAN_CHAR_T*>(stmt), prefix, sizeof(PAN_CHAR_T) * (STLSOFT_NUM_ELEMENTS(prefix) - 1));

    pantheios::be::test::reset();


    // 2. Create test data

    pantheios::log_NOTICE(pantheios::threadId);
    pantheios::log_NOTICE(prefix, pantheios::threadId);


    // 3. Verification

    pantheios::be::test::Results  results = pantheios::be::test::results();

    XTESTS_TEST(!results.empty());
    XTESTS_TEST_INTEGER_EQUAL(2, results.size());
    XTESTS_TEST_STRING_EQUAL(tid, results[0].statement);
    XTESTS_TEST_STRING_EQUAL(stmt, results[1].statement);
}

static pantheios::sint64_t pan_get_tid_()
{
#if defined(PLATFORMSTL_OS_IS_UNIX)

# ifdef PANTHEIOS_MT

    union
    {
        pantheios::sint64_t   u64;
        pthread_t           self;

    } u;

    STLSOFT_STATIC_ASSERT(sizeof(::pthread_self()) <= sizeof(pantheios::sint64_t));

    u.u64 = 0;
    u.self = ::pthread_self();

    return u.u64;
# else /* ? PANTHEIOS_MT */

    return 1;
# endif /* PANTHEIOS_MT */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    return static_cast<pantheios::sint64_t>(::GetCurrentThreadId());
#else /* ? OS */

# error Not discriminated for platforms other than UNIX and Windows
#endif /* OS */
}


/* ///////////////////////////// end of file //////////////////////////// */

