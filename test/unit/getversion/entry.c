/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/getversion/entry.c
 *
 * Purpose: Implementation file for the test.unit.getversion project.
 *
 * Created: 28th August 2008
 * Updated: 13th October 2026
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

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_pantheios_getVersion_SIGNATURE(void);
static void TEST_pantheios_getVersion_CALL(void);
static void TEST_pantheios_getVersion_VERSION(void);
static void TEST_pantheios_getVersion_MAJOR(void);
static void TEST_pantheios_getVersion_MINOR(void);
static void TEST_pantheios_getVersion_PATCH(void);
static void TEST_pantheios_getVersion_REVISION(void);
static void TEST_pantheios_getVersion_ALPHABETA(void);
static void TEST_pantheios_getVersion_COMPOSITE(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.getversion", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_SIGNATURE);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_CALL);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_VERSION);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_MAJOR);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_MINOR);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_PATCH);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_REVISION);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_ALPHABETA);
        XTESTS_RUN_CASE(TEST_pantheios_getVersion_COMPOSITE);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void TEST_pantheios_getVersion_SIGNATURE(void)
{
    pan_uint32_t (PANTHEIOS_CALLCONV *pfn)(void) = pantheios_getVersion;

    TEST_FNPTR_NE(((pan_uint32_t (PANTHEIOS_CALLCONV *)(void))0), pfn);
}

static void TEST_pantheios_getVersion_CALL(void)
{
    pantheios_getVersion();

    TEST_PASSED();
}

static void TEST_pantheios_getVersion_VERSION(void)
{
    pan_uint32_t const ver = pantheios_getVersion();

    TEST_INT_EQ(PANTHEIOS_VER, ver);
}

static void TEST_pantheios_getVersion_MAJOR(void)
{
    pan_uint32_t const verMajor = (pantheios_getVersion() & 0xff000000) >> 24;

    TEST_INT_EQ(PANTHEIOS_VER_MAJOR, verMajor);
}

static void TEST_pantheios_getVersion_MINOR(void)
{
    pan_uint32_t const verMinor = (pantheios_getVersion() & 0x00ff0000) >> 16;

    TEST_INT_EQ(PANTHEIOS_VER_MINOR, verMinor);
}

static void TEST_pantheios_getVersion_PATCH(void)
{
    pan_uint32_t const verPatch = (pantheios_getVersion() & 0x0000ff00) >> 8;

    TEST_INT_EQ(PANTHEIOS_VER_PATCH, verPatch);
}

static void TEST_pantheios_getVersion_REVISION(void)
{
    pan_uint32_t const verRevision = (pantheios_getVersion() & 0x0000ff00) >> 8;

    TEST_INT_EQ(PANTHEIOS_VER_REVISION, verRevision);
    TEST_INT_EQ(PANTHEIOS_VER_PATCH, PANTHEIOS_VER_REVISION);
}

static void TEST_pantheios_getVersion_ALPHABETA(void)
{
    pan_uint32_t const verAlphabeta = pantheios_getVersion() & 0x000000ff;

    TEST_INT_EQ(PANTHEIOS_VER_RELSTATUS, verAlphabeta);
    TEST_INT_EQ(PANTHEIOS_VER_AB, verAlphabeta);
    TEST_INT_EQ(PANTHEIOS_VER_ALPHABETA, verAlphabeta);
}

static void TEST_pantheios_getVersion_COMPOSITE(void)
{
    pan_uint32_t const expected = (pan_uint32_t)(
        0
    |   (PANTHEIOS_VER_MAJOR    << 24)
    |   (PANTHEIOS_VER_MINOR    << 16)
    |   (PANTHEIOS_VER_PATCH    <<  8)
    |   (PANTHEIOS_VER_AB       <<  0)
    );

    TEST_INT_EQ(expected, PANTHEIOS_VER);
    TEST_INT_EQ(expected, pantheios_getVersion());
    TEST_INT_EQ(PANTHEIOS_VER_1_0_1_RC4, PANTHEIOS_VER);
}


/* ///////////////////////////// end of file //////////////////////////// */

