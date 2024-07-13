
add_executable(test.unit.util.gethostname
	test.unit.util.gethostname.cpp
)

target_link_libraries(test.unit.util.gethostname
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.util.gethostname
	PRIVATE
		STLSoft::STLSoft
		xTests::xTests.core
)

target_compile_options(test.unit.util.gethostname PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

