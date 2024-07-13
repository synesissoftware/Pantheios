
add_subdirectory(example.cpp.inserter.args)
add_subdirectory(example.cpp.inserter.b)
if(b64_FOUND)

	add_subdirectory(example.cpp.inserter.b64)
endif(b64_FOUND)
add_subdirectory(example.cpp.inserter.blob)
#[====[
add_subdirectory(example.cpp.inserter.character)
#]====]
add_subdirectory(example.cpp.inserter.hex_ptr)
add_subdirectory(example.cpp.inserter.hostid)
add_subdirectory(example.cpp.inserter.i)
add_subdirectory(example.cpp.inserter.integer)
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(example.cpp.inserter.m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
add_subdirectory(example.cpp.inserter.p)
add_subdirectory(example.cpp.inserter.pointer)
add_subdirectory(example.cpp.inserter.processid)
add_subdirectory(example.cpp.inserter.real)
add_subdirectory(example.cpp.inserter.threadid)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(example.cpp.inserter.w2m)
endif()
add_subdirectory(example.cpp.inserter.xi)
add_subdirectory(example.cpp.inserter.xp)


# ############################## end of file ############################# #

