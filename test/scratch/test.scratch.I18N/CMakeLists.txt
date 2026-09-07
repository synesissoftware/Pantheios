
add_executable(test.scratch.I18N
	test.scratch.I18N.cpp
)

target_link_Pantheios_core(test.scratch.I18N)

target_link_libraries(test.scratch.I18N
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.AnsiConsole>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.AnsiConsole>
)

target_link_libraries(test.scratch.I18N
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.I18N)

target_link_STLSoft(test.scratch.I18N)

define_target_compile_options(test.scratch.I18N)


# ############################## end of file ############################# #

