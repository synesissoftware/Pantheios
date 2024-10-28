/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/test.component.bec.fprintf/test.component.bec.fprintf.cpp
 *
 * Purpose: Implementation file for the test.component.bec.fprintf project.
 *
 * Created: 25th June 2020
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/pantheios.h>
#include <pantheios/backends/bec.fprintf.h>
#include <pantheios/backend.h>

/* xTests header files */
#include <xtests/xtests.h>
#include <xtests/util/temp_file.hpp>

/* STLSoft header files */
#include <platformstl/filesystem/file_lines.hpp>
#include <platformstl/filesystem/FILE_stream.hpp>
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

/* Standard C++ header files */
#include <exception>
#include <string>
#include <iostream>

/* Standard C header files */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

#define PAN_STR                                             PANTHEIOS_LITERAL_STRING


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef PANTHEIOS_HAS_SHWILD

# define PATTERN_DATE_TIMEms                                PAN_STR("[JFAMSOND]?? [ 0123][0-9] [ 0-9][0-9]:[ 0-9][0-9]:[ 0-9][0-9].[ 0-9][0-9][ 0-9]")
# define PATTERN_DATE_TIMEus                                PAN_STR("[JFAMSOND]?? [ 0123][0-9] [ 0-9][0-9]:[ 0-9][0-9]:[ 0-9][0-9].[ 0-9][0-9][ 0-9][ 0-9][0-9][ 0-9]")
#endif /* PANTHEIOS_HAS_SHWILD */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_NO_THREAD_ID_and_NO_DATETIME();
static void test_NO_THREAD_ID_and_NO_DATETIME_and_NO_PROCESS_ID();
static void test_NO_THREAD_ID_and_NO_DATETIME_and_NO_SEVERITY();
static void test_NO_THREAD_ID_and_NO_DATETIME_and_NUMERIC_SEVERITY();
#ifdef PANTHEIOS_HAS_SHWILD

static void test_USE_UNIX_FORMAT_and_NO_THREAD_ID();
static void test_USE_UNIX_FORMAT_and_NO_THREAD_ID_and_HIGH_RESOLUTION();
#endif /* PANTHEIOS_HAS_SHWILD */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;


    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.bec.fprintf", verbosity))
    {
        XTESTS_RUN_CASE(test_NO_THREAD_ID_and_NO_DATETIME);
        XTESTS_RUN_CASE(test_NO_THREAD_ID_and_NO_DATETIME_and_NO_PROCESS_ID);
        XTESTS_RUN_CASE(test_NO_THREAD_ID_and_NO_DATETIME_and_NO_SEVERITY);
        XTESTS_RUN_CASE(test_NO_THREAD_ID_and_NO_DATETIME_and_NUMERIC_SEVERITY);
#ifdef PANTHEIOS_HAS_SHWILD

        XTESTS_RUN_CASE(test_USE_UNIX_FORMAT_and_NO_THREAD_ID);
        XTESTS_RUN_CASE(test_USE_UNIX_FORMAT_and_NO_THREAD_ID_and_HIGH_RESOLUTION);
#endif /* PANTHEIOS_HAS_SHWILD */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

using xtests::cpp::util::temp_file;

#if _STLSOFT_VER < 0x010a0181

using stlsoft::FILE_stream;
#else

using platformstl::FILE_stream;
#endif

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# if 0
typedef platformstl::file_lines_w       file_lines_t;

char const                              write_mode[] = "wb";
# else
typedef platformstl::file_lines_a       file_lines_t;

char const                              write_mode[] = "w";
# endif
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

typedef platformstl::file_lines_a       file_lines_t;

char const                              write_mode[] = "w";
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

PAN_CHAR_T const                        PROCESS_IDENTITY[]  =   PANTHEIOS_LITERAL_STRING("test.component.bec.fprintf");


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

namespace {

    // Rust `Result<>`-like hack
    typedef     std::pair<
        bool            // has_succeeded
    ,   file_lines_t    // lines
    >                                                       run_case_result_t;

    run_case_result_t
    run_case(
        char const*      /* test_case_name */
    ,   pantheios_uint32_t  flags
    ,   char const*         entry
    )
    {
        temp_file t(temp_file::EmptyOnOpen | temp_file::CloseOnOpen | temp_file::DeleteOnClose);

        {
            FILE_stream             f(t.c_str(), write_mode);

            pan_be_fprintf_init_t   init;

            pantheios_be_fprintf_getDefaultAppInit(&init);

            init.flags  =   0
                        |   flags
                        ;
            init.stm    =   stlsoft::get_FILE_ptr(*f.get());

            void*                   token;
            int const               r = pantheios_be_fprintf_init(
                                            PROCESS_IDENTITY
                                        ,   1
                                        ,   &init
                                        ,   NULL
                                        ,   &token
                                        );

            if (0 != r)
            {
                XTESTS_TEST_FAIL_WITH_QUALIFIER("could not initialise bec.fprintf", stlsoft::t2a(pantheios::getStockSeverityString(r)));

                return std::make_pair(false, file_lines_t());
            }
            else
            {
                stlsoft::scoped_handle<void*> scoper(token, pantheios_be_fprintf_uninit);

                // Now do some writing

                size_t const cchEntry = stlsoft::c_str_len_a(entry);

                int const r2 = pantheios_be_fprintf_logEntry(
                                    NULL
                                ,   token
                                ,   PANTHEIOS_SEV_NOTICE
                                ,   entry
                                ,   cchEntry
                                );

                if (r2 < 1)
                {
                    char buffer[21];

                    XTESTS_TEST_FAIL_WITH_QUALIFIER("could not write to bec.fprintf", stlsoft::integer_to_decimal_string(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer), r2));

                    return std::make_pair(false, file_lines_t());
                }
            }
        }

        file_lines_t lines(t);

        return std::make_pair(true, std::move(lines));
    }

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * forward implementations
 */

static void test_NO_THREAD_ID_and_NO_DATETIME()
{
    pantheios_uint32_t  flags   =   0
                                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                ;

    run_case_result_t   r       =   run_case(STLSOFT_FUNCTION_SYMBOL, flags, "some message");

    if (r.first)
    {
        file_lines_t const& lines = r.second;

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("[test.component.bec.fprintf; Notice]: some message"), lines[0].c_str());
    }
}

