/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.c_api/test.scratch.c_api.c
 *
 * Purpose:     Implementation file for the test.scratch.c_api project.
 *
 * Created:     14th October 2005
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/pantheios.h>
#include <pantheios/backends/be.lrsplit.h>
#include <pantheios/frontend.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL header files */
#include <platformstl/platformstl.h>

/* Standard C header files */
#include <stdio.h>
#include <time.h>

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static int main_(int /* argc */, char ** /*argv*/);
static void some_logging_1();
static void some_logging_2();
static void some_logging_3();

/* /////////////////////////////////////////////////////////////////////////
 * process identity
 *
 * This is defined for when we link with the pantheios.fe.simple front-end
 * library, which implements pantheios_fe_getProcessIdentity() in terms of this
 * externally defined array
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.c_api");

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char **argv)
{
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);

    some_logging_1();
    some_logging_2();
    some_logging_3();

    return 0;
}

int main(int argc, char *argv[])
{
    int res;

#if 0
    { for(size_t i = 0;0 != ++i;) {} }
#endif /* 0 */

    if(pantheios_init() < 0)
    {
        res = EXIT_FAILURE;
    }
    else
    {
        res = main_(argc, argv);

        pantheios_uninit();
    }

    return res;
}

/* ////////////////////////////////////////////////////////////////////// */

static void some_logging_1()
{
    short                   s       =   123;
    int                     i       =   456;
    long                    l       =   789;
    float                   f       =   (float)(0.123);
    double                  d       =   0.456;
    long double             ld      =   0.789;
    void                    *p      =   &l;
    char const              *lstr   =   "{a pointer to a C-style string}";

#if 0
    log_INFORMATIONAL(  "This is a (hopefully) typical error string, containing: "
                    ,   "some integers (", integer(s), ", ", integer(i), ", ", integer(l), "); "
                    ,   "some real numbers (", real(f), ", ", real(d), ", ", real(ld), "); "
                    ,   "a pointer (", pointer(p, fmt::hex), "); "
                    ,   "some strings (", lstr, ", ", str, ", ", sstr, "); "
                    ,   "and a converted time value (", tm, ")"
                    );
#endif /* 0 */
}

static void some_logging_2()
{
#if 0
    try
    {
        throw std::out_of_range("Eeep!");
    }
    catch(std::exception &x)
    {
        log_CRITICAL("Something really bad has happened! Details: \"", x, "\"");
    }
#endif /* 0 */
}

static void some_logging_3()
{
    int     numUsers    =   1000000;
    char    szNumUsers[101];

    /* The long-hand way */
    pantheios_log_4(
        PANTHEIOS_SEV_ALERT
    ,   "We're sure there're likely to be >",   -1
    ,   szNumUsers, sprintf(&szNumUsers[0], "%020d", numUsers)
    ,   " satisfied users of ", -1
    ,   "Pantheios", 9
    );

    /* The convenient way */
    pantheios_log_4(
        PANTHEIOS_SEV_ALERT
    ,   PANTHEIOS_CARG_STR("We're sure there're likely to be >")
    ,   szNumUsers, sprintf(&szNumUsers[0], "%020d", numUsers)
    ,   PANTHEIOS_CARG_STR(" satisfied users of ")
    ,   PANTHEIOS_CARG_STR_LEN("Pantheios", 9)
    );

    /* The more convenient way. The following #defines would be in a
     * location accessible to your application code
     */
#define PARG_S(s)           PANTHEIOS_CARG_STR(s)
#define PARG_SN(s, n)       PANTHEIOS_CARG_STR_LEN(s, n)

    pantheios_log_4(
        PANTHEIOS_SEV_ALERT
    ,   PARG_S("We're sure there're likely to be >")
    ,   szNumUsers, sprintf(&szNumUsers[0], "%020d", numUsers)
    ,   PARG_S(" satisfied users of ")
    ,   PARG_SN("Pantheios", 9)
    );
}

/* ///////////////////////////// end of file //////////////////////////// */

