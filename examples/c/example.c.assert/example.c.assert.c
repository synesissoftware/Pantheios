/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/c/example.c.assert/example.c.assert.c
 *
 * Purpose:     C example program for Pantheios. Demonstrates:
 *
 *                - how the Pantheios libraries must be explicitly
 *                  initialised in a C program; this is not the case in
 *                  C++ programs
 *                - use of PANTHEIOS_ASSERT()
 *
 * Created:     8th May 2009
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files */
#include <pantheios/assert.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 */

#ifdef STLSOFT_COMPILER_IS_BORLAND
# pragma warn -8008
# pragma warn -8066
#endif

/* ////////////////////////////////////////////////////////////////////// */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.c.assert");

/* ////////////////////////////////////////////////////////////////////// */

int main()
{
  int i = pantheios_init();

  if(i >= 0)
  {
    PANTHEIOS_ASSERT(1);

    PANTHEIOS_ASSERT(0);


    PANTHEIOS_MESSAGE_ASSERT(1, "it was true");

    PANTHEIOS_MESSAGE_ASSERT(0, "it was false");

    pantheios_uninit();
  }

  return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

