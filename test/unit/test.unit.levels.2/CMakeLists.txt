
add_executable(test.unit.levels.2
	test.unit.levels.2.cpp
)

target_link_Pantheios_util(test.unit.levels.2)

target_link_STLSoft(test.unit.levels.2)

if(shwild_FOUND)

	target_link_shwild(test.unit.levels.2)
endif(shwild_FOUND)

target_link_xTests(test.unit.levels.2)

define_target_compile_options(test.unit.levels.2)


# ############################## end of file ############################# #

