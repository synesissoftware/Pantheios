
set(FE_NULL_WC_SRC_DIR ../../../src/frontends)

file(GLOB FE_NULL_WC_SRCS
	${FE_NULL_WC_SRC_DIR}/fe.null.c
)

add_library(Pantheios.fe.null.WithCallback
	${FE_NULL_WC_SRCS}
)

target_link_STLSoft(Pantheios.fe.null.WithCallback)

target_compile_options(Pantheios.fe.null.WithCallback
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

install(TARGETS Pantheios.fe.null.WithCallback
	EXPORT project-targets
)

install_file(frontends fe.null.h)


# ############################## end of file ############################# #

