
set(BEC_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BEC_FPRINTF_SRCS
	${BEC_FPRINTF_SRC_DIR}/bec.AnsiConsole.cpp
)

add_library(Pantheios.bec.AnsiConsole.WithCallback
	${BEC_FPRINTF_SRCS}
)

target_link_STLSoft(Pantheios.bec.AnsiConsole.WithCallback)

target_compile_options(Pantheios.bec.AnsiConsole.WithCallback
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

install(TARGETS Pantheios.bec.AnsiConsole.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

