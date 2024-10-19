
add_executable(test.scratch.tstring
	test.scratch.tstring.cpp
)

target_link_Pantheios_core(test.scratch.tstring)

target_link_libraries(test.scratch.tstring
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.tstring
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.tstring)

target_link_STLSoft(test.scratch.tstring)

target_compile_options(test.scratch.tstring
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			/wd4996
		>
)


# ############################## end of file ############################# #

