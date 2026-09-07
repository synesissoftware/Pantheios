# Pantheios - Changes <!-- omit in toc -->


## 1.0.1-rc3 - 10th September 2026

T.B.C.


## 1.0.1-rc2 - 6th September 2026

* **bec.AnsiConsole**: on Windows, emit ANSI colours only when the host supports them — Win11 assumed ready, Win10 VT builds opt in via **`SetConsoleMode(... | ENABLE_VIRTUAL_TERMINAL_PROCESSING)`**, older hosts (e.g. XP) stay plain;
* examples and scratch tests: non-Windows console sink moved from **be.fprintf** to **be.AnsiConsole** for simple console demos (via **`define_simple_console_example_*`**, **be.console** / **bec.console** aliases, matching implicit-link headers, and per-project **CMakeLists.txt** / **implicit_link** updates); multiplex / callback / **be.N** cases deferred;
* **test.component.be.file.threading**: **be.N** console entry uses **`pantheios_be_console`** (platform alias) to match **bec.console.h** / Windows **bec.WindowsConsole** linkage;
* **CMake** package configuration: loaded `CMakeFindDependencyMacro` and added conditional `find_dependency()` calls for **STLSoft** and **b64** in **`pantheios-config.cmake`**; ensures exported static targets (such as `Pantheios::Pantheios.core`) provide transitive interface link dependencies (`b64::core`, `STLSoft::STLSoft`) to downstream consumers without requiring callers to invoke `find_package(b64)` manually;
* version definition: added `PANTHEIOS_VER_1_0_1_RC2` (`0x010001e2`) and updated `PANTHEIOS_VER` to RC2 in **include/pantheios/pantheios.h**;
* tooling and configuration: added **`.vscode/settings.json`**;
* documentation and release alignment: updated **NEWS.md**, **INSTALL.md**, and **KNOWN_ISSUES.md** for the 1.0.1-rc2 release;


## 1.0.1-rc1 - 5th August 2026

