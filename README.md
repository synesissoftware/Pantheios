# Pantheios <!-- omit in toc -->

The C/C++ Diagnostic Logging Sweetspot


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/Pantheios.svg)](https://github.com/synesissoftware/Pantheios/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/Pantheios)](https://github.com/synesissoftware/Pantheios/commits/master)
[![CMake on multiple platforms](https://github.com/synesissoftware/Pantheios/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/Pantheios/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
  - [Architecture](#architecture)
  - [Application Layer and inserters](#application-layer-and-inserters)
  - [Stock front-ends and back-ends](#stock-front-ends-and-back-ends)
- [Examples](#examples)
- [Getting started](#getting-started)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**Pantheios** is an efficient, flexible, and robust C/C++ diagnostic logging **API** library. It is designed to give application code a type-safe, high-performance way to emit diagnostic statements, while leaving *where* and *whether* those statements are emitted to link-time **front-end** and **back-end** choices.

In particular:

* It separates **what** you log (application code) from **how** output is filtered and transported (front-ends and back-ends);
* Statement arguments are converted lazily — inserters do work only if the front-end accepts the severity;
* Stock front-ends and back-ends are provided for common cases, and custom back-ends can wrap richer logging libraries (examples include **log4cxx** and **log4cplus**);
* C and C++ APIs are both supported.

**Pure Pantheios** is the Application Layer plus the Core. Stock front-ends and back-ends are convenient, but not required for that core contract.

Further reading: [http://pantheios.org/](http://pantheios.org/), [FAQ.md](./FAQ.md).


## Installation

Detailed instructions — via **CMake**, via bundling, via custom makefile parameters — are provided in the accompanying [INSTALL.md](./INSTALL.md) file.

In short: install [**STLSoft** 1.11](https://github.com/synesissoftware/STLSoft) (and optionally [**b64**](https://github.com/synesissoftware/b64) and [**shwild**](https://github.com/synesissoftware/shwild)) via **CMake**, clone **Pantheios**, run **prepare_cmake.sh**, build, then `cmake --install`.


## Components


### Architecture

| Layer | Responsibility |
| ----- | -------------- |
| **Application Layer** | What application code uses to write statements (`pantheios::log` / `log_*`, C `pantheios_logputs` / `pantheios_logprintf`) |
| **Core** | Ties the layers together; C++ auto-initialises via Schwarz counters in **pantheios/pantheios.hpp** (unless `PANTHEIOS_NO_AUTO_INIT`); C must call `pantheios_init()` |
| **Front-end** | Severity filtering and process identity (`pantheios_fe_init`, `pantheios_fe_isSeverityLogged`, …) |
| **Back-end** | Emits statements accepted by the front-end (`pantheios_be_init`, `pantheios_be_logEntry`, …) |

Apart from initialising the Core (automatic in C++ compilation units), application code does not normally interact with the Core directly. Front-end and back-end are selected at **link-time**, so initialisation can complete before `main()` and any code in the process can log.


### Application Layer and inserters

C++ application code typically includes **pantheios/pantheios.hpp** and logs with `pantheios::log_*` helpers or `pantheios::log(severity, …)`.

Statement arguments are converted lazily — inserters do work only if the front-end accepts the severity.

Common inserters include:

* `pantheios::integer`, `pantheios::real`, `pantheios::pointer`, `pantheios::hex_ptr`;
* `pantheios::character`, `pantheios::boolean`;
* `pantheios::args`, `pantheios::blob`, `pantheios::b64` (optional; requires **b64**);
* `pantheios::processId`, `pantheios::threadId`, `pantheios::hostId`;

and others under **include/pantheios/inserters/**.


### Stock front-ends and back-ends

Stock **front-ends** include `fe.simple`, `fe.all`, `fe.null`, `fe.fail`, `fe.N`, and `fe.WindowsRegistry` (plus `*.WithCallback` variants). Process identity for stock front-ends is supplied by defining `PANTHEIOS_FE_PROCESS_IDENTITY`.

Stock **back-ends** include `be.fprintf`, `be.file`, `be.null`, `be.fail`, `be.N`, `be.lrsplit`, `be.syslog`, `be.AnsiConsole`, and Windows-oriented backends such as `be.WindowsConsole`, `be.WindowsDebugger`, `be.WindowsEventLog`, `be.WindowsSyslog`, `be.COMErrorObject`, `be.speech`, and others. ACE-oriented stock backends exist in the tree; full **CMake** optional discovery for **ACE** is not yet complete.


## Examples

Examples are provided in the `examples` directory (C under `examples/c/`, C++ under `examples/cpp/`), including:

* `example.c.101`, `example.c.core.pantheios_logprintf`, `example.c.N`;
* `example.cpp.misc.101`;
* `example.cpp.linking.implicit_link_1`;
* `example.cpp.frontends.custom`;
* `example.cpp.backends.file`, `example.cpp.backends.callback`;
* `example.cpp.inserters.integer`, `example.cpp.inserters.b64`, `example.cpp.inserters.args`;
* `example.cpp.custom.wrap_log4cxx`, `example.cpp.custom.wrap_log4cplus`;
* `example.cpp.tracing.standard`;
* `example.cpp.contract.PANTHEIOS_ASSERT`;


## Getting started

A minimal C++ program using implicit linking of the Core, `fe.simple`, and `be.fprintf`:

```cpp
#include <pantheios/pantheios.hpp>
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.simple.h>
#include <pantheios/implicit_link/be.fprintf.h>

#include <stdlib.h>

PANTHEIOS_EXTERN const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] =
    PANTHEIOS_LITERAL_STRING("hello.pantheios");

int main()
{
    pantheios::log_INFORMATIONAL(PANTHEIOS_LITERAL_STRING("Hello!"));

    return EXIT_SUCCESS;
}
```

See **examples/cpp/linking/example.cpp.linking.implicit_link_1** for the canonical form of this pattern. C programs must call `pantheios_init()` (and check the return) before logging — see **examples/c/example.c.101**.


## Project Information


### Where to get help

* [GitHub Page](https://github.com/synesissoftware/Pantheios)
* [GitHub Issues](https://github.com/synesissoftware/Pantheios/issues)
* [FAQ.md](./FAQ.md)
* [http://pantheios.org/](http://pantheios.org/)


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/Pantheios.


### Dependencies

| Dependency | Role | Required? |
| ---------- | ---- | --------- |
| [**STLSoft**](https://github.com/synesissoftware/STLSoft) 1.11 (1.11.1-alpha25 or later) | Implementation and interface support | ✅ Always |
| [**b64**](https://github.com/synesissoftware/b64) | `pantheios::b64` inserter | ⚪ Optional (`PANTHEIOS_NO_B64` when absent) |
| [**shwild**](https://github.com/synesissoftware/shwild) | Pattern matching in tests | ⚪ Optional; tests only |
| [**xTests**](https://github.com/synesissoftware/xTests) (≥ 0.25.4) | Unit / component tests | ⚪ Tests only (`BUILD_TESTING`) |
| **ACE** | Stock `be.ACE` / related backends | ⚪ Optional; CMake wiring incomplete |


### Related projects

Projects closely related to **Pantheios** include:

* [**b64**](https://github.com/synesissoftware/b64) — optional Base-64 inserter support;
* [**Pantheios.Extras.DiagUtil**](https://github.com/synesissoftware/Pantheios.Extras.DiagUtil);
* [**Pantheios.Extras.Main**](https://github.com/synesissoftware/Pantheios.Extras.Main);
* [**Pantheios.Extras.xHelpers**](https://github.com/synesissoftware/Pantheios.Extras.xHelpers);
* [**shwild**](https://github.com/synesissoftware/shwild) — used in testing;
* [**STLSoft**](https://github.com/synesissoftware/STLSoft) — required foundation;
* [**xTests**](https://github.com/synesissoftware/xTests) — used in testing;


### License

**Pantheios** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
