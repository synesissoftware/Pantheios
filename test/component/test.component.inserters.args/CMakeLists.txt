
add_executable(test.component.inserters.args
	test.component.inserters.args.cpp
)

target_link_Pantheios_core(test.component.inserters.args)

target_link_libraries(test.component.inserters.args
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.args
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.args)

target_link_STLSoft(test.component.inserters.args)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.args)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.args)

define_target_compile_options(test.component.inserters.args)


# ############################## end of file ############################# #

