
add_executable(test.unit.be.fail
	test.unit.be.fail.c
)

target_link_libraries(test.unit.be.fail
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.be.fail
	PRIVATE
		Pantheios.be.fail
		Pantheios.bec.fail
)

target_link_libraries(test.unit.be.fail
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.be.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

