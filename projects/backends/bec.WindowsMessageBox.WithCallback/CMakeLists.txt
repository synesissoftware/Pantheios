
set(BEC_WINDOWSMESSAGEBOX_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSMESSAGEBOX_WC_SRCS
	${BEC_WINDOWSMESSAGEBOX_WC_SRC_DIR}/bec.WindowsMessageBox.cpp
)

add_library(Pantheios.bec.WindowsMessageBox.WithCallback
	${BEC_WINDOWSMESSAGEBOX_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsMessageBox.WithCallback)

target_compile_options(Pantheios.bec.WindowsMessageBox.WithCallback
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

install(TARGETS Pantheios.bec.WindowsMessageBox.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

