#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
MakeCmd=${SIS_CMAKE_COMMAND:-make}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")


Configuration=Release
ExamplesDisabled=0
MSVC_MT=0
MinGW=0
NO_b64=0
NO_shwild=0
RunMake=0
STLSoftDirGiven=
TestingDisabled=0
VerboseMakefile=0
WideStrings=0


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -v|--cmake-verbose-makefile)

      VerboseMakefile=1
      ;;
    -d|--debug-configuration)

      Configuration=Debug
      ;;
    -E|--disable-examples)

      ExamplesDisabled=1
      ;;
    -T|--disable-testing)

      TestingDisabled=1
      ;;
    --mingw)

      MinGW=1
      ;;
    --msvc-mt)

      MSVC_MT=1
      ;;
    --no-b64)

      NO_b64=1
      ;;
    --no-shwild)

      NO_shwild=1
      ;;
    -m|--run-make)

      RunMake=1
      ;;
    -s|--stlsoft-root-dir)

      shift
      STLSoftDirGiven=$1
      ;;
    -w|--wide-strings)

      WideStrings=1
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Creates/reinitialises the CMake build script(s)

$ScriptPath [ ... flags/options ... ]

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

    --no-b64
        suppresses discovery of b64 package

    --no-shwild
        suppresses discovery of shwild package

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

EOF

            exit 0
            ;;
        *)

            >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

            exit 1
            ;;
    esac

    shift
done


# ##########################################################
# main()

mkdir -p $CMakeDir || exit 1

cd $CMakeDir

echo "Executing CMake for ${ProjectName} (in ${CMakeDir})"

if [ $ExamplesDisabled -eq 0 ]; then CMakeBuildExamplesFlag="ON" ; else CMakeBuildExamplesFlag="OFF" ; fi
if [ $MSVC_MT -eq 0 ]; then CMakeMsvcMtFlag="OFF" ; else CMakeMsvcMtFlag="ON" ; fi
if [ $NO_b64 -eq 0 ]; then CMakeNoB64="OFF" ; else CMakeNoB64="ON" ; fi
if [ $NO_shwild -eq 0 ]; then CMakeNoShwild="OFF" ; else CMakeNoShwild="ON" ; fi
if [ -z $STLSoftDirGiven ]; then CMakeSTLSoftVariable="" ; else CMakeSTLSoftVariable="-DSTLSOFT=$STLSoftDirGiven/" ; fi
if [ $TestingDisabled -eq 0 ]; then CMakeBuildTestingFlag="ON" ; else CMakeBuildTestingFlag="OFF" ; fi
if [ $VerboseMakefile -eq 0 ]; then CMakeVerboseMakefileFlag="OFF" ; else CMakeVerboseMakefileFlag="ON" ; fi
if [ $WideStrings -eq 0 ]; then CMakeWideStringVariable="" ; else CMakeWideStringVariable="-DPANTHEIOS_USE_WIDE_STRINGS:BOOL=ON" ; fi

if [ $MinGW -ne 0 ]; then

  cmake \
    $CMakeSTLSoftVariable \
    $CMakeWideStringVariable \
    -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
    -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
    -DCMAKE_BUILD_TYPE=$Configuration \
    -DNO_B64=$CMakeNoB64 \
    -DNO_SHWILD=$CMakeNoShwild \
    -G "MinGW Makefiles" \
    -S $Dir \
    -B $CMakeDir \
    || (cd ->/dev/null ; exit 1)
else

  cmake \
    $CMakeSTLSoftVariable \
    $CMakeWideStringVariable \
    -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
    -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
    -DCMAKE_BUILD_TYPE=$Configuration \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=$CMakeVerboseMakefileFlag \
    -DMSVC_USE_MT:BOOL=$CMakeMsvcMtFlag \
    -DNO_B64=$CMakeNoB64 \
    -DNO_SHWILD=$CMakeNoShwild \
    -S $Dir \
    -B $CMakeDir \
    || (cd ->/dev/null ; exit 1)
fi


status=0

if [ $RunMake -ne 0 ]; then

  echo "Executing build for ${ProjectName} (via command \`$MakeCmd\`)"

  $MakeCmd
  status=$?
fi

cd ->/dev/null

if [ $VerboseMakefile -ne 0 ]; then

  echo -e "contents of $CMakeDir:"
  ls -al $CMakeDir
fi

exit $status


# ############################## end of file ############################# #

