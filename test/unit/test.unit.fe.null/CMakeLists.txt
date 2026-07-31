
add_executable(test.unit.fe.null
	test.unit.fe.null.c
)

target_link_libraries(test.unit.fe.null
	PRIVATE
		Pantheios.fe.null
)

target_link_Pantheios_util(test.unit.fe.null)

target_link_STLSoft(test.unit.fe.null)

if(shwild_FOUND)

	target_link_shwild(test.unit.fe.null)
endif(shwild_FOUND)

target_link_xTests(test.unit.fe.null)

define_target_compile_options(test.unit.fe.null)


# ############################## end of file ############################# #

