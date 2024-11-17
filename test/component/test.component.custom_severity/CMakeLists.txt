
add_executable(test.component.custom_severity
	test.component.custom_severity.cpp
)

target_link_Pantheios_core(test.component.custom_severity)

target_link_libraries(test.component.custom_severity
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.custom_severity
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.custom_severity)

target_link_STLSoft(test.component.custom_severity)

if(shwild_FOUND)

	target_link_shwild(test.component.custom_severity)
endif(shwild_FOUND)

target_link_xTests(test.component.custom_severity)

define_target_compile_options(test.component.custom_severity)


# ############################## end of file ############################# #

