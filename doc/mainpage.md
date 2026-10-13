# Pantheios {#mainpage}

**Pantheios** is an efficient, flexible, and robust C/C++ diagnostic logging
**API** library. Application code emits type-safe, high-performance
diagnostic statements; *where* and *whether* those statements are emitted is
chosen at link time via a **front-end** and a **back-end**.


## Components

| Module | Header | Summary |
| ------ | ------ | ------- |
| Core / Application Layer | `<pantheios/pantheios.h>` | Core logging API, application-layer calls, and utilities |
| \ref group__frontend | `<pantheios/frontend.h>` | Front-end contract (`pantheios_fe_*`) |
| \ref group__backend | `<pantheios/backend.h>` | Back-end contract (`pantheios_be_*`) |
| \ref group__frontend__stock_frontends | `<pantheios/frontends/stock.h>` | Stock front-ends (simple, N, null, …) |
| \ref group__backend__stock_backends | `<pantheios/backends/bec.file.h>` | Stock back-ends (file, console, syslog, …) |
| \ref group__init_codes | `<pantheios/init_codes.h>` | Low-level initialisation result codes |
| \ref group__assertion | `<pantheios/assert.h>` | Assertion macros |
| \ref group__tracing | `<pantheios/trace.h>` | File/line tracing macros |


## Quick start

```c
#include <pantheios/pantheios.h>

int main()
{
    pantheios_log_NOTICE("application starting");

    return 0;
}
```

Link a stock (or custom) front-end and back-end with the core. Consumer
**CMake** projects may use `find_package(Pantheios)` and link the exported
targets. See
[INSTALL.md](https://github.com/synesissoftware/Pantheios/blob/master/INSTALL.md)
for build and install instructions.


## Related projects

* [STLSoft](https://github.com/synesissoftware/STLSoft/) — required dependency
* [b64](https://github.com/synesissoftware/b64) — optional Base-64 inserter support
* [shwild](https://github.com/synesissoftware/shwild)
* [xTests](https://github.com/synesissoftware/xTests) — test harness


<!-- ########################### end of file ########################### -->
