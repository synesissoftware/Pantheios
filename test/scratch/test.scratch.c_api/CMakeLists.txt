
add_executable(test.scratch.c_api
	test.scratch.c_api.c
)

target_link_Pantheios_core(test.scratch.c_api)

target_link_libraries(test.scratch.c_api
	PRIVATE
		Pantheios.be.lrsplit
		Pantheios.bel.fprintf
		Pantheios.ber.null
		Pantheios.bec.fprintf
		Pantheios.bec.null
)

target_link_libraries(test.scratch.c_api
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.c_api)

target_link_xTests(test.scratch.c_api)

target_compile_options(test.scratch.c_api
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-extern-initializer
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

