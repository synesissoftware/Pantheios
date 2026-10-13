/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/fe.WindowsRegistry/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.fe.WindowsRegistry project.
 *
 * Created: 14th May 2008
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

#include <pantheios/frontends/fe.WindowsRegistry.h>
#include <pantheios/init_codes.h>

#include <xtests/terse-api.h>

#include <stlsoft/stlsoft.h>                        /* for STLSOFT_NUM_ELEMENTS */
#include <stlsoft/conversion/integer_to_string.hpp> /* stlsoft::integer_to_string */
#include <stlsoft/synch/lock_scope.hpp>             /* stlsoft::lock_scope */
#include <winstl/synch/process_mutex.hpp>           /* winstl::process_mutex */
#include <winstl/registry/reg_key.hpp>              /* for Windows Registry Library reg_key class */

#include <stdio.h>                                  /* for fprintf() */
#include <stdlib.h>                                 /* for EXIT_SUCCESS, EXIT_FAILURE */

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

#ifndef DEBUG_LOG_NOTICE
# define DEBUG_LOG_NOTICE(x)                                ::OutputDebugString(PANTHEIOS_LITERAL_STRING(x))
#endif // DEBUG_LOG_NOTICE

#ifdef PSTR
# undef PSTR
#endif
#define PSTR                                                PANTHEIOS_LITERAL_STRING


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.fe.WindowsRegistry");


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_fe_WindowsRegistry_CAN_INIT(void);
    static void TEST_fe_WindowsRegistry_CANNOT_INIT(void);
    static void TEST_fe_WindowsRegistry_LEVELS_IN_HKCU(void);
    static void TEST_fe_WindowsRegistry_LEVELS_IN_HKLM(void);
    static void TEST_fe_WindowsRegistry_HKCU_OVERRIDES_HKLM(void);
    static void TEST_fe_WindowsRegistry_STAR(void);
    static void TEST_fe_WindowsRegistry_CLEANUP(void);

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char* argv[])
{
    // Lock out other test program instances, otherwise they'll interfere
    // with each other

    winstl::process_mutex                       mx("test.unit.fe.WindowsRegistry.MX");
    stlsoft::lock_scope<winstl::process_mutex>  lock(mx);

    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.fe.WindowsRegistry", verbosity))
    {
        XTESTS_RUN_CASE(TEST_fe_WindowsRegistry_CAN_INIT);
        XTESTS_RUN_CASE(TEST_fe_WindowsRegistry_CANNOT_INIT);
        XTESTS_RUN_CASE(TEST_fe_WindowsRegistry_LEVELS_IN_HKCU);
        XTESTS_RUN_CASE(TEST_fe_WindowsRegistry_LEVELS_IN_HKLM);
        XTESTS_RUN_CASE(TEST_fe_WindowsRegistry_HKCU_OVERRIDES_HKLM);
        XTESTS_RUN_CASE(TEST_fe_WindowsRegistry_STAR);
        XTESTS_RUN_CASE(TEST_fe_WindowsRegistry_CLEANUP);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

int main(int argc, char* argv[])
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return main_(argc, argv);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch (std::bad_alloc&)
    {
        fprintf(stderr, "out of memory\n");
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "exception: %s\n", x.what());
    }
    catch (...)
    {
        fprintf(stderr, "unexpected condition\n");
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    return EXIT_FAILURE;
}

namespace stub
{

    PANTHEIOS_CALL(void) pantheios_onBailOut3(int severity, char const* message, char const* processId);
    PANTHEIOS_CALL(void) pantheios_onBailOut3(int severity, char const* message, char const* processId)
    {
#if 0
        fprintf(stdout, "%d: %s: %s", severity, (NULL != processId) ? processId : "", message);
        fprintf(stderr, "%d: %s: %s", severity, (NULL != processId) ? processId : "", message);
#else /* ? 0 */
        STLSOFT_SUPPRESS_UNUSED(severity);
        STLSOFT_SUPPRESS_UNUSED(message);
        STLSOFT_SUPPRESS_UNUSED(processId);
#endif /* 0 */
    }

    PANTHEIOS_CALL(void) pantheios_onBailOut6(
        int           severity
    ,   char const*   message
    ,   char const*   processId
    ,   char const*   qualifier
    ,   char const*   frontEndName
    ,   char const*   backEndName
    );
    PANTHEIOS_CALL(void) pantheios_onBailOut6(
        int           severity
    ,   char const*   message
    ,   char const*   processId
    ,   char const*   qualifier
    ,   char const*   frontEndName
    ,   char const*   backEndName
    )
    {
        STLSOFT_SUPPRESS_UNUSED(severity);
        STLSOFT_SUPPRESS_UNUSED(message);
        STLSOFT_SUPPRESS_UNUSED(processId);
        STLSOFT_SUPPRESS_UNUSED(qualifier);
        STLSOFT_SUPPRESS_UNUSED(frontEndName);
        STLSOFT_SUPPRESS_UNUSED(backEndName);
    }

} /* namespace stub */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if _STLSOFT_VER >= 0x010a0000 && \
    _STLSOFT_VER < 0x010c0000

# define windows_exception                                  winstl_exception
#endif


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

namespace
{

inline
DWORD
get_exception_status_code(
    winstl::windows_exception& x
)
{
#if _STLSOFT_VER >= 0x010a0181

    return x.status_code();
#else

    return x.get_error_code();
#endif
}

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
    static PAN_CHAR_T const ROOT_KEY_PATH[] = PANTHEIOS_LITERAL_STRING("SOFTWARE\\Synesis Software\\Logging Tools\\Pantheios\\fe.WindowsRegistry");

    static const int s_severityLevels[] =
    {
            PANTHEIOS_SEV_EMERGENCY
        ,   PANTHEIOS_SEV_ALERT
        ,   PANTHEIOS_SEV_CRITICAL
        ,   PANTHEIOS_SEV_ERROR
        ,   PANTHEIOS_SEV_WARNING
        ,   PANTHEIOS_SEV_NOTICE
        ,   PANTHEIOS_SEV_INFORMATIONAL
        ,   PANTHEIOS_SEV_DEBUG
    };


    static void ensure_HKCU(int debugLevel, int releaseLevel, int starLevel)
    {
        winstl::reg_key     key0 = winstl::reg_key::create_key(HKEY_CURRENT_USER, ROOT_KEY_PATH);
        winstl::reg_key     key = key0.create_sub_key(PANTHEIOS_FE_PROCESS_IDENTITY);

        if (debugLevel >= 0)
        {
            key.set_value(PSTR("Debug"), DWORD(debugLevel));
        }
        if (releaseLevel >= 0)
        {
            key.set_value(PSTR("Release"), DWORD(releaseLevel));
        }
        if (starLevel >= 0)
        {
            key.set_value(PSTR("*"), DWORD(starLevel));
        }
    }

    static bool ensure_HKLM(int debugLevel, int releaseLevel, int starLevel)
    {
        try
        {
            winstl::reg_key     key0 = winstl::reg_key::create_key(HKEY_LOCAL_MACHINE, ROOT_KEY_PATH);
            winstl::reg_key     key = key0.create_sub_key(PANTHEIOS_FE_PROCESS_IDENTITY);

            if (debugLevel >= 0)
            {
                key.set_value(PSTR("Debug"), DWORD(debugLevel));
            }
            if (releaseLevel >= 0)
            {
                key.set_value(PSTR("Release"), DWORD(releaseLevel));
            }
            if (starLevel >= 0)
            {
                key.set_value(PSTR("*"), DWORD(starLevel));
            }

            return true;
        }
        catch (winstl::windows_exception& x)
        {
            if (ERROR_ACCESS_DENIED == get_exception_status_code(x))
            {
                return false;
            }
            else
            {
                throw;
            }
        }
    }

    static void delete_HKCU()
    {
        winstl::reg_key     key0 = winstl::reg_key::create_key(HKEY_CURRENT_USER, ROOT_KEY_PATH);

        key0.delete_sub_key(PANTHEIOS_FE_PROCESS_IDENTITY);
    }

    static bool delete_HKLM()
    {
        try
        {
            winstl::reg_key     key0 = winstl::reg_key::create_key(HKEY_LOCAL_MACHINE, ROOT_KEY_PATH);

            key0.delete_sub_key(PANTHEIOS_FE_PROCESS_IDENTITY);

            return true;
        }
        catch (winstl::windows_exception& x)
        {
            if (ERROR_ACCESS_DENIED == get_exception_status_code(x))
            {
                return false;
            }
            else
            {
                throw;
            }
        }
    }

static void TEST_fe_WindowsRegistry_CAN_INIT()
{
    // Ensure that the HKCU key exists
    ensure_HKCU(0, 0, 0);
    if (!delete_HKLM())
    {
        DEBUG_LOG_NOTICE("could not change HKEY_LOCAL_MACHINE, so skipping test case");

        return;
    }

    void*   token;
    int     res;

    res = pantheios_fe_init(NULL, &token);

    TEST_INT_EQ(PANTHEIOS_INIT_RC_SUCCESS, res);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        char    num[21];

        TEST_FAIL_WITH_QUALIFIER("failed to initialise front-end", stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), res));
    }
    else
    {
        TEST_PASSED();

        pantheios_fe_uninit(token);
    }
}

