
add_executable(test.scratch.bec.WindowsConsoleCallback
	main.cpp
)

target_link_Pantheios_core(test.scratch.bec.WindowsConsoleCallback)

target_link_libraries(test.scratch.bec.WindowsConsoleCallback
	PRIVATE
		Pantheios.be.WindowsConsole
		Pantheios.bec.WindowsConsole.WithCallback
)

target_link_libraries(test.scratch.bec.WindowsConsoleCallback
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.bec.WindowsConsoleCallback)

target_link_STLSoft(test.scratch.bec.WindowsConsoleCallback)

define_target_compile_options(test.scratch.bec.WindowsConsoleCallback)


# ############################## end of file ############################# #

