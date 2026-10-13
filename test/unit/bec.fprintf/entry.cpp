/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/bec.fprintf/entry.cpp
 *
 * Purpose: Implementation file for the test.unit.bec.fprintf project.
 *
 * Created: 3rd August 2008
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/backends/bec.fprintf.h>
#include <pantheios/init_codes.h>
#include <pantheios/util/system/threadid.h>

/* STLSoft header files */
#include <platformstl/filesystem/file_lines.hpp>
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

/* xTests header files */
#include <xtests/terse-api.h>

/* Standard C++ header files */
#include <exception>                    // for std::exception
#include <new>                          // for std::bad_alloc

/* Standard C header files */
#include <stdio.h>                      // for fprintf(), remove()
#include <stdlib.h>                     // for exit codes

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

namespace
{

    const char STDERR_FILE_NAME[] = "stderr.txt";

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define PANTHEIOS_SEV_LEVELS_EQUAL(x, y)    TEST_INT_EQ(static_cast<int>(x), static_cast<int>(y))


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

typedef std::basic_string<PAN_CHAR_T>           string_t;
typedef platformstl::basic_file_lines<char>     lines_t;


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ

# define PGET_(x)                       string_t(stlsoft::m2w(x).c_str())

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ

# define PGET_(x)                       (x)

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

#ifdef PSTR
# undef PSTR
#endif
#define PSTR(x)                     PANTHEIOS_LITERAL_STRING(x)
//#define PSTR(x)                         x


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.bec.fprintf");


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void TEST_pantheios_be_fprintf_logEntry_SHOW_NONE();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_DATETIME();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_DATETIME();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_DATETIME();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID_DATETIME();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_SEVERITY();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_SEVERITY();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_DATETIME_SEVERITY();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_fprintf_logEntry_SHOW_ALL_STOCK();

} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER_WITH_STREAM("test.unit.bec.fprintf", verbosity, stdout))
    {
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_NONE);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_fprintf_logEntry_SHOW_ALL_STOCK);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{

static FILE* reopen_file(char const* fileName, char const* mode, FILE* stm)
{
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
    FILE*   f;

    if (0 != ::freopen_s(&f, fileName, mode, stm))
    {
        f = NULL;
    }
#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
    FILE*   f = ::freopen(fileName, mode, stm);
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */

    return f;
}

static string_t gettidstr_()
{
    PAN_CHAR_T          num[21];
    size_t              n;// = 0; STLSOFT_SUPPRESS_UNUSED(n); // Suppress Borland C/C++ warning (which is correct)
    PAN_CHAR_T const*   p = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), pantheios::util::getCurrentThreadId(), n);

    return string_t(p, n);
}

static PAN_CHAR_T const* strings[] =
{
        PANTHEIOS_LITERAL_STRING("abc")
    ,   PANTHEIOS_LITERAL_STRING("ABC")
    ,   PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz")
    ,   PANTHEIOS_LITERAL_STRING("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    ,   PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    ,   PANTHEIOS_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    ,   PANTHEIOS_LITERAL_STRING("00000000000000000000000000000000000000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111222222222222222222222222222222222222222223333333333333333333333333")
};

static void TEST_pantheios_be_fprintf_logEntry_SHOW_NONE()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + gettidstr_() + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ(resultPrefix + strings[i], PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_DATETIME()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_DATETIME()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_DATETIME()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID_DATETIME()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_SEVERITY()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_SEVERITY()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_SEVERITY()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_THREAD_ID_SEVERITY()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_DATETIME_SEVERITY()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_PROCESS_ID_DATETIME_SEVERITY()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_THREAD_ID_DATETIME_SEVERITY()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

static void TEST_pantheios_be_fprintf_logEntry_SHOW_ALL_STOCK()
{
    pan_be_fprintf_init_t  init;

    pantheios_be_fprintf_getDefaultAppInit(&init);

//  init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
//                ;

    void*   token;
    int     res = pantheios_be_fprintf_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.fprintf", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_fprintf_uninit);

        // create the output file
        FILE* f = reopen_file(STDERR_FILE_NAME, "w", stderr);

        if (NULL == f)
        {
            TEST_FAIL_WITH_QUALIFIER("failed to reopen standard output stream", strerror(errno));
        }
        else
        {
            { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
            {
                pantheios_be_fprintf_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, strings[i], stlsoft::c_str_len(strings[i]));
            }}

            ::fclose(f);

            // close the output file
            lines_t         lines(STDERR_FILE_NAME);
            string_t const  resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_ERROR)) + PSTR("]: ");

            ::remove(STDERR_FILE_NAME);

            // Start the tests
            REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));

            if (STLSOFT_NUM_ELEMENTS(strings) == lines.size())
            {
                { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
                {
#if 0
                    TEST_STRING_EQ((resultPrefix + strings[i]), PGET_(lines[i]));
#endif /* 0 */
                }}
            }
        }
    }
}

} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

