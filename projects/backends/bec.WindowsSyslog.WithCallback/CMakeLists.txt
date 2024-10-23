
set(BEC_WINDOWSSYSLOG_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSSYSLOG_WC_SRCS
	${BEC_WINDOWSSYSLOG_WC_SRC_DIR}/bec.WindowsSyslog.cpp
)

add_library(Pantheios.bec.WindowsSyslog.WithCallback
	${BEC_WINDOWSSYSLOG_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsSyslog.WithCallback)

target_compile_options(Pantheios.bec.WindowsSyslog.WithCallback
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

install(TARGETS Pantheios.bec.WindowsSyslog.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

