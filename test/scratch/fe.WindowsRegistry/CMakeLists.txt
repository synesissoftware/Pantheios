
add_executable(test.scratch.fe.WindowsRegistry
	main.cpp
)

target_link_Pantheios_core(test.scratch.fe.WindowsRegistry)

target_link_libraries(test.scratch.fe.WindowsRegistry
	PRIVATE
		Pantheios.be.WindowsConsole
		Pantheios.bec.WindowsConsole
)

target_link_libraries(test.scratch.fe.WindowsRegistry
	PRIVATE
		Pantheios.fe.WindowsRegistry
)

target_link_Pantheios_util(test.scratch.fe.WindowsRegistry)

target_link_STLSoft(test.scratch.fe.WindowsRegistry)

define_target_compile_options(test.scratch.fe.WindowsRegistry)

add_subdirectory(controller)


# ############################## end of file ############################# #

