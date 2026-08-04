
add_executable(test.scratch.bec.AnsiConsole
	test.scratch.bec.AnsiConsole.c
)

target_link_Pantheios_core(test.scratch.bec.AnsiConsole)

target_link_libraries(test.scratch.bec.AnsiConsole
	PRIVATE
		Pantheios.be.AnsiConsole
		Pantheios.bec.AnsiConsole
)

target_link_libraries(test.scratch.bec.AnsiConsole
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.scratch.bec.AnsiConsole)

target_link_STLSoft(test.scratch.bec.AnsiConsole)

target_link_xTests(test.scratch.bec.AnsiConsole)

define_target_compile_options(test.scratch.bec.AnsiConsole)


# ############################## end of file ############################# #
