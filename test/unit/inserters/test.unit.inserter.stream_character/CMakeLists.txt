
add_executable(test.unit.inserter.stream_character
	test.unit.inserter.stream_character.cpp
)

target_link_Pantheios_core(test.unit.inserter.stream_character)

target_link_Pantheios_util(test.unit.inserter.stream_character)

target_link_STLSoft(test.unit.inserter.stream_character)

if(shwild_FOUND)

	target_link_shwild(test.unit.inserter.stream_character)
endif(shwild_FOUND)

target_link_xTests(test.unit.inserter.stream_character)

define_target_compile_options(test.unit.inserter.stream_character)


# ############################## end of file ############################# #

