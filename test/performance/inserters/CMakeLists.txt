
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(w2m)
endif()


# ############################## end of file ############################# #
