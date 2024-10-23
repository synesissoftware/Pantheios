
add_executable(test.scratch.showPlus.integer
	test.scratch.showPlus.integer.cpp
)

target_link_Pantheios_core(test.scratch.showPlus.integer)

target_link_libraries(test.scratch.showPlus.integer
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.showPlus.integer
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.showPlus.integer)

target_link_STLSoft(test.scratch.showPlus.integer)

define_target_compile_options(test.scratch.showPlus.integer)


# ############################## end of file ############################# #

