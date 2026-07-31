
add_executable(test.component.inserters.stream_character
	test.component.inserters.stream_character.cpp
)

target_link_Pantheios_core(test.component.inserters.stream_character)

target_link_libraries(test.component.inserters.stream_character
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.stream_character
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.stream_character)

target_link_STLSoft(test.component.inserters.stream_character)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.stream_character)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.stream_character)

define_target_compile_options(test.component.inserters.stream_character)


# ############################## end of file ############################# #

