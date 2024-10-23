
set(BEC_WINDOWSDEBUGGER_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSDEBUGGER_WC_SRCS
	${BEC_WINDOWSDEBUGGER_WC_SRC_DIR}/bec.WindowsDebugger.cpp
)

add_library(Pantheios.bec.WindowsDebugger.WithCallback
	${BEC_WINDOWSDEBUGGER_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsDebugger.WithCallback)

target_compile_options(Pantheios.bec.WindowsDebugger.WithCallback
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

install(TARGETS Pantheios.bec.WindowsDebugger.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

