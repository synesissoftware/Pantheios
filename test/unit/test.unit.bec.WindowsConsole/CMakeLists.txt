
add_executable(test.unit.bec.WindowsConsole
	entry.cpp
)

target_link_libraries(test.unit.bec.WindowsConsole
	PRIVATE
		Pantheios.bec.WindowsConsole
)

target_link_Pantheios_util(test.unit.bec.WindowsConsole)

target_link_STLSoft(test.unit.bec.WindowsConsole)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.WindowsConsole)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.WindowsConsole)

define_target_compile_options(test.unit.bec.WindowsConsole)


# ############################## end of file ############################# #

