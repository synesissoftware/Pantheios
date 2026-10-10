
add_subdirectory(I18N)
if(_BUILD_AS_WIN32)

	add_subdirectory(WideString)
endif(_BUILD_AS_WIN32)
#[====[
add_subdirectory(api)
#]====]
if(HAS_ACE)

	add_subdirectory(be.ACE)
endif(HAS_ACE)
add_subdirectory(be.N)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.scratch.be.N.with.custom.fe)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(be.WindowsSyslog)
	add_subdirectory(be.WindowsSyslog.WithCallback)
endif(_BUILD_AS_WIN32)
add_subdirectory(be.file)
if(_BUILD_AS_WIN32)

	#[====[
	# Needs UNIXem; sources pull unixem headers unconditionally.
	add_subdirectory(be.pantheios.COM)
	#]====]
	add_subdirectory(be.speech)
endif(_BUILD_AS_WIN32)
if(_BUILD_AS_UNIX)

	add_subdirectory(be.syslog)
	add_subdirectory(be.syslog.WithCallback)
endif(_BUILD_AS_UNIX)

add_subdirectory(bec.AnsiConsole)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.bec.WindowsConsoleCallback)
	add_subdirectory(bec.WindowsMessageBox)
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

	add_subdirectory(fe.WindowsRegistry)
endif(_BUILD_AS_WIN32)
add_subdirectory(fe.simple.WithCallback)
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
