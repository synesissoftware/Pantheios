
set(BEC_NULL_SRC_DIR ../../../src/backends)

file(GLOB BEC_NULL_SRCS
	${BEC_NULL_SRC_DIR}/bec.null.c
)

add_library(Pantheios.bec.null.WithCallback
	${BEC_NULL_SRCS}
)

target_compile_options(Pantheios.bec.null.WithCallback PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-unused-parameter

		-DPANTHEIOS_BE_USE_CALLBACK
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		-DPANTHEIOS_BE_USE_CALLBACK
	>
)

install(TARGETS Pantheios.bec.null.WithCallback)


# ############################## end of file ############################# #

