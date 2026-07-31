
add_executable(test.unit.be.lrsplit
	test.unit.be.lrsplit.c
)

target_link_libraries(test.unit.be.lrsplit
	PRIVATE
		Pantheios.be.lrsplit
)

target_link_libraries(test.unit.be.lrsplit
	PRIVATE
		Pantheios.fe.null
)

target_link_Pantheios_util(test.unit.be.lrsplit)

target_link_STLSoft(test.unit.be.lrsplit)

if(shwild_FOUND)

	target_link_shwild(test.unit.be.lrsplit)
endif(shwild_FOUND)

target_link_xTests(test.unit.be.lrsplit)

define_target_compile_options(test.unit.be.lrsplit)


# ############################## end of file ############################# #

