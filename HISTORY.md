pantheios - History
===================

Updated:    5th July 2020


5th July 2020 - 1.0.1 beta 219
------------------------------

 * added ::pantheios_char_t with all appropriate changes in library
 * added support for PANTHEIOS_NO_B64 preprocessor symbol, which causes build and use of application layer inserters to be done without the b64 library (and the pantheios::b64 inserter)
 * added support (including implicit-linking support) for Visual C++ 15.x and 16.x
 * forward-compatibility support for STLSoft 1.10 and 1.11
 * substantial reworking and fixes to makefiles
 * added project files (auto-generated) for Visual C++ 10
 * added bec.stock (and bec.stock.WithCallback) archive(s) and implicit-link file(s)
 * bec.fprintf now always outputs to stderr by default; + can specify stream in initialiser
 * numerous minor mods and fixes to bec.file
 * added example.cpp.linking.N_with_stock
 * added test.unit.inserter.stream_character
 * added test.unit.util.snprintf
 * added test.component.bec.fprintf
 * added in test of stlsoft::fast_strftime in test.performance.util.date_elements_to_string


29th January 2017 - 1.0.1 beta 218
----------------------------------

 * added pantheios::windows::hive inserter and component test
 * added date elements -> string conversion functions
 * added pantheios::windows::hive inserter
 * added pantheios_be_N_tokenFromId()
 * added pantheios_getStockSeverityStringSlice()
 * added test.component.inserters.windows.hive
 * added test.performance.util.date_elements_to_string
 * added test.unit.inserters.windows.sc
 * added test.unit.util.date_elements_to_string
 * added callback functionality for be.WindowsEventLog
 * added PANTHEIOS_BE_INIT_F_NUMERIC_SEVERITY flag, which specifies that the severity will always be presented in numeric form in stock back-ends
 * added PANTHEIOS_BE_WINDOWSCONSOLE_F_CLEAR_AFTER_EACH_STATEMENT
 * added PANTHEIOS_BE_WINDOWSCONSOLE_F_RECOGNISE_16_SEVERITIES
 * stock back-ends now use the severity number for severity levels in the range [8, 16)
 * tightening up initialisation logic, in case where process identity cannot be provided by the front-end (which should not strictly happen, but we want to be as tight as possible)
 * separated out the default initialiser Schwarz counter instance from the counter header (so that it can be used separately)
 * extracted out pantheios_slice_t and various integer types, and simplified a number of API functions (incl. back-ends)
 * compatibility with STLSoft 1.9 and STLSoft 1.10.1 beta 2+
 * added CC_CUSTOM_DEFS_DEBUG, CC_CUSTOM_DEFS_RELEASE, CPPC_CUSTOM_DEFS_DEBUG, CPPC_CUSTOM_DEFS_RELEASE
 * moved pantheios_exitProcess (src/core/api.exitprocess.cpp) from Core to Util library
 * added clean.libs.util target
 * added compile.test.all target
 * changed compile.test target to be dependent only on compile.test.unit and compile.test.component targets
 * improved use of make preprocessor
 * shortening some target/intermediate names


30th June 2016 - 1.0.1 beta 217
-------------------------------

 * added severityFloor to be.N
 * test.unit.be.N.filtering
 * pantheios::pointer : + added protected method get_value(), to be used by deriving types such as forthcoming pantheios::windows::hive inserter
 * PANTHEIOS_ASSERT() and PANTHEIOS_MESSAGE_ASSERT() underlying assertions may now be overriden (via preprocessor)
 * changed names and locations of generated files
 * changed no-throw declaration from stlsoft_throw_0() to STLSOFT_NOEXCEPT
 * refactoring of pantheios_util_strnlen()
 * added GCC 4.8 support
 * added GCC 4.9 support


25th October 2015 - 1.0.1 beta 216
----------------------------------

 * fixed defect introduced in 1.0.1 beta 215


27th September 2015 - 1.0.1 beta 215
------------------------------------

 * added interval inserter
 * added stream_character inserter
 * Clang-compatibility
 * VC++ 11-compatibility
 * VC++ 12-compatibility
 * VC++ 14-compatibility
 * showPlus format flag support in pantheios::integer (pan::i)
 * makefiles customisable to specify non-bundled locations of b64, shwild, xContract, xCover, and xTests libraries (useful to getting head from GitHub)


7th August 2012 - 1.0.1 beta 214
--------------------------------

 * added variant_bool inserter, for COM Automation type VARIANT_BOOL
 * added new core API function pantheios_getProcessIdentity(), which reflects new dynamic process identity semantics for front-ends, and new C++ alias pantheios::getProcessIdentity()
 * added PANTHEIOS_CARG_STR()/PANTHEIOS_CARG_STR_LEN() macros
 * added makefile for Intel C/C++ 12
 * pantheios::character inserter now compatible with wide characters, and allow conversion construction from char when widestring mode (i.e. expecting wchar_t)
 * adjusted core initialisation to support new dynamic process identity semantics for front-ends
 * preparations for division of core (and later implementation in C)
 * refactoring of memory-pool
 * changed way in which core discriminates atomic integer operation support when in multithreaded mode
 * pantheios::inserter adaptor is now wide-string compatible
 * added test.component.core.getProcessIdentity project
 * added test.component.inserters.variant_bool
 * added test.scratch.be.WindowsSyslog project
 * added test.scratch.be.WindowsSyslog.WithCallback project
 * bec.WindowsConsole now implemented in terms of pantheios_util_snprintf(), and made fully compatible with 64-bit
 * fixed bec.WindowsSyslog defect in arguments parsing (whereby supplied address would be ignored)
 * removed use of deprecated format flag 'zeroPadded', replaced with 'zeroPad'
 * wholesale tidying of definition of PANTHEIOS_FE_PROCESS_IDENTITY (in terms of PANTHEIOS_EXTERN_C and PANTHEIOS_LITERAL_STRING())
 * wholesale changes for compatibility with STLSoft 1.9.115+'s integer_to_string
 * NOTE: Now requires STLSoft 1.9.115


6th December 2011 - 1.0.1 beta 213
----------------------------------

 * added GCC 4.6 makefiles
 * enhanced GCC compatibility in util component(s)
 * declared pantheios_exitProcess() (and pantheios::exitProcess()) to be noreturn (effective in GCC and VC++)
 * pantheios/util/com/exception_helpers.hpp is now deprecated. Users should instead obtain the Pantheios::Extras::xHelpers project, and include pantheios/extras/com/exception_helpers.hpp
 * NOTE: Now requires STLSoft 1.9.111


13th August 2011 - 1.0.1 beta 212
---------------------------------

 * fixes to various minor defects and documentation
 * added GCC format(printf) attribute to pantheios_util_snprintf_a()
 * NOTE: Now requires STLSoft 1.9.109


1st January 2011 - 1.0.1 beta 211
---------------------------------

 * fixed erroneous implementation of pantheios_be_file_flush() in be.file
 * changes in be.file to adapt to STLSoft 1.9.107/8
 * changes to be.file to hide false positives given by MSVCRT memory leak reporting
 * fixed widestring trailing nul character (via STLSoft 1.9.107 char conversions) in bec.WindowsSyslog
 * exposed pantheios::init() and pantheios::uninit() in documentation
 * non-functional improvements to implementation of pantheios_getPad(), including ability to adjust buffer size at compile time.
 * slightly enhanced status message for PANTHEIOS_INIT_RC_NOT_IMPLEMENTED
 * various other trivial changes to a number of source/project files
 * NOTE: Now requires STLSoft 1.9.108


