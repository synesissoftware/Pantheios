
add_executable(example.cpp.backends.file
	main.cpp
)

target_link_Pantheios_core(example.cpp.backends.file)

target_link_libraries(example.cpp.backends.file
	PRIVATE
		Pantheios.be.file
		Pantheios.bec.file
)

target_link_libraries(example.cpp.backends.file
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.backends.file)

target_link_STLSoft(example.cpp.backends.file)

define_target_compile_options(example.cpp.backends.file)

add_subdirectory(callback)
add_subdirectory(lrsplit)


# ############################## end of file ############################# #

