/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/inserters/m2w/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.inserter.m2w project.
 *
 * Created: 22nd November 2010
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>

#ifndef PANTHEIOS_USE_WIDE_STRINGS
# error This project only valid in wide-string builds
#endif

#include <pantheios/inserters/m2w.hpp>

#include <xtests/terse-api.h>

#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/util/limit_traits.h>
#include <stlsoft/util/minmax.hpp>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void TEST_pantheios_m2w_MATCHES_stlsoft_m2w();
} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = L"test.unit.inserter.m2w";

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.inserter.m2w", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_m2w_MATCHES_stlsoft_m2w);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{
    char const* strings[] =
    {
            ""
        ,   "a"
        ,   "ab"
        ,   "abc"
        ,   "abcd"
        ,   "abcde"
        ,   "abcdef"
        ,   "abcdefghijklmnopqrstuvwxyz"
        ,   "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789"
    };


static void TEST_pantheios_m2w_MATCHES_stlsoft_m2w()
{
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
    {
        TEST_WS_EQ(stlsoft::m2w(strings[i]), pantheios::m2w(strings[i]));
    }}
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

