/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/versions/main.cpp
 *
 * Purpose: Lists composite version macros for Pantheios and its
 *          dependencies.
 *
 * Created: 4th August 2026
 * Updated: 12th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/pantheios.h>

#include <stlsoft/stlsoft.h>

#ifdef HAS_b64
# include <b64/b64.h>
#endif

#ifdef HAS_shwild
# include <shwild/shwild.h>
#endif

#include <woad/woad.h>

#include <iomanip>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

template<
    typename T_stream
,   typename T_integer
>
void
version(
    T_stream&   stm
,   FILE*       file
,   char const* prefix
,   char const* libname
,   char const* macroname
,   T_integer   libver
)
{
    stm
        << prefix
        << WOAD_FG_BLUE_FOR(file)
        << libname
        << WOAD_RESET_FOR(file)
        << ": "
        << WOAD_FG_GREEN_FOR(file)
        << 'v'
        << ((libver >> 24) & 0xff)
        << '.'
        << ((libver >> 16) & 0xff)
        << '.'
        << ((libver >> 8) & 0xff)
        << '.'
        << ((libver >> 0) & 0xff)
        << WOAD_RESET_FOR(file)
        << " ("
        << WOAD_FG_CYAN_FOR(file)
        << macroname
        << WOAD_RESET_FOR(file)
        << " = "
        << WOAD_FG_GREEN_FOR(file)
        << "0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
        << WOAD_RESET_FOR(file)
        << ")"
        << std::endl
        ;
}


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
    {
        unsigned const libver = PANTHEIOS_VER;

        version(std::cout, stdout, "", "Pantheios", "PANTHEIOS_VER", libver);
    }

    std::cout << "\n" << "efferent dependencies:" << std::endl;

    {
        unsigned const libver = _STLSOFT_VER;

        version(std::cout, stdout, "\t", "STLSoft", "_STLSOFT_VER", libver);
    }

#ifdef HAS_b64

    {
        unsigned const libver = B64_VER;

        version(std::cout, stdout, "\t", "b64", "B64_VER", libver);
    }
#endif

#ifdef HAS_shwild

    {
        unsigned const libver = SHWILD_VER;

        version(std::cout, stdout, "\t", "shwild", "SHWILD_VER", libver);
    }
#endif

    {
        unsigned const libver = WOAD_VER;

        version(std::cout, stdout, "\t", "woad", "WOAD_VER", libver);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

