
add_executable(test.scratch.bec.WindowsMessageBox
	main.cpp
)

target_link_Pantheios_core(test.scratch.bec.WindowsMessageBox)

target_link_libraries(test.scratch.bec.WindowsMessageBox
	PRIVATE
		Pantheios.be.WindowsMessageBox
		Pantheios.bec.WindowsMessageBox
)

target_link_libraries(test.scratch.bec.WindowsMessageBox
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.bec.WindowsMessageBox)

target_link_STLSoft(test.scratch.bec.WindowsMessageBox)

define_target_compile_options(test.scratch.bec.WindowsMessageBox)


# ############################## end of file ############################# #

