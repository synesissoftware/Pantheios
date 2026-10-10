
set(BEC_WINDOWSEVENTLOG_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSEVENTLOG_WC_SRCS
	${BEC_WINDOWSEVENTLOG_WC_SRC_DIR}/bec.WindowsEventLog.cpp
)

add_library(Pantheios.bec.WindowsEventLog.WithCallback
	${BEC_WINDOWSEVENTLOG_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsEventLog.WithCallback)

target_compile_options(Pantheios.bec.WindowsEventLog.WithCallback
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

install(TARGETS Pantheios.bec.WindowsEventLog.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

