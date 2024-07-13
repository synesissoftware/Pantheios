
add_executable(test.scratch.api
	test.scratch.api.cpp
)

target_link_libraries(test.scratch.api
	Pantheios.util
	Pantheios.core
)

target_link_libraries(test.scratch.api
	Pantheios.fe.simple
)

target_link_libraries(test.scratch.api
	Pantheios.be.lrsplit
	Pantheios.bec.fprintf
	Pantheios.bec.null
	Pantheios.bel.fprintf
	Pantheios.ber.null
)

target_compile_options(test.scratch.api PRIVATE
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

