
add_subdirectory(args)
if(b64_FOUND)

	add_subdirectory(b64)
endif(b64_FOUND)
add_subdirectory(boolean)
add_subdirectory(hostid)
add_subdirectory(integer)
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
add_subdirectory(pad)
add_subdirectory(pointer)
add_subdirectory(processid)
add_subdirectory(real)
add_subdirectory(slice)
add_subdirectory(stream_character)
add_subdirectory(threadid)
if(_BUILD_AS_WIN32)

	add_subdirectory(variant_bool)
endif(_BUILD_AS_WIN32)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(w2m)
endif()
if(_BUILD_AS_WIN32)

	add_subdirectory(windows)
endif(_BUILD_AS_WIN32)


# ############################## end of file ############################# #
