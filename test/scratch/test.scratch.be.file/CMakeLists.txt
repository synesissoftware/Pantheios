
add_executable(test.scratch.be.file
	test.scratch.be.file.cpp
)

target_link_Pantheios_core(test.scratch.be.file)

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

target_link_Pantheios_util(test.scratch.be.file)

target_link_STLSoft(test.scratch.be.file)

target_compile_options(test.scratch.be.file
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-deprecated-copy-with-user-provided-copy
			-Wno-unused-variable
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

