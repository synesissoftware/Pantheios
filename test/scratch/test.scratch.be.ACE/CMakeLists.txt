
add_executable(test.scratch.be.ACE
	test.scratch.be.ACE.cpp
)

target_link_Pantheios_core(test.scratch.be.ACE)

target_link_libraries(test.scratch.be.ACE
	PRIVATE
		Pantheios.be.ACE
		Pantheios.bec.ACE
)

target_link_libraries(test.scratch.be.ACE
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.be.ACE)

target_link_STLSoft(test.scratch.be.ACE)

target_link_ACE(test.scratch.be.ACE)

define_target_compile_options(test.scratch.be.ACE)


# ############################## end of file ############################# #
