
add_executable(test.scratch.I18N
	test.scratch.I18N.cpp
)

target_link_Pantheios_core(test.scratch.I18N)

target_link_libraries(test.scratch.I18N
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.I18N
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.I18N)

target_link_STLSoft(test.scratch.I18N)

target_compile_options(test.scratch.I18N
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

