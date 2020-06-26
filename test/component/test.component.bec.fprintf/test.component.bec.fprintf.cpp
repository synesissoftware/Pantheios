/* /////////////////////////////////////////////////////////////////////////
 * File:        test/component/test.component.bec.fprintf/test.component.bec.fprintf.cpp
 *
 * Purpose:     Implementation file for the test.component.bec.fprintf project.
 *
 * Created:     25th June 2020
 * Updated:     26th June 2020
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2020, Synesis Information Systems Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
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

# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

#define FF_STR                              PANTHEIOS_LITERAL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_1();
static void test_1_2();
static void test_1_3();
static void test_1_4();
static void test_1_5();
static void test_1_6();
static void test_1_7();
static void test_1_8();

/* ////////////////////////////////////////////////////////////////////// */

#include <iostream>

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;


    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.bec.fprintf", verbosity))
    {
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);

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
 * forward implementations
 */

static void test_1_1()
{
    temp_file       t(temp_file::EmptyOnOpen | temp_file::CloseOnOpen | temp_file::DeleteOnClose);

    {
        FILE_stream             f(t.c_str(), write_mode);

        pan_be_fprintf_init_t   init;

        pantheios_be_fprintf_getDefaultAppInit(&init);

        init.flags  =   0
                    |   PANTHEIOS_BE_INIT_F_NO_THREAD_ID
                    |   PANTHEIOS_BE_INIT_F_NO_DATETIME
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

        if(0 != r)
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not initialise bec.fprintf", stlsoft::t2a(pantheios::getStockSeverityString(r)));

            return;
        }
        else
        {
            stlsoft::scoped_handle<void*> scoper(token, pantheios_be_fprintf_uninit);

            // Now do some writing

            int const r2 = pantheios_be_fprintf_logEntry(
                                NULL
                            ,   token
                            ,   PANTHEIOS_SEV_NOTICE
                            ,   PANTHEIOS_LITERAL_STRING("some message")
                            ,   12
                            );

            if (r2 < 1)
            {
                char buffer[21];

                XTESTS_TEST_FAIL_WITH_QUALIFIER("could not write to bec.fprintf", stlsoft::integer_to_decimal_string(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer), r2));

                return;
            }
        }
    }

    file_lines_t    lines(t);

    XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("[test.component.bec.fprintf; Notice]: some message"), lines[0].c_str());
}

static void test_1_2()
{
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{}

static void test_1_6()
{}

static void test_1_7()
{}

static void test_1_8()
{}

/* ///////////////////////////// end of file //////////////////////////// */

