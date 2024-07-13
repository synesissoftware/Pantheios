
set(FE_N_SRC_DIR ../../../src/frontends)

file(GLOB FE_N_SRCS
	${FE_N_SRC_DIR}/fe.N.c
)

add_library(Pantheios.fe.N
	${FE_N_SRCS}
)

target_compile_options(Pantheios.fe.N PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.fe.N)


# ############################## end of file ############################# #

