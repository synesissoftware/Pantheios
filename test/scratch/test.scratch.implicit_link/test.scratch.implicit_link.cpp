/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.implicit_link/test.scratch.implicit_link.cpp
 *
 * Purpose: Implicit link file for the test.scratch.implicit_link project.
 *
 * Created: 18th July 2007
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios header files */
#include <pantheios/pantheios.hpp>

#include <pantheios/implicit_link/core.h>

#include <pantheios/implicit_link/fe.simple.h>

#include <pantheios/implicit_link/be.fprintf.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.implicit_link");


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
    pantheios::log_ALERT("A simple log entry");

    pantheios::log_NOTICE("A simple log entry");

    return 0;
}


/* ///////////////////////////// end of file //////////////////////////// */

