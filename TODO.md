# Pantheios - TODO <!-- omit in toc -->


## Functional improvements


### 1.0.1-rc3 (10th September 2026)

* [ ] CI refactoring;
* [ ] **README.md** (and other project markdown) significant enhancement (in a similar vein as has been done for **xqsr3** (Ruby));
* [ ] Integration of **woad**;
* [ ] Using **AnsiConsole**;
* [ ] Using **ACE**;


### 1.0.1 final release (nice-to-have / non-mandatory)

Candidates to consider for the final 1.0.1 release if time permits, but non-blocking:

* [ ] Re-enable **test.unit.bec.COMErrorObject** on **MinGW** once **xTests** fixes multibyte string-equality helpers for GCC two-phase lookup (shim overloads declared after **xtests.h** is included); currently skipped in **test/unit/CMakeLists.txt**;
* [ ] Review all download/build/install documentation (**INSTALL.md**);
* [ ] Component test for **be.WindowsSyslog**;
* [ ] Sort out `\file` Doxygen fields across headers;
* [ ] Prune obsolete compiler and IDE project-file items from **TODO.md** (VS '98 through 2010, Turbo C++, Comeau, Xcode project-file generators);


### Pantheios 1.0 TODOs

* [ ] new logo;
* [ ] new website;
* [ ] integrated blog;
* [ ] separate out all utility code into separate headers, impl files, etc.;
* [ ] `PANTHEIOS_NOTHROW()`;
* [ ] rewrite Core in pure C (or NoX for VC++ 7.1+ and GCC);
* [ ] rewrite Back-ends in pure C (or NoX for VC++ 7.1+ and GCC);
* [ ] rewrite Front-ends in pure C (or NoX for VC++ 7.1+ and GCC);
* [ ] auto-generate project files for VS'98;
* [ ] auto-generate project files for 2010;
* [ ] auto-generate implicit-link files;
* [ ] auto-generate be l/r source files;
* [ ] auto-generate be l/r header files;
* [ ] rolling file;
* [ ] reimplement integral conversion in terms of new **STLSoft** 1.10 components;
* [ ] release by Q4 2012!!!;


### Pantheios 1.1 TODOs

* [ ] auto-generate project files for Xcode;
* [ ] fix the TODO file first!!;
* [ ] Comeau 4.3.10 support;
* [ ] README.TXT;
* [ ] complete, sensible distribution files;
* [ ] separate UNIX and Windows distros, with the appropriate newline sequence for each;
* [ ] sort out \file fields;
* [ ] full complement of Visual Studio 2003 project/solution files;
* [ ] full complement of Visual Studio 2005 project/solution files;
* [ ] full complement of Visual Studio 2008 project/solution files;
* [ ] full complement of Visual Studio 2010 project/solution files;
* [ ] full complement of Visual Studio '98 project/solution files;
* [ ] review all the download/build/install documentation;
* [ ] auto-check all implicit_link files;
* [ ] full complement of Turbo C++ project/solution files;
* [ ] (possibly, full complement of XCode project/solution files);
* [ ] be.file buffering;
* [ ] be.file rolling;
* [ ] control console for fe.WindowsRegistry;
* [ ] component test be.WindowsSyslog;


### Pantheios 1.2 TODOs

* [ ] Custom event log for bailout;
* [ ] Custom event log for be.WindowsEventLog;
* [ ] be.loader fixed/internal (Windows, Mac & UNIX);
* [ ] be.loader dynamic/external (Windows, Mac & UNIX);


### Pantheios 1.3 TODOs

* [ ] implicit support for integer;
* [ ] implicit support for floating-point types (possibly);


### Pantheios 1.4 TODOs

* [ ] Integrate **FastFormat** for full internationalisation;


### Future release items

* [ ] RPMs, and packages for SUSE, FreeBSD, Mac OS-X, etc.;
* [ ] Literal string internationalisation (internationalise the severity strings ????);
* [ ] Implement be.pantheios.COM (implemented in terms of Pantheios.COM, implementing the back-end calls in terms of the Composite logger);
* [ ] Workspaces/project files for compilers (generate automatically from the VC6 ones, for Borland, Visual C++ (7.x, 8.0), others?);
* [ ] Fully featured log4cxx, log4cplus, log4cpp backends;
* [ ] Implement be.loader for Windows;
* [ ] Implement be.loader for UNIX;
* [ ] Allow be.file (or another be) to support file rolling (where a log is closed, and another opened, based on date and/or size);
* [ ] A decent README, and tutorial for UNIX and Win32, w + w/o IDE(s);
* [ ] Fully document the library naming convention (explain to users what on earth pantheios.1.bec.COMErrorObject.vc71.mt.nox.debug.lib means);
* [ ] Fully-featured ACE back-end / front-end;


## Performance improvements

* [ ] `pantheios_printf_len()` family (these functions will help in the implementation of maximally efficient custom string access shims);
* [ ] Fast arena (create a Pantheios fast arena, for inserter classes);


<!-- ########################### end of file ########################### -->
