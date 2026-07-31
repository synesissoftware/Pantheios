
add_executable(test.unit.bec.file
	test.unit.bec.file.cpp
)

target_link_libraries(test.unit.bec.file
	PRIVATE
		Pantheios.bec.file
)

target_link_Pantheios_util(test.unit.bec.file)

target_link_STLSoft(test.unit.bec.file)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.file)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.file)

define_target_compile_options(test.unit.bec.file)


# ############################## end of file ############################# #

