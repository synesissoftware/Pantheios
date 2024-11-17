
add_executable(test.component.inserters.windows.hive
	test.component.inserters.windows.hive.cpp
)

target_link_Pantheios_core(test.component.inserters.windows.hive)

target_link_libraries(test.component.inserters.windows.hive
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.windows.hive
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.inserters.windows.hive)

target_link_STLSoft(test.component.inserters.windows.hive)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.windows.hive)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.windows.hive)

define_target_compile_options(test.component.inserters.windows.hive)


# ############################## end of file ############################# #

