
add_executable(test.unit.fe.simple
	test.unit.fe.simple.c
)

target_link_libraries(test.unit.fe.simple
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.unit.fe.simple)

target_link_STLSoft(test.unit.fe.simple)

if(shwild_FOUND)

	target_link_shwild(test.unit.fe.simple)
endif(shwild_FOUND)

target_link_xTests(test.unit.fe.simple)

define_target_compile_options(test.unit.fe.simple)


# ############################## end of file ############################# #

