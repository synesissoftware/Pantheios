
add_executable(test.unit.util.strnlen
	test.unit.util.strnlen.cpp
)

target_link_Pantheios_util(test.unit.util.strnlen)

target_link_STLSoft(test.unit.util.strnlen)

target_link_xTests(test.unit.util.strnlen)

define_target_compile_options(test.unit.util.strnlen)


# ############################## end of file ############################# #

