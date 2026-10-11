
add_executable(test.scratch.fe
	main.cpp
)

target_link_Pantheios_core(test.scratch.fe)

target_link_Pantheios_util(test.scratch.fe)

target_link_STLSoft(test.scratch.fe)

define_target_compile_options(test.scratch.fe)


# ############################## end of file ############################# #