static void TEST_fe_WindowsRegistry_CANNOT_INIT()
{
    // Ensure that neither the HKCU key nor the HKLM key exist
    delete_HKCU();
    if (!delete_HKLM())
    {
        DEBUG_LOG_NOTICE("could not change HKEY_LOCAL_MACHINE, so skipping test case");

        return;
    }

    void*   token;
    int     res;

    res = pantheios_fe_init(NULL, &token);

    TEST_INT_NE(PANTHEIOS_INIT_RC_SUCCESS, res);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_PASSED();
    }
    else
    {
        TEST_FAIL("unexpectedly able to initialise front-end");

        pantheios_fe_uninit(token);
    }
}

static void TEST_fe_WindowsRegistry_LEVELS_IN_HKCU()
{
    // Ensure that the HKCU key exists, and has the right levels
    ensure_HKCU(0xff, 0x3f, -1);
    if (!delete_HKLM())
    {
        DEBUG_LOG_NOTICE("could not change HKEY_LOCAL_MACHINE, so skipping test case");

        return;
    }

    static const int s_severityLevelResults[] =
    {
            1
        ,   1
        ,   1
        ,   1
        ,   1
        ,   1
#ifdef NDEBUG
        ,   0
        ,   0
#else /* ? NDEBUG */
        ,   1
        ,   1
#endif /* NDEBUG */
    };

    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(s_severityLevels) == STLSOFT_NUM_ELEMENTS(s_severityLevelResults));

    void*   token;
    int     res;

    res = pantheios_fe_init(NULL, &token);

    TEST_INT_EQ(PANTHEIOS_INIT_RC_SUCCESS, res);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        char    num[21];

        TEST_FAIL_WITH_QUALIFIER("failed to initialise front-end", stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), res));
    }
    else
    {
        TEST_PASSED();

        // Now verify the levels
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_severityLevels); ++i)
        {
            int b = pantheios_fe_isSeverityLogged(token, s_severityLevels[i], 0);

            TEST_INT_EQ(s_severityLevelResults[i], b);
        }}

        pantheios_fe_uninit(token);
    }
}

