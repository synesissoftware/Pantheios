
add_executable(test.scratch.c_api
	test.scratch.c_api.c
)

target_link_libraries(test.scratch.c_api
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.scratch.c_api
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.scratch.c_api
	PRIVATE
		Pantheios.be.lrsplit
		Pantheios.bec.fprintf
		Pantheios.bec.null
		Pantheios.bel.fprintf
		Pantheios.ber.null
)

target_link_libraries(test.scratch.c_api
	PRIVATE
		xTests::xTests.core
)

target_compile_options(test.scratch.c_api PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-extern-initializer
		-Wno-null-pointer-arithmetic
		-Wno-unused-variable
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

