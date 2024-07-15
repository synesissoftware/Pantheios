
add_executable(test.component.core.initialisation_sequence
	test.component.core.initialisation_sequence.c
)

target_link_libraries(test.component.core.initialisation_sequence
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.component.core.initialisation_sequence
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.core.initialisation_sequence
	PRIVATE
		Pantheios.fe.all
)

target_link_libraries(test.component.core.initialisation_sequence
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.component.core.initialisation_sequence
	PRIVATE
		xTests::core
)

target_compile_options(test.component.core.initialisation_sequence PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

