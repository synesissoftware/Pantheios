
set(BE_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BE_FAIL_SRCS
	${BE_FAIL_SRC_DIR}/be/be.fail.c
)

add_library(Pantheios.be.fail
	${BE_FAIL_SRCS}
)

target_compile_options(Pantheios.be.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.be.fail)


# ############################## end of file ############################# #

