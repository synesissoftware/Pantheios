#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do
    case $1 in
        --help)
            cat << EOF
Pantheios is an efficient, flexible, and robust C/C++ diagnostic logging library
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
Executes CMake-generated artefacts to clean project

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

if [ ! -d "$CMakePath" ]; then

    >&2 echo "$ScriptPath: CMake build directory '$CMakePath' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

    exit 1
else

    cd $CMakePath

    if [ ! -f "$CMakePath/Makefile" ]; then

        >&2 echo "$ScriptPath: CMake build directory '$CMakePath' does not contain expected file 'Makefile', so a clean cannot be performed. It is recommended that you remove all CMake artefacts using script 'remove_cmake_artefacts.sh' followed by regeneration via 'prepare_cmake.sh'"

        exit 1
    else

        echo "Cleaning build (via command \`make clean\`)"

        make clean

        cd ->/dev/null
    fi
fi


# ############################## end of file ############################# #

