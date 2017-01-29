/* /////////////////////////////////////////////////////////////////////////
 * File:        I18N.cpp
 *
 * Purpose:     Implementation file for the m2w project.
 *
 * Created:     1st September 2015
 * Updated:     27th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2015-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS

/* Pantheios header files */
#include <pantheios/pan.hpp>
#include <pantheios/inserters/m2t.hpp>
#include <pantheios/inserters/w2t.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL header files */
#include <platformstl/platformstl.hpp>

/* Standard C++ header files */
#include <exception>
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.I18N");

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    {
        wchar_t const   ws[]    =   L"wide-string";
        char const      mbs[]   =    "multibyte-string";

        pan::log_NOTICE(PANTHEIOS_LITERAL_STRING("ws:  "), pan::w2t(ws));
        pan::log_NOTICE(PANTHEIOS_LITERAL_STRING("mbs: "), pan::m2t(mbs));
    }

    {
        std::basic_string<wchar_t> const  ws(L"wide-string");
        std::basic_string<char> const     mbs("multibyte-string");

        pan::log_NOTICE(PANTHEIOS_LITERAL_STRING("ws:  "), pan::w2t(ws));
        pan::log_NOTICE(PANTHEIOS_LITERAL_STRING("mbs: "), pan::m2t(mbs));
    }

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    try
    {
        return main_(argc, argv);
    }
    catch(std::exception& x)
    {
        pan::log_ALERT(PANTHEIOS_LITERAL_STRING("Unexpected general error: "), x, PANTHEIOS_LITERAL_STRING(". Application terminating"));
    }
    catch(...)
    {
        pan::logputs(pan::emergency, PANTHEIOS_LITERAL_STRING("Unhandled unknown error"));
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
