
add_executable(example.cpp.frontends.custom
	example.cpp.frontends.custom.cpp
)

target_link_Pantheios_core(example.cpp.frontends.custom)

target_link_libraries(example.cpp.frontends.custom
	PRIVATE
		Pantheios.be.AnsiConsole
		Pantheios.bec.AnsiConsole
)

target_link_Pantheios_util(example.cpp.frontends.custom)

target_link_STLSoft(example.cpp.frontends.custom)

define_target_compile_options(example.cpp.frontends.custom)


# ############################## end of file ############################# #

