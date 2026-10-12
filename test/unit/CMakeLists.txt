
add_subdirectory(be.N)
add_subdirectory(be.fail)
add_subdirectory(be.lrsplit)
add_subdirectory(bec.AnsiConsole)
# Skipped on MinGW until xTests string-equality helpers honour post-include
# c_str_data_a shims under GCC two-phase lookup (see TODO.md in Pantheios
# and xTests).
if(_BUILD_AS_WIN32 AND NOT MINGW)

	add_subdirectory(bec.COMErrorObject)
endif()
add_subdirectory(bec.fail)
add_subdirectory(bec.file)
add_subdirectory(bec.fprintf)
if(_BUILD_AS_WIN32)

	add_subdirectory(bec.speech)
endif(_BUILD_AS_WIN32)
if(_BUILD_AS_UNIX)

	add_subdirectory(bec.syslog)
endif(_BUILD_AS_UNIX)
if(_BUILD_AS_WIN32)

	add_subdirectory(bec.WindowsConsole)
	add_subdirectory(bec.WindowsSyslog)
endif(_BUILD_AS_WIN32)
add_subdirectory(fe.N)
if(_BUILD_AS_WIN32)

	add_subdirectory(fe.WindowsRegistry)
endif(_BUILD_AS_WIN32)
add_subdirectory(fe.all)
add_subdirectory(fe.fail)
add_subdirectory(fe.null)
add_subdirectory(fe.simple)

add_subdirectory(getversion)
add_subdirectory(inserters)
add_subdirectory(levels)
add_subdirectory(util)


# ############################## end of file ############################# #
