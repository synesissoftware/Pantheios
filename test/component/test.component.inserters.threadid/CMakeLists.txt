
add_executable(test.component.inserters.threadid
	test.component.inserters.threadid.cpp
)

target_link_libraries(test.component.inserters.threadid
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.component.inserters.threadid
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.threadid
	PRIVATE
		Pantheios.fe.all
)

target_link_libraries(test.component.inserters.threadid
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.component.inserters.threadid
	PRIVATE
		xTests::core
)

target_compile_options(test.component.inserters.threadid PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

