
set(BEL_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BEL_FAIL_SRCS
	${BEL_FAIL_SRC_DIR}/bel/bel.fail.c
)

add_library(Pantheios.bel.fail
	${BEL_FAIL_SRCS}
)

target_compile_options(Pantheios.bel.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bel.fail)


# ############################## end of fail ############################# #

