
add_executable(test.scratch.trace
	test.scratch.trace.cpp
)

target_link_Pantheios_core(test.scratch.trace)

target_link_libraries(test.scratch.trace
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.trace
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.trace)

target_link_STLSoft(test.scratch.trace)

define_target_compile_options(test.scratch.trace)


# ############################## end of file ############################# #

