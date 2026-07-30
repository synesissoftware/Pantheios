/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.bec.AnsiConsole/test.scratch.bec.AnsiConsole.c
 *
 * Purpose: Scratch test program for demonstrating be.AnsiConsole, including
 *          ability to supply stock and be-specific flags for be
 *          initialisation.
 *
 * Created: 21st October 2024
 * Updated: 30th January 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/pantheios.h>
#include <pantheios/backends/bec.AnsiConsole.h>

#include <platformstl/filesystem/path_functions.h>

#include <stdio.h>


/* /////////////////////////////////////////////////////////////////////////
 * process identity
 *
 * This is required for when we link with one of several stock front-end
 * libraries - such as fe.all and fe.simple - that implement
 * pantheios_fe_getProcessIdentity() in terms of this externally defined
 * array
 */

/* Declared in include:pantheios/frontend.h */
PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.bec.AnsiConsole");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    pan_be_AnsiConsole_init_t           init;
    void*                               token;
    stlsoft_C_string_slice_m_t const    exe_name    =   platformstl_C_get_executable_name_from_path(argv[0]);

    pantheios_be_AnsiConsole_getDefaultAppInit(&init);

    switch (argc)
    {
    case 1:

        break;
    case 2:

        if (0 == strcmp("--help", argv[1]))
        {
            fprintf(stdout, "USAGE: %.*s [ --help | <flags-number> ]\n"
            ,   (int)exe_name.len, exe_name.ptr
            );

            return EXIT_SUCCESS;
        }
        else
        {
            char*               endptr;
            unsigned long const v = strtoul(argv[1], &endptr, 0);

            init.flags = (pantheios_uint32_t)v;
        }
        break;
    default:

        fprintf(stderr, "%.*s: too many arguments; use --help for usage\n"
        ,   (int)exe_name.len, exe_name.ptr
        );

        return EXIT_FAILURE;
    }

    int const r = pantheios_be_AnsiConsole_init(PANTHEIOS_FE_PROCESS_IDENTITY, 1, &init, NULL, &token);

    if (0 != r)
    {
        fprintf(stderr
        ,   "%.*s: failed to initialise Pantheios: %s\n"
        ,   (int)exe_name.len, exe_name.ptr
        ,   pantheios_getInitCodeString(r)
        );

        return EXIT_FAILURE;
    }
    else
    {
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_EMERGENCY, "emergency", 9);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_ALERT, "alert", 5);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_CRITICAL, "critical", 8);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_ERROR, "error", 5);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_WARNING, "warning", 7);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_NOTICE, "notice", 6);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_INFORMATIONAL, "informational", 13);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG, "debug", 5);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 1, "debug-1", 7);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 2, "debug-2", 7);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 3, "debug-3", 7);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 4, "debug-4", 7);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 5, "debug-5", 7);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 6, "debug-6", 7);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 7, "trace", 5);
        pantheios_be_AnsiConsole_logEntry(NULL, token, PANTHEIOS_SEV_DEBUG + 8, "benchmark", 9);

        pantheios_be_AnsiConsole_uninit(token);

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

