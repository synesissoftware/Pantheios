
add_executable(test.unit.util.getcurrenttime
	test.unit.util.getcurrenttime.cpp
)

target_link_Pantheios_util(test.unit.util.getcurrenttime)

target_link_STLSoft(test.unit.util.getcurrenttime)

if(shwild_FOUND)

	target_link_shwild(test.unit.util.getcurrenttime)
endif(shwild_FOUND)

target_link_xTests(test.unit.util.getcurrenttime)

define_target_compile_options(test.unit.util.getcurrenttime)


# ############################## end of file ############################# #

