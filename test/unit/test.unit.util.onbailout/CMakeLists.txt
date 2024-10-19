
add_executable(test.unit.util.onbailout
	test.unit.util.onbailout.cpp
)

target_link_Pantheios_util(test.unit.util.onbailout)

target_link_STLSoft(test.unit.util.onbailout)

target_link_shwild(test.unit.util.onbailout)

target_link_xTests(test.unit.util.onbailout)

target_compile_options(test.unit.util.onbailout
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-unused-but-set-parameter
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

