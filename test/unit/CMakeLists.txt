
add_subdirectory(inserters)

add_subdirectory(test.unit.be.N)
add_subdirectory(test.unit.be.N.filtering)
add_subdirectory(test.unit.be.fail)
add_subdirectory(test.unit.be.lrsplit)
add_subdirectory(test.unit.bec.AnsiConsole)
if(WIN32)

	add_subdirectory(test.unit.bec.COMErrorObject)
endif(WIN32)
add_subdirectory(test.unit.bec.fail)
add_subdirectory(test.unit.bec.file)
add_subdirectory(test.unit.bec.fprintf)
if(WIN32)

	add_subdirectory(test.unit.bec.speech)
endif(WIN32)
if(UNIX)

	add_subdirectory(test.unit.bec.syslog)
endif(UNIX)
if(WIN32)

	add_subdirectory(test.unit.bec.WindowsConsole)
	add_subdirectory(test.unit.bec.WindowsSyslog)
endif(WIN32)
add_subdirectory(test.unit.fe.N)
if(WIN32)

	add_subdirectory(test.unit.fe.WindowsRegistry)
endif(WIN32)
add_subdirectory(test.unit.fe.all)
add_subdirectory(test.unit.fe.fail)
add_subdirectory(test.unit.fe.null)
add_subdirectory(test.unit.fe.simple)
add_subdirectory(test.unit.getversion)
if(WIN32)

	add_subdirectory(test.unit.inserters.windows.sc)
endif(WIN32)
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