static void TEST_fe_WindowsRegistry_LEVELS_IN_HKLM()
{
    // Ensure that the HKCU key exists, and has the right levels
    delete_HKCU();
    if (!ensure_HKLM(0xff, 0x3f, -1))
    {
        DEBUG_LOG_NOTICE("could not change HKEY_LOCAL_MACHINE, so skipping test case");

        return;
    }

    static const int s_severityLevelResults[] =
    {
            1
        ,   1
        ,   1
        ,   1
        ,   1
        ,   1
#ifdef NDEBUG
        ,   0
        ,   0
#else /* ? NDEBUG */
        ,   1
        ,   1
#endif /* NDEBUG */
    };

    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(s_severityLevels) == STLSOFT_NUM_ELEMENTS(s_severityLevelResults));

    void*   token;
    int     res;

    res = pantheios_fe_init(NULL, &token);

    TEST_INT_EQ(PANTHEIOS_INIT_RC_SUCCESS, res);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        char    num[21];

        TEST_FAIL_WITH_QUALIFIER("failed to initialise front-end", stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), res));
    }
    else
    {
        TEST_PASSED();

        // Now verify the levels
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_severityLevels); ++i)
        {
            int b = pantheios_fe_isSeverityLogged(token, s_severityLevels[i], 0);

            TEST_INT_EQ(s_severityLevelResults[i], b);
        }}

        pantheios_fe_uninit(token);
    }
}

