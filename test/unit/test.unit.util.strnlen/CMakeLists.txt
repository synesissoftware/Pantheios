
add_executable(test.unit.util.strnlen
	test.unit.util.strnlen.cpp
)

target_link_libraries(test.unit.util.strnlen
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.util.strnlen
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.util.strnlen PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

