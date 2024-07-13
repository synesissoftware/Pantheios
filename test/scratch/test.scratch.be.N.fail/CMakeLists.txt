
add_executable(test.scratch.be.N.fail
	test.scratch.be.N.fail.cpp
)

target_link_libraries(test.scratch.be.N.fail
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.scratch.be.N.fail
	PRIVATE
		Pantheios.fe.N
)

target_link_libraries(test.scratch.be.N.fail
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.fail
		Pantheios.bec.file
		Pantheios.bec.fprintf
		Pantheios.bec.null
)

target_link_libraries(test.scratch.be.N.fail
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(test.scratch.be.N.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

