
add_executable(test.component.core.pantheios_logputs
	test.component.core.pantheios_logputs.cpp
)

target_link_Pantheios_core(test.component.core.pantheios_logputs)

target_link_libraries(test.component.core.pantheios_logputs
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.core.pantheios_logputs
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.core.pantheios_logputs)

target_link_STLSoft(test.component.core.pantheios_logputs)

if(shwild_FOUND)

	target_link_shwild(test.component.core.pantheios_logputs)
endif(shwild_FOUND)

target_link_xTests(test.component.core.pantheios_logputs)

define_target_compile_options(test.component.core.pantheios_logputs)


# ############################## end of file ############################# #

