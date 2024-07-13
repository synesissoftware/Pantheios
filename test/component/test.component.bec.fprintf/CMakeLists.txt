
add_executable(test.component.bec.fprintf
	test.component.bec.fprintf.cpp
)

target_link_libraries(test.component.bec.fprintf
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.component.bec.fprintf
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.component.bec.fprintf
	PRIVATE
		Pantheios.bec.fprintf
)

target_link_libraries(test.component.bec.fprintf
	PRIVATE
		xTests::xTests.core
)

target_compile_options(test.component.bec.fprintf PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

