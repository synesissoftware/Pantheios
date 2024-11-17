
add_executable(test.component.inserters.variant_bool
	test.component.inserters.variant_bool.cpp
)

target_link_Pantheios_core(test.component.inserters.variant_bool)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.inserters.variant_bool)

target_link_STLSoft(test.component.inserters.variant_bool)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.variant_bool)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.variant_bool)

define_target_compile_options(test.component.inserters.variant_bool)


# ############################## end of file ############################# #

