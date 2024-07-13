
set(FE_NULL_SRC_DIR ../../../src/frontends)

file(GLOB FE_NULL_SRCS
	${FE_NULL_SRC_DIR}/fe.null.c
)

add_library(Pantheios.fe.null
	${FE_NULL_SRCS}
)

target_compile_options(Pantheios.fe.null PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.fe.null)


