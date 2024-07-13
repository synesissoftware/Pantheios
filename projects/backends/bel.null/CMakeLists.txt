
set(BEL_NULL_SRC_DIR ../../../src/backends)

file(GLOB BEL_NULL_SRCS
	${BEL_NULL_SRC_DIR}/bel/bel.null.c
)

add_library(Pantheios.bel.null
	${BEL_NULL_SRCS}
)

target_compile_options(Pantheios.bel.null PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bel.null)


# ############################## end of null ############################# #

