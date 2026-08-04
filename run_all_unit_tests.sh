#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
[[ -n "$MSYSTEM" ]] && DefaultMakeCmd=mingw32-make.exe || DefaultMakeCmd=make
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-$DefaultMakeCmd}}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

ListOnly=0
RunMake=1
UnitOnly=0
ComponentOnly=0
Verbosity=${XTESTS_VERBOSITY:-${TEST_VERBOSITY:-3}}


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --list-only|-l)

      ListOnly=1
      ;;
    --no-make|-M)

      RunMake=0
      ;;
    --unit-only)

      UnitOnly=1
      ;;
    --component-only)

      ComponentOnly=1
      ;;
    --verbosity)

      shift
      Verbosity=$1
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Runs all (matching) unit-test and/or component-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -l
    --list-only
        lists the target programs but does not execute them

    -M
    --no-make
        does not execute CMake and make before running tests

    --unit-only
        runs only unit-test programs (test.unit.* / test_unit*)

    --component-only
        runs only component-test programs (test.component.* / test_component*)

    --verbosity <verbosity>
        specifies an explicit verbosity for the unit-test(s)


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

if [ $UnitOnly -ne 0 ] && [ $ComponentOnly -ne 0 ]; then

  >&2 echo "$ScriptPath: --unit-only and --component-only are mutually exclusive"

  exit 1
fi


# ##########################################################
# main()

status=0

if [ $UnitOnly -ne 0 ]; then

  TestKindDescription='unit test'
elif [ $ComponentOnly -ne 0 ]; then

  TestKindDescription='component test'
else

  TestKindDescription='component and unit test'
fi

if [ $RunMake -ne 0 ]; then

  if [ $ListOnly -eq 0 ]; then

    echo "Executing build (via command \`$MakeCmd\`) and then running all ${ProjectName} ${TestKindDescription} programs"

    mkdir -p $CMakeDir || exit 1

    cd $CMakeDir

    $MakeCmd
    status=$?

    cd ->/dev/null
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"

    exit 1
  fi
fi

if [ $status -eq 0 ]; then

  if [ $ListOnly -ne 0 ]; then

    echo "Listing all ${ProjectName} ${TestKindDescription} programs"
  else

    echo "Running all ${ProjectName} ${TestKindDescription} programs"
  fi

  if [ $UnitOnly -ne 0 ]; then

    find_name_expr=( \( -name 'test_unit*' -o -name 'test.unit.*' \) )
  elif [ $ComponentOnly -ne 0 ]; then

    find_name_expr=( \( -name 'test_component*' -o -name 'test.component.*' \) )
  else

    find_name_expr=( \( -name 'test_unit*' -o -name 'test.unit.*' -o -name 'test_component*' -o -name 'test.component.*' \) )
  fi

  for f in $(find "$CMakeDir" -type f "${find_name_expr[@]}" -exec test -x {} \; -print | sort)
  do

    if [ $ListOnly -ne 0 ]; then

      echo "would execute $f:"

      continue
    fi

    if [ $Verbosity -ge 3 ]; then

      echo
    fi
    if [ $Verbosity -ge 2 ]; then

      echo "executing $f:"
    fi

    if $f --verbosity=$Verbosity; then

      :
    else

      status=$?

      break 1
    fi
  done
fi

exit $status


# ############################## end of file ############################# #
