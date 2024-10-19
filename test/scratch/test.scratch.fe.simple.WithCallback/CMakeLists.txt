
add_executable(test.scratch.fe.simple.WithCallback
	test.scratch.fe.simple.WithCallback.cpp
)

target_link_Pantheios_core(test.scratch.fe.simple.WithCallback)

target_link_libraries(test.scratch.fe.simple.WithCallback
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.fe.simple.WithCallback
	PRIVATE
		Pantheios.fe.simple.WithCallback
)

target_link_Pantheios_util(test.scratch.fe.simple.WithCallback)

target_link_STLSoft(test.scratch.fe.simple.WithCallback)

target_compile_options(test.scratch.fe.simple.WithCallback
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

