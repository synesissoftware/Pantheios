
add_executable(test.scratch.be.file.rolling
test.scratch.be.file.rolling.cpp
)

target_link_Pantheios_core(test.scratch.be.file.rolling)

target_link_libraries(test.scratch.be.file.rolling
	PRIVATE
		Pantheios.be.lrsplit
		Pantheios.bec.file
		Pantheios.bel.file
		Pantheios.ber.file
)

target_link_libraries(test.scratch.be.file.rolling
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.be.file.rolling)

target_compile_options(test.scratch.be.file.rolling
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-deprecated-copy-with-user-provided-copy
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

