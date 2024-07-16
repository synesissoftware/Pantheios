#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=$Dir/_build

IgnoreRemainingFlagsAndOptions=0
Targets=()


# ##########################################################
# functions

function join_by { local IFS="$1"; shift; echo "$*"; }


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  if [ $IgnoreRemainingFlagsAndOptions -ne 0 ]; then

    Targets+=($1)

    shift

    continue
  else

    if [ ! ${1:0:1} = '-' ]; then

      Targets+=($1)

      shift

      continue
    fi
  fi

  case $1 in
    --)

      IgnoreRemainingFlagsAndOptions=1
      ;;
    --help)

      cat << EOF
Pantheios is an efficient, flexible, and robust C/C++ diagnostic logging library
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
Executes CMake-generated artefacts to (re)build project

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:


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

if [ ! -d "$CMakeDir" ]; then

  >&2 echo "$ScriptPath: CMake build directory '$CMakeDir' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

  exit 1
else

  cd $CMakeDir

  if [ ! -f "$CMakeDir/Makefile" ]; then

    >&2 echo "$ScriptPath: CMake build directory '$CMakeDir' does not contain expected file 'Makefile', so a clean cannot be performed. It is recommended that you remove all CMake artefacts using script 'remove_cmake_artefacts.sh' followed by regeneration via 'prepare_cmake.sh'"

    exit 1
  else

    if [ -z "$Targets" ]; then

      echo "Executing build (via command \`make\`)"
    else

      echo "Executing build (via command \`make\`) with specific target(s) $(join_by , "${Targets[@]}")"
    fi

    make ${Targets[*]}
    status=$?

    cd ->/dev/null

    exit $status
  fi
fi


# ############################## end of file ############################# #

