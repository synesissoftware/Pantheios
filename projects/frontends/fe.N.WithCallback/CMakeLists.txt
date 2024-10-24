
set(FE_N_WC_SRC_DIR ../../../src/frontends)

file(GLOB FE_N_WC_SRCS
	${FE_N_WC_SRC_DIR}/fe.N.c
)

add_library(Pantheios.fe.N.WithCallback
	${FE_N_WC_SRCS}
)

target_link_STLSoft(Pantheios.fe.N.WithCallback)

target_compile_options(Pantheios.fe.N.WithCallback
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

install(TARGETS Pantheios.fe.N.WithCallback
	EXPORT project-targets
)

install_file(frontends fe.N.h)


# ############################## end of file ############################# #

