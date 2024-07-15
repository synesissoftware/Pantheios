
add_executable(test.unit.bec.fprintf
	test.unit.bec.fprintf.cpp
)

target_link_libraries(test.unit.bec.fprintf
	PRIVATE
		Pantheios.bec.fprintf
)

target_link_libraries(test.unit.bec.fprintf
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.bec.fprintf
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.bec.fprintf PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

