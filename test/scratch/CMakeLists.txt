
add_subdirectory(I18N)
if(_BUILD_AS_WIN32)

	add_subdirectory(WideString)
endif(_BUILD_AS_WIN32)
#[====[
add_subdirectory(api)
#]====]
if(HAS_ACE)

	add_subdirectory(test.scratch.be.ACE)
endif(HAS_ACE)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.scratch.be.N)
endif()
add_subdirectory(test.scratch.be.N.fail)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.scratch.be.N.with.custom.fe)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.be.WindowsSyslog)
	add_subdirectory(test.scratch.be.WindowsSyslog.WithCallback)
endif(_BUILD_AS_WIN32)
add_subdirectory(test.scratch.be.file)
#[====[
add_subdirectory(test.scratch.be.file.rolling)
#]====]
if(_BUILD_AS_WIN32)

	#[====[
	# Needs UNIXem; sources pull unixem headers unconditionally.
	add_subdirectory(test.scratch.be.pantheios.COM)
	#]====]
	add_subdirectory(test.scratch.be.speech)
endif(_BUILD_AS_WIN32)
if(_BUILD_AS_UNIX)

	add_subdirectory(test.scratch.be.syslog)
	add_subdirectory(test.scratch.be.syslog.WithCallback)
endif(_BUILD_AS_UNIX)

add_subdirectory(test.scratch.bec.AnsiConsole)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.bec.WindowsConsoleCallback)
	add_subdirectory(test.scratch.bec.WindowsMessageBox)
endif(_BUILD_AS_WIN32)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(c_api)
endif()
#[====[
if(_BUILD_AS_WIN32)

	add_subdirectory(extras)
endif(_BUILD_AS_WIN32)
#]====]
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(fe)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.fe.WindowsRegistry)
	add_subdirectory(test.scratch.fe.WindowsRegistry.controller)
endif(_BUILD_AS_WIN32)
add_subdirectory(test.scratch.fe.simple.WithCallback)
#[====[
# Needs UNIXem (pseudo-UNIX on Windows); not valid under _BUILD_AS_WIN32.
if(_BUILD_AS_WIN32)

	add_subdirectory(pseudoUNIX)
endif(_BUILD_AS_WIN32)
#]====]
add_subdirectory(showPlus)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(trace)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(tstring)
endif(_BUILD_AS_WIN32)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(util)
endif()

add_subdirectory(versions)


# ############################## end of file ############################# #