* modular GitHub Actions CI via **`.github/workflows/ci.yml`** and **`ci-cell.yml`** (Linux **Clang**/**GCC**, macOS **Clang**/**GCC**, Windows **cl**/**MinGW**; install-smoke consumer build/run; examples / unit / component / scratch as separate cells);
* documentation modernisation: **CHANGES.md** (from **CHANGES.txt**), removal of **HISTORY.md** and **README.txt**, and updates to **README.md**, **FAQ.md**, **INSTALL.md**, **TODO.md**, **KNOWN_ISSUES.md**, **AUTHORS.md**, and **HOW_YOU_CAN_HELP.md**;
* new stock back-end **bec.AnsiConsole** / **be.AnsiConsole** (bel/ber, colouring flags, argument parsing, unit and scratch tests);
* **CMake** enhancements: **Threads** / `PANTHEIOS_FORCE_MT`, `BUILD_TESTING`, optional **b64** via `NO_B64` / **`--no-b64`**, CMP0177, lowercase export package (**`pantheios-config.cmake`**), improved **STLSoft** include handling, and **`_BUILD_AS_UNIX`** / **`_BUILD_AS_WIN32`** OS discrimination;
* **CMake** package config: `find_dependency()` for **STLSoft** and (when built with it) **b64**, so consumers of **`Pantheios::Pantheios.core`** no longer see a missing **`b64::core`** imported target;
* modern composite **`PANTHEIOS_VER`** (`MAJOR` / `MINOR` / `PATCH` / `ALPHABETA`); **`test.unit.getversion`** covers those fields via **xTests** terse-api assertions; scratch **`libver`** + top-level **`libver.sh`**;
* helper scripts: **`.sis/project_name.txt`** / **`.sis/script_info_lines.txt`** wired into **`--help`** and status messages; **run_all_examples.sh**; **run_all_unit_tests.sh** gains **`--unit-only`** / **`--component-only`**; test runners exclude **`*.log`** from discovery;
* **bec.file**: create log files without execute permission (was `S_IRWXU`/`S_IRWXG`, which made suite-named logs executable and runnable by test discovery);
* back-end argument parsing: stock/custom boolean matches accumulate correctly; stock recognition of **`showThreadId`** / **`showDateTime`**; **test.unit.util.parse_args** and expanded **bec.*.parseArgs** unit coverage;
* test layout: **test.unit.be.WindowsSyslog** renamed to **test.unit.bec.WindowsSyslog**; added unit tests for **bec.speech**, **bec.syslog**, **bec.WindowsConsole**, and **bec.AnsiConsole**; **test.unit.bec.COMErrorObject** skipped on **MinGW** pending **xTests** multibyte equality fix;
* tooling and packaging: **`.gitattributes`**, **`.vimrc`**, **`.vscode/settings.json`**; copyright years through 2026;


## 1.0.1-beta222 - 18th November 2024

* full CMake support for optional dependencies (**b64** and **shwild**; **ACE** not yet done);
* Visual C++/CMake static library (MT) support;
* full CMake headers installation;
* full CMake dependencies for all targets;
* application of `noexcept` in various components' methods;
* wholesale file structure canonicalisation;
* wholesale example/test file content simplification;
* now required STLSoft 1.11.1-alpha25 (or later);


## 1.0.1-beta221 - 24th October 2024

* Major CMake configuration enhancements;
* Now optionally dependent on **b64** library (for `pantheios::b64` inserter class);
* Removed large number of warning suppressions;
* Defect fixes;
* MinGW compatibility;
* VC++17 compatibility;


## 1.0.1-beta220 - 16th July 2024

* C++14, C++17;
* CMake compatibility (Linux, macOS, Windows);
* New widestring bail-out API functions;
* Full widestring compatibility on Windows;
* Forwards/backwards compatibility with STLSoft (1.9, ..., 1.11);
* GCC compatibility;
* Visual C++17 compatibility;


## 1.0.1-beta219 - 5th July 2020

* added ::pantheios_char_t with all appropriate changes in library;
* added support for `PANTHEIOS_NO_B64` preprocessor symbol, which causes build and use of application layer inserters to be done without the b64 library (and the pantheios::b64 inserter);
* added support (including implicit-linking support) for Visual C++ 15.x and 16.x;
* forward-compatibility support for STLSoft 1.10 and 1.11;
* substantial reworking and fixes to makefiles;
* added project files (auto-generated) for Visual C++ 10;
* added bec.stock (and bec.stock.WithCallback) archive(s) and implicit-link file(s);
* bec.fprintf now always outputs to stderr by default; + can specify stream in initialiser;
* numerous minor mods and fixes to bec.file;
* added example.cpp.linking.N_with_stock;
* added test.unit.inserter.stream_character;
* added test.unit.util.snprintf;
* added test.component.bec.fprintf;
* added in test of stlsoft::fast_strftime in test.performance.util.date_elements_to_string;


## 1.0.1-beta218 - 29th January 2017

* added pantheios::windows::hive inserter and component test;
* added date elements -> string conversion functions;
* added pantheios::windows::hive inserter;
* added pantheios_be_N_tokenFromId();
* added pantheios_getStockSeverityStringSlice();
* added test.component.inserters.windows.hive;
* added test.performance.util.date_elements_to_string;
* added test.unit.inserters.windows.sc;
* added test.unit.util.date_elements_to_string;
* added callback functionality for be.WindowsEventLog;
* added PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY flag, which specifies that the severity will always be presented in numeric form in stock back-ends;
* added PANTHEIOS_BE_WINDOWSCONSOLE_F_CLEAR_AFTER_EACH_STATEMENT;
* added PANTHEIOS_BE_WINDOWSCONSOLE_F_RECOGNISE_16_SEVERITIES;
* stock back-ends now use the severity number for severity levels in the range [8, 16);
* tightening up initialisation logic, in case where process identity cannot be provided by the front-end (which should not strictly happen, but we want to be as tight as possible);
* separated out the default initialiser Schwarz counter instance from the counter header (so that it can be used separately);
* extracted out pantheios_slice_t and various integer types, and simplified a number of API functions (incl. back-ends);
* compatibility with STLSoft 1.9 and STLSoft 1.10.1 beta 2+;
* added CC_CUSTOM_DEFS_DEBUG, CC_CUSTOM_DEFS_RELEASE, CPPC_CUSTOM_DEFS_DEBUG, CPPC_CUSTOM_DEFS_RELEASE;
* moved pantheios_exitProcess (src/core/api.exitprocess.cpp) from Core to Util library;
* added clean.libs.util target;
* added compile.test.all target;
* changed compile.test target to be dependent only on compile.test.unit and compile.test.component targets;
* improved use of make preprocessor;
* shortening some target/intermediate names;


## 1.0.1-beta217 - 30th June 2016

* added severityFloor to be.N;
* test.unit.be.N.filtering;
* pantheios::pointer : + added protected method get_value(), to be used by deriving types such as forthcoming pantheios::windows::hive inserter;
* PANTHEIOS_ASSERT() and PANTHEIOS_MESSAGE_ASSERT() underlying assertions may now be overriden (via preprocessor);
* changed names and locations of generated files;
* changed no-throw declaration from stlsoft_throw_0() to STLSOFT_NOEXCEPT;
* refactoring of pantheios_util_strnlen();
* added GCC 4.8 support;
* added GCC 4.9 support;


## 1.0.1-beta216 - 25th October 2015

* fixed defect introduced in 1.0.1 beta 215;


## 1.0.1-beta215 - 27th September 2015

* added interval inserter;
* added stream_character inserter;
* Clang-compatibility;
* VC++ 11-compatibility;
* VC++ 12-compatibility;
* VC++ 14-compatibility;
* showPlus format flag support in pantheios::integer (pan::i);
* makefiles customisable to specify non-bundled locations of b64, shwild, xContract, xCover, and xTests libraries (useful to getting head from GitHub);


## 1.0.1-beta214 - 7th August 2012

* added variant_bool inserter, for COM Automation type VARIANT_BOOL;
* added new core API function pantheios_getProcessIdentity(), which reflects new dynamic process identity semantics for front-ends, and new C++ alias pantheios::getProcessIdentity();
* added PANTHEIOS_CARG_STR()/PANTHEIOS_CARG_STR_LEN() macros;
* added makefile for Intel C/C++ 12;
* pantheios::character inserter now compatible with wide characters, and allow conversion construction from char when widestring mode (i.e. expecting wchar_t);
* adjusted core initialisation to support new dynamic process identity semantics for front-ends;
* preparations for division of core (and later implementation in C);
* refactoring of memory-pool;
* changed way in which core discriminates atomic integer operation support when in multithreaded mode;
* pantheios::inserter adaptor is now wide-string compatible;
* added test.component.core.getProcessIdentity project;
* added test.component.inserters.variant_bool;
* added test.scratch.be.WindowsSyslog project;
* added test.scratch.be.WindowsSyslog.WithCallback project;
* bec.WindowsConsole now implemented in terms of pantheios_util_snprintf(), and made fully compatible with 64-bit;
* fixed bec.WindowsSyslog defect in arguments parsing (whereby supplied address would be ignored);
* removed use of deprecated format flag 'zeroPadded', replaced with 'zeroPad';
* wholesale tidying of definition of PANTHEIOS_FE_PROCESS_IDENTITY (in terms of PANTHEIOS_EXTERN_C and PANTHEIOS_LITERAL_STRING());
* wholesale changes for compatibility with STLSoft 1.9.115+'s integer_to_string;
* NOTE: Now requires STLSoft 1.9.115;


## 1.0.1-beta213 - 6th December 2011

* added GCC 4.6 makefiles;
* enhanced GCC compatibility in util component(s);
* declared pantheios_exitProcess() (and pantheios::exitProcess()) to be noreturn (effective in GCC and VC++);
* pantheios/util/com/exception_helpers.hpp is now deprecated. Users should instead obtain the Pantheios::Extras::xHelpers project, and include pantheios/extras/com/exception_helpers.hpp;
* NOTE: Now requires STLSoft 1.9.111;


## 1.0.1-beta212 - 13th August 2011

* fixes to various minor defects and documentation;
* added GCC format(printf) attribute to pantheios_util_snprintf_a();
* NOTE: Now requires STLSoft 1.9.109;


## 1.0.1-beta211 - 1st January 2011

* fixed erroneous implementation of pantheios_be_file_flush() in be.file;
* changes in be.file to adapt to STLSoft 1.9.107/8;
* changes to be.file to hide false positives given by MSVCRT memory leak reporting;
* fixed widestring trailing nul character (via STLSoft 1.9.107 char conversions) in bec.WindowsSyslog;
* exposed pantheios::init() and pantheios::uninit() in documentation;
* non-functional improvements to implementation of pantheios_getPad(), including ability to adjust buffer size at compile time;
* slightly enhanced status message for PANTHEIOS_INIT_RC_NOT_IMPLEMENTED;
* various other trivial changes to a number of source/project files;
* NOTE: Now requires STLSoft 1.9.108;


## 1.0.1-beta210 - 10th January 2011

* added compile-time validation to prevent fundamental types being passed to log statements;
* added GCC 4.5 support;
* NOTE: Now requires STLSoft 1.9.106;


## 1.0.1-beta209 - 6th January 2011

* Now returns the string "unrecognised status code" if the status code is, er, unrecognised;
* wide-string compatibility fix for example.cpp.util.strdup;
* skips manipulation of HKEY_LOCAL_MACHINE when don't have change access: allows program to succeed when tests run by user with limited premissions;
* added test.unit.util.getcurrenttime.vcproj;
* removing unnecessary C++ flags from C compiler settings in VC++ makefiles;


## 1.0.1-beta208 - 4th January 2011

* be.file added pantheios_be_file_flush(), and corrected omission to add 1900 to year and 1 to month in be.file's interpretation of date/time format specifiers in its file path;
* renamed status codes PANTHEIOS_INIT_RC_UNKNOWN_ERROR, PANTHEIOS_INIT_RC_UNSPECIFIED_ERROR to PANTHEIOS_INIT_RC_UNKNOWN_FAILURE, PANTHEIOS_INIT_RC_UNSPECIFIED_FAILURE;
* removed magic-numbers for return values and replacing with PANTHEIOS_INIT_RC_UNSPECIFIED_FAILURE in core and some stock back-ends;
* be.N minor performance/consistency improvement, and groundwork for coming feature enhancements;
* added FAQ#19, which explains how to use get Pantheios to compile the libraries when using Microsoft's -Zc:wchar_t- flag;
* all VC8+ makefiles no longer specify -D_CRT_SECURE_NO_DEPRECATE;
* added example.cpp.util.strdup;
* removed all extras files; these will be distributed in separate packages henceforth;


## 1.0.1-beta207 - 27th December 2010

* added FAQ-18, which discusses use of custom front-end with multiplexing back-end(s);
* added known implicit integral conversion vulnerability to KNOWN_ISSUES (affects Windows wide-string builds only);
* changed initialisation failure/warning bailout messages of fe.WindowsRegistry, for ease of use;
* improved bailout warning messages passed to Windows Event Log (affects Windows-only);
* added PANTHEIOS_FE_INIT_RC_INIT_CONFIG_REQUIRED initialisation code;
* added test.scratch.be.N.with.custom.fe for illustrating use of be.N back-end with a custom front-end;
* moved back-end sole/local/remote library forwarding symbols implementation files into subdirectories of src/backends/;
* NOTE: Now requires STLSoft 1.9.105;
* Windows users are advised to install the latest Pantheios.COM;


## 1.0.1-beta206 - 21st December 2010

* include/pantheios/inserters.hpp updated to include all new individual inserter headers;
* added test.unit.inserter.integer;
* added test.unit.inserter.m2w;
* added test.unit.inserter.w2m;
* workaround for Digital Mars symbol ambiguity defect in examples/cpp/misc/example.cpp.misc.custom_type_1/example.cpp.misc.custom_type_1.cpp;
* corrected/removed misleading statements in INSTALL.txt;
* include/pantheios/implicit_link/appl.h no longer includes include/pantheios/implicit_link/util.h;


## 1.0.1-beta205 - 11th December 2010

* added new example example.cpp.inserter.w2m;
* added new implicit link header include/pantheios/implicit_link/appl.h;
* added example.cpp.inserter.m2w to makefile(s);
* various improvements to examples and documentation;


## 1.0.1-beta204 - 7th December 2010

* wholesale changes to directory structure of C++ examples;
* added VC++ 6-9 project files for C++ examples;
* updating makefiles with all examples, including new and forgotten ones;


## 1.0.1-beta203 - 26th November 2010

* added pantheios::ch inserter typedef (for pantheios::character) for inserting characters in a succinct manner;
* added experimental support for use of 64-bit UNIX file-handling APIs in 32-bit builds, using -D_FILE_OFFSET_BITS=64 in build/gcc44.unix.file64bits directory;
* added appl library build targets, to facilitate use of Pantheios across shared libraries with a common code;
* added HOW_YOU_CAN_HELP.txt to distribution;
* enhanced the documentation;


## 1.0.1-beta202 - 23rd November 2010

* added pantheios::m2w inserter class;
* added unit test, component test, and performance test for pantheios::m2w;
* added single-threaded widestring targets to makefiles for VC++ 5-7.1;
* improved compatibility with Visual C++'s so-called "safe string" library;
* updated util and core project files for Visual C++ 6, 8, and 9;
* tidied up makefiles;
* NOTE: Now requires STLSoft 1.9.104;


## 1.0.1-beta201 - 19th November 2010

* added callback frontend functionality, to allow dynamic specification/creation of process identity at runtime, to stock front-ends;
* added implicit link headers, scratch test programs, and new make targets for callback frontends;
* pantheios_util_snprintf() now uses __attribute__((format(printf())) (in GCC compilation);
* various changes to improve makefiles, correct minor defects: shorted scratch test target names; simplified target labels;
* be.syslog scratch test program now uses simpler, dedicated program;
* added test.scratch.be.syslog.WithCallback;


## 1.0.1-beta200 - 15th November 2010

* added PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY to be.file;
* added pantheios::b shorthand inserter typedef (for pantheios::boolean);
* added implicit link headers for be.syslog.WithCallback;
* added missing be.speech project files;


## 1.0.1-beta199 - 10th November 2010

* added pantheios::xp inserter;
* added example.cpp.inserter.p example program;
* added example.cpp.inserter.xp example program;
* added test.scratch.be.syslog scratch test for Syslog;
* added test.scratch.be.syslog.WithCallback scratch test for Syslog, which illustrates how to change facility and/or suppress writing to stderr;


## 1.0.1-beta198 - 8th November 2010

* added pantheios::i shorthand inserter typedef (for pantheios::integer);
* added pantheios::xi shorthand inserter class (for pantheios::integer);
* fixed defect vulnerability in PANTHEIOS_ASSERT() and PANTHEIOS_MESSAGE_ASSERT();
* improves compatibility between narrow/wide Pantheios and narrow/wide ACE in be.ACE;
* improved detection of ACE in makefiles;
* trace API now reports file+line in bailout when assert log fails;
* added example for pantheios::i inserter;
* added example for pantheios::xi inserter;
* NOTE: Now requires STLSoft 1.9.102;


## 1.0.1-beta197 - 18th October 2010

* pantheios::integer inserter: now respects negative widths in three-parameter overloads;
* pantheios::integer inserter: 0x-prefix now counts in fixed-width formatting;
* pantheios::integer inserter: now deals with differently-sized integer types separately, allowing it to represents hex-form of 8-/16-bit integers in 2 and 4 digits;
* be.file now supports %T (for time) and %D (for date) format specifiers in file name;
* several substantial changes to Pantheios.Extras.COM's Exception Helpers, including change from default return E_UNEXPECTED to call ExitProcess() in catch-all clauses;
* NOTE: Now requires STLSoft 1.9.101;


## 1.0.1-beta196 - 4th April 2010

* full widestring compatibility;
* VC++ 10 support;
* minor defect fixes;
* added PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS and PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS to be.file;
* NOTE: Now requires STLSoft 1.9.97;


## 1.0.1-beta195 - 5th March 2010

* pantheios::w2m inserter class now accepts arbitrary wide string types (e.g. std::wstring, stlsoft::simple_wstring);
* enhanced component test for pantheios::w2m inserter class;
* NOTE: Now requires STLSoft 1.9.94;


## 1.0.1-beta194 - 15th February 2010

* added pantheios::slice inserter, along with test programs;
* wide-string compatibility at the source level (no build targets);
* ensures that PANTHEIOS_TRACE_PREFIX is convertible to pan_char_t const*;
* reports failure to assign file for all back-ends;
* Windows versions of GCC makefiles now generate libraries with leading lib and with the .a extension (i.e. libpantheios.1.util.gcc34.a, rather than pantheios.1.util.gcc34.lib);
* added build.common target to makefiles;
* removed VC++ 8/9 "safe" makefiles;
* bundles xTests 0.14.5;
* NOTE: Now requires STLSoft 1.9.93;


## 1.0.1-beta193 - 24th July 2009

* added static filtering to be.N (to supplement the dynamic filtering);
* minor change to be.WindowsConsole (to avoid seeming to leak memory, when none is leaked, due to initialisation ordering issues);
* bundles xTests 0.14.1;
* NOTE: Now requires STLSoft 1.9.86;
* NOTE: These are breaking changes: any programs that use be.N must be recompiled and relinked;


## 1.0.1-beta192 - 8th July 2009

* fixed defect in 64-bit bec.WindowsConsole;
* enhanced compiler compatibility for GCC, Intel and VC++ compilers;
* reduced dependencies in inserters header files;
* bundles xTests 0.13.3;
* NOTE: Now requires STLSoft 1.9.85;


## 1.0.1-beta191 - 4th July 2009

* added be.console pseudo back-end (resolves to be.WindowsConsole on Windows, and be.fprintf otherwise);
* fixed multi-threading defect in be.file;
* added test.component.be.file.threading component test;
* bundles xTests 0.13.2;
* NOTE: Now requires STLSoft 1.9.85;


## 1.0.1-beta190 - 3rd July 2009

* workaround of probably Intel 11 defect;
* added GCC 4.4 (UNIX) makefile;
* bundles xTests 0.13.2;
* NOTE: Now requires STLSoft 1.9.85;


## 1.0.1-beta189 - 29th June 2009

* added pantheios::pad inserter function, and PANTHEIOS_LPAD() and PANTHEIOS_RPAD() macros;
* added example and component-test for pantheios::pad inserter;
* fixed defect in test back-end be.test;
* bundles xTests 0.13.2;
* NOTE: Now requires STLSoft 1.9.85;


## 1.0.1-beta188 - 21st May 2009

* added example.c.extended_severity example;
* added two new FAQ items;
* fixed defect in stock back-ends whereby severity string would be empty if extended severity information was specified;
* various documentation enhancements;
* NOTE: Now requires STLSoft 1.9.83;


## 1.0.1-beta187 - 15th May 2009

* added makefile for Mac OS-X 64-bit;
* added prototype makefile for Sun Pro 5.9;
* all UNIX makefiles now remove Windows newline sequence in distribution sources;
* bundles xTests 0.13.1;
* NOTE: Now requires STLSoft 1.9.82;


## 1.0.1-beta186 - 8th May 2009

* added the Pantheios Assertion API: PANTHEIOS_ASSERT() and PANTHEIOS_MESSAGE_ASSERT();
* added example.c.assert and example.cpp.assert examplee;
* includes examples involving variadic macros in Borland makefiles, from 5.82 onwards;
* removed unnecessary (and unhelpful) dependencies on pantheios/pantheios.hpp for inserter classes;
* changed semantics of pantheios_malloc() to guarantee zeroing of allocation memory and valid alignment for any type;
* fixed incorrect definition of getInitErrorString();
* numerous changes to build foundation of future wide string support;
* bundles xTests 0.13.1;
* NOTE: Now requires STLSoft 1.9.81;


## 1.0.1-beta185 - 17th April 2009

* implicit link support for Intel C/C++ 10 & 11;
* preparatory work for widestring support;
* corrected two defects in pantheios_util_strnlen() length-limited length calculations;
* added unit test for strnlen;
* implicit link example now returns EXIT_SUCCESS, so 'make test.examples' can succeed;
* makefile clean.* targets now clean up all artefacts;
* NoX builds now correctly suppress use of exceptions and RTTI;
* bundles xTests 0.11.4;
* NOTE: Now requires STLSoft 1.9.77;


## 1.0.1-beta184 - 16th April 2009

* added 'version' member to all back-end initialisation structures, and verification action during back-end initialisation function;
* added PANTHEIOS_BE_INIT_RC_FUTURE_VERSION_REQUESTED and PANTHEIOS_BE_INIT_RC_OLD_VERSION_NOT_SUPPORTED initialisation codes;
* various minor documentation enhancements;
* bundles xTests 0.11.3;
* NOTE: Now requires STLSoft 1.9.77;
* NOTE: These are breaking changes: any programs that use stock back-ends must be modified, recompiled and relinked;


## 1.0.1-beta183 - 16th February 2009

* fixed defect in pantheios_logvprintf() that resulted in complete (rather than partial) truncation of over-long statements;
* workaround in pantheios::integer inserter class for VC++ 6's distinct 32-bit integer types;


## 1.0.1-beta182 - 15th February 2009

* workaround for Mac OS-X gethostname() defect;
* added support for Intel C/C++ 10 and 11;
* corrected packaging problem which led to old version of xTests being bundled in 1.0.1 beta 181;
* bundles xTests 0.10.4;


## 1.0.1-beta181 - 13th February 2009

* forces use of STLSoft 1.9.74, to workaround Borland code generation defects;
* NOTE: Now requires STLSoft 1.9.74;


## 1.0.1-beta180 - 3rd February 2009

* support for Borland 5.9.x and 6.1.x;
* NOTE: Now requires STLSoft 1.9.73;


## 1.0.1-beta179 - 1st February 2009

* fixed defect whereby pantheios_logvprintf() (and pantheios_logprintf()) failed to check severity before logging;
* NOTE: Now requires STLSoft 1.9.72;


## 1.0.1-beta178 - 16th January 2009

* added PANTHEIOS_BE_FILE_F_SHARE_ON_WINDOWS, which causes be.file to allow write-sharing on Windows;
* other minor changes;
* NOTE: Now requires STLSoft 1.9.66;


## 1.0.1-beta177 - 1st January 2009

* now has full "Safe String" compatibility for VC++ 8+;
* added GNU printf-format attribute to pantheios_logprintf();
* adjustment of example and test programs to use updated functions, instead of deprecated functions;
* adjusting case of bail out statements;


## 1.0.1-beta176 - 30th December 2008

* cleaned up creation of static libraries in Borland makefiles;
* bundles xTests 0.9.3;
* NOTE: Now requires STLSoft 1.9.64;


## 1.0.1-beta175 - 19th December 2008

* added two new initialisation codes, for resource access denial (permissions and locking);
* enhanced the return codes from be.file for file-open failure;
* enhanced COM exception helper function templates to enable working with custom severity level pseudo-constants;
* added scratch test for COM exception helper function templates;
* NOTE: Now requires STLSoft 1.9.63;


## 1.0.1-beta174 - 3rd December 2008

* logputs() now subject to severity filtering;
* refactored core => back-end dispatching;
* added two more scratch test projects;
* added one more component test project;
* removal of previously deprecated files;


## 1.0.1-beta173 - 18th November 2008

* added new functionality to be.speech, in order to provide workaround for suspected SAPI defect;
* enhanced pantheios::integer inserter class, adding 3-parameter ctors to remove ambiguity between width and format;
* more changes forming part of the groundwork for future widestring support;
* reduced dependencies of various components;


## 1.0.1-beta172 - 13th November 2008

* enhanced pantheios::integer inserter class, adding 3-parameter ctors to remove ambiguity between width and format;
* many changes forming part of the groundwork for future widestring support;


## 1.0.1-beta171 - 11th November 2008

* enhanced pantheios::hex_ptr inserter class in line with the changes to pantheios::pointer in the previous release;
* added example.cpp.hex_ptr;
* added test.examples target, which executes all example programs;


## 1.0.1-beta170 - 10th November 2008

* enhanced pantheios::pointer inserter class, adding 3-parameter ctor to remove ambiguity between width and format;
* added compile-time user-customisation of pantheios_log_n() internal buffer size;
* added compile-time user-customisation of pantheios_logprintf() stack size;


## 1.0.1-beta169 - 3rd November 2008

* added more overloads to pantheios::extras::com::invoke_nothrow_method();


## 1.0.1-beta168 - 18th October 2008

* added two new FAQ items;
* removed previously deprecated files;
* added implementations of functions deprecated (and renamed) in 1.0.1 beta 167;
* fixed defective using declaration in pantheios/util/com/exception_helpers.hpp;


## 1.0.1-beta167 - 16th October 2008

* final changes to ensure no-namespace compatibility;
* renaming/deprecation of badly-named API functions;


## 1.0.1-beta166 - 15th October 2008

* Final pre-release refactoring of all util|helper|extra header files;


## 1.0.1-beta165 - 14th October 2008

* Substantial reworking of contract API, reflected throughout the headers, implementation, example and test files;


## 1.0.1-beta164 - 12th October 2008

* several changes to ensure that the suppression of stock severity levels is complete, and that the definition of custom severity levels is clean and may use the pantheios::levels constant generator class template;
* the pantheios::util::backends::Context base class is altered in two ways to facilitate a wider range of severity levels than is provided by the stock front-/back-ends;
* the deprecated file include/pantheios/error_codes.h now issues a #error if included, in preparation for final removal;
* NOTE: These are breaking changes: any programs that define custom back-ends based on pantheios::util::backends::Context must be modified, recompiled and relinked;


## 1.0.1-beta163 - 11th October 2008

* removal of deprecated file(s);
* more compatibility with namespace-suppression;


## 1.0.1-beta162 - 7th October 2008

* compatibility with MFC when pantheios/pantheios.hpp is the first #include;
* compatibility with namespace-suppression;


## 1.0.1-beta161 - 27th September 2008

* sharpened up error messages when attempting to use previously removed features of fe.simple;
* changed requirements of application-defined components in be.WindowsEventLog to a single new function;
* NOTE: These are breaking changes: any programs that use be.WindowsEventLog must be modified, recompiled and relinked;


## 1.0.1-beta160 - 24th September 2008

* include/pantheios/inserters.hpp now includes include/pantheios/inserters/hostid.hpp;
* modification to ensure cross-link-unit compatibility when Pantheios libraries are exported from a dynamic library;
* added missing project map (HTML) files within project structure;


## 1.0.1-beta159 - 22nd September 2008

* added two back-end targeting/multiplexing examples;
* added PANTHEIOS_MAKE_EXTENDED_SEVERITY() macro, for targeting statements to back-ends when using the C API;
* added project map (HTML) files within project structure;


## 1.0.1-beta158 - 19th September 2008

* deprecated file pantheios/util/threading/threadid.h now #error on use;
* include/pantheios/error_codes.h => include/pantheios/init_codes.h;
* include/src/util/init_error_strings.c => include/src/util/init_code_strings.c;


## 1.0.1-beta157 - 18th September 2008

* added new error code (PANTHEIOS_BE_INIT_RC_INIT_CONFIG_REQUIRED);
* improved error reporting in fe.WindowsRegistry;


## 1.0.1-beta156 - 12th September 2008

* refactoring of build directories;
* non-functional textual changes;
* NOTE: These are breaking changes: some target compiler/operating-system/architecture have been renamed;


## 1.0.1-beta155 - 11th September 2008

* fixed defect in component test for pantheios::w2m inserter class;
* NOTE: Now requires STLSoft 1.9.52;


## 1.0.1-beta154 - 2nd September 2008

* added pantheios::w2m (widestring to multibyte) inserter, for use until widestring version of library available;
* added component test for pantheios::w2m inserter class;
* added performance test for pantheios::w2m inserter class;
* NOTE: Now requires STLSoft 1.9.49;


## 1.0.1-beta153 - 1st September 2008

* fixed defect in pantheios/util/time/currenttime.h;
* added example.c.getcurrenttime (for pantheios_getCurrentTime());


## 1.0.1-beta152 - 28th August 2008

* added source-only distribution, to reduce the download size for users that use the online documentation;
* added pantheios_getVersion() function, to allow client code to do runtime tests on the version of Pantheios to which they're linking;
* added unit-test for pantheios_getVersion();
* added missing implicit link headers for fe.fail and fe.null;
* modified fe.fail to reduce unnecessary link dependencies;


## 1.0.1-beta151 - 25th August 2008

* tidied up a large number of out-of-date markup elements in docs;
* optimised the implementation of fe.N;
* added example for pantheios_getHostName();
* finalised the structure of the project/solution files for Visual Studio (other IDEs will be done in later release);
* bundles b64 1.3.4;


## 1.0.1-beta150 - 24th August 2008

* fixed defect in fe.N, whereby a negative catch-all severity ceiling would not be respected;
* other minor adjustments/improvements to fe.N;
* added unit-test for fe.N;
* bundles xTests 0.8.5;
* NOTE: Now requires STLSoft 1.9.48;
* NOTE: These are breaking changes. Any code using the extant fe.N front-end library will need to be edited and re-compiled;


## 1.0.1-beta149 - 12th August 2008

* added unit-test for fe.WindowsRegistry;
* adjustments to contract enforcement conditions to be compatible with ultra-pedantic GCC 4.3 warnings;
* minor adjustments to CodeWarrior and Digital Mars makefiles;


## 1.0.1-beta148 - 11th August 2008

* a large number of small changes to the names and/or namespaces of utility functions and classes that do not form part of the set commonly used by authors of client code, in order to simplify the apparent APIs of the Core and Application Layer;
* bundles xTests 0.8.4;


## 1.0.1-beta147 - 7th August 2008

* enhanced pantheios::boolean inserter class to be I18N/L10N-friendly;
* added unit test for pantheios::boolean inserter class;
* adjustments to contract enforcement conditions to be compatible with ultra-pedantic GCC 4.3 warnings;


## 1.0.1-beta146 - 7th August 2008

* added pantheios::boolean inserter class;
* added unit test for be.fprintf;


## 1.0.1-beta145 - 1st August 2008

* fixed bug in be.fprintf introduced in 1.0.1 beta 144;
* cleanup in the comment headers for a large number of source files, in preparation for final non-beta release;


## 1.0.1-beta144 - 30th July 2008

* added thread Id as a default detail in the statement prefix of all Pantheios stock back-end(s) (except be.speech);
* NOTE: These are breaking changes. Any programs using the Pantheios stock back-ends that do not want to see thread Id will now need to use the callback forms of the back-end(s) and set the PANTHEIOS_BE_INIT_F_NO_THREAD_ID flag in the callback function!;
* added support for GCC 4.3;


## 1.0.1-beta143 - 29th July 2008

* refactoring of process Id and thread Id functions;
* added support for GCC 4.3;


## 1.0.1-beta142 - 25th July 2008

* minor adjustments of Application Layer;
* enhanced functionality of pantheios::args inserter class;


## 1.0.1-beta141 - 24th July 2008

* deprecation of pantheios_exit_process(), and replacement with pantheios_exitProcess();
* reduction in source code size of Application Layer generated function templates;
* fix to date-dependent bug in unit-test for pantheios_getCurrentTime();


## 1.0.1-beta140 - 19th June 2008

* correction of bug in pantheios.h introduced in beta 139;


## 1.0.1-beta139 - 18th June 2008

* deprecation of pantheios_puts() and pantheios::put(), in favour of pantheios_logputs() and pantheios::logputs();
* minor makefile fixes and modifications;
* bundles xTests 0.8.3;


## 1.0.1-beta138 - 16th June 2008

* enhancements to customisation of Application Layer;
* implicit linking for fe.WindowsRegistry;
* added project files for Visual C++ v7.1 for Core, Util, backends, and frontends;
* added project files for Visual C++ v8 for Core, Util, backends, and frontends;
* bundles xTests 0.8.2;


## 1.0.1-beta137 - 2nd June 2008

* distribution cleanup release - no new functionality;
* minor fix to implicit linking for VC++ 8 & 9;
* bundles shwild 0.9.18;


## 1.0.1-beta136 - 21st May 2008

* fixed a bug in the contract enforcements of fe.N;
* fixed a bug in the unit-test for pantheios_getCurrentTime();
* bundles xTests 0.7.3;


## 1.0.1-beta135 - 17th May 2008

* fully separated the Pantheios Util and Pantheios Core libraries, including source, makefiles and targets, and project files;
* NOTE: Now requires STLSoft 1.9.42;
* NOTE: These are breaking changes. Any code using the extant Pantheios Core library will need to be relinked (to also include the Util library);


## 1.0.1-beta134 - 16th May 2008

* fixed bug in test.unit.util.getcurrenttime;
* bundles shwild 0.9.16;


## 1.0.1-beta133 - 14th May 2008

* added unit-tests for fe.all, fe.fail, fe.null and fe.simple;
* minor modifications to contract enforcement macros;
* NOTE: Now requires STLSoft 1.9.41;


## 1.0.1-beta132 - 13th May 2008

* wholesale refactoring of front-end and back-end directory names;
* NOTE: Now requires STLSoft 1.9.40;


## 1.0.1-beta131 - 11th May 2008

* enhanced the behaviour of the pantheios::args inserter;
* enhanced testability of bailout functionality;
* removal of obsolete implementation files;
* bundles xTests 0.7.2;
* NOTE: Now requires STLSoft 1.9.39;


## 1.0.1-beta130 - 4th May 2008

* Win64 compatibility;
* bundles shwild 0.9.15;
* bundles xTests 0.7.1;
* NOTE: Now requires STLSoft 1.9.38;


## 1.0.1-beta129 - 3rd May 2008

* fix for minor errors in distribution;
* removal of incorrect auto-initialisation suppression in MFC client programs;
* bundles shwild 0.9.14;
* NOTE: Now requires STLSoft 1.9.37;


## 1.0.1-beta128 - 1st May 2008

* now compatible with FreeBSD;
* minor bug fix in bail-out functionality on UNIX;
* NOTE: Now requires STLSoft 1.9.36;


## 1.0.1-beta127 - 29th April 2008

* modification of measures to reduce compilation times on Windows;
* enhancement of bail-out functionality for UNIX;
* addition of unit test for bail-out;
* bundles xTests 0.6.5;
* NOTE: Now requires STLSoft 1.9.34;


## 1.0.1-beta126 - 22nd April 2008

* introduction of measures to reduce compilation times on Windows;
* various trivial warning suppressions;
* addition of UNIX emulation makefiles for VC++ 7.1, 8 and 9;
* NOTE: Now requires STLSoft 1.9.32;


## 1.0.1-beta125 - 20th April 2008

* fixes for UNIX/GCC compilation errors and warnings introduced in beta 124;
* refactoring of Util library header/implementation names;
* NOTE: These are breaking changes. Any code using the extant Pantheios current time API will need to be edited and rebuilt!;


## 1.0.1-beta124 - 20th April 2008

* added full-fledged contract enforcement constructs;
* updates to test code in respect of enhancements of xTests 0.6.1;
* bundles xTests 0.6.1;
* NOTE: These are breaking changes. Any code using the extant Pantheios assert macros will need to be edited and rebuilt!;


## 1.0.1-beta123 - 19th April 2008

* fix for VC++ 6 / Borland / DMC++ compilation problems with hostId;
* fix for ACE builds with VC++;
* refactoring of test directories/names;
* large-scale refactoring of Core and Util library header and implementation file and API member names;
* bundles xTests 0.5.2;
* NOTE: These are breaking changes. Any code using the Pantheios C API will need to be edited and rebuilt!;


## 1.0.1-beta122 - 16th April 2008

* addition of missing back-end implicit link header files;
* new example for hostId inserter;
* workaround for VC++ 8/9 linker error;
* bundles xTests 0.5.1;


## 1.0.1-beta121 - 15th April 2008

* addition of pantheios::hostId inserter class, and supporting utility functions;
* various minor back-end fixes and refactorings;
* NOTE: Now requires STLSoft 1.9.31;


## 1.0.1-beta120 - 10th April 2008

* addition of missing back-end implicit link header files;
* renamed supporting libraries to UNIX-conventional prefix/suffix;


## 1.0.1-beta119 - 8th April 2008

* addition of missing back-end implicit link header files;


## 1.0.1-beta118 - 6th April 2008

* minor contract enforcement enhancements in some front-/back-ends;
* bundles shwild 0.9.13;


## 1.0.1-beta117 - 5th April 2008

* fix for threadId component test on Mac OS-X (G4);


## 1.0.1-beta116 - 4th April 2008

* fix for b64 component test for big-endian architectures;


## 1.0.1-beta115 - 3rd April 2008

* Visual C++ 8/9 compatiblity fixes;
* Solaris compatibility fixes;
* NOTE: Now requires STLSoft 1.9.30;


## 1.0.1-beta114 - 2nd April 2008

* Syslog compatibility fixes;


## 1.0.1-beta113 - 28th March 2008

* Solaris compatibility fixes;


## 1.0.1-beta112 - 20th March 2008

* renamed libraries to UNIX-conventional prefix/suffix;


## 1.0.1-beta111 - 19th March 2008

* added compatibility with VC++ 9;
* added compatibility with GCC 4.2;
* bundles shwild 0.9.12;
* fix for string conversion pedantic warning with GCC 4.2;


## 1.0.1-beta110 - 18th March 2008

* fix for weird namespace bug in pantheios::threadId inserter with GCC;


## 1.0.1-beta109 - 17th March 2008

* fix for bug in b64 inserter header (introduced in 1.0.1 beta 107);
* fix for GCC 4.0 error in pantheios::integer inserter;
* fix for token-pasting error in tracing example;
* fix for test.component.inserters.threadid on OS-X;
* bundles xTests 0.3.2;
* now depends on STLSoft 1.9.27;


## 1.0.1-beta108 - 16th March 2008

* added new be.WindowsMessageBox back-end;
* bundles b64 1.3.1;
* bundles shwild 0.9.11;
* bundles xTests 0.3.1;
* now requires STLSoft 1.9.26;


## 1.0.1-beta107 - 15th March 2008

* various adjustments to ensure correct functioning when compiling C++ client code, but suppressing pantheios namespace;
* added example for namespace-suppressed use of library;
* added example for tracing;
* updated FAQ item;
* new FAQ item;
* updated to include xTests 0.3;


## 1.0.1-beta106 - 13th March 2008

* complete back-end and front-end project files for Visual Studio '98;
* upgraded to use xTests 0.2.2;
* bug fix to pantheios_onBailOut3();


## 1.0.1-beta105 - 9th March 2008

* new front-end: fe.fail;
* use of forward include guards throughout include files to improve compilation times;
* fix for bug introducted in 1.0.1 beta 104;
* documentation improvements;


## 1.0.1-beta104 - 8th March 2008

* new front-end: fe.null;
* documentation improvements;


## 1.0.1-beta103 - 1st March 2008

* enhanced bail out features, to include a message qualifier;
* minor compiler warning modifications;


## 1.0.1-beta102 - 25th February 2008

* upgraded to use xTests 0.1.15, to fix compilation bug when exception-handling support is switched off;


## 1.0.1-beta101 - 23rd February 2008

* makefile for GCC 4.1;
* upgraded to use xTests 0.1.14;
* upgraded to use STLSoft 1.9.23;
* minor implementation adjustments;


## 1.0.1-beta100 - 20th February 2008

* documentation improvements;
* added back-end structure initialisation;
* makefile improvements;
* upgraded to use xTests v0.1.11;


## 1.0.1-beta99 - 12th February 2008

* reduced compilation load for inserter classes;
* bug fix for Linux compilation;


## 1.0.1-beta98 - 9th February 2008

* added new test case;
* refactored back-end implementation files;
* bug fix to src/util/time.cpp;


## 1.0.1-beta97 - 8th February 2008

* NOTE: Now requires STLSoft 1.9.22;
* bundles b64 1.2.5;
* bundles shwild 0.9.9;
* bundles xTests 0.1.8;
* partial compatiblity with safe string library (VC8+);


## 1.0.1-beta96 - 5th February 2008

* fixed subtle makefile bug (pertaining to be.test);
* workaround for odd (and breaking) #include behaviour of GCC on UNIX;


## 1.0.1-beta95 - 5th February 2008

* NOTE: Now requires STLSoft 1.9.21;
* added unit test for be.N;
* fixed wrong test values in test.component.inserters.threadId;


## 1.0.1-beta94 - 3rd February 2008

* NOTE: Now requires STLSoft 1.9.20;
* makefiles updated for separate single- and multi-threaded targets on UNIX;
* updated string API, and concomitant refactoring of inserter classes;
* removal of multi-threading constructs from core and back-end implementations in single-threading compilation contexts;
* updated to version 0.1.8 of xTests library;


## 1.0.1-beta93 - 2nd February 2008

* NOTE: Now requires STLSoft 1.9.19;
* increased severity levels ranges for be.fprintf and be.speech;


## 1.0.1-beta92 - 28th January 2008

* added more unit-tests;
* refactored back-end stock implementation class namespace;
* NOTE: These are breaking changes. Any custom back-ends defined using pantheios::internal::Context will have to be edited and recompiled;


## 1.0.1-beta91 - 27th January 2008

* NOTE: Now requires STLSoft 1.9.18;
* refactoring of inserter classes;
* bug fix to makefile for GCC compilation;


## 1.0.1-beta90 - 27th January 2008

* almost complete elimination of use of sprintf() / snprintf() except where necessary to support variadic API functions;


## 1.0.1-beta89 - 26th January 2008

* refactored example directories and file-names;
* enhanced makefiles to incorporate all examples;


## 1.0.1-beta88 - 20th January 2008

* fixes for various minor bugs introduced in beta 87;


## 1.0.1-beta87 - 20th January 2008

* refactor threadId and pointer inserter classes;
* simplified Tracing API implementation;
* refactored 4 back-ends (be.file, be.speech, be.WindowsConsole, be.WindowsDebugger);
* enhanced unit testing of be.COMErrorObject;
* added unit testing of be.file;
* added component testing of Tracing API;
* uses version 0.1.6 of xTests library;


## 1.0.1-beta86 - 19th January 2008

* enhanced be.test, so it can be used in conjunction with other back-ends;
* minor changes/enhancements to memory handling;
* added more example projects;


## 1.0.1-beta85 - 15th January 2008

* Bug file in be.file;
* Updated error strings;


## 1.0.1-beta84 - 14th January 2008

* Minor enhancements to Application Layer;
* Refactoring of stock back-end common library, to enhance efficiency;
* Additional component tests;


## 1.0.1-beta83 - 13th January 2008

* Minor enhancements to Application Layer;
* Additional component tests;


## 1.0.1-beta82 - 12th January 2008

* Changed befe.test to be.test, for increased flexibility in testing;


## 1.0.1-beta81 - 11th January 2008

* Bug fix for 64-bit Linux;


## 1.0.1-beta80 - 8th January 2008

* changed be.file API: BREAKING CHANGE!;
* NOTE: These are breaking changes. Any code using any be.file stock back-ends will need to be edited!;
* further refactoring of src directories;


## 1.0.1-beta79 - 6th January 2008

* fixed broken UNIX makefiles introduced with beta 78;
* incorporates shwild 0.9.9;


## 1.0.1-beta78 - 6th January 2008

* added new front-end: fe.all;
* compatibility release, to require v1.9.17 of STLSoft, which fixes a compilation issue with GCC on Leopard;


## 1.0.1-beta77 - 5th January 2008

* major code refactoring: moving all unnecessary code from Core into Util to facilitate future reductions in coupling between modules;
* minor addition to Util API;


## 1.0.1-beta76 - 4th January 2008

* workaround for VC++ 8 linker issue;
* minor bug fix in component test program;
* minor change in Core API to reduce coupling;
* minor compatibility changes with Win64;


## 1.0.1-beta75 - 3rd January 2008

* Included unit/component-testing framework into public distribution;
* Now bundles shwild library for use in unit-test pattern matching;
* Now bundles xTests library for component/unit-testing;
* Updated the error code strings in the Core to reflect recent additions;
* Enhanced pantheios::pointer inserter (Application Layer);
* Fixed benign (but annoying) bug in time routines (Util);
* Enhanced functionality of be.COMErrorObject (Back-end);
* Adjusted all makefiles to build and execute new Unit and Component tests;
* Fixed compilation error in example 10 (Examples);
* Added/adjusted 4 Unit tests (Test);
* Added/adjusted 8 Component tests (Test);


## 1.0.1-beta74 - 30th December 2007

* compatibility release, to require v1.9.16 of STLSoft, which fixes two bugs: -ve short/int formatting on 64-bit Linux; 12hr/24hr time representation on Windows;


## 1.0.1-beta73 - 29th December 2007

* fixed compilation error introduced in 1.0.1 beta 72;


## 1.0.1-beta72 - 28th December 2007

* Change of back-end initialisation flags and parsing: BREAKING CHANGE!;
* NOTE: These are breaking changes. Any code using any stock back-ends may need to be edited!;
* NOTE: *ALL* code using Pantheios must be recompiled, or runtime errors may occur!;
* Additional minor adjustments in application layer;
* Additional initialisation error codes defined;


## 1.0.1-beta71 - 27th December 2007

* Cleanup release, preparing for introduction of unit/component-testing to the distribution;


## 1.0.1-beta70 - 11th December 2007

* Shift of back-end initialisation flags: BREAKING CHANGE!;
* NOTE: These are breaking changes. All code using any stock back-ends will need to be edited and recompiled!;
* NOTE: *ALL* code using Pantheios must be recompiled, or runtime errors may occur;


## 1.0.1-beta69 - 10th December 2007

* Further documentation enhancements;


## 1.0.1-beta68 - 8th December 2007

* Small refactoring of #include directories, and test programs;
* Further documentation enhancements;
* Corrected spelling errors (pantheios, not panthieos);


## 1.0.1-beta67 - 5th December 2007

* Substantial rework/enhancement to the documentation;


## 1.0.1-beta66 - 4th December 2007

* Added new pantheios::hex_ptr inserter class, which provides a shorthand for using pantheios::pointer in hex format;


## 1.0.1-beta65 - 3rd December 2007

* Moved all remaining test files to new naming/directory scheme;
* Fixed compilation warnings with GCC in test files;


## 1.0.1-beta64 - 2nd December 2007

* Fixed weird behaviour in test programs with DMC++;


## 1.0.1-beta63 - 29th November 2007

* Further refactoring of test directories;


## 1.0.1-beta62 - 27th November 2007

* fixed compiler warnings with VC++ 8;


## 1.0.1-beta61 - 26th November 2007

* enhancement of fe.WindowsRegistry;


## 1.0.1-beta60 - 25th November 2007

* reduction of source code size in generated headers;
* ability to reduce compilation load of Application Layer by control of PANTHEIOS_APPL_PARAMS_LIMIT pre-processor symbol;
* new FAQ item;
* minor inconsistency fix in shim suppression symbols;
* minor changes in documentation;


## 1.0.1-beta59 - 24th November 2007

* Refactoring of test directories;
* Tidying of examples;
* Added hexptr inserter example;


## 1.0.1-beta58 - 23rd November 2007

* Refactoring of front-end include files and API symbols;


## 1.0.1-beta57 - 22nd November 2007

* Various necessary changes and enhancements to back-end argument parsing and documentation;


## 1.0.1-beta56 - 21st November 2007

* bug fix in pantheios::threadId inserter (when used on UNIX);
* significant refactoring of back-end argument parsing API and include file directory structure;


## 1.0.1-beta55 - 20th November 2007

* Renamed be.Win32Console backend to be.WindowsConsole;
* Renamed be.Win32Debugger backend to be.WindowsDebugger;
* Renamed be.Win32syslog backed to be.WindowsSyslog;
* NOTE: These are breaking changes. All code using any stock back-ends will need to be edited and recompiled!;
* NOTE: *ALL* code using Pantheios must be recompiled, or linker errors may occur;


## 1.0.1-beta54 - 19th November 2007

* Standardisation of front-end process identity symbols. NOTE: This is a breaking change. All code using any stock front-ends will need to be edited and recompiled!;
* NOTE: *ALL* code using Pantheios must be recompiled, or linker errors may occur;


## 1.0.1-beta53 - 18th November 2007

* NOTE: Now requires STLSoft 1.9.7;
* Facilities for accelerating compilation times by restricting function template parameter range;
* Various code cleanup in backend utility functions;


## 1.0.1-beta52 - 17th November 2007

* Refactoring of include files;
* Removal of implementation functions from pantheios namespace, and documentation;
* Removed Windows-dependency that broke the build in beta 51;


## 1.0.1-beta51 - 16th November 2007

* VC++ 2005 / 64-bit compilation fixes;


## 1.0.1-beta50 - 15th November 2007

* re-issue due to distribution error with 1.0.1 beta 49;


## 1.0.1-beta49 - 14th November 2007

* bug fix for VC++ 2005;
* refactoring of severity translations from ACE, syslog, log4???;


## 1.0.1-beta48 - 13th November 2007

* high and low resolution timing options in backend statement formatting;
* example programs for high and low resolution timing;
* adjustments to makefiles;


## 1.0.1-beta47 - 12th November 2007

* moved Pantheios Trace API into separate include file;
* minor adjustment to GCC makefiles;
* minor bug fix to address compiler warning on UNIX;


## 1.0.1-beta46 - 11th November 2007

* considerable refactoring of date/time handling in back-end statement;
* minor fix to makefiles on Mac OS-X;


## 1.0.1-beta45 - 10th November 2007

* code cleanup and refactoring, ready for several functional enhancements in next several releases;
* reduced size of N-ary Generated Function Templates in Application Layer;
* removal of obsolete KiwiSyslog KLOG back-end;


## 1.0.1-beta44 - 3rd November 2007

* more code tidying / refactoring;


## 1.0.1-beta43 - 3rd November 2007

* code tidying / refactoring;


## 1.0.1-beta42 - 29th October 2007

* fix for fe.WindowsRegistry;


## 1.0.1-beta41 - 28th October 2007

* added new frontend: fe.WindowsRegistry;
* further initialisation error codes;
* minor additions to core API;


## 1.0.1-beta40 - 26th October 2007

* minor bug fix in be.file back-end;


## 1.0.1-beta39 - 25th October 2007

* minor modifications and code cleanup;


## 1.0.1-beta38 - 23rd October 2007

* added new be.speech back-end, which provides spoken output of log statements. (Note: currently for Windows only.);


## 1.0.1-beta37 - 21st October 2007

* Changed PANTHEIOS_SEV_xxx from enumerators to SEV_xxx enumerators, and #define corresponding PANTHEIOS_SEV_xxx;
* Changed implementation of levels "constant classes", to avoid dynamic initialisation ordering problems;
* Tidying up code in test tree;


## 1.0.1-beta36 - 20th October 2007

* further enhancements be.N to facilitate backup back-end to be initialised only if all prior back-end initialisations failed;


## 1.0.1-beta35 - 19th October 2007

* further enhancements be.N to facilitate targeting messages to specific back-ends;


## 1.0.1-beta34 - 18th October 2007

* enhanced be.N to facilitate targeting messages to specific back-ends;


## 1.0.1-beta33 - 7th October 2007

* standardised Initialisation Error Codes;
* large number of makefile changes, to simplify & clean;
* callback functionality to be.COMErrorObject;
* minor bug-fix in be.Win32syslog;


## 1.0.1-beta32 - 3rd September 2007

* Fixes for 64-bit UNIX;


## 1.0.1-beta31 - 18th August 2007

* Fix to Pantheios Tracing API;
* Fix to GCC 3.x makefiles;


## 1.0.1-beta30 - 16th August 2007

* Added back-end generation macros, to ease compile-time selection/definition;
* fixed (benign) bug for Borland build;


## 1.0.1-beta29 - 5th August 2007

* message-first statement composition;


## 1.0.1-beta28 - 2nd August 2007

* compatible with STLSoft 1.9.4;
* added the Pantheios Tracing API;
* fixes for some back-end project files;


## 1.0.1-beta27 - 29th July 2007

* compatible with STLSoft 1.9.3;
* bug fixes in be.file;


## 1.0.1-beta26 - 30th April 2007

* Compatible with STLSoft 1.9.1 (version released with Extended STL, vol 1: CD);
* bug fix in be.file;


## 1.0.1-beta25 - 11th April 2007

* reimplemented core initialisation on UNIX;
* bug fix for be.file on UNIX;
* added missing project files;


## 1.0.1-beta24 - 6th April 2007

* intermediate release, containing a fix to be.file, and other minor changes;


## 1.0.1-beta23 - 27th January 2007

* distribution now rooted at pantheios-1.0.1-beta23;
* refactoring of core implementation (.c, .cpp) files;
* DMC++ compiler improvement-related enhancements to fe.N and fe.simple;
* more 64-bit fixes;


## 1.0.1-beta22 - 15th January 2007

* fixes for 64-bit Linux compatibility;
* NOTE: requires STLSoft 1.9.1 beta 42, or later;


## 1.0.1-beta21 - 9th January 2007

* added fault-tolerance to be.N, so one or more (but not all) back-ends can fail and the application can proceed;
* added be.fail back-end that always fails (for testing be.N fault tolerance);


## 1.0.1-beta20 - 5th January 2007

* addition of missing implicit link file (be.file);
* time formatting bug fix;


## 1.0.1-beta19 - 2nd January 2007

* dynamic control of severity ceiling for fe.N;
* minor bug fix;


## 1.0.1-beta18 - 23rd December 2006

* bug fix and performance enhancements to fe.N;
* addition of implicit link headers for be.N and fe.N;
* refactoring of several back-ends to use common processId+severity+time handling;


## 1.0.1-beta17 - 20th December 2006

* Refactoring of several back-end implementations;
* Finalising of functionality of be.fprintf;


## 1.0.1-beta16 - 18th December 2006

* Minor fix for dynamic library builds;


## 1.0.1-beta15 - 16th December 2006

* Minor fix for C++/COM compilation;


## 1.0.1-beta14 - 12th December 2006

* Minor fix for dynamic library builds;


## 1.0.1-beta13 - 7th December 2006

* Added be.N and fe.N, for splitting to multiple back-ends;
* Fixes to header files (names);
* Fix to be.file;


## 1.0.1-beta12 - 5th December 2006

* Fixes to VC++ 8 build/linking;


## 1.0.1-beta11 - 3rd December 2006

* Fixes to be.COMErrorObject;


## 1.0.1-beta10 - 1st December 2006

* Fixes to be.file;
* Fixes to C compilation;


## 1.0.1-beta9 - 29th November 2006

* Fixes to be.file;
* Example for be.file;


## 1.0.1-beta8 - 27th November 2006

* Added new backend - be.file;
* Resolved some compiler compatibility issues;


## 1.0.1-beta7 - 29th October 2006

* minor increased in efficiency in a couple of areas;


## 1.0.1-beta6 - 21st October 2006

* 3 new inserter classes: args, processId, threadId;
* 3 more examples;
* improvements in compiler compatility;


## 1.0.1-beta5 - 8th October 2006

* Fixed broken UNIX makefiles (broken in beta 4);
* Fixed Win32syslog facility codes (broken in beta 4);


## 1.0.1-beta4 - 5th October 2006

* Fixed UNIX/GCC compilation/build issues;
* Added bail-out functionality (to handle init failures);
* be.syslog Back-end functionality expanded;


## 1.0.1-beta3 - 24th September 2006

* Makefiles that support NOX (NO eXception builds) no longer build NOX versions of ACE and KLOG projects;
* Visual C++ 8 makefile now includes `-w4996`, and single-threaded variants no longer specify the obsolete compiler flags `-ML` / `-MLd`;
* added `pantheios_getSeverityStringLength()`;
* added string access shims for the `pan_severity_t` type;
* `pantheios_getNextBackEndId()` now implemented in terms of a mutex (`platformstl::process_mutex`) when compiling on a platform that does not provide an `atomic_preincrement()` function;
* changes to all `log()`/`log_XXXX()` function templates to use "using declarations" rather than explicit qualification of the string access shim functions, in order to cover up a problem that GCC has in its ADL (argument-dependent lookup);
* `pantheios::blob()` now does 1-grouping when the two-parameter constructor is used;
* more `pantheios::com` function overloads;


## 1.0.1-beta2 - 2nd September 2006

* There have been myriad small changes, and some breaking changes, to previous non-public releases of Pantheios (and its preceeding proprietary Synesis Software incarnation). However, they're way too many to list here, and those who have those previous non-public versions are sufficiently in the know (including my phone number) that there's no need to enumerate the differences here;
* To all intents and purposes, this is the first public release of Pantheios. From here on in, it gets interesting ...;


<!-- ########################### end of file ########################### -->
