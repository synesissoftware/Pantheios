
add_executable(test.unit.util.date_elements_to_string
	test.unit.util.date_elements_to_string.cpp
)

target_link_Pantheios_util(test.unit.util.date_elements_to_string)

target_link_STLSoft(test.unit.util.date_elements_to_string)

if(shwild_FOUND)

	target_link_shwild(test.unit.util.date_elements_to_string)
endif(shwild_FOUND)

target_link_xTests(test.unit.util.date_elements_to_string)

define_target_compile_options(test.unit.util.date_elements_to_string)


# ############################## end of file ############################# #

