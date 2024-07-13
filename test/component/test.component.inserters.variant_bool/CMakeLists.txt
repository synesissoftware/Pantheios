
add_executable(test.component.inserters.variant_bool
	test.component.inserters.variant_bool.cpp
)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		xTests::xTests.core
)

target_compile_options(test.component.inserters.variant_bool PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

