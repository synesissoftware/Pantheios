
add_executable(test.component.core.pantheios_logputs
	test.component.core.pantheios_logputs.cpp
)

target_link_Pantheios_core(test.component.core.pantheios_logputs)

target_link_libraries(test.component.core.pantheios_logputs
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.core.pantheios_logputs
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.component.core.pantheios_logputs)

target_link_xTests(test.component.core.pantheios_logputs)

target_compile_options(test.component.core.pantheios_logputs
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

