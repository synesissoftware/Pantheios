
add_executable(test.component.inserters.slice
	test.component.inserters.slice.cpp
)

target_link_libraries(test.component.inserters.slice
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.component.inserters.slice
	PRIVATE
		Pantheios.fe.all
)

target_link_libraries(test.component.inserters.slice
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.slice
	PRIVATE
		xTests::xTests.core
)

target_compile_options(test.component.inserters.slice PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

