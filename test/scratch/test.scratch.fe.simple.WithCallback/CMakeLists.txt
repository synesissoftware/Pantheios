
add_executable(test.scratch.fe.simple.WithCallback
	test.scratch.fe.simple.WithCallback.cpp
)

target_link_Pantheios_core(test.scratch.fe.simple.WithCallback)

target_link_libraries(test.scratch.fe.simple.WithCallback
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.AnsiConsole>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.AnsiConsole>
)

target_link_libraries(test.scratch.fe.simple.WithCallback
	PRIVATE
		Pantheios.fe.simple.WithCallback
)

target_link_Pantheios_util(test.scratch.fe.simple.WithCallback)

target_link_STLSoft(test.scratch.fe.simple.WithCallback)

define_target_compile_options(test.scratch.fe.simple.WithCallback)


# ############################## end of file ############################# #

