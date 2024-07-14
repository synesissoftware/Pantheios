
add_executable(test.unit.inserter.m2w
	test.unit.inserter.m2w.cpp
)

target_link_libraries(test.unit.inserter.m2w
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.unit.inserter.m2w
	PRIVATE
		Pantheios.fe.null
)

target_link_libraries(test.unit.inserter.m2w
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.unit.inserter.m2w
	PRIVATE
		xTests::core
)

target_compile_options(test.unit.inserter.m2w PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

