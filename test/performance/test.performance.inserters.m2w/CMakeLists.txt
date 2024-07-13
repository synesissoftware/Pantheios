
add_executable(test.performance.inserters.m2w
	test.performance.inserters.m2w.cpp
)

target_link_libraries(test.performance.inserters.m2w
	Pantheios.util
	Pantheios.core
)

target_link_libraries(test.performance.inserters.m2w
	Pantheios.fe.simple
)

target_link_libraries(test.performance.inserters.m2w
	Pantheios.be.null
	Pantheios.bec.null
)

target_link_libraries(test.performance.inserters.m2w
	xTests::xTests.core
)

target_compile_options(test.performance.inserters.m2w PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-unused-but-set-variable
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

