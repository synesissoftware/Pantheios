
add_executable(test.scratch.util.onbailout
	test.scratch.util.onbailout.cpp
)

target_link_libraries(test.scratch.util.onbailout
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.scratch.util.onbailout
	PRIVATE
		Pantheios.fe.all
)

target_link_libraries(test.scratch.util.onbailout
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.scratch.util.onbailout
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(test.scratch.util.onbailout PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

