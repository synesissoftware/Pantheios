
add_executable(test.unit.fe.fail
	test.unit.fe.fail.c
)

target_link_libraries(test.unit.fe.fail
	PRIVATE
		Pantheios.fe.fail
)

target_link_Pantheios_util(test.unit.fe.fail)

target_link_STLSoft(test.unit.fe.fail)

if(shwild_FOUND)

	target_link_shwild(test.unit.fe.fail)
endif(shwild_FOUND)

target_link_xTests(test.unit.fe.fail)

define_target_compile_options(test.unit.fe.fail)


# ############################## end of file ############################# #

