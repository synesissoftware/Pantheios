
set(FE_SIMPLE_WC_SRC_DIR ../../../src/frontends)

file(GLOB FE_SIMPLE_WC_SRCS
	${FE_SIMPLE_WC_SRC_DIR}/fe.simple.c
)

add_library(Pantheios.fe.simple.WithCallback
	${FE_SIMPLE_WC_SRCS}
)

target_link_STLSoft(Pantheios.fe.simple.WithCallback)

target_compile_options(Pantheios.fe.simple.WithCallback
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

install(TARGETS Pantheios.fe.simple.WithCallback
	EXPORT project-targets
)

install_file(frontends fe.simple.h)


# ############################## end of file ############################# #

