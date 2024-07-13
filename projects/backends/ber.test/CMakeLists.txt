
set(BER_TEST_SRC_DIR ../../../src/backends)

file(GLOB BER_TEST_SRCS
	${BER_TEST_SRC_DIR}/ber/ber.test.c
)

add_library(Pantheios.ber.test
	${BER_TEST_SRCS}
)

target_link_libraries(Pantheios.ber.test
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.ber.test PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.ber.test)


# ############################## end of test ############################# #

