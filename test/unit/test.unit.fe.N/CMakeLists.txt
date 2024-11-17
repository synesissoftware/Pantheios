
add_executable(test.unit.fe.N
	test.unit.fe.N.c
)

target_link_libraries(test.unit.fe.N
	PRIVATE
		Pantheios.fe.N
)

target_link_Pantheios_util(test.unit.fe.N)

target_link_STLSoft(test.unit.fe.N)

if(shwild_FOUND)

	target_link_shwild(test.unit.fe.N)
endif(shwild_FOUND)

target_link_xTests(test.unit.fe.N)

define_target_compile_options(test.unit.fe.N)


# ############################## end of file ############################# #

