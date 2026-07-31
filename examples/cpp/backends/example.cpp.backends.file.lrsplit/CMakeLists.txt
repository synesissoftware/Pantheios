
add_executable(example.cpp.backends.file.lrsplit
	example.cpp.backends.file.lrsplit.cpp
)

target_link_Pantheios_core(example.cpp.backends.file.lrsplit)

target_link_libraries(example.cpp.backends.file.lrsplit
	PRIVATE
		Pantheios.be.file
		Pantheios.bec.file
		Pantheios.bel.file
		Pantheios.ber.file
)

target_link_libraries(example.cpp.backends.file.lrsplit
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.backends.file.lrsplit)

target_link_STLSoft(example.cpp.backends.file.lrsplit)

define_target_compile_options(example.cpp.backends.file.lrsplit)


# ############################## end of file ############################# #

