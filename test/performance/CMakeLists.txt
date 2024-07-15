
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.performance.inserters.m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.performance.inserters.w2m)
	add_subdirectory(test.performance.util.date_elements_to_string)
endif()


# ############################## end of file ############################# #

