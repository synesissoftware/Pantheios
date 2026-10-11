
add_subdirectory(args)
add_subdirectory(b)
if(b64_FOUND)

	add_subdirectory(b64)
endif(b64_FOUND)
add_subdirectory(blob)
#[====[
add_subdirectory(character)
#]====]
add_subdirectory(hex_ptr)
add_subdirectory(hostid)
add_subdirectory(i)
add_subdirectory(integer)
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
add_subdirectory(p)
add_subdirectory(pointer)
add_subdirectory(processid)
add_subdirectory(real)
add_subdirectory(threadid)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(w2m)
endif()
add_subdirectory(xi)
add_subdirectory(xp)


# ############################## end of file ############################# #
