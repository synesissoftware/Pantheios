
set(BEC_WINDOWSCONSOLE_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSCONSOLE_WC_SRCS
	${BEC_WINDOWSCONSOLE_WC_SRC_DIR}/bec.WindowsConsole.cpp
)

add_library(Pantheios.bec.WindowsConsole.WithCallback
	${BEC_WINDOWSCONSOLE_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsConsole.WithCallback)

target_compile_options(Pantheios.bec.WindowsConsole.WithCallback
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

install(TARGETS Pantheios.bec.WindowsConsole.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

