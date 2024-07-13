
add_executable(test.component.log.1
	test.component.log.1.cpp
)

target_link_libraries(test.component.log.1
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.component.log.1
	PRIVATE
		Pantheios.fe.all
)

target_link_libraries(test.component.log.1
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.log.1
	PRIVATE
		xTests::xTests.core
)

target_compile_options(test.component.log.1 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

