
add_executable(example.cpp.contract.PANTHEIOS_ASSERT
	example.cpp.contract.PANTHEIOS_ASSERT.cpp
)

target_link_Pantheios_core(example.cpp.contract.PANTHEIOS_ASSERT)

target_link_libraries(example.cpp.contract.PANTHEIOS_ASSERT
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.AnsiConsole>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.AnsiConsole>
)

target_link_libraries(example.cpp.contract.PANTHEIOS_ASSERT
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.contract.PANTHEIOS_ASSERT)

target_link_STLSoft(example.cpp.contract.PANTHEIOS_ASSERT)

define_target_compile_options(example.cpp.contract.PANTHEIOS_ASSERT)


# ############################## end of file ############################# #

