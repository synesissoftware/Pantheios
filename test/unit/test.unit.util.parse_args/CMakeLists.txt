
add_executable(test.unit.util.parse_args
	entry.cpp
)

target_link_Pantheios_util(test.unit.util.parse_args)

target_link_STLSoft(test.unit.util.parse_args)

if(shwild_FOUND)

	target_link_shwild(test.unit.util.parse_args)
endif(shwild_FOUND)

target_link_xTests(test.unit.util.parse_args)

define_target_compile_options(test.unit.util.parse_args)


# ############################## end of file ############################# #

