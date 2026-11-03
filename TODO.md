# Pantheios - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
  - [Pantheios 1.0.1](#pantheios-101)
    - [(final)](#final)
    - [1.0.1-rc10 (3rd November 2026)](#101-rc10-3rd-november-2026)
    - [1.0.1-rc9 (3rd November 2026)](#101-rc9-3rd-november-2026)
    - [1.0.1-rc5 (18th October 2026)](#101-rc5-18th-october-2026)
    - [1.0.1-rc4 (14th October 2026)](#101-rc4-14th-october-2026)
    - [1.0.1-rc3 (12th October 2026)](#101-rc3-12th-october-2026)
  - [Pantheios 1.0.x TODOs](#pantheios-10x-todos)
  - [Pantheios 1.1 TODOs](#pantheios-11-todos)
  - [Pantheios 1.2 TODOs](#pantheios-12-todos)
  - [Pantheios 1.3 TODOs](#pantheios-13-todos)
  - [Pantheios 1.4 TODOs](#pantheios-14-todos)
  - [Future release items](#future-release-items)
- [Performance improvements](#performance-improvements)


## Functional improvements

### Pantheios 1.0.1

#### (final)

* [x] ~~~Resolve the awkward / interim elements introduced into the helper scripts (**run_all_unit_tests.sh**, **run_all_examples.sh**, **run_all_scratch_tests.sh**, and related **GHA** steps such as executable-bit restore) before completing the **1.0.1** final release~~~ - ✅;


#### 1.0.1-rc10 (3rd November 2026)

* [ ] `PANTHEIOS_NOEXCEPT()`;
* [ ] Additional performance tests;
* [ ] Review all download/build/install documentation (**INSTALL.md**);
* [ ] ~~~Sort out **build/** directory~~~ - ✅;


#### 1.0.1-rc9 (3rd November 2026)

* [x] ~~~**b64** link-time dependency broken~~~ - ✅;


#### 1.0.1-rc5 (18th October 2026)

* [x] ~~~Integration of **woad** for coloured output~~~ - ✅;


#### 1.0.1-rc4 (14th October 2026)

* [x] ~~~**bec.stock** / **bec.stock.WithCallback** (exclude **bec.test**)~~~ - ✅;
* [x] ~~~Replace selected Pantheios custom code with post-**STLSoft**-1.9 facilities (process id via `platformstl_C_get_current_process_id`, **args** path basenaming via `filesystem_traits::find_last_path_name_separator`, **snprintf** via `stlsoft_C_vsnprintf`)~~~ - ✅;
* [x] ~~~**xTests**' Terse API applied throughout~~~ - ✅;
* [x] ~~~sort out \file fields~~~ - ✅;
* [x] ~~~Sort out `\file` Doxygen fields across headers~~~ - ✅;


#### 1.0.1-rc3 (12th October 2026)

* [x] ~~~CI refactoring~~~ - ✅;
* [x] ~~~Using **AnsiConsole**~~~ - ✅;
* [x] ~~~Using **ACE**~~~ - ✅;
* [x] ~~~Prune obsolete compiler and IDE project-file items from **TODO.md** (VS '98 through 2010, Turbo C++, Comeau, Xcode project-file generators)~~~ - ✅;
* [x] ~~~auto-generate project files for VS'98~~~ - ❌;
* [x] ~~~auto-generate project files for 2010~~~ - ❌;
* [x] ~~~auto-generate project files for Xcode~~~ - ❌;
* [x] ~~~Comeau 4.3.10 support~~~ - ❌;
* [x] ~~~full complement of Visual Studio 2003 project/solution files~~~ - ❌;
* [x] ~~~full complement of Visual Studio 2005 project/solution files~~~ - ❌;
* [x] ~~~full complement of Visual Studio 2008 project/solution files~~~ - ❌;
* [x] ~~~full complement of Visual Studio 2010 project/solution files~~~ - ❌;
* [x] ~~~full complement of Visual Studio '98 project/solution files~~~ - ❌;
* [x] ~~~auto-check all implicit_link files~~~ - ❌;
* [x] ~~~full complement of Turbo C++ project/solution files~~~ - ❌;
* [x] ~~~(possibly, full complement of XCode project/solution files)~~~ - ❌;


### Pantheios 1.0.x TODOs

* [ ] Refactor CMake test targets / options so that only unit-test executables are built when only unit-tests are asked for;
* [ ] Re-enable **test.unit.bec.COMErrorObject** on **MinGW** once **xTests** fixes multibyte string-equality helpers for GCC two-phase lookup (shim overloads declared after **xtests.h** is included); currently skipped in **test/unit/CMakeLists.txt**;
* [ ] Component test for **be.WindowsSyslog**;
* [ ] Thin `pantheios_getHostName` / **src/util/hostname.c** over a platformstl host-name C API once that API lands in **STLSoft** (Windows via `winstl_C_get_computer_name_*`; UNIX `gethostname` plus Pantheios Mac `ENAMETOOLONG` / length contract); keep test oracles OS-direct for orthogonality;
* [ ] new logo;
* [ ] new website;
* [ ] integrated blog;
* [ ] separate out all utility code into separate headers, impl files, etc.;
* [X] ~~~auto-generate implicit-link files~~~ - ❌;
* [ ] auto-generate be l/r source files;
* [ ] auto-generate be l/r header files;
* [ ] reimplement integral conversion in terms of new **STLSoft** 1.10 components;
* [X] ~~~release by Q4 2012!!!~~~ - ❌;
* [ ] additional performance tests;
* [ ] STLSoft-iiof last picks;


### Pantheios 1.1 TODOs

* [ ] fix the TODO file first!!;
* [ ] new backends:
  * [ ] **bec.mongoose**;
  * [ ] **bec.mosquitto**;
  * [ ] **bec.nanomsg**;
  * [ ] **bec.speech** macOS compatible;
  * [ ] **bec.sqlite**;
  * [ ] **bec.zmq** (Mikkoi's old submission modernised and introduced);
* [ ] be.file buffering;
* [ ] be.file rolling;
* [ ] rolling file;
* [x] ~~~README.TXT~~~ - ✅;
* [ ] complete, sensible distribution files;
* [ ] review all the download/build/install documentation;
* [x] ~~~separate UNIX and Windows distros, with the appropriate newline sequence for each~~~ - ✅;
* [ ] control console for fe.WindowsRegistry;
* [ ] component test be.WindowsSyslog;


### Pantheios 1.2 TODOs

* [ ] Custom event log for bailout;
* [ ] Custom event log for be.WindowsEventLog;
* [ ] be.loader fixed/internal (Windows, Mac & UNIX);
* [ ] be.loader dynamic/external (Windows, Mac & UNIX);
* [ ] rewrite Core in pure C (or NoX for VC++ 7.1+ and GCC);
* [ ] rewrite Back-ends in pure C (or NoX for VC++ 7.1+ and GCC);
* [ ] rewrite Front-ends in pure C (or NoX for VC++ 7.1+ and GCC);


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
* [ ] Develop a modern equivalent to the legacy Windows back-end selector tool (e.g. an interactive CLI setup assistant or web-based configurator) to generate ready-to-use **CMake** target linking configurations and presets;


## Performance improvements

* [ ] `pantheios_printf_len()` family (these functions will help in the implementation of maximally efficient custom string access shims);
* [ ] Fast arena (create a Pantheios fast arena, for inserter classes);


<!-- ########################### end of file ########################### -->
