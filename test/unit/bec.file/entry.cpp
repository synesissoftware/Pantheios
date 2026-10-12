/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/bec.file/entry.cpp
 *
 * Purpose: Unit-tests for bec.file.
 *
 * Created: 19th January 2008
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/backends/bec.file.h>
#include <pantheios/init_codes.h>
#include <pantheios/util/system/threadid.h>

/* STLSoft header files */
#include <platformstl/filesystem/file_lines.hpp>
#include <platformstl/filesystem/filesystem_traits.hpp>
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
 * macros
 */

#define PANTHEIOS_SEV_LEVELS_EQUAL(x, y)    TEST_INT_EQ(static_cast<int>(x), static_cast<int>(y))


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

typedef platformstl::filesystem_traits<PAN_CHAR_T>  fs_traits_t;
typedef platformstl::basic_file_lines<char>         lines_m_t;
typedef platformstl::basic_file_lines<wchar_t>      lines_w_t;
typedef platformstl::basic_file_lines<PAN_CHAR_T>   lines_t;
typedef std::basic_string<char>                     string_m_t;
typedef std::basic_string<wchar_t>                  string_w_t;
typedef std::basic_string<PAN_CHAR_T>               string_t;


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define TEST_STRING_EQ                                     TEST_WS_EQ

# define P_TO_M_(x)                     static_cast<char const*>(stlsoft::w2m((x)))
# define P_TO_W_(x)                     (x)

# define gettidstr_()                   gettidstr_w_()

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define TEST_STRING_EQ                                     TEST_MS_EQ

# define P_TO_M_(x)                     (x)
# define P_TO_W_(x)                     static_cast<wchar_t const*>(stlsoft::m2w((x)))

# define gettidstr_()                   gettidstr_m_()

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

#ifdef PSTR
# undef PSTR
#endif
#define PSTR                                                PANTHEIOS_LITERAL_STRING


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.bec.file");


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_NONE();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_SEVERITY();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_ALL_STOCK();

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_NONE();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_SEVERITY();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_ALL_STOCK();

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_NONE();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_SEVERITY();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY();
static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_ALL_STOCK();

static void TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY();
static void TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY_SHOW_NONE();

static void TEST_pantheios_be_file_WITH_ALL_STOCK_true();
static void TEST_pantheios_be_file_WITH_ALL_STOCK_false();
} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.bec.file", verbosity))
    {
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_NONE);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_ALL_STOCK);

        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_NONE);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_ALL_STOCK);

        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_NONE);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_ALL_STOCK);

        XTESTS_RUN_CASE(TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY_SHOW_NONE);

        XTESTS_RUN_CASE(TEST_pantheios_be_file_WITH_ALL_STOCK_true);
        XTESTS_RUN_CASE(TEST_pantheios_be_file_WITH_ALL_STOCK_false);


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{

static string_m_t gettidstr_m_()
{
    char        num[21];
    size_t      n;// = 0; STLSOFT_SUPPRESS_UNUSED(n); // Suppress Borland C/C++ warning (which is correct)
    char const* p = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), pantheios::util::getCurrentThreadId(), n);

    return string_m_t(p, n);
}

static string_w_t gettidstr_w_()
{
    wchar_t         num[21];
    size_t          n;// = 0; STLSOFT_SUPPRESS_UNUSED(n); // Suppress Borland C/C++ warning (which is correct)
    wchar_t const*  p = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), pantheios::util::getCurrentThreadId(), n);

    return string_w_t(p, n);
}

static PAN_CHAR_T const* strings[] =
{
        PSTR("abc")
    ,   PSTR("ABC")
    ,   PSTR("abcdefghijklmnopqrstuvwxyz")
    ,   PSTR("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    ,   PSTR("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    ,   PSTR("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    ,   PSTR("00000000000000000000000000000000000000000000000000000000000000000000001111111111111111111111111111111111111111111111111111111111222222222222222222222222222222222222222223333333333333333333333333")
};




static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_NONE()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + gettidstr_m_() + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "." + gettidstr_m_() + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "." + gettidstr_m_() + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "; " + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + gettidstr_m_() + "; " + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "." + gettidstr_m_() + "; " + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "." + gettidstr_m_() + "; " + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "." + gettidstr_m_() + "; " + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "." + gettidstr_m_() + "; " + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_ALL_STOCK()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_MULTIBYTE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_m_t           lines(FILE_PATH);
        string_m_t const    resultPrefix = "[" + string_m_t(P_TO_M_(PANTHEIOS_FE_PROCESS_IDENTITY)) + "." + gettidstr_m_() + "; " + string_m_t(P_TO_M_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + "]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_MS_EQ((resultPrefix + P_TO_M_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}



static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_NONE()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + gettidstr_w_() + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"." + gettidstr_w_() + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"." + gettidstr_w_() + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"; " + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + gettidstr_w_() + L"; " + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"." + gettidstr_w_() + L"; " + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"." + gettidstr_w_() + L"; " + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"." + gettidstr_w_() + L"; " + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"." + gettidstr_w_() + L"; " + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_ALL_STOCK()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_WIDE_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_w_t           lines(FILE_PATH);
        string_w_t const    resultPrefix = L"[" + string_w_t(P_TO_W_(PANTHEIOS_FE_PROCESS_IDENTITY)) + L"." + gettidstr_w_() + L"; " + string_w_t(P_TO_W_(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY))) + L"]: ";

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_WS_EQ((resultPrefix + P_TO_W_(strings[i])), lines[i]);
#endif /* 0 */
        }}
    }
}



