
add_executable(test.unit.be.fail
	test.unit.be.fail.c
)

target_link_libraries(test.unit.be.fail
	PRIVATE
		Pantheios.be.fail
		Pantheios.bec.fail
)

target_link_Pantheios_util(test.unit.be.fail)

target_link_STLSoft(test.unit.be.fail)

if(shwild_FOUND)

	target_link_shwild(test.unit.be.fail)
endif(shwild_FOUND)

target_link_xTests(test.unit.be.fail)

define_target_compile_options(test.unit.be.fail)


# ############################## end of file ############################# #

