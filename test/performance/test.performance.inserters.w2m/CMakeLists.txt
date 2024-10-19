
add_executable(test.performance.inserters.w2m
	test.performance.inserters.w2m.cpp
)

target_link_Pantheios_core(test.performance.inserters.w2m)

target_link_libraries(test.performance.inserters.w2m
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.performance.inserters.w2m
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.performance.inserters.w2m)

target_link_xTests(test.performance.inserters.w2m)

target_compile_options(test.performance.inserters.w2m
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-unused-but-set-variable
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

