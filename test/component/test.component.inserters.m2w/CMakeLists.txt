
add_executable(test.component.inserters.m2w
	test.component.inserters.m2w.cpp
)

target_link_Pantheios_core(test.component.inserters.m2w)

target_link_libraries(test.component.inserters.m2w
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.m2w
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.m2w)

target_link_STLSoft(test.component.inserters.m2w)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.m2w)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.m2w)

define_target_compile_options(test.component.inserters.m2w)


# ############################## end of file ############################# #

