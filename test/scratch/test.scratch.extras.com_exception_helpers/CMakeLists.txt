
add_executable(test.scratch.extras.com_exception_helpers
	test.scratch.extras.com_exception_helpers.cpp
)

target_link_libraries(test.scratch.extras.com_exception_helpers
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.scratch.extras.com_exception_helpers
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.scratch.extras.com_exception_helpers
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_compile_options(test.scratch.extras.com_exception_helpers PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

