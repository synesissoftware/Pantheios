
add_executable(test.scratch.c_api
	test.scratch.c_api.c
)

target_link_Pantheios_core(test.scratch.c_api)

target_link_libraries(test.scratch.c_api
	PRIVATE
		Pantheios.be.lrsplit
		Pantheios.bel.AnsiConsole
		Pantheios.ber.null
		Pantheios.bec.AnsiConsole
		Pantheios.bec.null
)

target_link_libraries(test.scratch.c_api
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.c_api)

target_link_STLSoft(test.scratch.c_api)

define_target_compile_options(test.scratch.c_api)


# ############################## end of file ############################# #

