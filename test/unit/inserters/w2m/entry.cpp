/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/inserters/w2m/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.inserter.w2m project.
 *
 * Created: 21st December 2010
 * Updated: 29th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/pantheios.h>

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# error This project only valid in multibyte-string builds
#endif

#include <pantheios/inserters/w2m.hpp>

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

static void TEST_pantheios_w2m_MATCHES_stlsoft_w2m();
} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.inserter.w2m");

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.inserters.w2m", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_w2m_MATCHES_stlsoft_w2m);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{
    wchar_t const* strings[] =
    {
            L""
        ,   L"a"
        ,   L"ab"
        ,   L"abc"
        ,   L"abcd"
        ,   L"abcde"
        ,   L"abcdef"
        ,   L"abcdefghijklmnopqrstuvwxyz"
        ,   L"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789"
    };


static void TEST_pantheios_w2m_MATCHES_stlsoft_w2m()
{
    { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
    {
        TEST_MS_EQ(stlsoft::w2m(strings[i]), pantheios::w2m(strings[i]));
    }}
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

