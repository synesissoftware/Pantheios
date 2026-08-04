
add_executable(test.component.details
	test.component.details.cpp
)

target_link_Pantheios_core(test.component.details)

target_link_libraries(test.component.details
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.details
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.details)

if(shwild_FOUND)

	target_link_shwild(test.component.details)
endif(shwild_FOUND)

target_link_STLSoft(test.component.details)

target_link_xTests(test.component.details)

define_target_compile_options(test.component.details)


# ############################## end of file ############################# #

