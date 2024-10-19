
add_executable(test.component.inserters.variant_bool
	test.component.inserters.variant_bool.cpp
)

target_link_Pantheios_core(test.component.inserters.variant_bool)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.variant_bool
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.inserters.variant_bool)

target_link_xTests(test.component.inserters.variant_bool)

target_compile_options(test.component.inserters.variant_bool
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-null-pointer-arithmetic
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

