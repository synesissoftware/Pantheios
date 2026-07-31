
add_executable(test.unit.util.onbailout
	test.unit.util.onbailout.cpp
)

target_link_Pantheios_util(test.unit.util.onbailout)

target_link_STLSoft(test.unit.util.onbailout)

if(shwild_FOUND)

	target_link_shwild(test.unit.util.onbailout)
endif(shwild_FOUND)

target_link_xTests(test.unit.util.onbailout)

define_target_compile_options(test.unit.util.onbailout)


# ############################## end of file ############################# #

