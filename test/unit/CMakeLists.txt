
add_subdirectory(inserters)

add_subdirectory(test.unit.be.N)
add_subdirectory(test.unit.be.N.filtering)
add_subdirectory(test.unit.be.fail)
add_subdirectory(test.unit.be.lrsplit)
add_subdirectory(test.unit.bec.AnsiConsole)
# Skipped on MinGW until xTests string-equality helpers honour post-include
# c_str_data_a shims under GCC two-phase lookup (see TODO.md in Pantheios
# and xTests).
if(_BUILD_AS_WIN32 AND NOT MINGW)

	add_subdirectory(test.unit.bec.COMErrorObject)
endif()
add_subdirectory(test.unit.bec.fail)
add_subdirectory(test.unit.bec.file)
add_subdirectory(test.unit.bec.fprintf)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.unit.bec.speech)
endif(_BUILD_AS_WIN32)
if(_BUILD_AS_UNIX)

	add_subdirectory(test.unit.bec.syslog)
endif(_BUILD_AS_UNIX)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.unit.bec.WindowsConsole)
	add_subdirectory(test.unit.bec.WindowsSyslog)
endif(_BUILD_AS_WIN32)
add_subdirectory(test.unit.fe.N)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.unit.fe.WindowsRegistry)
endif(_BUILD_AS_WIN32)
add_subdirectory(test.unit.fe.all)
add_subdirectory(test.unit.fe.fail)
add_subdirectory(test.unit.fe.null)
add_subdirectory(test.unit.fe.simple)
add_subdirectory(test.unit.getversion)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.unit.inserters.windows.sc)
endif(_BUILD_AS_WIN32)
#[====[
add_subdirectory(test.unit.levels.2)
#]====]
add_subdirectory(test.unit.levels.dynamic_initialisation)
add_subdirectory(test.unit.levels.values)
add_subdirectory(test.unit.util.date_elements_to_string)
if(shwild_FOUND)

	add_subdirectory(test.unit.util.getcurrenttime)
endif(shwild_FOUND)
add_subdirectory(test.unit.util.gethostname)
if(shwild_FOUND)

	add_subdirectory(test.unit.util.onbailout)
endif(shwild_FOUND)
add_subdirectory(test.unit.util.parse_args)
add_subdirectory(test.unit.util.snprintf)
add_subdirectory(test.unit.util.strnlen)


# ############################## end of file ############################# #

