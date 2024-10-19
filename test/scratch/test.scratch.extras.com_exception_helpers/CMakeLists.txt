
add_executable(test.scratch.extras.com_exception_helpers
	test.scratch.extras.com_exception_helpers.cpp
)

target_link_Pantheios_core(test.scratch.extras.com_exception_helpers)

target_link_libraries(test.scratch.extras.com_exception_helpers
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.extras.com_exception_helpers
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.extras.com_exception_helpers)

define_target_compile_options(test.scratch.extras.com_exception_helpers)


# ############################## end of file ############################# #

