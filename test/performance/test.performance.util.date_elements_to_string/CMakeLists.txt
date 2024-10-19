
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

target_link_xTests(test.performance.util.date_elements_to_string)

target_compile_options(test.performance.util.date_elements_to_string
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-deprecated-declarations
			-Wno-missing-field-initializers
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

