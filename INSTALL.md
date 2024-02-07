pantheios - Install
====================

Updated:    5th July 2020


The following steps are required to install Pantheios:

    1. Download the latest distribution of Pantheios, from
       http://pantheios.org/

    2. Unzip it to a directory of your choice, e.g c:\3pty\pantheios-1.0.1

    3. Define an environment variable PANTHEIOS_ROOT, whose
       value is the directory in which you unzipped
       it, e.g. PANTHEIOS_ROOT=c:\3pty\pantheios-1.0.1

    4. Download the latest distribution of STLSoft, from http://stlsoft.org/

    5. Unzip it to a directory of your choice, e.g c:\3pty\stlsoft-1.9.134

    6. Define an environment variable STLSOFT, whose value is the directory
       in which you unzipped it, e.g. STLSOFT=c:\3pty\stlsoft-1.9.134

    7. Open a command shell in the appropriate directory that matches your
       compiler:

       * if you're compiling with Visual C++ 7.1 then cd to build/vc71
       * if you're compiling for UNIX with GCC 4.2, then cd
         to build/gcc42.unix
       * if you're compiling for Win-x64 with Visual C++ 9, then cd
         to build/vc9.x64

    8. Build using make:

       * to build the Pantheios core libraries: "make build.libs.core"
       * to build all libraries, examples and test: "make build"
       * to build and run unit/component tests: "make test"

NOTE: Pantheios depends on the (header-only) STLSoft libraries - version
  1.9.134 or later - available
  from http://github.com/synesissoftware/stlsoft-1.9/. However, as of
  this time, the beta version of STLSoft 1.10 is recommended - see
  http://github.com/synesissoftware/stlsoft-1.10/

=============================== End of file ================================
