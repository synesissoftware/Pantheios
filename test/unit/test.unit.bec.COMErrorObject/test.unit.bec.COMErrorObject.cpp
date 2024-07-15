/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.bec.COMErrorObject/test.unit.bec.COMErrorObject.cpp
 *
 * Purpose:     Implementation file for the test.unit.be.COMErrorObject project.
 *
 * Created:     1st January 2008
 * Updated:     16th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * preprocessor feature control
 */

//#define STLSOFT_TRACE_INCLUDE


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/backends/bec.COMErrorObject.h>
#include <pantheios/init_codes.h>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/shims/access/string.hpp>
#ifdef PANTHEIOS_STLSOFT_1_12_OR_LATER
# include <comstl/diagnostics/errorinfo_desc.hpp>
# include <comstl/diagnostics/errorinfo_functions.h>
#else /* ? PANTHEIOS_STLSOFT_1_12_OR_LATER */
# include <comstl/error/errorinfo_desc.hpp>
# include <comstl/error/errorinfo_functions.h>
#endif /* PANTHEIOS_STLSOFT_1_12_OR_LATER */
#include <comstl/util/initialisers.hpp>

/* Standard C++ header files */
#include <exception>                    // for std::exception
#include <new>                          // for std::bad_alloc

/* Standard C header files */
#include <stdio.h>                      // for fprintf()
#include <stdlib.h>                     // for exit codes

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PANTHEIOS_SEV_LEVELS_EQUAL(x, y)    XTESTS_TEST_INTEGER_EQUAL(static_cast<int>(x), static_cast<int>(y))


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL

#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.be.COMErrorObject");

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    static PAN_CHAR_T const* strings[] =
    {
            PANTHEIOS_LITERAL_STRING("abc")
        ,   PANTHEIOS_LITERAL_STRING("ABC")
        ,   PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz")
        ,   PANTHEIOS_LITERAL_STRING("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
        ,   PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    };
    static int severities[] =
    {
            PANTHEIOS_SEV_DEBUG
        ,   PANTHEIOS_SEV_INFORMATIONAL
        ,   PANTHEIOS_SEV_NOTICE
        ,   PANTHEIOS_SEV_WARNING
        ,   PANTHEIOS_SEV_ERROR
        ,   PANTHEIOS_SEV_CRITICAL
        ,   PANTHEIOS_SEV_ALERT
        ,   PANTHEIOS_SEV_EMERGENCY
    };

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.be.COMErrorObject", verbosity))
    {
        /* Case 1 - verifying be.COMErrorObject, with flags 0 */
        if (!XTESTS_CASE_BEGIN("case-1", "verifying be.COMErrorObject, with flags 0"))
        {
            retCode = EXIT_FAILURE;
        }
        else
        {
            pan_be_COMErrorObject_init_t    init;

            init.flags  =   0
//                      |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//                      |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                        |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                        ;

            void*   token;
            int     res = pantheios_be_COMErrorObject_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

            if (PANTHEIOS_INIT_RC_SUCCESS != res)
            {
                XTESTS_FAIL_WITH_QUALIFIER("failed to initialise bec.COMErrorObject", pantheios::getInitErrorString(res));
            }
            else
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(severities); ++i)
                {
                    { for (size_t j = 0; j != STLSOFT_NUM_ELEMENTS(strings); ++j)
                    {
                        const int severity = severities[i];

                        pantheios_be_COMErrorObject_logEntry(NULL, token, severity, strings[j], stlsoft::c_str_len(strings[j]));

                        if (PANTHEIOS_SEV_DEBUG == severity ||
                            PANTHEIOS_SEV_INFORMATIONAL == severity)
                        {
                            ;   // be.COMErrorObject does not write out debug-level or informational-level messages
                        }
                        else
                        {
                            comstl::errorinfo_desc  ed;

                            XTESTS_TEST_STRING_EQUAL(strings[j], ed);
                        }
                    }}
                }}

                pantheios_be_COMErrorObject_uninit(token);
            }

            XTESTS_CASE_END("");
        }

        /* Case 2 - verifying be.COMErrorObject, with PANTHEIOS_BE_COMERROROBJECT_F_DONT_OVERWRITE_EXISTING flag */
        if (!XTESTS_CASE_BEGIN("case-2", "verifying be.COMErrorObject, with PANTHEIOS_BE_COMERROROBJECT_F_DONT_OVERWRITE_EXISTING flag"))
        {
            retCode = EXIT_FAILURE;
        }
        else
        {
            pan_be_COMErrorObject_init_t    init;

            init.flags  =   0
//                      |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//                      |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                        |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                        |   PANTHEIOS_BE_COMERROROBJECT_F_DONT_OVERWRITE_EXISTING
                        ;

            void*   token;
            int     res = pantheios_be_COMErrorObject_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

            if (PANTHEIOS_INIT_RC_SUCCESS != res)
            {
                XTESTS_FAIL_WITH_QUALIFIER("failed to initialise bec.COMErrorObject", pantheios::getInitErrorString(res));
            }
            else
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(severities); ++i)
                {
                    { for (size_t j = 0; j != STLSOFT_NUM_ELEMENTS(strings); ++j)
                    {
                        const int severity = severities[i];

                        comstl::set_error_info(L"the first string");

                        pantheios_be_COMErrorObject_logEntry(NULL, token, severity, strings[j], stlsoft::c_str_len(strings[j]));

                        if (PANTHEIOS_SEV_DEBUG == severity ||
                            PANTHEIOS_SEV_INFORMATIONAL == severity)
                        {
                            ;   // be.COMErrorObject does not write out debug-level or informational-level messages
                        }
                        else
                        {
                            comstl::errorinfo_desc  ed;

                            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("the first string", ed);
                        }
                    }}
                }}

                pantheios_be_COMErrorObject_uninit(token);
            }

            XTESTS_CASE_END("");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

int main(int argc, char** argv)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        comstl::com_initialiser coinit;

        return main_(argc, argv);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch (std::exception &x)
    {
        ::fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch (...)
    {
        ::fprintf(stderr, "Unhandled unknown error\n");
    }

    return EXIT_FAILURE;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

/* ///////////////////////////// end of file //////////////////////////// */

