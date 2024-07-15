
set(BEC_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BEC_FAIL_SRCS
	${BEC_FAIL_SRC_DIR}/bec.fail.c
)

add_library(Pantheios.bec.fail
	${BEC_FAIL_SRCS}
)

target_link_libraries(Pantheios.bec.fail
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bec.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.fail)


# ############################## end of file ############################# #

