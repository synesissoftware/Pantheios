/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.getversion/test.unit.getversion.c
 *
 * Purpose:     Implementation file for the test.unit.getversion project.
 *
 * Created:     28th August 2008
 * Updated:     30th June 2016
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2016, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
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

static void test_signature(void);
static void test_call(void);
static void test_version(void);
static void test_major(void);
static void test_minor(void);
static void test_revision(void);

/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.getversion", verbosity))
    {
        XTESTS_RUN_CASE(test_signature);
        XTESTS_RUN_CASE(test_call);
        XTESTS_RUN_CASE(test_version);
        XTESTS_RUN_CASE(test_major);
        XTESTS_RUN_CASE(test_minor);
        XTESTS_RUN_CASE(test_revision);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_signature()
{
    pan_uint32_t (PANTHEIOS_CALLCONV *pfn)(void) = pantheios_getVersion;

    XTESTS_TEST(((pan_uint32_t (PANTHEIOS_CALLCONV *)(void))0) != pfn);
}

static void test_call()
{
    pantheios_getVersion();

    XTESTS_TEST_PASSED();
}

static void test_version()
{
    pan_uint32_t const ver = pantheios_getVersion();

    XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_VER, ver);
}

static void test_major()
{
    pan_uint32_t const verMajor = (pantheios_getVersion() & 0xff000000) >> 24;

    XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_VER_MAJOR, verMajor);
}

static void test_minor()
{
    pan_uint32_t const verMinor = (pantheios_getVersion() & 0x00ff0000) >> 16;

    XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_VER_MINOR, verMinor);
}

static void test_revision()
{
    pan_uint32_t const verRevision = (pantheios_getVersion() & 0x0000ff00) >> 8;

    XTESTS_TEST_INTEGER_EQUAL(PANTHEIOS_VER_REVISION, verRevision);
}

/* ///////////////////////////// end of file //////////////////////////// */
