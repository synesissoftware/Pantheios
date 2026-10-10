
add_executable(test.scratch.extras.com_exception_helpers
	main.cpp
)

target_link_Pantheios_core(test.scratch.extras.com_exception_helpers)

target_link_libraries(test.scratch.extras.com_exception_helpers
	PRIVATE
		Pantheios.be.AnsiConsole
		Pantheios.bec.AnsiConsole
)

target_link_libraries(test.scratch.extras.com_exception_helpers
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.extras.com_exception_helpers)

define_target_compile_options(test.scratch.extras.com_exception_helpers)


# ############################## end of file ############################# #

