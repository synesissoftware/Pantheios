
add_executable(test.scratch.api
	test.scratch.api.cpp
)

target_link_Pantheios_core(test.scratch.api)

target_link_libraries(test.scratch.api
	PRIVATE
		Pantheios.be.lrsplit
		Pantheios.bec.fprintf
		Pantheios.bec.null
		Pantheios.bel.fprintf
		Pantheios.ber.null
)

target_link_libraries(test.scratch.api
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.api)

target_link_STLSoft(test.scratch.api)

define_target_compile_options(test.scratch.api)


# ############################## end of file ############################# #

