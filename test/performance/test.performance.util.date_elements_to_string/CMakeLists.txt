
add_executable(test.performance.util.date_elements_to_string
	test.performance.util.date_elements_to_string.cpp
)

target_link_Pantheios_core(test.performance.util.date_elements_to_string)

target_link_libraries(test.performance.util.date_elements_to_string
	PRIVATE
		Pantheios.be.null
)

target_link_libraries(test.performance.util.date_elements_to_string
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.performance.util.date_elements_to_string)

target_link_STLSoft(test.performance.util.date_elements_to_string)

if(shwild_FOUND)

	target_link_shwild(test.performance.util.date_elements_to_string)
endif(shwild_FOUND)

target_link_xTests(test.performance.util.date_elements_to_string)

list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED deprecated-declarations)
define_target_compile_options(test.performance.util.date_elements_to_string)


# ############################## end of file ############################# #

