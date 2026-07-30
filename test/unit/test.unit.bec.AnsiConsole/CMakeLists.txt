
add_executable(test.unit.bec.AnsiConsole
	entry.cpp
)

target_link_libraries(test.unit.bec.AnsiConsole
	PRIVATE
		Pantheios.bec.AnsiConsole
)

target_link_Pantheios_util(test.unit.bec.AnsiConsole)

target_link_STLSoft(test.unit.bec.AnsiConsole)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.AnsiConsole)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.AnsiConsole)

define_target_compile_options(test.unit.bec.AnsiConsole)


# ############################## end of file ############################# #

