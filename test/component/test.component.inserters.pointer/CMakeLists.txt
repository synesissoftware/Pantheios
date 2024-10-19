
add_executable(test.component.inserters.pointer
	test.component.inserters.pointer.cpp
)

target_link_Pantheios_core(test.component.inserters.pointer)

target_link_libraries(test.component.inserters.pointer
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.pointer
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.pointer)

target_link_xTests(test.component.inserters.pointer)

target_compile_options(test.component.inserters.pointer
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

