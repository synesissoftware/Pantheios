
add_executable(test.unit.bec.speech
	entry.cpp
)

target_link_libraries(test.unit.bec.speech
	PRIVATE
		Pantheios.bec.speech
)

target_link_Pantheios_util(test.unit.bec.speech)

target_link_STLSoft(test.unit.bec.speech)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.speech)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.speech)

define_target_compile_options(test.unit.bec.speech)


# ############################## end of file ############################# #

