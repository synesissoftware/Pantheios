/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.tstring/test.scratch.tstring.cpp
 *
 * Purpose: Implementation file for the test.scratch.tstring project.
 *
 * Created: 23rd February 2010
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES


/* Pantheios header files */
#include <pantheios/pan.hpp>
#include <pantheios/inserters/m2t.hpp>
#include <pantheios/inserters/w2t.hpp>

/* STLSoft header files */
#include <stlsoft/string/simple_string.hpp>
#include <platformstl/platformstl.hpp>

/* Standard C++ header files */
#include <exception>

#if !defined(__WATCOMC__) && \
    (   !defined(_MSC_VER) || \
        _MSC_VER >= 1100)

#else /* ? __WATCOMC__ */
namespace std
{
    using ::exception;
}
#endif /* __WATCOMC__ */

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR                                                PANTHEIOS_LITERAL_STRING


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.tstring");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char** /*argv*/)
{
    std::string             mbs("multibyte string");
    std::wstring            ws1(L"wide string #1");
    stlsoft::simple_wstring ws2(L"wide string #2");

    pan::log_NOTICE(PSTR("mbs="), pan::m2t(mbs), PSTR(", ws1="), pan::w2t(ws1), PSTR(", ws2="), pan::w2t(ws2));

#ifdef PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES

    {
        VARIANT var;

        var.vt = VT_I4;
        var.lVal = -10;

        pan::log_DEBUG(PSTR("var="), pan::w2t(var));
    }
#endif /* PANTHEIOS_SAFE_ALLOW_SHIM_INTERMEDIATES */


    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
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
    { for (size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.tstring: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch (std::exception& x)
    {
        pantheios::log_ALERT(PSTR("Unexpected general error: "), x, PSTR(". Application terminating"));

        res = EXIT_FAILURE;
    }
    catch (...)
    {
        pantheios::puts(pantheios::emergency, PSTR("Unhandled unknown error"));

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* ///////////////////////////// end of file //////////////////////////// */

