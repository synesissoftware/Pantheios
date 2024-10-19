
add_executable(test.scratch.WideString
	test.scratch.WideString.cpp
)

target_link_Pantheios_core(test.scratch.WideString)

target_link_libraries(test.scratch.WideString
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.WideString
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.WideString)

target_link_STLSoft(test.scratch.WideString)

target_link_libraries(test.scratch.WideString
	PRIVATE
		b64::core
)

target_compile_options(test.scratch.WideString
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-null-pointer-arithmetic
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

