
add_subdirectory(test.unit.inserter.integer)
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.unit.inserter.m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
add_subdirectory(test.unit.inserter.stream_character)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.unit.inserter.w2m)
endif()


# ############################## end of file ############################# #

