
add_executable(test.component.trace.1
	test.component.trace.1.cpp
)

target_link_libraries(test.component.trace.1
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.component.trace.1
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.trace.1
	PRIVATE
		Pantheios.fe.all
)

target_link_libraries(test.component.trace.1
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.component.trace.1
	PRIVATE
		xTests::core
)

target_compile_options(test.component.trace.1 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

