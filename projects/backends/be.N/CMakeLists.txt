
set(BE_N_SRC_DIR ../../../src/backends)

file(GLOB BE_N_SRCS
	${BE_N_SRC_DIR}/be.N.c
)

add_library(Pantheios.be.N
	${BE_N_SRCS}
)

target_compile_options(Pantheios.be.N PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.be.N)


# ############################## end of file ############################# #

