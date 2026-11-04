# Pantheios {#mainpage}

**Pantheios** is an efficient, flexible, and robust C/C++ diagnostic logging
**API** library. Application code emits type-safe, high-performance
diagnostic statements; *where* and *whether* those statements are emitted is
chosen at link time via a **front-end** and a **back-end**.


## Quick start

Install [STLSoft](https://github.com/synesissoftware/STLSoft) (**1.11.5**
or later) and [woad](https://github.com/synesissoftware/woad) (**0.2.2**
or later), then from a **Pantheios** tree:

```bash
./prepare_cmake.sh --run-make # also use '--cmake-verbose-makefile' to see verbose output
./run_all_automated_tests.sh --no-make
```

A logging statement sits in the **application layer**. The other three
parts are chosen when you link: **Core** (and **Util**, providing
initialisation, formatting, and dispatch), a **front-end** (whether a
statement is emitted), and one or more **back-ends** (where an accepted
statement goes). Including `<pantheios/pan.hpp>` initialises the Core
and aliases `pantheios` as `pan`. `fe.simple` reads
`PANTHEIOS_FE_PROCESS_IDENTITY` and applies a severity ceiling;
`be.AnsiConsole` with `bec.AnsiConsole` writes the accepted lines to
the console. The application code itself is one simple statement that
logs, at severity `NOTICE`, all arguments provided to the process:

```cpp
#include <pantheios/pan.hpp>
#include <pantheios/inserters/args.hpp>
#include <pantheios/frontends/stock.h>

#include <stdlib.h>

const char PANTHEIOS_FE_PROCESS_IDENTITY[] = "hello.pantheios";

int main(int argc, char* argv[])
{
    pan::log_NOTICE("main(", pan::args(argc, argv), ")");

    return EXIT_SUCCESS;
}
```

```cmake
find_package(Pantheios REQUIRED)

target_link_libraries(hello
    PRIVATE
        Pantheios::Pantheios.core
        Pantheios::Pantheios.util
        Pantheios::Pantheios.fe.simple
        Pantheios::Pantheios.be.AnsiConsole
        Pantheios::Pantheios.bec.AnsiConsole
)
```

\image html readme-example.png "Console output of the C++ example, via be.AnsiConsole" width=60%

A C program does not auto-initialise. Define the same identity, call
`pantheios_init()`, and log only when that returns 0. **examples/c/101**
is the full form.
([**Pantheios.Extras.Main**](https://github.com/synesissoftware/Pantheios.Extras.Main) - a separate project - abstracts this and simplifies C programs that use Pantheios.)

```c
#include <pantheios/pantheios.h>
#include <pantheios/frontends/stock.h>

#include <stdio.h>
#include <stdlib.h>

const char PANTHEIOS_FE_PROCESS_IDENTITY[] = "hello.pantheios";

int main(void)
{
    int res = pantheios_init();

    if (0 != res)
    {
        fprintf(stderr, "pantheios_init: %s\n",
            pantheios_getInitCodeString(res));

        return EXIT_FAILURE;
    }

    pantheios_logputs(PANTHEIOS_SEV_NOTICE, "Hello!");

    pantheios_uninit();

    return EXIT_SUCCESS;
}
```

Link the same targets for a C program. Clone or a release archive:
[INSTALL.md](https://github.com/synesissoftware/Pantheios/blob/master/INSTALL.md).


## Components

| Module | Header | Summary |
| ------ | ------ | ------- |
| \ref group__core_library | `<pantheios/pantheios.h>` | Core logging API |
| \ref group__application_layer_interface | `<pantheios/pantheios.hpp>` | Application-layer API and inserters |
| \ref group__util_library | `<pantheios/pantheios.h>` | Utility helpers |
| \ref group__frontend | `<pantheios/frontend.h>` | Front-end contract (`pantheios_fe_*`) |
| \ref group__backend | `<pantheios/backend.h>` | Back-end contract (`pantheios_be_*`) |
| \ref group__frontend__stock_frontends | `<pantheios/frontends/stock.h>` | Stock front-ends (simple, N, null, …) |
| \ref group__backend__stock_backends | `<pantheios/backends/bec.file.h>` | Stock back-ends (file, console, syslog, …) |
| \ref group__init_codes | `<pantheios/init_codes.h>` | Low-level initialisation result codes |
| \ref group__assertion | `<pantheios/assert.h>` | Assertion macros |
| \ref group__tracing | `<pantheios/trace.h>` | File/line tracing macros |


## Related projects

* [b64](https://github.com/synesissoftware/b64) — optional Base-64 inserter support
* [Pantheios.Extras.Main](https://github.com/synesissoftware/Pantheios.Extras.Main) — separate project; C `main()` initialisation
* [shwild](https://github.com/synesissoftware/shwild)
* [STLSoft](https://github.com/synesissoftware/STLSoft/) — required dependency
* [woad](https://github.com/synesissoftware/woad) — required, for ANSI console colour
* [xTests](https://github.com/synesissoftware/xTests) — test harness


<!-- ########################### end of file ########################### -->
