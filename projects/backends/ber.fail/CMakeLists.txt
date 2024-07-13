
set(BER_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BER_FAIL_SRCS
	${BER_FAIL_SRC_DIR}/ber/ber.fail.c
)

add_library(Pantheios.ber.fail
	${BER_FAIL_SRCS}
)

target_compile_options(Pantheios.ber.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.ber.fail)


# ############################## end of fail ############################# #

