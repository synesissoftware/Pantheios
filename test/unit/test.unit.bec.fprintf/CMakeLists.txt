
add_executable(test.unit.bec.fprintf
	test.unit.bec.fprintf.cpp
)

target_link_libraries(test.unit.bec.fprintf
	PRIVATE
		Pantheios.bec.fprintf
)

target_link_Pantheios_util(test.unit.bec.fprintf)

target_link_STLSoft(test.unit.bec.fprintf)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.fprintf)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.fprintf)

define_target_compile_options(test.unit.bec.fprintf)


# ############################## end of file ############################# #

