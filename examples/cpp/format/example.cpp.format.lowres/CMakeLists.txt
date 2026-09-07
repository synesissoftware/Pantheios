
add_executable(example.cpp.format.lowres
	example.cpp.format.lowres.cpp
)

target_link_Pantheios_core(example.cpp.format.lowres)

target_link_libraries(example.cpp.format.lowres
	PRIVATE
		Pantheios.be.AnsiConsole
		Pantheios.bec.AnsiConsole
)

target_link_libraries(example.cpp.format.lowres
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.format.lowres)

target_link_STLSoft(example.cpp.format.lowres)

define_target_compile_options(example.cpp.format.lowres)


# ############################## end of file ############################# #

