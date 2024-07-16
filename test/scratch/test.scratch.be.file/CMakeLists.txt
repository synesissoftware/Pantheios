
add_executable(test.scratch.be.file
	test.scratch.be.file.cpp
)

target_link_libraries(test.scratch.be.file
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.scratch.be.file
	PRIVATE
		Pantheios.be.lrsplit
		Pantheios.bec.file
		Pantheios.bel.file
		Pantheios.ber.file
)

target_link_libraries(test.scratch.be.file
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.scratch.be.file
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.scratch.be.file
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(test.scratch.be.file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
		-Wno-null-pointer-arithmetic
		-Wno-unused-variable
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

