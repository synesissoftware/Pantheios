
add_executable(test.component.inserters.boolean
	test.component.inserters.boolean.cpp
)

target_link_Pantheios_core(test.component.inserters.boolean)

target_link_libraries(test.component.inserters.boolean
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.boolean
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.boolean)

target_link_STLSoft(test.component.inserters.boolean)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.boolean)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.boolean)

define_target_compile_options(test.component.inserters.boolean)


# ############################## end of file ############################# #

