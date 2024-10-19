
add_executable(test.component.inserters.w2m
	test.component.inserters.w2m.cpp
)

target_link_Pantheios_core(test.component.inserters.w2m)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.w2m)

target_link_xTests(test.component.inserters.w2m)

target_compile_options(test.component.inserters.w2m
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

