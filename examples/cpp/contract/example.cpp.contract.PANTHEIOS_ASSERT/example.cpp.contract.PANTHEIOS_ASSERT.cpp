/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/contract/example.cpp.contract.PANTHEIOS_ASSERT/example.cpp.contract.PANTHEIOS_ASSERT.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of Pantheios inserter for thread ids
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 8th May 2009
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS // Faster compilation

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


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* Define the stock front-end process identity, so that it links when using
 * fe.N, fe.simple, etc. */
PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.contract.PANTHEIOS_ASSERT");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
  int i = pantheios::init();

  if (i >= 0)
  {
    PANTHEIOS_ASSERT(true);

    PANTHEIOS_ASSERT(false);

    pantheios::uninit();
  }

  return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

