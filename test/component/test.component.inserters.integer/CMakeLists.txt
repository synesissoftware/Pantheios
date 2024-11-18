
add_executable(test.component.inserters.integer
	test.component.inserters.integer.cpp
)

target_link_Pantheios_core(test.component.inserters.integer)

target_link_libraries(test.component.inserters.integer
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.integer
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.integer)

target_link_STLSoft(test.component.inserters.integer)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.integer)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.integer)

define_target_compile_options(test.component.inserters.integer)


# ############################## end of file ############################# #

