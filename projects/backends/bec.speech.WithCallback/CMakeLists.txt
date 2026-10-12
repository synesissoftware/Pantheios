
set(BEC_SPEECH_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_SPEECH_WC_SRCS
	${BEC_SPEECH_WC_SRC_DIR}/bec.speech.cpp
)

add_library(Pantheios.bec.speech.WithCallback
	${BEC_SPEECH_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.speech.WithCallback)

target_compile_options(Pantheios.bec.speech.WithCallback
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

install(TARGETS Pantheios.bec.speech.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

