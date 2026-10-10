
add_subdirectory(be.file)
add_subdirectory(bec.fprintf)
add_subdirectory(core)
add_subdirectory(custom_severity)
add_subdirectory(details)
add_subdirectory(inserters)
add_subdirectory(log)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(trace)
endif()


# ############################## end of file ############################# #
