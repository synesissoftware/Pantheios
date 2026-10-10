
add_subdirectory(integer)
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
add_subdirectory(stream_character)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(w2m)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(windows)
endif(_BUILD_AS_WIN32)


# ############################## end of file ############################# #
