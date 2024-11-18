
add_executable(test.component.core.initialisation_sequence
	test.component.core.initialisation_sequence.c
)

target_link_Pantheios_core(test.component.core.initialisation_sequence)

target_link_libraries(test.component.core.initialisation_sequence
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.core.initialisation_sequence
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.core.initialisation_sequence)

target_link_STLSoft(test.component.core.initialisation_sequence)

if(shwild_FOUND)

	target_link_shwild(test.component.core.initialisation_sequence)
endif(shwild_FOUND)

target_link_xTests(test.component.core.initialisation_sequence)

define_target_compile_options(test.component.core.initialisation_sequence)


# ############################## end of file ############################# #

