
add_executable(test.unit.levels.dynamic_initialisation
	test.unit.levels.dynamic_initialisation.cpp
)

target_link_Pantheios_util(test.unit.levels.dynamic_initialisation)

target_link_STLSoft(test.unit.levels.dynamic_initialisation)

if(shwild_FOUND)

	target_link_shwild(test.unit.levels.dynamic_initialisation)
endif(shwild_FOUND)

target_link_xTests(test.unit.levels.dynamic_initialisation)

define_target_compile_options(test.unit.levels.dynamic_initialisation)


# ############################## end of file ############################# #

