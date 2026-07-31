
set(FE_WINDOWSREGISTRY_WC_SRC_DIR ../../../src/frontends)

file(GLOB FE_WINDOWSREGISTRY_WC_SRCS
	${FE_WINDOWSREGISTRY_WC_SRC_DIR}/fe.WindowsRegistry.cpp
)

add_library(Pantheios.fe.WindowsRegistry.WithCallback
	${FE_WINDOWSREGISTRY_WC_SRCS}
)

target_link_STLSoft(Pantheios.fe.WindowsRegistry.WithCallback)

target_compile_options(Pantheios.fe.WindowsRegistry.WithCallback
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

install(TARGETS Pantheios.fe.WindowsRegistry.WithCallback
	EXPORT project-targets
)

install_file(frontends fe.WindowsRegistry.h)


# ############################## end of file ############################# #

