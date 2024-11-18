
add_executable(test.unit.fe.WindowsRegistry
	test.unit.fe.WindowsRegistry.cpp
)

target_link_libraries(test.unit.fe.WindowsRegistry
	PRIVATE
		Pantheios.fe.WindowsRegistry
)

target_link_Pantheios_util(test.unit.fe.WindowsRegistry)

target_link_STLSoft(test.unit.fe.WindowsRegistry)

if(shwild_FOUND)

	target_link_shwild(test.unit.fe.WindowsRegistry)
endif(shwild_FOUND)

target_link_xTests(test.unit.fe.WindowsRegistry)

define_target_compile_options(test.unit.fe.WindowsRegistry)


# ############################## end of file ############################# #