10th January 2011 - 1.0.1 beta 210
----------------------------------

 * added compile-time validation to prevent fundamental types being passed to log statements
 * added GCC 4.5 support
 * NOTE: Now requires STLSoft 1.9.106


6th January 2011 - 1.0.1 beta 209
---------------------------------

 * Now returns the string "unrecognised status code" if the status code is, er, unrecognised
 * wide-string compatibility fix for example.cpp.util.strdup
 * skips manipulation of HKEY_LOCAL_MACHINE when don't have change access: allows program to succeed when tests run by user with limited premissions
 * added test.unit.util.getcurrenttime.vcproj
 * removing unnecessary C++ flags from C compiler settings in VC++ makefiles


4th January 2011 - 1.0.1 beta 208
---------------------------------

 * be.file added pantheios_be_file_flush(), and corrected omission to add 1900 to year and 1 to month in be.file's interpretation of date/time format specifiers in its file path
 * renamed status codes PANTHEIOS_INIT_RC_UNKNOWN_ERROR, PANTHEIOS_INIT_RC_UNSPECIFIED_ERROR to PANTHEIOS_INIT_RC_UNKNOWN_FAILURE, PANTHEIOS_INIT_RC_UNSPECIFIED_FAILURE
 * removed magic-numbers for return values and replacing with PANTHEIOS_INIT_RC_UNSPECIFIED_FAILURE in core and some stock back-ends
 * be.N minor performance/consistency improvement, and groundwork for coming feature enhancements
 * added FAQ#19, which explains how to use get Pantheios to compile the libraries when using Microsoft's -Zc:wchar_t- flag
 * all VC8+ makefiles no longer specify -D_CRT_SECURE_NO_DEPRECATE
 * added example.cpp.util.strdup
 * removed all extras files; these will be distributed in separate packages henceforth


27th December 2010 - 1.0.1 beta 207
-----------------------------------

 * added FAQ-18, which discusses use of custom front-end with multiplexing back-end(s)
 * added known implicit integral conversion vulnerability to KNOWN_ISSUES (affects Windows wide-string builds only)
 * changed initialisation failure/warning bailout messages of fe.WindowsRegistry, for ease of use
 * improved bailout warning messages passed to Windows Event Log (affects Windows-only)
 * added PANTHEIOS_FE_INIT_RC_INIT_CONFIG_REQUIRED initialisation code
 * added test.scratch.be.N.with.custom.fe for illustrating use of be.N back-end with a custom front-end
 * moved back-end sole/local/remote library forwarding symbols implementation files into subdirectories of src/backends/
 * NOTE: Now requires STLSoft 1.9.105
 * Windows users are advised to install the latest Pantheios.COM


21st December 2010 - 1.0.1 beta 206
-----------------------------------

 * include/pantheios/inserters.hpp updated to include all new individual inserter headers
 * added test.unit.inserter.integer
 * added test.unit.inserter.m2w
 * added test.unit.inserter.w2m
 * workaround for Digital Mars symbol ambiguity defect in examples/cpp/misc/example.cpp.misc.custom_type_1/example.cpp.misc.custom_type_1.cpp
 * corrected/removed misleading statements in INSTALL.txt
 * include/pantheios/implicit_link/appl.h no longer includes include/pantheios/implicit_link/util.h


11th December 2010 - 1.0.1 beta 205
-----------------------------------

 * added new example example.cpp.inserter.w2m
 * added new implicit link header include/pantheios/implicit_link/appl.h
 * added example.cpp.inserter.m2w to makefile(s)
 * various improvements to examples and documentation


7th December 2010 - 1.0.1 beta 204
----------------------------------

 * wholesale changes to directory structure of C++ examples
 * added VC++ 6-9 project files for C++ examples
 * updating makefiles with all examples, including new and forgotten ones


26th November 2010 - 1.0.1 beta 203
-----------------------------------

 * added pantheios::ch inserter typedef (for pantheios::character) for inserting characters in a succinct manner
 * added experimental support for use of 64-bit UNIX file-handling APIs in 32-bit builds, using -D_FILE_OFFSET_BITS=64 in build/gcc44.unix.file64bits directory
 * added appl library build targets, to facilitate use of Pantheios across shared libraries with a common code
 * added HOW_YOU_CAN_HELP.txt to distribution
 * enhanced the documentation


23rd November 2010 - 1.0.1 beta 202
-----------------------------------

 * added pantheios::m2w inserter class
 * added unit test, component test, and performance test for pantheios::m2w
 * added single-threaded widestring targets to makefiles for VC++ 5-7.1
 * improved compatibility with Visual C++'s so-called "safe string" library
 * updated util and core project files for Visual C++ 6, 8, and 9
 * tidied up makefiles
 * NOTE: Now requires STLSoft 1.9.104


