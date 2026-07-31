
add_executable(test.component.inserters.w2m
	test.component.inserters.w2m.cpp
)

target_link_Pantheios_core(test.component.inserters.w2m)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.w2m)

target_link_STLSoft(test.component.inserters.w2m)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.w2m)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.w2m)

define_target_compile_options(test.component.inserters.w2m)


# ############################## end of file ############################# #

