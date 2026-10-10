
set(BEL_SPEECH_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_SPEECH_SRCS
	${BEL_SPEECH_SRC_DIR}/bel.speech.c
)

add_library(Pantheios.bel.speech
	${BEL_SPEECH_SRCS}
)

target_link_STLSoft(Pantheios.bel.speech)

define_target_compile_options(Pantheios.bel.speech)

install(TARGETS Pantheios.bel.speech
	EXPORT project-targets
)


# ############################## end of file ############################# #

