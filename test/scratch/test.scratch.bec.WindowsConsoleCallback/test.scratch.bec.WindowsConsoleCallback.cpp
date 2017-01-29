/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.bec.WindowsConsoleCallback/test.scratch.bec.WindowsConsoleCallback.cpp
 *
 * Purpose:     Implementation file for the test.scratch.bec.WindowsConsoleCallback project.
 *
 * Created:     31st July 2007
 * Updated:     27th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2007-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/backends/bec.WindowsConsole.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <winstl/winstl.h>
#include <winstl/error/error_desc.hpp>

/* Standard C++ header files */
#include <exception>

/* Standard C header files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.bec.WindowsConsoleCallback");

/* ////////////////////////////////////////////////////////////////////// */

PANTHEIOS_CALL(void) pantheios_be_WindowsConsole_getAppInit(int backEndId, pan_be_WindowsConsole_init_t *init) /* throw() */
{
    init->flags |= PANTHEIOS_BE_INIT_F_NO_PROCESS_ID;
    init->flags |= PANTHEIOS_BE_INIT_F_NO_DATETIME;
    init->flags |= PANTHEIOS_BE_INIT_F_NO_SEVERITY;
    init->flags |= PANTHEIOS_BE_INIT_F_USE_SYSTEM_TIME;

//  init->flags |= PANTHEIOS_BE_WINDOWSCONSOLE_F_NO_COLOURS;
}

static int main_(int /* argc */, char** /*argv*/)
{
    pantheios::log_DEBUG("debug");
    pantheios::log_INFORMATIONAL("info");
    pantheios::log_NOTICE("notice");
    pantheios::log_WARNING("warn");
    pantheios::log_ERROR("error");
    pantheios::log_CRITICAL("critical");
    pantheios::log_ALERT("alert");
    pantheios::log_EMERGENCY("emergency");

    /* . */
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception &x)
    {
        pantheios::log_ALERT("Unexpected general error: ", x, ". Application terminating");

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        pantheios::logputs(pantheios::emergency, "Unhandled unknown error");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ////////////////////////////////////////////////////////////////////// */