static void TEST_fe_WindowsRegistry_HKCU_OVERRIDES_HKLM()
{
    // Ensure that the HKCU key exists, and has the right levels
    ensure_HKCU(0xff, 0x3f, -1);
    if (!ensure_HKLM(0, 0, 0))
    {
        DEBUG_LOG_NOTICE("could not change HKEY_LOCAL_MACHINE, so skipping test case");

        return;
    }

    static const int s_severityLevelResults[] =
    {
            1
        ,   1
        ,   1
        ,   1
        ,   1
        ,   1
#ifdef NDEBUG
        ,   0
        ,   0
#else /* ? NDEBUG */
        ,   1
        ,   1
#endif /* NDEBUG */
    };

    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(s_severityLevels) == STLSOFT_NUM_ELEMENTS(s_severityLevelResults));

    void*   token;
    int     res;

    res = pantheios_fe_init(NULL, &token);

    TEST_INT_EQ(PANTHEIOS_INIT_RC_SUCCESS, res);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        char    num[21];

        TEST_FAIL_WITH_QUALIFIER("failed to initialise front-end", stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), res));
    }
    else
    {
        TEST_PASSED();

        // Now verify the levels
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_severityLevels); ++i)
        {
            int b = pantheios_fe_isSeverityLogged(token, s_severityLevels[i], 0);

            TEST_INT_EQ(s_severityLevelResults[i], b);
        }}

        pantheios_fe_uninit(token);
    }
}

static void TEST_fe_WindowsRegistry_STAR()
{
    // Ensure that the HKCU key exists, and has the right levels
    delete_HKCU();
    ensure_HKCU(-1, -1, 0x0f);
    if (!delete_HKLM())
    {
        DEBUG_LOG_NOTICE("could not change HKEY_LOCAL_MACHINE, so skipping test case");

        return;
    }

    static const int s_severityLevelResults[] =
    {
            1
        ,   1
        ,   1
        ,   1
        ,   0
        ,   0
        ,   0
        ,   0
    };

    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(s_severityLevels) == STLSOFT_NUM_ELEMENTS(s_severityLevelResults));

    void*   token;
    int     res;

    res = pantheios_fe_init(NULL, &token);

    TEST_INT_EQ(PANTHEIOS_INIT_RC_SUCCESS, res);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        char    num[21];

        TEST_FAIL_WITH_QUALIFIER("failed to initialise front-end", stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), res));
    }
    else
    {
        TEST_PASSED();

        // Now verify the levels
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_severityLevels); ++i)
        {
            int b = pantheios_fe_isSeverityLogged(token, s_severityLevels[i], 0);

            TEST_INT_EQ(s_severityLevelResults[i], b);
        }}

        pantheios_fe_uninit(token);
    }
}


static void TEST_fe_WindowsRegistry_CLEANUP()
{
    delete_HKCU();
    delete_HKLM();

    TEST_PASSED();
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

