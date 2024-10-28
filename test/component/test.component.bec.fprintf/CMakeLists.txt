
add_executable(test.component.bec.fprintf
	test.component.bec.fprintf.cpp
)

target_link_libraries(test.component.bec.fprintf
	PRIVATE
		Pantheios.bec.fprintf
)

target_link_libraries(test.component.bec.fprintf
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.bec.fprintf)

if(shwild_FOUND)

	target_link_shwild(test.component.bec.fprintf)
endif(shwild_FOUND)

target_link_STLSoft(test.component.bec.fprintf)

target_link_xTests(test.component.bec.fprintf)

define_target_compile_options(test.component.bec.fprintf)


# ############################## end of file ############################# #