static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_NONE()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + gettidstr_() + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ(resultPrefix + strings[i], lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_DATETIME()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_SEVERITY.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_THREAD_ID_SEVERITY.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_DATETIME_SEVERITY.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_PROCESS_ID_DATETIME_SEVERITY.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_THREAD_ID_DATETIME_SEVERITY.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}

static void TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_ALL_STOCK()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
//              |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
//              |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
//              |   PANTHEIOS_BE_INIT_F_NO_DATETIME
//              |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_logEntry_DEFAULT_TRUNCATE_SHOW_ALL_STOCK.results");

        // create the output file
        pantheios_be_file_setFilePath(FILE_PATH);

        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, strings[i], stlsoft::c_str_len(strings[i]));
        }}

        pantheios_be_file_setFilePath(NULL);

        // close the output file
        lines_t             lines(FILE_PATH);
        string_t const      resultPrefix = PSTR("[") + string_t(PANTHEIOS_FE_PROCESS_IDENTITY) + PSTR(".") + gettidstr_() + PSTR("; ") + string_t(pantheios::getSeverityString(PANTHEIOS_SEV_EMERGENCY)) + PSTR("]: ");

        fs_traits_t::unlink_file(FILE_PATH);

        // Start the tests
        REQUIRE(TEST_INT_EQ(STLSOFT_NUM_ELEMENTS(strings), lines.size()));
        { for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
        {
#if 0
            TEST_STRING_EQ((resultPrefix + strings[i]), lines[i]);
#endif /* 0 */
        }}
    }
}


static void TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY.results");


        { // (i) Writing something (none-0 length)
            pantheios_be_file_setFilePath(FILE_PATH);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));

            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, PANTHEIOS_LITERAL_STRING("abc"), 3u);

            pantheios_be_file_setFilePath(NULL);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));
        }

        { // (i) Writing something (0 length)
            pantheios_be_file_setFilePath(FILE_PATH);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));

            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, PANTHEIOS_LITERAL_STRING("abc"), 0u);

            pantheios_be_file_setFilePath(NULL);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));
        }

        { // (i) Writing nothing
            pantheios_be_file_setFilePath(FILE_PATH);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));

            pantheios_be_file_setFilePath(NULL);

            TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(FILE_PATH));
        }


        // ... do it anyway ...
        fs_traits_t::unlink_file(FILE_PATH);
    }
}

static void TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY_SHOW_NONE()
{
    pan_be_file_init_t  init;

    pantheios_be_file_getDefaultAppInit(&init);

    init.flags  |=  0
                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                |   0
                |   PANTHEIOS_BE_FILE_F_TRUNCATE
                |   PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY
                ;

    void*   token;
    int     res = pantheios_be_file_init(PANTHEIOS_FE_PROCESS_IDENTITY, PANTHEIOS_BEID_ALL, &init, NULL, &token);

    if (PANTHEIOS_INIT_RC_SUCCESS != res)
    {
        TEST_FAIL_WITH_QUALIFIER("failed to initialise bec.file", pantheios::getInitErrorString(res));
    }
    else
    {
        stlsoft::scoped_handle<void*>   uninit_(token, pantheios_be_file_uninit);

        static PAN_CHAR_T const FILE_PATH[] = PANTHEIOS_LITERAL_STRING("TEST_pantheios_be_file_TRUNCATE_DELETE_IF_EMPTY.results");


        { // (i) Writing something (none-0 length)
            pantheios_be_file_setFilePath(FILE_PATH);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));

            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, PANTHEIOS_LITERAL_STRING("abc"), 3u);

            pantheios_be_file_setFilePath(NULL);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));
        }

        { // (i) Writing something (0 length)
            pantheios_be_file_setFilePath(FILE_PATH);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));

            pantheios_be_file_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, PANTHEIOS_LITERAL_STRING("abc"), 0u);

            pantheios_be_file_setFilePath(NULL);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));
        }

        { // (i) Writing nothing
            pantheios_be_file_setFilePath(FILE_PATH);

            TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(FILE_PATH));

            pantheios_be_file_setFilePath(NULL);

            TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(FILE_PATH));
        }


        // ... do it anyway ...
        fs_traits_t::unlink_file(FILE_PATH);
    }
}


