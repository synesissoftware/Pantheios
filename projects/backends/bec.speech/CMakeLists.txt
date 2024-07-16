
set(BEC_SPEECH_SRC_DIR ../../../src/backends)

file(GLOB BEC_SPEECH_SRCS
	${BEC_SPEECH_SRC_DIR}/bec.speech.cpp
)

add_library(Pantheios.bec.speech
	${BEC_SPEECH_SRCS}
)

target_link_libraries(Pantheios.bec.speech
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bec.speech PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.speech)


# ############################## end of file ############################# #

