
add_executable(test.scratch.be.N.with.custom.fe
	test.scratch.be.N.with.custom.fe.cpp
)

target_link_Pantheios_core(test.scratch.be.N.with.custom.fe)

target_link_libraries(test.scratch.be.N.with.custom.fe
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_Pantheios_util(test.scratch.be.N.with.custom.fe)

target_link_STLSoft(test.scratch.be.N.with.custom.fe)

define_target_compile_options(test.scratch.be.N.with.custom.fe)


# ############################## end of file ############################# #

