
add_executable(test.scratch.be.speech
	test.scratch.be.speech.cpp
)

target_link_Pantheios_core(test.scratch.be.speech)

target_link_libraries(test.scratch.be.speech
	PRIVATE
		Pantheios.be.speech
		Pantheios.bec.speech
)

target_link_libraries(test.scratch.be.speech
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.be.speech)

target_link_STLSoft(test.scratch.be.speech)

define_target_compile_options(test.scratch.be.speech)


# ############################## end of file ############################# #

