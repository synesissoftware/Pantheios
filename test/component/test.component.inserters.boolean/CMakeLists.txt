
add_executable(test.component.inserters.boolean
	test.component.inserters.boolean.cpp
)

target_link_libraries(test.component.inserters.boolean
	Pantheios.util
	Pantheios.core
)

target_link_libraries(test.component.inserters.boolean
	Pantheios.fe.all
)

target_link_libraries(test.component.inserters.boolean
	Pantheios.be.test
	Pantheios.bec.test
)

target_link_libraries(test.component.inserters.boolean
	xTests::xTests.core
)

target_compile_options(test.component.inserters.boolean PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

