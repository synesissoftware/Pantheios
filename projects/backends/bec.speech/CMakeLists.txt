
set(BEC_SPEECH_SRC_DIR ../../../src/backends)

file(GLOB BEC_SPEECH_SRCS
	${BEC_SPEECH_SRC_DIR}/bec.speech.cpp
)

add_library(Pantheios.bec.speech
	${BEC_SPEECH_SRCS}
)

target_link_STLSoft(Pantheios.bec.speech)

define_target_compile_options(Pantheios.bec.speech)

install(TARGETS Pantheios.bec.speech
	EXPORT project-targets
)

install_file(backends bec.speech.h)


# ############################## end of file ############################# #

