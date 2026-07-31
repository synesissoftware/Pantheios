
add_executable(test.unit.levels.values
	test.unit.levels.values.c
)

target_link_Pantheios_util(test.unit.levels.values)

target_link_STLSoft(test.unit.levels.values)

if(shwild_FOUND)

	target_link_shwild(test.unit.levels.values)
endif(shwild_FOUND)

target_link_xTests(test.unit.levels.values)

define_target_compile_options(test.unit.levels.values)


# ############################## end of file ############################# #

