
add_executable(test.unit.util.snprintf
	test.unit.util.snprintf.cpp
)

target_link_Pantheios_util(test.unit.util.snprintf)

target_link_STLSoft(test.unit.util.snprintf)

if(shwild_FOUND)

	target_link_shwild(test.unit.util.snprintf)
endif(shwild_FOUND)

target_link_xTests(test.unit.util.snprintf)

define_target_compile_options(test.unit.util.snprintf)


# ############################## end of file ############################# #

