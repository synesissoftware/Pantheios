
set(BEL_TEST_SRC_DIR ../../../src/backends)

file(GLOB BEL_TEST_SRCS
	${BEL_TEST_SRC_DIR}/bel/bel.test.c
)

add_library(Pantheios.bel.test
	${BEL_TEST_SRCS}
)

target_link_libraries(Pantheios.bel.test
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bel.test PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bel.test)


# ############################## end of test ############################# #