static void test_NO_THREAD_ID_and_NO_DATETIME_and_NO_PROCESS_ID()
{
    pantheios_uint32_t  flags   =   0
                                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                |   PANTHEIOS_BE_INIT_F_NO_PROCESS_ID
                                ;

    run_case_result_t   r       =   run_case(STLSOFT_FUNCTION_SYMBOL, flags, "some message");

    if (r.first)
    {
        file_lines_t const& lines = r.second;

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("[Notice]: some message"), lines[0].c_str());
    }
}

static void test_NO_THREAD_ID_and_NO_DATETIME_and_NO_SEVERITY()
{
    pantheios_uint32_t  flags   =   0
                                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                |   PANTHEIOS_BE_INIT_F_NO_SEVERITY
                                ;

    run_case_result_t   r       =   run_case(STLSOFT_FUNCTION_SYMBOL, flags, "some message");

    if (r.first)
    {
        file_lines_t const& lines = r.second;

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("[test.component.bec.fprintf]: some message"), lines[0].c_str());
    }
}

static void test_NO_THREAD_ID_and_NO_DATETIME_and_NUMERIC_SEVERITY()
{
    pantheios_uint32_t  flags   =   0
                                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                |   PANTHEIOS_BE_INIT_F_NO_DATETIME
                                |   PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY
                                ;

    run_case_result_t   r       =   run_case(STLSOFT_FUNCTION_SYMBOL, flags, "some message");

    if (r.first)
    {
        file_lines_t const& lines = r.second;

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("[test.component.bec.fprintf; 5]: some message"), lines[0].c_str());
    }
}
#ifdef PANTHEIOS_HAS_SHWILD

static void test_USE_UNIX_FORMAT_and_NO_THREAD_ID()
{
    pantheios_uint32_t  flags   =   0
                                |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                ;

    run_case_result_t   r       =   run_case(STLSOFT_FUNCTION_SYMBOL, flags, "some message");

    if (r.first)
    {
        file_lines_t const& lines = r.second;

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("\\[*\\]: *", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*test.component.bec.fprintf,*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*" PATTERN_DATE_TIMEms "*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*Notice*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*test.component.bec.fprintf, " PATTERN_DATE_TIMEms "; Notice*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("\\[test.component.bec.fprintf, " PATTERN_DATE_TIMEms "; Notice\\]: *", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("\\[test.component.bec.fprintf, " PATTERN_DATE_TIMEms "; Notice\\]: some message", lines[0]);
    }
}

static void test_USE_UNIX_FORMAT_and_NO_THREAD_ID_and_HIGH_RESOLUTION()
{
    pantheios_uint32_t  flags   =   0
                                |   PANTHEIOS_BE_INIT_F_USE_UNIX_FORMAT
                                |   PANTHEIOS_BE_INIT_F_HIGH_RESOLUTION
                                |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                                ;

    run_case_result_t   r       =   run_case(STLSOFT_FUNCTION_SYMBOL, flags, "some message");

    if (r.first)
    {
        file_lines_t const& lines = r.second;

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("\\[*\\]: *", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*test.component.bec.fprintf,*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*" PATTERN_DATE_TIMEus "*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*Notice*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("*test.component.bec.fprintf, " PATTERN_DATE_TIMEus "; Notice*", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("\\[test.component.bec.fprintf, " PATTERN_DATE_TIMEus "; Notice\\]: *", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("\\[test.component.bec.fprintf, " PATTERN_DATE_TIMEus "; Notice\\]: some message", lines[0]);
    }
}
#endif /* PANTHEIOS_HAS_SHWILD */


/* ///////////////////////////// end of file //////////////////////////// */

