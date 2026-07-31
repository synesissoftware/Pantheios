
add_executable(test.unit.fe.all
	test.unit.fe.all.c
)

target_link_libraries(test.unit.fe.all
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.unit.fe.all)

target_link_STLSoft(test.unit.fe.all)

if(shwild_FOUND)

	target_link_shwild(test.unit.fe.all)
endif(shwild_FOUND)

target_link_xTests(test.unit.fe.all)

define_target_compile_options(test.unit.fe.all)


# ############################## end of file ############################# #

