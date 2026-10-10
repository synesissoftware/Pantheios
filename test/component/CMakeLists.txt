
add_subdirectory(core)
add_subdirectory(custom_severity)
add_subdirectory(details)
add_subdirectory(inserters)
add_subdirectory(log)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(trace)
endif()

add_subdirectory(test.component.be.file.threading)
add_subdirectory(test.component.bec.fprintf)


# ############################## end of file ############################# #
