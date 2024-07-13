
add_executable(test.unit.be.lrsplit
	test.unit.be.lrsplit.c
)

target_link_libraries(test.unit.be.lrsplit
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.be.lrsplit
	PRIVATE
		Pantheios.fe.null
)

target_link_libraries(test.unit.be.lrsplit
	PRIVATE
		Pantheios.be.lrsplit
)

target_link_libraries(test.unit.be.lrsplit
	PRIVATE
		STLSoft::STLSoft
		xTests::xTests.core
)

target_compile_options(test.unit.be.lrsplit PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

