
set(BEC_TEST_SRC_DIR ../../../src/backends)

file(GLOB BEC_TEST_SRCS
	${BEC_TEST_SRC_DIR}/bec.test.cpp
)

add_library(Pantheios.bec.test
	${BEC_TEST_SRCS}
)

target_link_libraries(Pantheios.bec.test
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bec.test PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.test)


# ############################## end of file ############################# #

