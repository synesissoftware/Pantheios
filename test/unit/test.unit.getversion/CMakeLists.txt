
add_executable(test.unit.getversion
	test.unit.getversion.c
)

target_link_Pantheios_core(test.unit.getversion)

target_link_libraries(test.unit.getversion
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.unit.getversion
	PRIVATE
		Pantheios.fe.fail
)

target_link_Pantheios_util(test.unit.getversion)

target_link_STLSoft(test.unit.getversion)

if(shwild_FOUND)

	target_link_shwild(test.unit.getversion)
endif(shwild_FOUND)

target_link_xTests(test.unit.getversion)

define_target_compile_options(test.unit.getversion)


# ############################## end of file ############################# #

