
add_subdirectory(inserters)

add_subdirectory(test.unit.be.N)
add_subdirectory(test.unit.be.N.filtering)
if (WIN32)

    add_subdirectory(test.unit.be.WindowsSyslog)
endif (WIN32)
add_subdirectory(test.unit.be.fail)
add_subdirectory(test.unit.be.lrsplit)
if (WIN32)

    add_subdirectory(test.unit.bec.COMErrorObject)
endif (WIN32)
add_subdirectory(test.unit.bec.fail)
add_subdirectory(test.unit.bec.file)
add_subdirectory(test.unit.bec.fprintf)
add_subdirectory(test.unit.fe.N)
if (WIN32)

    add_subdirectory(test.unit.fe.WindowsRegistry)
endif (WIN32)
add_subdirectory(test.unit.fe.all)
add_subdirectory(test.unit.fe.fail)
add_subdirectory(test.unit.fe.null)
add_subdirectory(test.unit.fe.simple)
add_subdirectory(test.unit.getversion)
add_subdirectory(test.unit.inserters.windows.sc)
add_subdirectory(test.unit.levels.2)
add_subdirectory(test.unit.levels.dynamic_initialisation)
add_subdirectory(test.unit.levels.values)
add_subdirectory(test.unit.util.date_elements_to_string)
add_subdirectory(test.unit.util.getcurrenttime)
add_subdirectory(test.unit.util.gethostname)
add_subdirectory(test.unit.util.onbailout)
add_subdirectory(test.unit.util.snprintf)
add_subdirectory(test.unit.util.strnlen)


# ############################## end of file ############################# #

