/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example.c.extended_severity/example.c.extended_severity.c
 *
 * Purpose: C example program for Pantheios. Demonstrates:
 *
 *            - how the Pantheios libraries must be explicitly
 *              initialised in a C program; this is not the case in
 *              C++ programs
 *            - use of extended severity information, via
 *              PANTHEIOS_MAKE_EXTENDED_SEVERITY()
 *
 * Created: 21st May 2009
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/pantheios.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 */

#ifdef STLSOFT_COMPILER_IS_BORLAND
# pragma warn -8008
# pragma warn -8066
#endif


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.c.extended_severity");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
  int i = pantheios_init();

  ((void)&argc);
  ((void)&argv);

  if (i >= 0)
  {
    /* 1. Using the Pantheios API macro PANTHEIOS_MAKE_EXTENDED_SEVERITY() */
    pantheios_logprintf(PANTHEIOS_MAKE_EXTENDED_SEVERITY(PANTHEIOS_SEV_NOTICE, 10), PANTHEIOS_LITERAL_STRING("hello"));


    /* 2 (a). In your code, you'd define your own, most succinct, symbol, e.g. ACME_XSEV(sev, xi28) */
#define ACME_XSEV(sev, xi28)    PANTHEIOS_MAKE_EXTENDED_SEVERITY(PANTHEIOS_SEV_ ## sev, xi28)

    /* 2 (b). and use it as follows */
    pantheios_logprintf(ACME_XSEV(NOTICE, 10), PANTHEIOS_LITERAL_STRING("hello"));


    pantheios_uninit();
  }

  return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

