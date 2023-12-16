/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.util.onbailout/test.scratch.util.onbailout.cpp
 *
 * Purpose:     Implementation file for the test.scratch.util.onbailout project.
 *
 * Created:     21st June 2005
 * Updated:     16th January 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* This inclusion required for suppressing warnings during NoX (No eXception-support) configurations. */
#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/pantheios.h>
#include <pantheios/init_codes.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C header files */
#include <stdio.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.util.onbailout");

static int main_(int /* argc */, char ** /*argv*/)
{
#if 0
    pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, "abc");

    pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, "abc", PANTHEIOS_FE_PROCESS_IDENTITY);

    pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, "abc", PANTHEIOS_FE_PROCESS_IDENTITY, pantheios::getInitErrorString(PANTHEIOS_INIT_RC_CANNOT_CREATE_TSS_INDEX));

// no longer valid  pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, "abc", PANTHEIOS_FE_PROCESS_IDENTITY, (char const*)(pantheios::uint16_t)PANTHEIOS_INIT_RC_CANNOT_CREATE_TSS_INDEX);


    {
        std::string message(1200, 'm');
        std::string qualifier(1200, 'q');

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY);

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, qualifier.c_str());
    }

    {
        std::string message(2000, 'm');
        std::string qualifier(100, 'q');

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY);

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, qualifier.c_str());
    }

    {
        std::string message(100, 'm');
        std::string qualifier(2000, 'q');

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY);

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, qualifier.c_str());
    }

    {
        std::string message(2500, 'm');
        std::string qualifier(1200, 'q');

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY);

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, qualifier.c_str());
    }

    {
        std::string message(2500, 'm');
        std::string qualifier(100, 'q');

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY);

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, qualifier.c_str());
    }

    {
        std::string message(2500, 'm');

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY);

        pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, "");
    }

#endif /* 0 */

    const size_t INCREMENT  =   150;

    STLSOFT_STATIC_ASSERT(0 == (3000 % INCREMENT));

    { for(size_t i = 0; i != 3000; i += INCREMENT)
    {
        { for(size_t j = 0; j != 3000; j += INCREMENT)
        {
            if(0 == i)
            {
                std::string qualifier(j, 'q');

                pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, NULL, PANTHEIOS_FE_PROCESS_IDENTITY, qualifier.c_str());
            }
            else if(0 == j)
            {
                std::string message(i, 'm');

                pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, "");
            }
            else
            {
                std::string message(i, 'm');
                std::string qualifier(j, 'q');

                pantheios::util::onBailOut(PANTHEIOS_SEV_DEBUG, message.c_str(), PANTHEIOS_FE_PROCESS_IDENTITY, qualifier.c_str());
            }
        }}
    }}


    return EXIT_SUCCESS;
}


int main(int argc, char *argv[])
{
#if 0
    for(;;) {}
#endif /* 0 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return main_(argc, argv);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::exception &x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch(...)
    {
        pantheios::puts(pantheios::emergency, "Unhandled unknown error");
    }

    return EXIT_FAILURE;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

/* ///////////////////////////// end of file //////////////////////////// */

