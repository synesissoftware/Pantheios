
set(FE_ALL_WC_SRC_DIR ../../../src/frontends)

file(GLOB FE_ALL_WC_SRCS
	${FE_ALL_WC_SRC_DIR}/fe.all.c
)

add_library(Pantheios.fe.all.WithCallback
	${FE_ALL_WC_SRCS}
)

target_link_STLSoft(Pantheios.fe.all.WithCallback)

target_compile_options(Pantheios.fe.all.WithCallback
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

install(TARGETS Pantheios.fe.all.WithCallback
	EXPORT project-targets
)

install_file(frontends fe.all.h)


# ############################## end of file ############################# #

