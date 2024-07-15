
add_executable(test.unit.bec.file
	test.unit.bec.file.cpp
)

target_link_libraries(test.unit.bec.file
	PRIVATE
		Pantheios.bec.file
)

target_link_libraries(test.unit.bec.file
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.bec.file
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.bec.file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

