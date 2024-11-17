
add_executable(test.component.inserters.pointer
	test.component.inserters.pointer.cpp
)

target_link_Pantheios_core(test.component.inserters.pointer)

target_link_libraries(test.component.inserters.pointer
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.pointer
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.pointer)

target_link_STLSoft(test.component.inserters.pointer)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.pointer)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.pointer)

define_target_compile_options(test.component.inserters.pointer)


# ############################## end of file ############################# #

