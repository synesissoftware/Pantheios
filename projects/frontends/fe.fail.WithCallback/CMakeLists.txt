
set(FE_FAIL_WC_SRC_DIR ../../../src/frontends)

file(GLOB FE_FAIL_WC_SRCS
	${FE_FAIL_WC_SRC_DIR}/fe.fail.c
)

add_library(Pantheios.fe.fail.WithCallback
	${FE_FAIL_WC_SRCS}
)

target_link_STLSoft(Pantheios.fe.fail.WithCallback)

target_compile_options(Pantheios.fe.fail.WithCallback
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

install(TARGETS Pantheios.fe.fail.WithCallback
	EXPORT project-targets
)

install_file(frontends fe.fail.h)


# ############################## end of file ############################# #

