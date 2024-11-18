
add_executable(test.unit.inserter.integer
	test.unit.inserter.integer.cpp
)

target_link_Pantheios_core(test.unit.inserter.integer)

target_link_Pantheios_util(test.unit.inserter.integer)

target_link_STLSoft(test.unit.inserter.integer)

if(shwild_FOUND)

	target_link_shwild(test.unit.inserter.integer)
endif(shwild_FOUND)

target_link_xTests(test.unit.inserter.integer)

define_target_compile_options(test.unit.inserter.integer)


# ############################## end of file ############################# #

