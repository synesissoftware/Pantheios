# pantheios - Install <!-- omit in toc -->

## Table of Contents <!-- omit in toc -->

- [Installing](#installing)
  - [Cloning project, installing via CMake](#cloning-project-installing-via-cmake)
  - [As downloaded archive(s), using environment variables](#as-downloaded-archives-using-environment-variables)
  - [Cloning project, using environment variables](#cloning-project-using-environment-variables)
- [Understanding the top-level project build scripts](#understanding-the-top-level-project-build-scripts)


## Installing

There are three options for installing **Pantheios**, depending on how you obtain it. The recommended way is to [clone and install via CMake](#cloning-project-installing-via-cmake).


### Cloning project, installing via CMake

0. First, ensure that [**STLSoft-1.11**](https://github.com/synesissoftware/STLSoft-1.11) and, optionally, [**b64**](https://github.com/synesissoftware/b64) and [**shwild**](https://github.com/synesissoftware/shwild), have been cloned and then built and installed via CMake, as per the instructions in those projects.


1. Clone **Pantheios** from GitHub, as in;

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ git clone -b master https://github.com/synesissoftware/Pantheios
```

2. "Prepare" the **CMake** build context:

When using **CMake**, a prepare-step is required. In order to assist with getting the correct incantations for CMake use, [a number of build scripts are provided](#understanding-the-top-level-project-build-scripts). (Look for the **.sh** files in the root directory of the project.)

If you're working on Linux and OSX, or using Git Bash (or similar) on Windows, then you can use the CMake driver script **prepare_cmake.sh** provided by the project, as follows:

```bash
$ cd ~/open-source/Pantheios
$ ./prepare_cmake.sh
```

---
**NOTE**

The **prepare_cmake.sh** script has a bunch of command-line flags/options to customise the compilation, which can be obtained by using the flag `--help`, which gives the following output in the current version:

```plaintext
Pantheios is an efficient, flexible, and robust C/C++ diagnostic logging library
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
Creates/reinitialises the CMake build script(s)

./prepare_cmake.sh [ ... flags/options ... ]

Flags/options:

    behaviour:

    -v
    --cmake-verbose-makefile
        configures CMake to run verbosely (by setting CMAKE_VERBOSE_MAKEFILE
        to be ON)

    -d
    --debug-configuration
        use Debug configuration (by setting CMAKE_BUILD_TYPE=Debug). Default
        is to use Release

    -E
    --disable-examples
        disables building of examples (by setting BUILD_EXAMPLES=OFF)

    -T
    --disable-testing
        disables building of tests (by setting BUILD_TESTING=OFF). With
        testing disabled, the dependency projects shwild and xTests are not
        required (and not searched)

    --mingw
        uses explicitly the "MinGW Makefiles" generator

    --msvc-mt
        when using Visual C++ (MSVC), the static runtime library will be
        selected; the default is the dynamic runtime library

    -m
    --run-make
        executes make after a successful running of CMake

    -s <dir>
    --stlsoft-root-dir <dir>
        specifies the STLSoft root-directory, which will be passed to CMake
        as the variable STLSOFT, and which will override the environment
        variable STLSOFT (if present)

    -w
    --wide-strings
        builds for wide-strings. Default is multibyte strings


    standard flags:

    --help
        displays this help and terminates
```

If you are using **MinGW**/**MinGW-64** on Windows, you should specify `--mingw`.

If you are using **Visual C++** (on Windows) and want to use static linking, specify `--msvc-mt`.

If you wish to prepare and build in one step, you should specify `-m` (=== `--run-make`).

If you don't want to build examples, you should specify `-E` (=== `--disable-examples`).

If you don't want to build tests, you should specify `-T (=== `--disable-tests`).

---

3. Install the **CMake** build artefacts such that they are available for use _and_ that **Pantheios** may be found by other **CMake**-based installations:

```bash
$ cd ~/open-source/Pantheios
$ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
```

### As downloaded archive(s), using environment variables

1. Download the latest distributions;

Obtain the latest releases of **Pantheios** and **STLSoft** from:
* [Pantheios GitHub project](https://github.com/synesissoftware/Pantheios/tags), e.g. [**Pantheios-1.0.1-beta222.zip**](https://github.com/synesissoftware/Pantheios/archive/refs/tags/1.0.1-beta222.zip);
* [STLSoft GitHub project](https://github.com/synesissoftware/STLSoft-1.11/tags), e.g. [**STLSoft-1.11-1.11.1-alpha25.zip**](https://github.com/synesissoftware/STLSoft-1.11/archive/refs/tags/1.11.1-alpha25.zip);


2. Unzip to directories of your choice, as in:

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ unzip Pantheios-1.0.1-beta222.zip
$ unzip STLSoft-1.11-1.11.1-alpha25.zip
```

3. Define an environment variable `STLSOFT`, whose value is the directory in which you unzipped it, e.g. `STLSOFT=~/open-source/STLSoft-1.11-1.11.1-alpha25`, and then specify `$(STLSOFT)/include` (**UNIX**) or `%STLSOFT%\include` (**Windows**) in your project files and makefiles;

4. Select and change to the appropriate build subdirectory under your **Pantheios** directory, e.g. **build/gcc48.unix**, and then execute make

```bash
$ cd Pantheios-1.0.1-beta222
$ cd build/gcc48.unix
$ make
```


### Cloning project, using environment variables

T.B.C.


----

## Understanding the top-level project build scripts

This project comes with a number of scripts useful for building with **CMake**, as follows:

| Script                    | Purpose |
| ------------------------- | ------- |
| **prepare_cmake.sh**          | Creates/reinitialises the **CMake** build script(s).<br/><br/>This is the primary script, and is used to generate all the **CMake** build artefacts. We recommend that you use the command  as follows:</br></br>&nbsp;&nbsp;&nbsp;&nbsp;`./prepare_cmake.sh -m -v`.<br/><br/>The flag `-m` executes a build upon successful generation completes, and the flag `-v` generates verbose makefile(s). Use `./prepare_cmake.sh --help` for further information. |
| **build_cmake.sh**            | Executes **CMake**-generated artefacts to (re)build project.<br/><br/>Performs a (re)build, meaningful only once `prepare_cmake.sh` has been run once to generate all the **CMake** build artefacts.<br/><br/>Use `./build_cmake.sh --help` for further information. |
| **clean_cmake.sh**            | Executes **CMake**-generated artefacts to clean project.<br/><br/>Performs a (re)build, meaningful only once `prepare_cmake.sh` has been run once to generate all the **CMake** build artefacts and a build has been run.<br/><br/>Use `./clean_cmake.sh --help` for further information. |
| **run_all_unit_tests.sh**     | Runs all (matching) unit-test programs.<br/><br/>Performs a build and then recursively runs and executes all (excutable programs) matching the shell patterns `test_*` and `test.*`.<br/><br/>Use `./run_all_unit_tests.sh --help` for further information. |
| **remove_cmake_artefacts.sh** | Removes all known **CMake** artefacts.<br/><br/>Removes all known **CMake** build artefacts from the build directory (currently hard-coded to `./_build`) to prepare for complete regeneration using `prepare_cmake.sh`.<br/><br/>Use `./remove_cmake_artefacts.sh --help` for further information. |


<!-- ########################### end of file ########################### -->
