/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.pseudoUNIX/test.scratch.pseudoUNIX.c
 *
 * Purpose:     Implementation file for the pseudoUNIX.test project.
 *
 * Created:     23rd September 2006
 * Updated:     27th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */

/* Pantheios header files */
#include <pantheios/pantheios.h>
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.simple.h>
#if defined(unix) || \
    defined(__unix) || \
    defined(__unix__)
# include <pantheios/implicit_link/be.fprintf.h>
#elif defined(_WIN32) || \
      defined(WIN32)
# include <pantheios/implicit_link/be.WindowsConsole.h>
#endif /* operating system */

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL header files */
#include <platformstl/platformstl.h>


/* UNIXem header files */
#include <unixem/unixem.h>
#include <unixem/implicit_link.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef true
# undef true
#endif /* true */
#ifdef false
# undef false
#endif /* false */
#define true    (1)
#define false   (0)

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

#if defined(_DEBUG) || \
    defined(_SYB_DEBUG)
static int  s_bDebugging                =   true;
#else /* ? debug */
static int  s_bDebugging                =   false;
#endif /* debug */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("pseudoUNIX.test");

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv);

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
    int bVerbose    =   1;

    if(pantheios_init() < 0)
    {
        return EXIT_FAILURE;
    }
    else
    {
        pantheios_init();

        pantheios_init();
        pantheios_uninit();

        pantheios_init();
        pantheios_uninit();


        pantheios_getNextBackEndId();

        { int i; for(i = 1; i < argc; ++i)
        {
            char const  *const  arg =   argv[i];

            if(arg[0] == '-')
            {
                if(arg[1] == '-')
                {
                    /* -- arguments */
                    usage(1, "Invalid argument(s) specified", i, argc, argv);
                }
                else
                {
                    /* - arguments */
                    switch(arg[1])
                    {
                        case    '?':
                            usage(1, NULL, -1, argc, argv);
                            break;
                        case    's':
                            bVerbose    =   0;
                            break;
                        case    'v':
                            bVerbose    =   1;
                            break;
                        default:
                            usage(1, "Invalid argument(s) specified", i, argc, argv);
                            break;
                    }
                }
            }
            else
            {
                /* other arguments */
                usage(1, "Invalid argument(s) specified", i, argc, argv);
            }
        }}

        pantheios_uninit();

        pantheios_uninit();

        return EXIT_SUCCESS;
    }
}

/* ////////////////////////////////////////////////////////////////////// */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv)
{
    FILE    *stm    =   (NULL == reason) ? stdout : stderr;


    fprintf(stm, "\n");
    fprintf(stm, "  pseudoUNIX.test\n\n");
    fprintf(stm, "\n");

    if(NULL != reason)
    {
        fprintf(stm, "  Error: %s\n", reason);
        fprintf(stm, "\n");
    }

    if(0 < invalidArg)
    {
        fprintf(stm, "  First invalid argument #%d: %s\n", invalidArg, argv[invalidArg]);
        fprintf(stm, "  Arguments were (first bad marked *):\n\n");
        { int i; for(i = 1; i < argc; ++i)
        {
            fprintf(stm, "  %s%s\n", (i == invalidArg) ? "* " : "  ", argv[i]);
        }}
        fprintf(stm, "\n");
    }

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
