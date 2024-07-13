
add_subdirectory(test.unit.inserter.integer)
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.unit.inserter.m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
add_subdirectory(test.unit.inserter.stream_character)
add_subdirectory(test.unit.inserter.w2m)


# ############################## end of file ############################# #

