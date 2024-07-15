
add_executable(test.performance.util.date_elements_to_string
	test.performance.util.date_elements_to_string.cpp
)

target_link_libraries(test.performance.util.date_elements_to_string
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.performance.util.date_elements_to_string
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.performance.util.date_elements_to_string
	PRIVATE
		Pantheios.be.null
)

target_link_libraries(test.performance.util.date_elements_to_string
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.performance.util.date_elements_to_string
	PRIVATE
		xTests::core
)

target_compile_options(test.performance.util.date_elements_to_string PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-missing-field-initializers
		-Wno-unused-but-set-variable
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

