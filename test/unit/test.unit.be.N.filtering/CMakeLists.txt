
add_executable(test.unit.be.N.filtering
	test.unit.be.N.filtering.c
)

target_link_libraries(test.unit.be.N.filtering
	PRIVATE
		Pantheios.be.N
)

target_link_libraries(test.unit.be.N.filtering
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.unit.be.N.filtering)

target_link_STLSoft(test.unit.be.N.filtering)

if(shwild_FOUND)

	target_link_shwild(test.unit.be.N.filtering)
endif(shwild_FOUND)

target_link_xTests(test.unit.be.N.filtering)

define_target_compile_options(test.unit.be.N.filtering)


# ############################## end of file ############################# #

