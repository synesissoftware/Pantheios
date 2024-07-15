
add_executable(test.component.inserters.w2m
	test.component.inserters.w2m.cpp
)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.fe.all
)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.component.inserters.w2m
	PRIVATE
		xTests::core
)

target_compile_options(test.component.inserters.w2m PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

