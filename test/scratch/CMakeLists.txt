

add_subdirectory(libver)
add_subdirectory(test.scratch.I18N)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.WideString)
endif(_BUILD_AS_WIN32)
#[====[
add_subdirectory(test.scratch.api)
#]====]
#[====[
add_subdirectory(test.scratch.be.ACE)
#]====]
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

	add_subdirectory(test.scratch.be.pantheios.COM)
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

	add_subdirectory(test.scratch.c_api)
endif()
#[====[
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.extras.com.invoke_nothrow_method)
	add_subdirectory(test.scratch.extras.com_exception_helpers)
endif(_BUILD_AS_WIN32)
#]====]
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.scratch.fe)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.fe.WindowsRegistry)
	add_subdirectory(test.scratch.fe.WindowsRegistry.controller)
endif(_BUILD_AS_WIN32)
add_subdirectory(test.scratch.fe.simple.WithCallback)
#[====[
add_subdirectory(test.scratch.implicit_link)
#]====]
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.pseudoUNIX)
endif(_BUILD_AS_WIN32)
add_subdirectory(test.scratch.showPlus.integer)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.scratch.trace)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.tstring)
endif(_BUILD_AS_WIN32)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.scratch.util.onbailout)
endif()


# ############################## end of file ############################# #

