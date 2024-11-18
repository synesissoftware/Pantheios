
add_executable(test.unit.bec.fail
	test.unit.bec.fail.c
)

target_link_libraries(test.unit.bec.fail
	PRIVATE
		Pantheios.bec.fail
)

target_link_Pantheios_util(test.unit.bec.fail)

target_link_STLSoft(test.unit.bec.fail)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.fail)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.fail)

define_target_compile_options(test.unit.bec.fail)


# ############################## end of file ############################# #

