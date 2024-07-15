pantheios - TODO lists
======================

Updated:    5th July 2020


Summaries:
==========


Pantheios 1.0 TODOs:
--------------------

 + new logo
 + new website
 + integrated blog
 ~ separate out all utility code into separate headers, impl files, etc.
 + PANTHEIOS_NOTHROW()
 ~ rewrite Core in pure C (or NoX for VC++ 7.1+ and GCC)
 ~ rewrite Back-ends in pure C (or NoX for VC++ 7.1+ and GCC)
 ~ rewrite Front-ends in pure C (or NoX for VC++ 7.1+ and GCC)
 + auto-generate project files for VS'98
 + auto-generate project files for 2010
 + auto-generate implicit-link files
 + auto-generate be l/r source files
 + auto-generate be l/r header files
 + rolling file
 ~ reimplement integral conversion in terms of new STLSoft 1.10 components
 * release by Q4 2012!!!



Pantheios 1.1 TODOs:
--------------------

 + auto-generate project files for Xcode


 ** fix the TODO file first!! **


 + Comeau 4.3.10 support

 + README.TXT
 ~ complete, sensible distribution files
 + separate UNIX and Windows distros, with the appropriate
   newline sequence for each
 ~ sort out \file fields
 + full complement of Visual Studio 2003 project/solution files
 + full complement of Visual Studio 2005 project/solution files
 + full complement of Visual Studio 2008 project/solution files
 + full complement of Visual Studio 2010 project/solution files
 ~ full complement of Visual Studio '98 project/solution files
 ~ review all the download/build/install documentation
 + auto-check all implicit_link files


Pantheios 1.1 TODOs:
--------------------

 + full complement of Turbo C++ project/solution files
 (possibly, + full complement of XCode project/solution files)
 + be.file buffering
 + be.file rolling
 + control console for fe.WindowsRegistry
 + component test be.WindowsSyslog

Pantheios 1.2 TODOs:
--------------------

 ~ Custom event log for bailout
 ~ Custom event log for be.WindowsEventLog
 + be.loader fixed/internal (Windows, Mac & UNIX)
 + be.loader dynamic/external (Windows, Mac & UNIX)

Pantheios 1.3 TODOs:
--------------------

 + implicit support for integer
 + implicit support for floating-point types (possibly)


Pantheios 1.4 TODOs:
--------------------

 + Integrate FastFormat for full internationalisation



Details:
========

The following is a (non-exhaustive) list of items that will ideally be
included in future releases.


? 2. RPMs, and packages for SUSE, FreeBSD, Mac OS-X, etc.
---------------------------------------------------------

Status:

Priority:   low/medium


? 4. pantheios_printf_len() family
----------------------------------

Status:

Priority:   low/medium

Details:

  These functions will help in the implementation of maximally
  efficient custom string access shims


? 6. Fast arena
---------------

Status:

Priority:   low/medium

Details:

  Create a Pantheios fast arena, for inserter classes.


? 8. Literal string internationalisation
----------------------------------------

Status:

Priority:   low

Details:

  Internationalise the severity strings ????


? 9. Implement be.pantheios.COM
-------------------------------

Status:

Priority:   medium

Details:

  This'll be implemented in terms of Pantheios.COM, implementing the
  back-end calls in terms of the Composite logger.


? 11. Workspaces/project files for compilers
--------------------------------------------

Status:

Priority:   low/medium

Details:

  Need to generate automatically from the VC6 ones, for:
    Borland
    Visual C++ (7.x, 8.0)
    others?


? 12. Fully featured log4cxx, log4cplus, log4cpp backends
---------------------------------------------------------

Status:

Priority:   medium


? 14. Implement be.loader for Windows
-------------------------------------

Status:

Priority:   medium

Details:


? 15. Implement be.loader for UNIX
----------------------------------

Status:

Priority:   medium

Details:


? 18. Allow be.file (or another be) to support file rolling
-----------------------------------------------------------

Status:

Prioriry:   medium

Details:    a user has requested a facility to allow log file rolling, i.e.
            where a log is closed, and another opened, based on date and/or
            size.


? 21. A decent README, and tutorial for UNIX and Win32, w + w/o IDE(s)
----------------------------------------------------------------------

Status:

Prioriry:   medium

Details:    ????.


? 24. Fully document the library naming convention
--------------------------------------------------

Status:

Prioriry:   medium

Details:    Explain to users what on earth
            pantheios.1.bec.COMErrorObject.vc71.mt.nox.debug.lib means.



? 27. Fully-featured ACE back-end / front-end
---------------------------------------------

Status:

Priority:   medium



=============================== End of file ================================