static void TEST_pantheios_be_file_WITH_ALL_STOCK_true()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    /* stock */
    ,   { 18, "showProcessId=true" }
    ,   { 17, "showThreadId=true" }
    ,   { 17, "showDateTime=true" }
    ,   { 17, "showSeverity=true" }
    ,   { 18, "useSystemTime=true" }
    ,   { 23, "showDetailsAtStart=true" }
    ,   { 18, "useUnixFormat=true" }
    ,   { 13, "showDate=true" }
    ,   { 13, "showTime=true" }
    ,   { 19, "highResolution=true" }
    ,   { 18, "lowResolution=true" }
    ,   { 20, "numericSeverity=true" }
    /* custom */
    ,   { 13, "truncate=true" }
    ,   { 26, "discardCachedContents=true" }
    ,   { 19, "shareOnWindows=true" }
    ,   { 27, "writeMultibyteContents=true" }
    ,   { 22, "writeWideContents=true" }
    ,   { 18, "deleteIfEmpty=true" }
    };

    pan_be_file_init_t  init;

    init.flags                      =   0
                                    /* stock */
                                    |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    // |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    // |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    // |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    // |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    /* custom */
                                    // |   PANTHEIOS_BE_FILE_F_TRUNCATE
                                    // |   PANTHEIOS_BE_FILE_F_DISCARD_CACHED_CONTENTS
                                    // |   PANTHEIOS_BE_FILE_F_SHARE_ON_WINDOWS
                                    // |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                                    // |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                                    // |   PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY
                                    ;

    int const r = pantheios_be_file_parseArgs(STLSOFT_NUM_ELEMENTS(args), args, &init);

    TEST_INT_EQ(18, r);

    pantheios_uint32_t  expected    =   0
                                    /* stock */
                                    // |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    // |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    /* custom */
                                    |   PANTHEIOS_BE_FILE_F_TRUNCATE
                                    |   PANTHEIOS_BE_FILE_F_DISCARD_CACHED_CONTENTS
                                    |   PANTHEIOS_BE_FILE_F_SHARE_ON_WINDOWS
                                    |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                                    |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                                    |   PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY
                                    ;

    TEST_INT_EQ(expected, init.flags);
}

static void TEST_pantheios_be_file_WITH_ALL_STOCK_false()
{
    pantheios_slice_t args[] =
    {
        { 0, "" }
    /* stock */
    ,   { 19, "showProcessId=false" }
    ,   { 18, "showThreadId=false" }
    ,   { 18, "showDateTime=false" }
    ,   { 18, "showSeverity=false" }
    ,   { 19, "useSystemTime=false" }
    ,   { 24, "showDetailsAtStart=false" }
    ,   { 19, "useUnixFormat=false" }
    ,   { 14, "showDate=false" }
    ,   { 14, "showTime=false" }
    ,   { 20, "highResolution=false" }
    ,   { 19, "lowResolution=false" }
    ,   { 21, "numericSeverity=false" }
    /* custom */
    ,   { 14, "truncate=false" }
    ,   { 27, "discardCachedContents=false" }
    ,   { 20, "shareOnWindows=false" }
    ,   { 28, "writeMultibyteContents=false" }
    ,   { 23, "writeWideContents=false" }
    ,   { 19, "deleteIfEmpty=false" }
    };

    pan_be_file_init_t  init;

    init.flags                      =   0
                                    /* stock */
                                    // |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    // |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    // |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    // |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    /* custom */
                                    |   PANTHEIOS_BE_FILE_F_TRUNCATE
                                    |   PANTHEIOS_BE_FILE_F_DISCARD_CACHED_CONTENTS
                                    |   PANTHEIOS_BE_FILE_F_SHARE_ON_WINDOWS
                                    |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                                    |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                                    |   PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY
                                    ;

    int const r = pantheios_be_file_parseArgs(STLSOFT_NUM_ELEMENTS(args), args, &init);

    TEST_INT_EQ(18, r);

    pantheios_uint32_t  expected    =   0
                                    /* stock */
                                    |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                    |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                    |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                    // |   PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME
                                    // |   PANTHEIOS_BE_INIT_F_DETAILS_AT_START
                                    // |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                    |   PANTHEIOS_BE_INIT_F_HIDE_DATE
                                    |   PANTHEIOS_BE_INIT_F_HIDE_TIME
                                    // |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_LOW_RESOLUTION
                                    // |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                    /* custom */
                                    // |   PANTHEIOS_BE_FILE_F_TRUNCATE
                                    // |   PANTHEIOS_BE_FILE_F_DISCARD_CACHED_CONTENTS
                                    // |   PANTHEIOS_BE_FILE_F_SHARE_ON_WINDOWS
                                    // |   PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS
                                    // |   PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS
                                    // |   PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY
                                    ;

    TEST_INT_EQ(expected, init.flags);
}
} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

