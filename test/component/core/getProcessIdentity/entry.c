/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/core/getProcessIdentity/entry.c
 *
 * Purpose: Implementation file for the test.component.core.getProcessIdentity project.
 *
 * Created: 6th August 2012
 * Updated: 10th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <pantheios/pantheios.h>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_0(void);
static void test_1_1(void);
static int setup(void*);
static int teardown(void*);
static void* s_param;


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.core.getProcessIdentity", verbosity, setup, teardown, s_param))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR                                                PANTHEIOS_LITERAL_STRING
#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * Pantheios front-end
 */

#include <pantheios/frontend.h>

static unsigned             s_numInits;
static unsigned             s_numUninits;
static unsigned             s_numGPI;
static unsigned             s_numISL;
static PAN_CHAR_T const*    s_PI_0;
static PAN_CHAR_T const*    s_PI_N;

PANTHEIOS_CALL(int) pantheios_fe_init(
    void*   reserved
,   void**  ptoken
)
{
    STLSOFT_SUPPRESS_UNUSED(reserved);
    STLSOFT_SUPPRESS_UNUSED(ptoken);

    ++s_numInits;

    return 0;
}
PANTHEIOS_CALL(void) pantheios_fe_uninit(void* token)
{
    STLSOFT_SUPPRESS_UNUSED(token);

    ++s_numUninits;
}
PANTHEIOS_CALL(PAN_CHAR_T const*) pantheios_fe_getProcessIdentity(void* token)
{
    STLSOFT_SUPPRESS_UNUSED(token);

    if (1 == ++s_numGPI)
    {
        return s_PI_0;
    }
    else
    {
        return s_PI_N;
    }
}
PANTHEIOS_CALL(int) pantheios_fe_isSeverityLogged(
    void*   token
,   int     severity
,   int     backEndId
)
{
    STLSOFT_SUPPRESS_UNUSED(token);
    STLSOFT_SUPPRESS_UNUSED(severity);
    STLSOFT_SUPPRESS_UNUSED(backEndId);

    ++s_numISL;

    return 0;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static int setup(void* param)
{
    STLSOFT_SUPPRESS_UNUSED(param);

    s_numInits = 0;
    s_numUninits = 0;
    s_numGPI = 0;
    s_numISL = 0;
    s_PI_0 = NULL;
    s_PI_N = NULL;

    return 0;
}

static int teardown(void* param)
{
    STLSOFT_SUPPRESS_UNUSED(param);

#if 0
    STLSOFT_ASSERT(0 == s_numInits);
    STLSOFT_ASSERT(0 == s_numUninits);
    STLSOFT_ASSERT(0 == s_numGPI);
    STLSOFT_ASSERT(0 == s_numISL);
    STLSOFT_ASSERT(NULL == s_PI);
#endif /* 0 */

    return 0;
}

static void test_1_0(void)
{
    PAN_CHAR_T const pi[] = PSTR("test_1_0");

    int r;

    s_PI_0 = pi;

    r = pantheios_init();

    XTESTS_TEST_INTEGER_EQUAL(1, s_numGPI);

    if (r < 0)
    {
        XTESTS_FAIL("could not initialise libraries");
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(1, s_numInits);
        XTESTS_TEST_INTEGER_EQUAL(0, s_numUninits);
        XTESTS_TEST_INTEGER_EQUAL(1, s_numGPI);

        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("test_1_0"), pantheios_getProcessIdentity());
        XTESTS_TEST_POINTER_NOT_EQUAL(pi, pantheios_getProcessIdentity());

        pantheios_uninit();

        XTESTS_TEST_INTEGER_EQUAL(1, s_numInits);
        XTESTS_TEST_INTEGER_EQUAL(1, s_numUninits);
        XTESTS_TEST_INTEGER_EQUAL(1, s_numGPI);
    }
}

static void test_1_1(void)
{
    PAN_CHAR_T const pi[] = PSTR("test_1_1");

    int r;

    s_PI_N = pi;

    r = pantheios_init();

    XTESTS_TEST_INTEGER_EQUAL(2, s_numGPI);

    if (r < 0)
    {
        XTESTS_FAIL("could not initialise libraries");
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(1, s_numInits);
        XTESTS_TEST_INTEGER_EQUAL(0, s_numUninits);
        XTESTS_TEST_INTEGER_EQUAL(2, s_numGPI);

        XTESTS_TEST_STRING_EQUAL(PANTHEIOS_LITERAL_STRING("test_1_1"), pantheios_getProcessIdentity());
        XTESTS_TEST_POINTER_EQUAL(pi, pantheios_getProcessIdentity());

        pantheios_uninit();

        XTESTS_TEST_INTEGER_EQUAL(1, s_numInits);
        XTESTS_TEST_INTEGER_EQUAL(1, s_numUninits);
        XTESTS_TEST_INTEGER_EQUAL(4, s_numGPI);
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

