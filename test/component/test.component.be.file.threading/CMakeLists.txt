
add_executable(test.component.be.file.threading
	test.component.be.file.threading.cpp
)

target_link_Pantheios_core(test.component.be.file.threading)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.fe.N
)

target_link_Pantheios_util(test.component.be.file.threading)

target_link_STLSoft(test.component.be.file.threading)

if(shwild_FOUND)

	target_link_shwild(test.component.be.file.threading)
endif(shwild_FOUND)

target_link_xTests(test.component.be.file.threading)

define_target_compile_options(test.component.be.file.threading)


# ############################## end of file ############################# #

