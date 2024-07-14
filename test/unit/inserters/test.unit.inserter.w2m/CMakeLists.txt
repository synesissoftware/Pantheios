
add_executable(test.unit.inserter.w2m
	test.unit.inserter.w2m.cpp
)

target_link_libraries(test.unit.inserter.w2m
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.unit.inserter.w2m
	PRIVATE
		Pantheios.fe.null
)

target_link_libraries(test.unit.inserter.w2m
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.unit.inserter.w2m
	PRIVATE
		xTests::core
)

target_compile_options(test.unit.inserter.w2m PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

