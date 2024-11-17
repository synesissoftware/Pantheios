
add_executable(test.component.trace.1
	test.component.trace.1.cpp
)

target_link_Pantheios_core(test.component.trace.1)

target_link_libraries(test.component.trace.1
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.trace.1
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.trace.1)

target_link_STLSoft(test.component.trace.1)

if(shwild_FOUND)

	target_link_shwild(test.component.trace.1)
endif(shwild_FOUND)

target_link_xTests(test.component.trace.1)

define_target_compile_options(test.component.trace.1)


# ############################## end of file ############################# #

