
set(BEC_TEST_SRC_DIR ../../../src/backends)

file(GLOB BEC_TEST_SRCS
	${BEC_TEST_SRC_DIR}/bec.test.cpp
)

add_library(Pantheios.bec.test.WithCallback
	${BEC_TEST_SRCS}
)

target_link_STLSoft(Pantheios.bec.test.WithCallback)

target_compile_options(Pantheios.bec.test.WithCallback
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-unused-private-field # this (temporarily) for bec.test.cpp

			-DPANTHEIOS_BE_USE_CALLBACK
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			-DPANTHEIOS_BE_USE_CALLBACK
		>
)

install(TARGETS Pantheios.bec.test.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