19th November 2010 - 1.0.1 beta 201
-----------------------------------

 * added callback frontend functionality, to allow dynamic specification/creation of process identity at runtime, to stock front-ends
 * added implicit link headers, scratch test programs, and new make targets for callback frontends
 * pantheios_util_snprintf() now uses __attribute__((format(printf())) (in GCC compilation)
 * various changes to improve makefiles, correct minor defects: shorted scratch test target names; simplified target labels
 * be.syslog scratch test program now uses simpler, dedicated program
 * added test.scratch.be.syslog.WithCallback


15th November 2010 - 1.0.1 beta 200
-----------------------------------

 * added PANTHEIOS_BE_FILE_F_DELETE_IF_EMPTY to be.file
 * added pantheios::b shorthand inserter typedef (for pantheios::boolean)
 * added implicit link headers for be.syslog.WithCallback
 * added missing be.speech project files


10th November 2010 - 1.0.1 beta 199
-----------------------------------

 * added pantheios::xp inserter
 * added example.cpp.inserter.p example program
 * added example.cpp.inserter.xp example program
 * added test.scratch.be.syslog scratch test for Syslog
 * added test.scratch.be.syslog.WithCallback scratch test for Syslog, which illustrates how to change facility and/or suppress writing to stderr


8th November 2010 - 1.0.1 beta 198
----------------------------------

 * added pantheios::i shorthand inserter typedef (for pantheios::integer)
 * added pantheios::xi shorthand inserter class (for pantheios::integer)
 * fixed defect vulnerability in PANTHEIOS_ASSERT() and PANTHEIOS_MESSAGE_ASSERT()
 * improves compatibility between narrow/wide Pantheios and narrow/wide ACE in be.ACE
 * improved detection of ACE in makefiles
 * trace API now reports file+line in bailout when assert log fails
 * added example for pantheios::i inserter
 * added example for pantheios::xi inserter
 * NOTE: Now requires STLSoft 1.9.102


18th October 2010 - 1.0.1 beta 197
----------------------------------

 * pantheios::integer inserter: now respects negative widths in three-parameter overloads
 * pantheios::integer inserter: 0x-prefix now counts in fixed-width formatting
 * pantheios::integer inserter: now deals with differently-sized integer types separately, allowing it to represents hex-form of 8-/16-bit integers in 2 and 4 digits
 * be.file now supports %T (for time) and %D (for date) format specifiers in file name
 * several substantial changes to Pantheios.Extras.COM's Exception Helpers, including change from default return E_UNEXPECTED to call ExitProcess() in catch-all clauses
 * NOTE: Now requires STLSoft 1.9.101


4th April 2010 - 1.0.1 beta 196
-------------------------------

 * full widestring compatibility
 * VC++ 10 support
 * minor defect fixes
 * added PANTHEIOS_BE_FILE_F_WRITE_MULTIBYTE_CONTENTS and PANTHEIOS_BE_FILE_F_WRITE_WIDE_CONTENTS to be.file
 * NOTE: Now requires STLSoft 1.9.97


5th March 2010 - 1.0.1 beta 195
-------------------------------

 * pantheios::w2m inserter class now accepts arbitrary wide string types (e.g. std::wstring, stlsoft::simple_wstring)
 * enhanced component test for pantheios::w2m inserter class
 * NOTE: Now requires STLSoft 1.9.94


15th February 2010 - 1.0.1 beta 194
-----------------------------------

 * added pantheios::slice inserter, along with test programs
 * wide-string compatibility at the source level (no build targets)
 * ensures that PANTHEIOS_TRACE_PREFIX is convertible to pan_char_t const*
 * reports failure to assign file for all back-ends
 * Windows versions of GCC makefiles now generate libraries with leading lib and with the .a extension (i.e. libpantheios.1.util.gcc34.a, rather than pantheios.1.util.gcc34.lib)
 * added build.common target to makefiles
 * removed VC++ 8/9 "safe" makefiles
 * bundles xTests 0.14.5
 * NOTE: Now requires STLSoft 1.9.93


24th July 2009 - 1.0.1 beta 193
-------------------------------

 * added static filtering to be.N (to supplement the dynamic filtering)
 * minor change to be.WindowsConsole (to avoid seeming to leak memory, when none is leaked, due to initialisation ordering issues)
 * bundles xTests 0.14.1
 * NOTE: Now requires STLSoft 1.9.86
 * NOTE: These are breaking changes: any programs that use be.N
   must be recompiled and relinked


8th July 2009 - 1.0.1 beta 192
------------------------------

 * fixed defect in 64-bit bec.WindowsConsole
 * enhanced compiler compatibility for GCC, Intel and VC++ compilers
 * reduced dependencies in inserters header files
 * bundles xTests 0.13.3
 * NOTE: Now requires STLSoft 1.9.85


4th July 2009 - 1.0.1 beta 191
------------------------------

 * added be.console pseudo back-end (resolves to be.WindowsConsole on Windows, and be.fprintf otherwise)
 * fixed multi-threading defect in be.file
 * added test.component.be.file.threading component test
 * bundles xTests 0.13.2
 * NOTE: Now requires STLSoft 1.9.85


3rd July 2009 - 1.0.1 beta 190
------------------------------

 * workaround of probably Intel 11 defect
 * added GCC 4.4 (UNIX) makefile
 * bundles xTests 0.13.2
 * NOTE: Now requires STLSoft 1.9.85


29th June 2009 - 1.0.1 beta 189
-------------------------------

 * added pantheios::pad inserter function, and PANTHEIOS_LPAD() and PANTHEIOS_RPAD() macros
 * added example and component-test for pantheios::pad inserter
 * fixed defect in test back-end be.test
 * bundles xTests 0.13.2
 * NOTE: Now requires STLSoft 1.9.85


21st May 2009 - 1.0.1 beta 188
------------------------------

 * added example.c.extended_severity example
 * added two new FAQ items
 * fixed defect in stock back-ends whereby severity string would be empty if extended severity information was specified
 * various documentation enhancements
 * NOTE: Now requires STLSoft 1.9.83


15th May 2009 - 1.0.1 beta 187
------------------------------

 * added makefile for Mac OS-X 64-bit
 * added prototype makefile for Sun Pro 5.9
 * all UNIX makefiles now remove Windows newline sequence in distribution sources
 * bundles xTests 0.13.1
 * NOTE: Now requires STLSoft 1.9.82


8th May 2009 - 1.0.1 beta 186
-----------------------------

 * added the Pantheios Assertion API: PANTHEIOS_ASSERT() and PANTHEIOS_MESSAGE_ASSERT()
 * added example.c.assert and example.cpp.assert examplee
 * includes examples involving variadic macros in Borland makefiles, from 5.82 onwards
 * removed unnecessary (and unhelpful) dependencies on pantheios/pantheios.hpp for inserter classes
 * changed semantics of pantheios_malloc() to guarantee zeroing of allocation memory and valid alignment for any type
 * fixed incorrect definition of getInitErrorString()
 * numerous changes to build foundation of future wide string support
 * bundles xTests 0.13.1
 * NOTE: Now requires STLSoft 1.9.81


17th April 2009 - 1.0.1 beta 185
--------------------------------

 * implicit link support for Intel C/C++ 10 & 11
 * preparatory work for widestring support
 * corrected two defects in pantheios_util_strnlen() length-limited length calculations
 * added unit test for strnlen
 * implicit link example now returns EXIT_SUCCESS, so 'make test.examples' can succeed
 * makefile clean.* targets now clean up all artefacts
 * NoX builds now correctly suppress use of exceptions and RTTI
 * bundles xTests 0.11.4
 * NOTE: Now requires STLSoft 1.9.77


16th April 2009 - 1.0.1 beta 184
--------------------------------

 * added 'version' member to all back-end initialisation structures, and verification action during back-end initialisation function
 * added PANTHEIOS_BE_INIT_RC_FUTURE_VERSION_REQUESTED and PANTHEIOS_BE_INIT_RC_OLD_VERSION_NOT_SUPPORTED initialisation codes
 * various minor documentation enhancements
 * bundles xTests 0.11.3
 * NOTE: Now requires STLSoft 1.9.77
 * NOTE: These are breaking changes: any programs that use stock
   back-ends must be modified, recompiled and relinked


16th February 2009 - 1.0.1 beta 183
-----------------------------------

 * fixed defect in pantheios_logvprintf() that resulted in complete (rather than partial) truncation of over-long statements
 * workaround in pantheios::integer inserter class for VC++ 6's distinct 32-bit integer types


15th February 2009 - 1.0.1 beta 182
-----------------------------------

 * workaround for Mac OS-X gethostname() defect
 * added support for Intel C/C++ 10 and 11
 * corrected packaging problem which led to old version of xTests being bundled in 1.0.1 beta 181
 * bundles xTests 0.10.4


13th February 2009 - 1.0.1 beta 181
-----------------------------------

 * forces use of STLSoft 1.9.74, to workaround Borland code generation defects
 * NOTE: Now requires STLSoft 1.9.74


3rd February 2009 - 1.0.1 beta 180
----------------------------------

 * support for Borland 5.9.x and 6.1.x


1st February 2009 - 1.0.1 beta 179
----------------------------------

 * fixed defect whereby pantheios_logvprintf() (and pantheios_logprintf()) failed to check severity before logging
 * NOTE: Now requires STLSoft 1.9.72


16th January 2009 - 1.0.1 beta 178
----------------------------------

 * added PANTHEIOS_BE_FILE_F_SHARE_ON_WINDOWS, which causes be.file to allow write-sharing on Windows
 * other minor changes
 * NOTE: Now requires STLSoft 1.9.66


1st January 2009 - 1.0.1 beta 177
---------------------------------

 * now has full "Safe String" compatibility for VC++ 8+
 * added GNU printf-format attribute to pantheios_logprintf()
 * adjustment of example and test programs to use updated functions, instead of deprecated functions
 * adjusting case of bail out statements


30th December 2008 - 1.0.1 beta 176
-----------------------------------

 * cleaned up creation of static libraries in Borland makefiles
 * bundles xTests 0.9.3
 * NOTE: Now requires STLSoft 1.9.64


19th December 2008 - 1.0.1 beta 175
-----------------------------------

 * added two new initialisation codes, for resource access denial (permissions and locking)
 * enhanced the return codes from be.file for file-open failure
 * enhanced COM exception helper function templates to enable working with custom severity level pseudo-constants
 * added scratch test for COM exception helper function templates
 * NOTE: Now requires STLSoft 1.9.63


3rd December 2008 - 1.0.1 beta 174
----------------------------------

 * logputs() now subject to severity filtering
 * refactored core => back-end dispatching
 * added two more scratch test projects
 * added one more component test project
 * removal of previously deprecated files


18th November 2008 - 1.0.1 beta 173
-----------------------------------

 * added new functionality to be.speech, in order to provide workaround for
   suspected SAPI defect
 * enhanced pantheios::integer inserter class, adding 3-parameter ctors to
   remove ambiguity between width and format
 * more changes forming part of the groundwork for future widestring support
 * reduced dependencies of various components


13th November 2008 - 1.0.1 beta 172
-----------------------------------

 * enhanced pantheios::integer inserter class, adding 3-parameter ctors to
   remove ambiguity between width and format
 * many changes forming part of the groundwork for future widestring support


11th November 2008 - 1.0.1 beta 171
-----------------------------------

 * enhanced pantheios::hex_ptr inserter class in line with the changes to
   pantheios::pointer in the previous release
 * added example.cpp.hex_ptr
 * added test.examples target, which executes all example programs

10th November 2008 - 1.0.1 beta 170
-----------------------------------

 * enhanced pantheios::pointer inserter class, adding 3-parameter ctor to
   remove ambiguity between width and format
 * added compile-time user-customisation of pantheios_log_n() internal
   buffer size
 * added compile-time user-customisation of pantheios_logprintf() stack
   size

3rd November 2008 - 1.0.1 beta 169
----------------------------------

 * added more overloads to pantheios::extras::com::invoke_nothrow_method()

18th October 2008 - 1.0.1 beta 168
----------------------------------

 * added two new FAQ items
 * removed previously deprecated files
 * added implementations of functions deprecated (and renamed) in
   1.0.1 beta 167
 * fixed defective using declaration in
   pantheios/util/com/exception_helpers.hpp

16th October 2008 - 1.0.1 beta 167
----------------------------------

 * final changes to ensure no-namespace compatibility
 * renaming/deprecation of badly-named API functions

15th October 2008 - 1.0.1 beta 166
----------------------------------

 * Final pre-release refactoring of all util|helper|extra header files

14th October 2008 - 1.0.1 beta 165
----------------------------------

 * Substantial reworking of contract API, reflected throughout the
   headers, implementation, example and test files

12th October 2008 - 1.0.1 beta 164
----------------------------------

 * several changes to ensure that the suppression of stock severity
   levels is complete, and that the definition of custom severity
   levels is clean and may use the pantheios::levels constant
   generator class template
 * the pantheios::util::backends::Context base class is altered in
   two ways to facilitate a wider range of severity levels than is
   provided by the stock front-/back-ends
 * the deprecated file include/pantheios/error_codes.h now issues a
   #error if included, in preparation for final removal
 * NOTE: These are breaking changes: any programs that define custom
   back-ends based on pantheios::util::backends::Context must be
   modified, recompiled and relinked

11th October 2008 - 1.0.1 beta 163
----------------------------------

 * removal of deprecated file(s)
 * more compatibility with namespace-suppression

7th October 2008 - 1.0.1 beta 162
---------------------------------

 * compatibility with MFC when pantheios/pantheios.hpp is the first #include
 * compatibility with namespace-suppression

27th September 2008 - 1.0.1 beta 161
------------------------------------

 * sharpened up error messages when attempting to use previously removed
   features of fe.simple
 * changed requirements of application-defined components in
   be.WindowsEventLog to a single new function
 * NOTE: These are breaking changes: any programs that use
   be.WindowsEventLog must be modified, recompiled and relinked

24th September 2008 - 1.0.1 beta 160
------------------------------------

 * include/pantheios/inserters.hpp now includes
   include/pantheios/inserters/hostid.hpp
 * modification to ensure cross-link-unit compatibility when Pantheios
   libraries are exported from a dynamic library
 * added missing project map (HTML) files within project structure

22nd September 2008 - 1.0.1 beta 159
------------------------------------

 * added two back-end targeting/multiplexing examples
 * added PANTHEIOS_MAKE_EXTENDED_SEVERITY() macro, for targeting statements
   to back-ends when using the C API
 * added project map (HTML) files within project structure

19th September 2008 - 1.0.1 beta 158
------------------------------------

 * deprecated file pantheios/util/threading/threadid.h now #error on use
 * include/pantheios/error_codes.h => include/pantheios/init_codes.h
 * include/src/util/init_error_strings.c => include/src/util/init_code_strings.c

18th September 2008 - 1.0.1 beta 157
------------------------------------

 * added new error code (PANTHEIOS_BE_INIT_RC_INIT_CONFIG_REQUIRED)
 * improved error reporting in fe.WindowsRegistry

12th September 2008 - 1.0.1 beta 156
------------------------------------

 * refactoring of build directories
 * non-functional textual changes
 * NOTE: These are breaking changes: some target
   compiler/operating-system/architecture have been renamed

11th September 2008 - 1.0.1 beta 155
------------------------------------

 * fixed defect in component test for pantheios::w2m inserter class
 * NOTE: Now requires STLSoft 1.9.52

2nd September 2008 - 1.0.1 beta 154
-----------------------------------

 * added pantheios::w2m (widestring to multibyte) inserter, for use until
   widestring version of library available
 * added component test for pantheios::w2m inserter class
 * added performance test for pantheios::w2m inserter class
 * NOTE: Now requires STLSoft 1.9.49

1st September 2008 - 1.0.1 beta 153
-----------------------------------

 * fixed defect in pantheios/util/time/currenttime.h
 * added example.c.getcurrenttime (for pantheios_getCurrentTime())

28th August 2008 - 1.0.1 beta 152
---------------------------------

 * added source-only distribution, to reduce the download size for users that
   use the online documentation
 * added pantheios_getVersion() function, to allow client code to do runtime
   tests on the version of Pantheios to which they're linking
 * added unit-test for pantheios_getVersion()
 * added missing implicit link headers for fe.fail and fe.null
 * modified fe.fail to reduce unnecessary link dependencies

25th August 2008 - 1.0.1 beta 151
---------------------------------

 * tidied up a large number of out-of-date markup elements in docs
 * optimised the implementation of fe.N
 * added example for pantheios_getHostName()
 * finalised the structure of the project/solution files for
   Visual Studio (other IDEs will be done in later release)
 * bundles b64 1.3.4

24th August 2008 - 1.0.1 beta 150
---------------------------------

 * fixed defect in fe.N, whereby a negative catch-all severity ceiling would
   not be respected
 * other minor adjustments/improvements to fe.N
 * added unit-test for fe.N
 * bundles xTests 0.8.5
 * NOTE: Now requires STLSoft 1.9.48
 * NOTE: These are breaking changes. Any code using the extant fe.N front-end
   library will need to be edited and re-compiled

12th August 2008 - 1.0.1 beta 149
---------------------------------

 * added unit-test for fe.WindowsRegistry
 * adjustments to contract enforcement conditions to be compatible with
   ultra-pedantic GCC 4.3 warnings
 * minor adjustments to CodeWarrior and Digital Mars makefiles

11th August 2008 - 1.0.1 beta 148
---------------------------------

 * a large number of small changes to the names and/or namespaces of
   utility functions and classes that do not form part of the set
   commonly used by authors of client code, in order to simplify the
   apparent APIs of the Core and Application Layer
 * bundles xTests 0.8.4

7th August 2008 - 1.0.1 beta 147
--------------------------------

 * enhanced pantheios::boolean inserter class to be I18N/L10N-friendly
 * added unit test for pantheios::boolean inserter class
 * adjustments to contract enforcement conditions to be compatible with
   ultra-pedantic GCC 4.3 warnings

7th August 2008 - 1.0.1 beta 146
--------------------------------

 * added pantheios::boolean inserter class
 * added unit test for be.fprintf

1st August 2008 - 1.0.1 beta 145
--------------------------------

 * fixed bug in be.fprintf introduced in 1.0.1 beta 144
 * cleanup in the comment headers for a large number of source files,
   in preparation for final non-beta release

30th July 2008 - 1.0.1 beta 144
-------------------------------

 * added thread Id as a default detail in the statement prefix of all
   Pantheios stock back-end(s) (except be.speech)
 * NOTE: These are breaking changes. Any programs using the Pantheios
   stock back-ends that do not want to see thread Id will now need to
   use the callback forms of the back-end(s) and set the
   PANTHEIOS_BE_INIT_F_NO_THREAD_ID flag in the callback function!
 * added support for GCC 4.3

29th July 2008 - 1.0.1 beta 143
-------------------------------

 * refactoring of process Id and thread Id functions
 * added support for GCC 4.3

25th July 2008 - 1.0.1 beta 142
-------------------------------

 * minor adjustments of Application Layer
 * enhanced functionality of pantheios::args inserter class

24th July 2008 - 1.0.1 beta 141
-------------------------------

 * deprecation of pantheios_exit_process(), and replacement with
   pantheios_exitProcess()
 * reduction in source code size of Application Layer generated function
   templates
 * fix to date-dependent bug in unit-test for pantheios_getCurrentTime()

19th June 2008 - 1.0.1 beta 140
-------------------------------

 * correction of bug in pantheios.h introduced in beta 139

18th June 2008 - 1.0.1 beta 139
-------------------------------

 * deprecation of pantheios_puts() and pantheios::put(), in favour of
   pantheios_logputs() and pantheios::logputs()
 * minor makefile fixes and modifications
 * bundles xTests 0.8.3

16nd June 2008 - 1.0.1 beta 138
-------------------------------

 * enhancements to customisation of Application Layer
 * implicit linking for fe.WindowsRegistry
 * added project files for Visual C++ v7.1 for Core, Util, backends, and
   frontends
 * added project files for Visual C++ v8 for Core, Util, backends, and
   frontends
 * bundles xTests 0.8.2

2nd June 2008 - 1.0.1 beta 137
------------------------------

 * distribution cleanup release - no new functionality
 * minor fix to implicit linking for VC++ 8 & 9

21st May 2008 - 1.0.1 beta 136
------------------------------

 * fixed a bug in the contract enforcements of fe.N
 * fixed a bug in the unit-test for pantheios_getCurrentTime()
 * bundles xTests 0.7.3

17th May 2008 - 1.0.1 beta 135
------------------------------

 * fully separated the Pantheios Util and Pantheios Core libraries,
   including source, makefiles and targets, and project files
 * NOTE: Now requires STLSoft 1.9.42
 * NOTE: These are breaking changes. Any code using the extant Pantheios
   Core library will need to be relinked (to also include the Util library)

16th May 2008 - 1.0.1 beta 134
------------------------------

 * fixed bug in test.unit.util.getcurrenttime
 * bundles shwild 0.9.16

14th May 2008 - 1.0.1 beta 133
------------------------------

 * added unit-tests for fe.all, fe.fail, fe.null and fe.simple
 * minor modifications to contract enforcement macros
 * NOTE: Now requires STLSoft 1.9.41

13th May 2008 - 1.0.1 beta 132
------------------------------

 * wholesale refactoring of front-end and back-end directory names
 * NOTE: Now requires STLSoft 1.9.40

11th May 2008 - 1.0.1 beta 131
------------------------------

 * enhanced the behaviour of the pantheios::args inserter
 * enhanced testability of bailout functionality
 * removal of obsolete implementation files
 * bundles xTests 0.7.2
 * NOTE: Now requires STLSoft 1.9.39

4th May 2008 - 1.0.1 beta 130
-----------------------------

 * Win64 compatibility
 * bundles shwild 0.9.15
 * bundles xTests 0.7.1
 * NOTE: Now requires STLSoft 1.9.38

3rd May 2008 - 1.0.1 beta 129
-----------------------------

 * fix for minor errors in distribution
 * removal of incorrect auto-initialisation suppression in MFC client
   programs
 * bundles shwild 0.9.14
 * NOTE: Now requires STLSoft 1.9.37

1st May 2008 - 1.0.1 beta 128
-----------------------------

 * now compatible with FreeBSD
 * minor bug fix in bail-out functionality on UNIX
 * NOTE: Now requires STLSoft 1.9.36

29th April 2008 - 1.0.1 beta 127
--------------------------------

 * modification of measures to reduce compilation times on Windows
 * enhancement of bail-out functionality for UNIX
 * addition of unit test for bail-out
 * bundles xTests 0.6.5
 * NOTE: Now requires STLSoft 1.9.34

22nd April 2008 - 1.0.1 beta 126
--------------------------------

 * introduction of measures to reduce compilation times on Windows
 * various trivial warning suppressions
 * addition of UNIX emulation makefiles for VC++ 7.1, 8 and 9
 * NOTE: Now requires STLSoft 1.9.32

20th April 2008 - 1.0.1 beta 125
--------------------------------

 * fixes for UNIX/GCC compilation errors and warnings introduced in beta 124
 * refactoring of Util library header/implementation names
 * NOTE: These are breaking changes. Any code using the extant Pantheios
   current time API will need to be edited and rebuilt!

20th April 2008 - 1.0.1 beta 124
--------------------------------

 * added full-fledged contract enforcement constructs
 * updates to test code in respect of enhancements of xTests 0.6.1
 * bundles xTests 0.6.1
 * NOTE: These are breaking changes. Any code using the extant Pantheios
   assert macros will need to be edited and rebuilt!

19th April 2008 - 1.0.1 beta 123
--------------------------------

 * fix for VC++ 6 / Borland / DMC++ compilation problems with hostId
 * fix for ACE builds with VC++
 * refactoring of test directories/names
 * large-scale refactoring of Core and Util library header and
   implementation file and API member names
 * NOTE: These are breaking changes. Any code using the Pantheios C
   API will need to be edited and rebuilt!

16th April 2008 - 1.0.1 beta 122
--------------------------------

 * addition of missing back-end implicit link header files
 * new example for hostId inserter
 * bundles xTests 0.5.1
 * workaround for VC++ 8/9 linker error

15th April 2008 - 1.0.1 beta 121
--------------------------------

 * addition of pantheios::hostId inserter class, and supporting utility
   functions
 * various minor back-end fixes and refactorings
 * NOTE: Now requires STLSoft 1.9.31

10th April 2008 - 1.0.1 beta 120
--------------------------------

 * addition of missing back-end implicit link header files
 * renamed supporting libraries to UNIX-conventional prefix/suffix

8th April 2008 - 1.0.1 beta 119
-------------------------------

 * addition of missing back-end implicit link header files

6th April 2008 - 1.0.1 beta 118
-------------------------------

 * minor contract enforcement enhancements in some front-/back-ends
 * bundles shwild 0.9.13

5th April 2008 - 1.0.1 beta 117
-------------------------------

 * fix for threadId component test on Mac OS-X (G4)

4th April 2008 - 1.0.1 beta 116
-------------------------------

 * fix for b64 component test for big-endian architectures

3rd April 2008 - 1.0.1 beta 115
-------------------------------

 * Visual C++ 8/9 compatiblity fixes
 * Solaris compatibility fixes
 * NOTE: Now requires STLSoft 1.9.30

2nd April 2008 - 1.0.1 beta 114
-------------------------------

 * Syslog compatibility fixes

28th March 2008 - 1.0.1 beta 113
--------------------------------

 * Solaris compatibility fixes

20th March 2008 - 1.0.1 beta 112
--------------------------------

 * renamed libraries to UNIX-conventional prefix/suffix

19th March 2008 - 1.0.1 beta 111
--------------------------------

 * added compatibility with VC++ 9
 * added compatibility with GCC 4.2
 * bundles shwild 0.9.11
 * fix for string conversion pedantic warning with GCC 4.2

18th March 2008 - 1.0.1 beta 110
--------------------------------

 * fix for weird namespace bug in pantheios::threadId inserter with GCC

17th March 2008 - 1.0.1 beta 109
--------------------------------

 * fix for bug in b64 inserter header (introduced in 1.0.1 beta 107)
 * fix for GCC 4.0 error in pantheios::integer inserter
 * fix for token-pasting error in tracing example
 * fix for test.component.inserters.threadid on OS-X
 * bundles xTests 0.3.2
 * now depends on STLSoft 1.9.27

16th March 2008 - 1.0.1 beta 108
--------------------------------

 * added new be.WindowsMessageBox back-end
 * bundles b64 1.3.1
 * bundles shwild 0.9.11
 * bundles xTests 0.3.1
 * now requires STLSoft 1.9.26

15th March 2008 - 1.0.1 beta 107
--------------------------------

 * various adjustments to ensure correct functioning when compiling C++
   client code, but suppressing pantheios namespace
 * added example for namespace-suppressed use of library
 * added example for tracing
 * updated FAQ item
 * new FAQ item
 * updated to include xTests 0.3

13th March 2008 - 1.0.1 beta 106
--------------------------------

 * complete back-end and front-end project files for Visual Studio '98
 * upgraded to use xTests 0.2.2
 * bug fix to pantheios_onBailOut3()

9th March 2008 - 1.0.1 beta 105
-------------------------------

 * new front-end: fe.fail
 * use of forward include guards throughout include files to improve
   compilation times
 * fix for bug introducted in 1.0.1 beta 104
 * documentation improvements

8th March 2008 - 1.0.1 beta 104
-------------------------------

 * new front-end: fe.null
 * documentation improvements

1st March 2008 - 1.0.1 beta 103
-------------------------------

 * enhanced bail out features, to include a message qualifier
 * minor compiler warning modifications

25th February 2008 - 1.0.1 beta 102
-----------------------------------

 * upgraded to use xTests 0.1.15, to fix compilation bug when
   exception-handling support is switched off

23rd February 2008 - 1.0.1 beta 101
-----------------------------------

 * makefile for GCC 4.1
 * upgraded to use xTests 0.1.14
 * upgraded to use STLSoft 1.9.23
 * minor implementation adjustments

20th February 2008 - 1.0.1 beta 100
-----------------------------------

 * documentation improvements
 * added back-end structure initialisation
 * makefile improvements
 * upgraded to use xTests v0.1.11

12th February 2008 - 1.0.1 beta 99
----------------------------------

 * reduced compilation load for inserter classes

9th February 2008 - 1.0.1 beta 98
---------------------------------

 * added new test case
 * refactored back-end implementation files
 * bug fix to src/util/time.cpp

8th February 2008 - 1.0.1 beta 97
---------------------------------

 * NOTE: Now requires STLSoft 1.9.22
 * bundles b64 1.2.5
 * bundles shwild 0.9.9
 * bundles xTests 0.1.8
 * partial compatiblity with safe string library (VC8+)

5th February 2008 - 1.0.1 beta 96
---------------------------------

 * fixed subtle makefile bug (pertaining to be.test)
 * workaround for odd (and breaking) #include behaviour of GCC on UNIX

5th February 2008 - 1.0.1 beta 95
---------------------------------

 * NOTE: Now requires STLSoft 1.9.21
 * added unit test for be.N
 * fixed wrong test values in test.component.inserters.threadId

3rd February 2008 - 1.0.1 beta 94
---------------------------------

 * NOTE: Now requires STLSoft 1.9.20
 * makefiles updated for separate single- and multi-threaded targets on UNIX
 * updated string API, and concomitant refactoring of inserter classes
 * removal of multi-threading constructs from core and back-end
   implementations in single-threading compilation contexts
 * updated to version 0.1.8 of xTests library

2nd February 2008 - 1.0.1 beta 93
---------------------------------

 * NOTE: Now requires STLSoft 1.9.19
 * increased severity levels ranges for be.fprintf and be.speech

28th January 2008 - 1.0.1 beta 92
---------------------------------

 * added more unit-tests
 * refactored back-end stock implementation class
 * NOTE: These are breaking changes. Any custom back-ends
   defined using pantheios::internal::Context will have to
   be edited and recompiled

27th January 2008 - 1.0.1 beta 91
---------------------------------

 * NOTE: Now requires STLSoft 1.9.18
 * refactoring of inserter classes
 * bug fix to makefile for GCC compilation

27th January 2008 - 1.0.1 beta 90
---------------------------------

 * almost complete elimination of use of sprintf() / snprintf() except
   where necessary to support variadic API functions

26th January 2008 - 1.0.1 beta 89
---------------------------------

 * refactored example directories and file-names
 * enhanced makefiles to incorporate all examples

20th January 2008 - 1.0.1 beta 88
---------------------------------

 * fixes for various minor bugs introduced in beta 87

20th January 2008 - 1.0.1 beta 87
---------------------------------

 * refactor threadId and pointer inserter classes
 * simplified Tracing API implementation
 * refactored 4 back-ends (be.file, be.speech, be.WindowsConsole,
   be.WindowsDebugger)
 * enhanced unit testing of be.COMErrorObject
 * added unit testing of be.file
 * added component testing of Tracing API

19th January 2008 - 1.0.1 beta 86
---------------------------------

 * enhanced be.test, so it can be used in conjunction with other back-ends
 * minor changes/enhancements to memory handling
 * added more example projects

15th January 2008 - 1.0.1 beta 85
---------------------------------

 * Bug file in be.file
 * Updated error strings

14th January 2008 - 1.0.1 beta 84
---------------------------------

 * Minor enhancements to Application Layer
 * Refactoring of stock back-end common library, to enhance efficiency
 * Additional component tests

13th January 2008 - 1.0.1 beta 83
---------------------------------

 * Minor enhancements to Application Layer
 * Additional component tests

12th January 2008 - 1.0.1 beta 82
---------------------------------

 * Changed befe.test to be.test, for increased flexibility in testing

11th January 2008 - 1.0.1 beta 81
---------------------------------

 * Bug fix for 64-bit Linux

8th January 2008 - 1.0.1 beta 80
--------------------------------

 * changed be.file API: BREAKING CHANGE!
 * NOTE: These are breaking changes. Any code using any be.file stock
   back-ends will need to be edited!
 * further refactoring of src directories

6th January 2008 - 1.0.1 beta 79
--------------------------------

 * fixed broken UNIX makefiles introduced with beta 78
 * incorporates shwild 0.9.9

6th January 2008 - 1.0.1 beta 78
--------------------------------

 * added new front-end: fe.all
 * compatibility release, to require v1.9.17 of STLSoft, which fixes
   a compilation issue with GCC on Leopard

5th January 2008 - 1.0.1 beta 77
--------------------------------

 * major code refactoring: moving all unnecessary code from Core into Util
   to facilitate future reductions in coupling between modules
 * minor addition to Util API

4th January 2008 - 1.0.1 beta 76
--------------------------------

 * workaround for VC++ 8 linker issue
 * minor bug fix in component test program
 * minor change in Core API to reduce coupling
 * minor compatibility changes with Win64

3rd January 2008 - 1.0.1 beta 75
--------------------------------

 * Included unit/component-testing framework into public distribution
 * Now bundles shwild library for use in unit-test pattern matching
 * Now bundles xTests library for use in unit-test pattern matching
 * Updated the error code strings in the Core to reflect recent additions
 * Enhanced pantheios::pointer inserter (Application Layer)
 * Fixed benign (but annoying) bug in time routines (Util)
 * Enhanced functionality of be.COMErrorObject (Back-end)
 * Adjusted all makefiles to build and execute new Unit and Component tests
 * Fixed compilation error in example 10 (Examples)
 * Added/adjusted 4 Unit tests (Test)
 * Added/adjusted 8 Component tests (Test)

30th December 2007 - 1.0.1 beta 74
----------------------------------

 * compatibility release, to require v1.9.16 of STLSoft, which fixes two
   bugs: -ve short/int formatting on 64-bit Linux; 12hr/24hr time
   representation on Windows

29th December 2007 - 1.0.1 beta 73
----------------------------------

 * fixed compilation error introduced in 1.0.1 beta 72

28th December 2007 - 1.0.1 beta 72
----------------------------------

 * Change of back-end initialisation flags and parsing: BREAKING CHANGE!
 * NOTE: These are breaking changes. Any code using any
   stock back-ends may need to be edited!
 * NOTE: *ALL* code using Pantheios must be recompiled, or
   runtime errors may occur!
 * Additional minor adjustments in application layer
 * Additional initialisation error codes defined

27th December 2007 - 1.0.1 beta 71
----------------------------------

 * Cleanup release, preparing for introduction of unit/component-testing
   to the distribution

11th December 2007 - 1.0.1 beta 70
----------------------------------

 * Shift of back-end initialisation flags: BREAKING CHANGE!

10th December 2007 - 1.0.1 beta 69
----------------------------------

 * Further documentation enhancements

8th December 2007 - 1.0.1 beta 68
---------------------------------

 * Small refactoring of #include directories, and test programs
 * Further documentation enhancements
 * Corrected spelling errors (panthieos, not pantheios)

5th December 2007 - 1.0.1 beta 67
---------------------------------

 * Substantial rework/enhancement to the documentation

4th December 2007 - 1.0.1 beta 66
---------------------------------

 * New hex_ptr inserter class

3rd December 2007 - 1.0.1 beta 65
---------------------------------

 * Moved all remaining test files to new naming/directory
   scheme

2nd December 2007 - 1.0.1 beta 64
---------------------------------

 * Fixed weird behaviour in test programs with DMC++

29th November 2007 - 1.0.1 beta 63
----------------------------------

 * Further refactoring of test directories

27th November 2007 - 1.0.1 beta 62
----------------------------------

 * fixed compiler warnings with VC++ 8

26th November 2007 - 1.0.1 beta 61
----------------------------------

 * enhancement of fe.WindowsRegistry

25th November 2007 - 1.0.1 beta 60
----------------------------------

 * reduction of source code size in generated headers
 * ability to reduce compilation load of Application Layer by
   control of PANTHEIOS_APPL_PARAMS_LIMIT pre-processor symbol
 * new FAQ item
 * minor inconsistency fix in shim suppression symbols
 * minor changes in documentation

24th November 2007 - 1.0.1 beta 59
----------------------------------

 * Refactoring of test directories
 * Tidying of examples
 * Added hexptr inserter example

23rd November 2007 - 1.0.1 beta 58
----------------------------------

 * Refactoring of front-end include files and API symbols

22nd November 2007 - 1.0.1 beta 57
----------------------------------

 * Various necessary changes and enhancements to back-end argument
   parsing and documentation

21st November 2007 - 1.0.1 beta 56
----------------------------------

 * bug fix in pantheios::threadId inserter (when used on UNIX)
 * significant refactoring of back-end argument parsing API and
   include file directory structure

20th November 2007 - 1.0.1 beta 55
----------------------------------

 * Renamed be.Win32Console backend to be.WindowsConsole
 * Renamed be.Win32Debugger backend to be.WindowsDebugger
 * Renamed be.Win32syslog backed to be.WindowsSyslog
 * NOTE: These are breaking changes. All code using any
   stock back-ends will need to be edited and recompiled!
 * NOTE: *ALL* code using Pantheios must be recompiled, or
   linker errors may occur

19th November 2007 - 1.0.1 beta 54
----------------------------------

 * Standardisation of front-end process identity symbols.
   NOTE: This is a breaking change. All code using any
   stock front-ends will need to be edited and recompiled!
 * NOTE: *ALL* code using Pantheios must be recompiled, or
   linker errors may occur

18th November 2007 - 1.0.1 beta 53
----------------------------------

 * NOTE: Now requires STLSoft 1.9.7
 * Facilities for accelerating compilation times by
   restricting function template parameter range
 * Various code cleanup in backend utility functions

17th November 2007 - 1.0.1 beta 52
----------------------------------

 * Refactoring of include files
 * Removal of implementation functions from
   pantheios namespace, and documentation
 * Removed Windows-dependency that broke the build
   in beta 51

16th November 2007 - 1.0.1 beta 51
----------------------------------

 * VC++ 2005 / 64-bit compilation fixes

15th November 2007 - 1.0.1 beta 50
----------------------------------

 * re-issue due to distribution error with 1.0.1 beta 49

14th November 2007 - 1.0.1 beta 49
----------------------------------

 * bug fix for VC++ 2005
 * refactoring of severity translations from ACE, syslog, log4???

13th November 2007 - 1.0.1 beta 48
----------------------------------

 * high and low resolution timing options in backend statement
   formatting
 * example programs for high and low resolution timing
 * adjustments to makefiles

12th November 2007 - 1.0.1 beta 47
----------------------------------

 * moved Pantheios Trace API into separate include file
 * minor adjustment to GCC makefiles
 * minor bug fix to address compiler warning on UNIX

11th November 2007 - 1.0.1 beta 46
----------------------------------

 * considerable refactoring of date/time handling in back-end
   statement
 * minor fix to makefiles on Mac OS-X

10th November 2007 - 1.0.1 beta 45
----------------------------------

 * code cleanup and refactoring, ready for several functional
   enhancements in next several releases
 * reduced size of N-ary Generated Function Templates in Application
   Layer
 * removal of obsolete KiwiSyslog KLOG back-end

3rd November 2007 - 1.0.1 beta 44
---------------------------------

 * more code tidying / refactoring

3rd November 2007 - 1.0.1 beta 43
---------------------------------

 * code tidying / refactoring

29th October 2007 - 1.0.1 beta 42
---------------------------------

 * bug fix to fe.WindowsRegistry

28th October 2007 - 1.0.1 beta 41
---------------------------------

 * added fe.WindowsRegistry

26th October 2007 - 1.0.1 beta 40
---------------------------------

 * minor bug fix in be.file back-end

25th October 2007 - 1.0.1 beta 39
---------------------------------

 * minor code cleanup

23rd October 2007 - 1.0.1 beta 38
---------------------------------

 * added new be.speech back-end, which provides spoken output of
   log statements.

21st October 2007 - 1.0.1 beta 37
---------------------------------

 * further enhancements be.N to facilitate backup back-end to be
   initialised only if all prior back-end initialisations failed

20th October 2007 - 1.0.1 beta 36
---------------------------------

 * further enhancements be.N to facilitate backup back-end to be
   initialised only if all prior back-end initialisations failed

19th October 2007 - 1.0.1 beta 35
---------------------------------

 * further enhancements be.N to facilitate targeting messages to
   specific back-ends

18th October 2007 - 1.0.1 beta 34
---------------------------------

 * enhanced be.N to facilitate back-end-specific message targeting

7th October 2007 - 1.0.1 beta 33
--------------------------------

 * standardised Initialisation Error Codes
 * large number of makefile changes, to simplify & clean
 * callback functionality to be.COMErrorObject
 * minor bug-fix in be.Win32syslog

3rd September 2007 - 1.0.1 beta 32
----------------------------------

 Various fixes for 64-bit UNIX compilation

16th August 2007 - 1.0.1 beta 30
--------------------------------

 Added back-end generation macros, to ease compile-time
   selection/definition
 fixed (benign) bug for Borland build

5th August 2007 - 1.0.1 beta 29
-------------------------------

 message-first statement composition

2nd August 2007 - 1.0.1 beta 28
-------------------------------

 compatible with STLSoft 1.9.4
 added the Pantheios Tracing API
 fixes for some back-end project files


29th July 2007 - 1.0.1 beta 27
------------------------------

 compatible with STLSoft 1.9.3
 bug fix for be.file


30th April 2007 - 1.0.1 beta 26
-------------------------------

 compatible with STLSoft 1.9.1 (version with Extended STL, vol 1)
 bug fix for be.file


11th April 2007 - 1.0.1 beta 25
-----------------------------

 reimplemented core initialisation on UNIX
 bug fix for be.file on UNIX
 added missing project files


6th April 2007 - 1.0.1 beta 24
----------------------------

 fix to be.file, to allow reading of log file
 fix to core project file
 minor adjustments to syntax to prepare for next beta changes


27th Jan 2007 - 1.0.1 beta 23
-----------------------------

 refactoring of core source files; DMC++ compiler
 improvement-related enhancements to fe.N and fe.simple;
 distribution now rooted at pantheios-1.0.1-beta23/; 64-bit fixes

15th Jan 2007 - 1.0.1 beta 22
-----------------------------

 fixed a problem with compiling under 64-bit Linux; this requires
 the latest STLSoft distro: 1.9.1 beta 42, or later

9th Jan 2007 - 1.0.1 beta 21
----------------------------

 added fault-tolerance to be.N, so one or more (but not all) back-ends
 can fail and the application can proceed; added be.fail back-end that
 always fails (for testing be.N fault tolerance)

5th Jan 2007 - 1.0.1 beta 20
----------------------------

 Adding missing implicit link file; time formatting bug fix

2nd Jan 2007 - 1.0.1 beta 19
----------------------------

 Enhancements to fe.N front-end; minor bug fix

23rd Dec 2006 - 1.0.1 beta 18
-----------------------------

 Bug fix; refactoring of back-ends; more implicit linking
 facilities

20th Dec 2006 - 1.0.1 beta 17
-----------------------------

 Refactoring, and implementation of be.fprintf

18th Dec 2006 - 1.0.1 beta 16
-----------------------------

 Minor fix for dynamic library builds

16th Dec 2006 - 1.0.1 beta 15
-----------------------------

 Fix to C++/COM util header

12th Dec 2006 - 1.0.1 beta 14
-----------------------------

 Minor fix for dynamic library builds

7th Dec 2006 - 1.0.1 beta 13
----------------------------

 Added fe.N front-end and be.N back-end, to allow
 splitting to multiple (2+) transports

5th Dec 2006 - 1.0.1 beta 12
----------------------------

 Fixes to VC++ 8 build/linking

3rd Dec 2006 - 1.0.1 beta 11
----------------------------

 Minor fix to be.COMErrorObject

1st Dec 2006 - 1.0.1 beta 10
----------------------------

 Fixes to C compilation

 Fixes to be.file

29th Nov 2006 - 1.0.1 beta 9
----------------------------

 New example (for be.file)

 Minor fixes to be.file

27th Nov 2006 - 1.0.1 beta 8
----------------------------

 Added new backend - be.file

 Compiler compatibility issues

29th Oct 2006 - 1.0.1 beta 7
----------------------------

 Minor efficiency increases

21st Oct 2006 - 1.0.1 beta 6
----------------------------

 Added three new inserter classes (args, pointerId, threadId)

8th Oct 2006 - 1.0.1 beta 5
---------------------------

 Fixed bugs introduced in beta 4

5th Oct 2006 - 1.0.1 beta 4
---------------------------

 Fixes to UNIX/GCC compilation, and some minor additions

24th Sept 2006 - 1.0.1 beta 3
-----------------------------

 A few minor changes and some fixes to the makefiles

2nd Sept 2006 - 1.0.1 beta 2
----------------------------

 This is the first released version.

 All history before this day is moot!

=============================== End of file ================================
