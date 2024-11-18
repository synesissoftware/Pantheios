
add_executable(test.component.inserters.slice
	test.component.inserters.slice.cpp
)

target_link_Pantheios_core(test.component.inserters.slice)

target_link_libraries(test.component.inserters.slice
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.slice
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.slice)

target_link_STLSoft(test.component.inserters.slice)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.slice)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.slice)

define_target_compile_options(test.component.inserters.slice)


# ############################## end of file ############################# #

