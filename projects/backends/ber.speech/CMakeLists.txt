
set(BER_SPEECH_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_SPEECH_SRCS
	${BER_SPEECH_SRC_DIR}/ber.speech.c
)

add_library(Pantheios.ber.speech
	${BER_SPEECH_SRCS}
)

target_link_STLSoft(Pantheios.ber.speech)

define_target_compile_options(Pantheios.ber.speech)

install(TARGETS Pantheios.ber.speech
	EXPORT project-targets
)


# ############################## end of file ############################# #

