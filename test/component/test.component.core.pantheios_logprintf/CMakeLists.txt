
add_executable(test.component.core.pantheios_logprintf
	test.component.core.pantheios_logprintf.cpp
)

target_link_Pantheios_core(test.component.core.pantheios_logprintf)

target_link_libraries(test.component.core.pantheios_logprintf
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.core.pantheios_logprintf
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.core.pantheios_logprintf)

target_link_STLSoft(test.component.core.pantheios_logprintf)

if(shwild_FOUND)

	target_link_shwild(test.component.core.pantheios_logprintf)
endif(shwild_FOUND)

target_link_xTests(test.component.core.pantheios_logprintf)

define_target_compile_options(test.component.core.pantheios_logprintf)


# ############################## end of file ############################# #

