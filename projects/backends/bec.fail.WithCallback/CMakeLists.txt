
set(BEC_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BEC_FAIL_SRCS
	${BEC_FAIL_SRC_DIR}/bec.fail.c
)

add_library(Pantheios.bec.fail.WithCallback
	${BEC_FAIL_SRCS}
)

target_link_STLSoft(Pantheios.bec.fail.WithCallback)

target_compile_options(Pantheios.bec.fail.WithCallback
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-DPANTHEIOS_BE_USE_CALLBACK
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			-DPANTHEIOS_BE_USE_CALLBACK
		>
)

install(TARGETS Pantheios.bec.fail.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

