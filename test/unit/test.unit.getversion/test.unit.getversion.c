/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.getversion/test.unit.getversion.c
 *
 * Purpose: Implementation file for the test.unit.getversion project.
 *
 * Created: 28th August 2008
 * Updated: 5th August 2026
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
#include <xtests/terse-api.h>
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_signature(void);
static void test_call(void);
static void test_version(void);
static void test_major(void);
static void test_minor(void);
static void test_patch(void);
static void test_revision(void);
static void test_alphabeta(void);
static void test_composite(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.getversion", verbosity))
    {
        XTESTS_RUN_CASE(test_signature);
        XTESTS_RUN_CASE(test_call);
        XTESTS_RUN_CASE(test_version);
        XTESTS_RUN_CASE(test_major);
        XTESTS_RUN_CASE(test_minor);
        XTESTS_RUN_CASE(test_patch);
        XTESTS_RUN_CASE(test_revision);
        XTESTS_RUN_CASE(test_alphabeta);
        XTESTS_RUN_CASE(test_composite);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_signature(void)
{
    pan_uint32_t (PANTHEIOS_CALLCONV *pfn)(void) = pantheios_getVersion;

    TEST_FNPTR_NE(((pan_uint32_t (PANTHEIOS_CALLCONV *)(void))0), pfn);
}

static void test_call(void)
{
    pantheios_getVersion();

    TEST_PASSED();
}

static void test_version(void)
{
    pan_uint32_t const ver = pantheios_getVersion();

    TEST_INT_EQ(PANTHEIOS_VER, ver);
}

static void test_major(void)
{
    pan_uint32_t const verMajor = (pantheios_getVersion() & 0xff000000) >> 24;

    TEST_INT_EQ(PANTHEIOS_VER_MAJOR, verMajor);
}

static void test_minor(void)
{
    pan_uint32_t const verMinor = (pantheios_getVersion() & 0x00ff0000) >> 16;

    TEST_INT_EQ(PANTHEIOS_VER_MINOR, verMinor);
}

static void test_patch(void)
{
    pan_uint32_t const verPatch = (pantheios_getVersion() & 0x0000ff00) >> 8;

    TEST_INT_EQ(PANTHEIOS_VER_PATCH, verPatch);
}

static void test_revision(void)
{
    pan_uint32_t const verRevision = (pantheios_getVersion() & 0x0000ff00) >> 8;

    TEST_INT_EQ(PANTHEIOS_VER_REVISION, verRevision);
    TEST_INT_EQ(PANTHEIOS_VER_PATCH, PANTHEIOS_VER_REVISION);
}

static void test_alphabeta(void)
{
    pan_uint32_t const verAlphabeta = pantheios_getVersion() & 0x000000ff;

    TEST_INT_EQ(PANTHEIOS_VER_ALPHABETA, verAlphabeta);
}

static void test_composite(void)
{
    pan_uint32_t const expected = (pan_uint32_t)(
        0
    |   (PANTHEIOS_VER_MAJOR        << 24)
    |   (PANTHEIOS_VER_MINOR        << 16)
    |   (PANTHEIOS_VER_PATCH        <<  8)
    |   (PANTHEIOS_VER_ALPHABETA    <<  0)
    );

    TEST_INT_EQ(expected, PANTHEIOS_VER);
    TEST_INT_EQ(expected, pantheios_getVersion());
    TEST_INT_EQ(PANTHEIOS_VER_1_0_1_RC3, PANTHEIOS_VER);
}


/* ///////////////////////////// end of file //////////////////////////// */
