
add_executable(test.unit.be.N
	test.unit.be.N.c
)

target_link_libraries(test.unit.be.N
	PRIVATE
		Pantheios.be.N
)

target_link_libraries(test.unit.be.N
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.unit.be.N)

target_link_STLSoft(test.unit.be.N)

if(shwild_FOUND)

	target_link_shwild(test.unit.be.N)
endif(shwild_FOUND)

target_link_xTests(test.unit.be.N)

list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED null-pointer-arithmetic)
define_target_compile_options(test.unit.be.N)


# ############################## end of file ############################# #

