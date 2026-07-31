# Pantheios - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on
[GitHub Issues](https://github.com/synesissoftware/Pantheios/issues)
it will be used to create one.


## Table of Contents <!-- omit in toc -->

- [Q1: "What happens if the Pantheios libraries fail to initialise?"](#q1-what-happens-if-the-pantheios-libraries-fail-to-initialise)
- [Q2: "What if I need more than 32 parameters?"](#q2-what-if-i-need-more-than-32-parameters)
- [Q3: "How do I represent a process Id?"](#q3-how-do-i-represent-a-process-id)
- [Q4: "What is 'Pure Pantheios'?"](#q4-what-is-pure-pantheios)
- [Q5: "Is Pantheios thread-safe?"](#q5-is-pantheios-thread-safe)
- [Q6: "How do I alter the number of parameters in the Application Layer?"](#q6-how-do-i-alter-the-number-of-parameters-in-the-application-layer)
- [Q7: "Why do the back-end(s) have to be specified at link-time?"](#q7-why-do-the-back-ends-have-to-be-specified-at-link-time)
- [Q8: "I get linker errors with GCC, even though I'm specifying the libraries…"](#q8-i-get-linker-errors-with-gcc-even-though-im-specifying-the-libraries)
- [Q9: "Does Pantheios provide a Trace configuration that includes the function name?"](#q9-does-pantheios-provide-a-trace-configuration-that-includes-the-function-name)
- [Q10: "Do you hand code the makefiles?"](#q10-do-you-hand-code-the-makefiles)
- [Q11: "Have you considered CMake?"](#q11-have-you-considered-cmake)
- [Q12: "Which compilers support implicit linking with Pantheios?"](#q12-which-compilers-support-implicit-linking-with-pantheios)
- [Q13: "How do I link when using compilers that don't support implicit linking?"](#q13-how-do-i-link-when-using-compilers-that-dont-support-implicit-linking)
- [Q14: "I'm using the Trace API, but it fails to print the function. Why?"](#q14-im-using-the-trace-api-but-it-fails-to-print-the-function-why)
- [Q15: "How do I select severity and back-end dynamically with be.N?"](#q15-how-do-i-select-severity-and-back-end-dynamically-with-ben)
- [Q16: "Is there any way to modify the logged message format?"](#q16-is-there-any-way-to-modify-the-logged-message-format)
- [Q17: "How do I retain pretty formatting when converting printf to pantheios::log?"](#q17-how-do-i-retain-pretty-formatting-when-converting-printf-to-pantheioslog)
- [Q18: "Why is backendId always 0 in pantheios\_fe\_isSeverityLogged()?"](#q18-why-is-backendid-always-0-in-pantheios_fe_isseveritylogged)
- [Q19: "How do I build/link Pantheios with /Zc:wchar\_t-?"](#q19-how-do-i-buildlink-pantheios-with-zcwchar_t-)


## Q1: "What happens if the Pantheios libraries fail to initialise?"

*2nd October 2006*

The process will be terminated, via `exit()` (`ExitProcess()` on Windows)

From 1.0.1 beta 4 onwards, library initialisation is also accompanied
by invocation of `pantheios_onBailOut()`, a fallback log function that is
used by the Core (and Front/Back-end(s)) to report on a failure to
initialise Pantheios. The output facilities are operating
system-dependent:
  * on **UNIX** the bail-out message is written to `syslog()` and to the
    console of the calling process (via `fprintf()`), and to a local file
    **logging-bailout.txt** (appending if already exists);
  * on **Windows** the bail-out message is written to the debugger (via
    `OutputDebugString()`), the console (if any) of the calling process (via
    `WriteFile()`), to a local file **logging-bailout.txt** (appending if it
    already exists), and to the **Windows Event Log** (under the source
    **"logging-bailout"**).

    > NOTE: The Event Log messages will not be correctly formatted (although
    their information will be accessible), unless **pantheios.COM** is
    installed: The **Windows** bail-out functionality piggy backs on the
    **Event Log** message resources in pantheios.COM (version 1.0.1 beta 3
    or later)


## Q2: "What if I need more than 32 parameters?"

You can regenerate the six automatically-generated files as follows:
  * edit the **scripts/make_hdrs.rb** (Ruby) script;
  * change the `NUM_PARAMS` constant to the required value;
  * run the script from the scripts directory. You may have to change file
    permissions of the automatically-generated files, if they're read-only;


## Q3: "How do I represent a process Id?"

*15th November 2007*

By using the `pantheios::processId` inserter.

```C++
#include <pantheios/inserters/ids.hpp>

int main()
{
  pantheios::log_NOTICE("process id=", pantheios::processId);
}
```


## Q4: "What is 'Pure Pantheios'?"

*15th November 2007*

**Pantheios** is primarily a logging _API_ library. That is, it is explictly
designed to layer over the top of other, feature-rich, logging libraries.
Of course, it comes with several of its own transport mechanisms, known as
back-ends, but they are not part of '_Pure Pantheios_'.

Technically speaking, 'Pure Pantheios' consists only of:

* **The Application Layer**;
* **The Core**;

The **Application Layer** talks only to the **Core**. The **Core** talks to
a **Front-End** and a **Back-End**, which are, strictly, external to '_Pure
Pantheios_'.

The **Core** talks to the **Front-End** via the following four functions,
declared in **include/pantheios/frontend.h**:

* `pantheios_fe_init()`:
    initialises the front-end; called at most once per process;
* `pantheios_fe_uninit()`:
    uninitialises the front-end; called at most once per process;
* `pantheios_fe_getProcessIdentity()`:
    returns a C-style string that names the current process, e.g.
    "logdaemon"; called at most once per process;
* `pantheios_fe_isSeverityLogged()`:
    returns an integer to indicate whether a log statement of a given;
    severity level is to be emitted to the Back-End; called each time a
    statement is processed;

These functions must be implemented by any **Front-End** linked to the
application/shared object.

The **Core** talks to the **Back-End** via the following three functions,
declared in **include/pantheios/backend.h**:

* `pantheios_be_init()`:
    initialises the back-end; called at most once per process;
* `pantheios_be_uninit()`:
    uninitialises the back-end; called at most once per process;
* `pantheios_be_logEntry()`:
    called to emit each statement;

These functions must be implemented by any Back-End linked to the
application/shared object.

**Pantheios** comes with a number of stock **Front-End** and **Back-end**
libraries, for the convenience of users. Furthermore, a number of **Inserter
Classes** are provided which supplement the **Application Layer**,
including:

  | Inserter type                     | Inserts                                                                | Alias                          |
  | --------------------------------- | ---------------------------------------------------------------------- | ------------------------------ |
  | `pantheios::args`                 | `argc`/`argv` pair (e.g. from `main()`)                                | -                              |
  | `pantheios::b64`                  | binary region as Base-64 (requires the **b64** library)                | -                              |
  | `pantheios::blob`                 | binary region as a hex dump (optional grouping/separators)             | -                              |
  | `pantheios::boolean`              | boolean value                                                          | `pantheios::b` (or `pan::b`)   |
  | `pantheios::character`            | character value                                                        | `pantheios::ch` (or `pan::ch`) |
  | `pantheios::exception`            | `std::exception` (via `pantheios::exception(...)`)                     | -                              |
  | `pantheios::hex_ptr`              | pointer in hexadecimal (obsolete; prefer `pointer` / `xp`)             | -                              |
  | `pantheios::hostId`               | host identity                                                          | -                              |
  | `pantheios::inserter`             | adaptor that applies a string conversion to a value                    | -                              |
  | `pantheios::integer`              | integer value                                                          | `pantheios::i` (or `pan::i`)   |
  | `pantheios::interval`             | time interval (µs … days)                                              | -                              |
  | `pantheios::m2t`                  | multibyte string into the ambient character encoding                   | -                              |
  | `pantheios::m2w`                  | multibyte string into a wide-string statement                          | -                              |
  | `pantheios::pad`                  | padding spaces for minimum width (`PANTHEIOS_LPAD` / `PANTHEIOS_RPAD`) | -                              |
  | `pantheios::pointer`              | pointer value                                                          | `pantheios::p` (or `pan::p`)   |
  | `pantheios::processId`            | current process identity                                               | -                              |
  | `pantheios::real`                 | floating-point value                                                   | -                              |
  | `pantheios::slice`                | slice (substring / length-bounded view) of a string                    | -                              |
  | `pantheios::stream_character`     | character value as typically read from a stream                        | -                              |
  | `pantheios::threadId`             | current thread identity                                                | -                              |
  | `pantheios::variant_bool`         | COM `VARIANT_BOOL`                                                     | `pantheios::vb` (or `pan::vb`) |
  | `pantheios::w2m`                  | wide string into a multibyte-string statement                          | -                              |
  | `pantheios::w2t`                  | wide string into the ambient character encoding                        | -                              |
  | `pantheios::windows::hive`        | Windows Registry `HKEY` (known hive name, else hex)                    | -                              |
  | `pantheios::windows::status_code` | Windows `DWORD` / COM `HRESULT` status code                            | `pantheios::windows::sc`       |
  | `pantheios::xi`                   | integer value in hexadecimal                                           | -                              |
  | `pantheios::xp`                   | pointer value in hexadecimal                                           | -                              |

Importantly, instances of these Inserters do not perform any conversions (or
allocate memory) unless the given statement they are in is to be emitted (as
determined by `pantheios_fe_isSeverityLogged()`). This is one of many ways
in which Pantheios provides extremely high-levels of performance.


## Q5: "Is Pantheios thread-safe?"

*19th November 2007*

The short answer is: Yes.

The long answer is:

The Core is thread-safe. The Core initialisation/uninitialisation
functions are reference-counted. On architectures with atomic integer
operations *all* calls to `pantheios_init()` are thread-safe. On other
architectures *all* calls to `pantheios_init()` except the first are
thread-safe.

The Application is layer is thread-safe simply because there is no
shared state between threads in any application layer components.

As for the Front-end and Back-ends, the answer is: It depends.

The Front-end functions `pantheios_fe_init()`, `pantheios_fe_uninit()` and
`pantheios_fe_getProcessIdentity()` are called at most once per-process
during the initialisation phase. Therefore, they do not need to be
thread-safe. The Front-end function `pantheios_fe_isSeverityLogged()` is
called every time a statement is processed, to evaluate whether the
statement should be emitted to the back-end(s). Thus, this function
must be thread-safe.

The Back-end functions `pantheios_be_init()`, and `pantheios_be_uninit()`
are called at most once per-process during the initialisation phase.
Therefore, they do not need to be thread-safe. The Back-end function
`pantheios_be_logEntry()` is called every time a statement is to be
emitted. It must be thread-safe.

All stock Front-end and Back-end implementations are thread-safe.

If you write custom Front-end and/or Back-end, you must ensure that
the functions `pantheios_fe_isSeverityLogged()` and
`pantheios_be_logEntry()` are thread-safe. If you do so, your use of
Pantheios will be entirely thread-safe.


## Q6: "How do I alter the number of parameters in the Application Layer?"

*25th November 2007*

There are two ways.

First, if you wish to reduce the number of parameters in the **Application
Layer** - presumably to speed compilation when you don't need the full
range of parameters - then you can simply #define the pre-processor
symbol `PANTHEIOS_APPL_PARAMS_LIMIT` (introduced in 1.0.1 beta 60) to a
number between 1 and 32.

Second, if you wish to increase the number of parameters available in
functions in the **N-ary Function Templates** of the **Application Layer**,
you must re-generate the **Application Layer** headers using the
**make_hdrs.rb** Ruby script in the script directory. However, we would
advise that if you are writing application code that needs to pass more than
32 parameters to **Pantheios**, you are unlikely to be writing transparent
code, one of the design requirements of **Pantheios**.


## Q7: "Why do the back-end(s) have to be specified at link-time?"

*3rd January 2008*

The short answer is: Because Pantheios is initialised automatically, and
before `main()` is called. (This is actually done by using the Schwarz
counters found in **include/pantheios/internal/initialiser.hpp**, included
by **include/pantheios/pantheios.hpp** unless in a DLL context or you
#define `PANTHEIOS_NO_AUTO_INIT`)

This is done to allow any piece of code in any part of the system to be able
to log any conditions that may be necessary. If the process could not log
before `main()` started, this might not be possible; indeed, how would you
log a failure in another pre-main sub-system?

The reason why this question comes up a lot is, of course, because users
quite reasonably want to be able to specify logging options, at the start of
`main()`.

The best approach to cater for both requirements is as follows:
 1. Link to **be.N**;
 2. Define the `PAN_BE_N_BACKEND_LIST` array (see the documentation on
    **be.N**) for an explanation of how this works. Make sure to include an
    entry for a back-end that does not need any configuration, e.g.
    **be.syslog**. Then also include an entry for a back-end that provides
    run-time customisation, say, **be.YourConfigurableBackEnd**;
 4. Customise **be.YourConfigurableBackEnd** inside `main()`. If the program
    does not make it as far as `main()`, at least you will have had some
    logging output go to **Syslog**, via **be.syslog**;

NOTE: A future version of Pantheios will include **be.loader**, which will
allow you to load and configure back-ends at runtime, based on
configuration file(s)


## Q8: "I get linker errors with GCC, even though I'm specifying the libraries…"

*28th January 2008*

"_I get linker errors with GCC, even though I'm specifying the core,
front-end and back-end libraries. I've used nm, and the core library says it
contains the missing symbols. What gives?_"

What's going on here is that GCC's linker reads symbols in a
left-to-right manner. The Pantheios initialisation functions -
`pantheios_init()`, `pantheios_uninit()` - must be elicited from the core
library, which is listed first in the libraries list. They then require
symbols from the back-end and front-end libraries, which come next in
the libraries list. They, in turn, require symbols from the core, which
must therefore be listed again, at the end of the libraries list. The
GCC makefiles included in the distribution do this, and can be used as
templates for how to do it in your own projects.


## Q9: "Does Pantheios provide a Trace configuration that includes the function name?"

*15th March 2008*

"_Does Pantheios provide a configuration that yields a logged message
containing the containing function, equivalent to:_
`log(informational, __FUNCTION__, ": my message");` _without having to write
that (or some wrapper that checks for compiler support)._"

You need to #define PANTHEIOS_TRACE_PREFIX to what you want. By default
it is `__FILE__ "(" PANTHEIOS_STRINGIZE(__LINE__) "): "`, which gives the
format '\<file>(\<line>): '

To include the function, lets says you want it to have the format
'\<file>(\<line>): \<func>: '. To achieve this you'd define it as follows:

```C++
  #include <pantheios/pantheios.h>
  #define PANTHEIOS_TRACE_PREFIX         __FILE__ " " PANTHEIOS_STRINGIZE(__LINE__) ": " __FUNCTION__ ": "
  #include <pantheios/trace.h>
```

Note that the definition *must* come before the inclusion of
pantheios/trace.h. Therefore, a safer way of doing this is as follows:

```C++
  /* File: myPantheiosRootHeader.h */
  #include <pantheios/pantheios.h>

  #ifdef PANTHEIOS_INCL_PANTHEIOS_H_TRACE
  # error pantheios/trace.h must not be included before myPantheiosRootHeader.h
  #endif /* PANTHEIOS_INCL_PANTHEIOS_H_TRACE */

  #define PANTHEIOS_TRACE_PREFIX         __FILE__ " " PANTHEIOS_STRINGIZE(__LINE__) ": " __FUNCTION__ ": "
  #include <pantheios/trace.h>
```


## Q10: "Do you hand code the makefiles?"

*18th June 2008*

No, although it sometimes feels a bit like that. I use a proprietary tool,
**tmpl2make**, that takes a makefile template and a tools configuration
file, and runs a merge over them. The makefile template language has `IFDEF`
and `FOREACH`, but it's still a non-trivial effort to start a new one, which
is why I tend to copy them from established projects (such as **Pantheios**)
to new ones (**flecxx**, **FastFormat**).


## Q11: "Have you considered CMake?"

*18th June 2008*

Yes, and it's on the roadmap for post 1.0 things to do (along with
project/solution files for **XCode**, **Code::Blocks**), and so on).
However, it will always be the case that the raw makefiles will be available
for maximum portability.


## Q12: "Which compilers support implicit linking with Pantheios?"

*16th October 2008*

Borland, Metrowerks CodeWarrior (on Windows), Intel (on Windows) and
Visual C++.


## Q13: "How do I link when using compilers that don't support implicit linking?"

*16th October 2008*

You must use explicit linking.

For example, say you're using **GCC** on **UNIX**, and wishing to use the
**fe.simple** front-end and along with the **be.fprintf** back-end. The
libraries you link to depend on the configuration.

For single-threaded & debug, you need to link to:

* **pantheios.1.core.gcc40.debug.a**;
* **pantheios.1.util.gcc40.debug.a**;
* **pantheios.1.fe.simple.gcc40.debug.a**;
* **pantheios.1.be.fprintf.gcc40.debug.a**;
* **pantheios.1.bec.fprintf.gcc40.debug.a**;

The command-line will look like:

```bash
 g++ -Dunix -I$PANTHEIOS_ROOT/include -I$STLSOFT/include \
   -L$PANTHEIOS_ROOT/lib \
   -lpantheios.1.core.gcc40 \
   -lpantheios.1.fe.simple.gcc40 \
   -lpantheios.1.be.fprintf.gcc40 \
   -lpantheios.1.bec.fprintf.gcc40 \
   -lpantheios.1.core.gcc40 \
   -lpantheios.1.util.gcc40 \
   my_program.cpp
```

Note the double specification of the **pantheios.1.core.gcc40.debug.a**
library. This is required with **GCC** because of the way it handles
library lookup and interpositioning: basically the core depends on symbols
defined in the front-end and back-end(s), and they in turn depend on some
symbols defined in the core, so it has to be specified before and after
them.


## Q14: "I'm using the Trace API, but it fails to print the function. Why?"

*6th May 2009*

You are using a compiler that does not support the `__FUNCTION__` macro. At
the current time (Pantheios 1.0.1-beta 186, STLSoft 1.9.81; 8th May 2009),
the compilers known to support it are:

  * **Comeau**;
  * **Digital Mars** (8.50+);
  * **GCC** (3+);
  * **Intel C/C++** (7+);
  * **Metrowerks CodeWarrior** (8+);
  * **Visual C++** (7.0+);
  * **Watcom C/C++** (OpenWatcom 1.4+);
  * **SunPro 5.9** (by defining `__FUNCTION__` in terms of the
    compiler-specific `__func__`);

Those known to not support it are:

  * Borland (all versions 5.5 - 6.1);
  * VectorC;

If your compiler does not support it, then the only avenue available if
you absolutely must have it, is to #define it in each function, as in:

```C
  int main()
  {
  #define __FUNCTION__ main

    PANTHEIOS_TRACE_PRINTF(pantheios::notice, "a string '%s' and a number %d", "<abc>", 42);

    . . .
```

You'll also need to "persuade" the trace macro you wish to use that it can
actually proceed. In the example.cpp.tracing.with_function example, the
PANTHEIOS_TRACE_PREFIX macro is defined as follows:

```C++
  // From examples/cpp/example.cpp.tracing.with_function/example.cpp.tracing.with_function.cpp

  #ifdef STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT
  # define PANTHEIOS_TRACE_PREFIX             __FILE__ " " PANTHEIOS_STRINGIZE(__LINE__) ": " __FUNCTION__ ": "
  #endif /* STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT */
```

If you're using a compiler that does not support __FUNCTION__, and for
which STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT is not defined, you would remove
the #ifdef and #endif lines.

If you wish to ensure that program remains compatible with compilers that
do support __FUNCTION__, then you would add a guard around the #define, as
in:

```C++
  int main()
  {
  #ifndef STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT
  # define __FUNCTION__ "main"
  #endif /* !STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT */

  . . .
```


## Q15: "How do I select severity and back-end dynamically with be.N?"

*21st May 2009*

"_I have numerous back ends defined, and am trying to pass the log message
to a specific backend for a specific log level, like this:_
`log_message( int logLevel, int log_BE, const char* message) { pantheios::log(pantheios::critical(log_BE), "log this"); }`
_but change_
`pantheios::critical()` _to be based on the logLevel, such as_
`PANTHEIOS_SEV_DEBUG` _or similar. How is this done?_"

Use `PANTHEIOS_MAKE_EXTENDED_SEVERITY()` to define severity+extended_info
on the fly, as in:

```C
  // C example
  pantheios_logprintf(
    PANTHEIOS_MAKE_EXTENDED_SEVERITY(PANTHEIOS_SEV_NOTICE, 10), "hello");
```

and:

```C++
  // C++ example
  pantheios::log(
    PANTHEIOS_MAKE_EXTENDED_SEVERITY(PANTHEIOS_SEV_NOTICE, 10), "hello");
```

You can #define your own codebase-specific macro that's more
succinct, e.g:

```C++
  #define ACME_SEV_X(sev, x) PANTHEIOS_MAKE_EXTENDED_SEVERITY(sev, x)
```

and use it as:

```C++
  log_message( int logLevel, int log_BE, const char* message)
  {
    pantheios::log(ACME_SEV_X(logLevel, log_BE), "log this");
  }
```


## Q16: "Is there any way to modify the logged message format?"

*21st May 2009*

"_Currently the logging format is something like:_
`[Project.5844, 5/20/2009 1:58:37.006 PM; Debug ]: logging message`. _Is
there any way to modify the format of this?_"

Yes, in a limited way, via the callback mechanism. Link to a callback
version of a particular back-end library and implement the back-end
callback initialisation function.

This allows you to turn on/off various format prefix fields

  `[process identity, thread identity, date, time, severity, etc.]`

For example, the non-callback version of the **be.fprintf** back-end is
defined in the **bec.fprintf** library (e.g.
**pantheios.1.bec.fprintf.vc9.lib**), whereas the callback version is
defined in the **bec.fprintf.WithCallback** library (e.g.
**pantheios.1.bec.fprintf.WithCallback.vc6.lib**).

The callback initialisation function for **be.fprintf** is
`pantheios_be_fprintf_getAppInit()`. You implement this function and
customise the behaviour of **be.fprintf** via the flags member of
`pan_be_fprintf_init_t`.

Note that the only reordering possible is to put the whole prefix,
en-bloc, to the end (as a suffix). For more sophisticated ordering, the
only option currently available is to write your own back-end, or engage
the services of Synesis Software (http://www.synesis.com.au/contact.html)
to assist you.


## Q17: "How do I retain pretty formatting when converting printf to pantheios::log?"

*24th June 2009*

"_I'm going through and converting a lot of printf statements to_
`pantheios::log` _statements and I'm unsure of how to best retain the pretty
formatting aspects. For types with explicit inserters (real, int, etc.) it
seems I can use the width and fmt parameters to log prettily, but its
unclear how to space strings. For example how should I translate:_
`printf("Name: %40s", name.c_str());` "

As of 1.0.1 beta 189, the padding inserter `pantheios::pad()` can be used to
provide a string of spaces of the necessary size to pad a variable of
arbitrary type, as in:

```C++
  #include <pantheios/inserters/pad.hpp>          // for pantheios::pad


  printf("Name: %40s.\n", name.c_str());

  pantheios::log_NOTICE("Name: ", PANTHEIOS_LPAD(name, 40), ".");
```

The inserter is used via the `PANTHEIOS_LPAD()`, which inserts pad spaces
to the left of the variable, and `PANTHEIOS_RPAD()`, which inserts pad
spaces to the right.


## Q18: "Why is backendId always 0 in pantheios_fe_isSeverityLogged()?"

"_I've written a custom front-end to work with be.N, but the backendId is
always 0 in_ `pantheios_fe_isSeverityLogged()`, _and nothing gets logged!_"

`pantheios_fe_isSeverityLogged()` is always called first by the
**Application Layer**, to determine whether a log statement at the given
severity level will be logged; If not, nothing needs to be converted. In
this invocation the backendId parameter will be 0 (aka
`PANTHEIOS_BEID_ALL`), meaning "does anything need to be logged?"

Multiplexing back-ends (e.g. be.N) also call
`pantheios_fe_isSeverityLogged()` to determine whether a specific back-end
is interested in the given log statement (based on its severity level).

So, if you are writing a custom front-end, you must handle both cases: 0
for "any back-ends?", and specific non-0 values (your specific back-end
identifiers) representing your specific back-ends. The scratch test
program test.scratch.be.N.with.custom.fe illustrates how this is to done.
Its definition of `pantheios_fe_isSeverityLogged()` is as follows:

```C++
PANTHEIOS_CALL(int) pantheios_fe_isSeverityLogged(void*, int severity, int beid)
{
  switch(beid)
  {
    // Must handle PANTHEIOS_BEID_ALL, as that's the Application Layer's
    // (initial) enquiry as to whether anything should be logged at all
    case  PANTHEIOS_BEID_ALL:
#if 0
      // The inefficient way to do this is to just 'return true'
      return true;
#else /* ? 0 */
      // The efficient (but complicated) way to do this is to see if
      // *any* back-end wants output, in which case we say yes
      return  severity <= iCeilingMain ||
          severity <= iCeilingConsole ||
          severity <= iCeilingError;
#endif /* 0 */

    // Now handle each specified back-end, which will come from be.N
    // multiplexing the output(s)

    case  WG_LOG_FILE_ID:
      return severity <= iCeilingMain;
    case  WG_LOG_CONSOLE_ID:
      return severity <= iCeilingConsole;
    case  WG_LOG_FILE_ERROR_ID:
      return severity <= iCeilingError;

    // Don't know about anything else
    default:
      PANTHEIOS_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_API("unexpected back-end identifier");
      return false;
  }
}
```


## Q19: "How do I build/link Pantheios with /Zc:wchar_t-?"

"_My project requires that I use **Microsoft Visual C++**'s_ `/Zc:wchar_t-`
_option, which prevents_ `wchar_t` _from being a built-in type, instead
being just a typedef to_ `unsigned short`. _When I try to link with
**Pantheios** I get link errors, such as:_
```
1>Zc.wchar_t.test.obj : error LNK2019: unresolved external symbol "public: __thiscall pantheios::args::args(int,unsigned short const * const *,int,unsigned short const *)" (??0args@pantheios@@QAE@HPBQBGHPBG@Z) referenced in function _wmain
1>Zc.wchar_t.test.obj : error LNK2019: unresolved external symbol "public: unsigned short const * __thiscall pantheios::args::data(void)const " (?data@args@pantheios@@QBEPBGXZ) referenced in function "unsigned short const * __cdecl pantheios::shims::c_str_data_w(class pantheios::args const &)" (?c_str_data_w@shims@pantheios@@YAPBGABVargs@2@@Z)
1>Zc.wchar_t.test.obj : error LNK2019: unresolved external symbol "public: unsigned short const * __thiscall pantheios::integer::data(void)const " (?data@integer@pantheios@@QBEPBGXZ) referenced in function "unsigned short const * __cdecl pantheios::shims::c_str_data_w(class pantheios::integer const &)" (?c_str_data_w@shims@pantheios@@YAPBGABVinteger@2@@Z)
```
 _How can I get Pantheios to define_ `wchar_t` _in the same way without
 hacking the makefile?_"

You have to link against a version of **Pantheios** compiled with the same
compiler flag. This can be achieved by setting the `CUSTOM_DEFS` make macro
as follows:

  > nmake CUSTOM_DEFS="-Zc:wchar_t-" build

You will then be able to link to your program.

NOTE: You will need to ensure that other code that relies on **Pantheios**
and that was not compiled with `-Zc:wchar_t-` will see another,
uncustomised, version, otherwise you'll have the same linking problem, but
in reverse.


<!-- ########################### end of file ########################### -->
