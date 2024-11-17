
add_executable(test.unit.util.gethostname
	test.unit.util.gethostname.cpp
)

target_link_Pantheios_util(test.unit.util.gethostname)

target_link_STLSoft(test.unit.util.gethostname)

if(shwild_FOUND)

	target_link_shwild(test.unit.util.gethostname)
endif(shwild_FOUND)

target_link_xTests(test.unit.util.gethostname)

define_target_compile_options(test.unit.util.gethostname)


# ############################## end of file ############################# #

