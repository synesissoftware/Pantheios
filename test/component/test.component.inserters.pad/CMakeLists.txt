
add_executable(test.component.inserters.pad
	test.component.inserters.pad.cpp
)

target_link_Pantheios_core(test.component.inserters.pad)

target_link_libraries(test.component.inserters.pad
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.pad
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.pad)

target_link_STLSoft(test.component.inserters.pad)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.pad)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.pad)

define_target_compile_options(test.component.inserters.pad)


# ############################## end of file ############################# #

