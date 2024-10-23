
set(BE_SPEECH_SRC_DIR ../../../src/backends/be)

file(GLOB BE_SPEECH_SRCS
	${BE_SPEECH_SRC_DIR}/be.speech.c
)

add_library(Pantheios.be.speech
	${BE_SPEECH_SRCS}
)

target_link_STLSoft(Pantheios.be.speech)

define_target_compile_options(Pantheios.be.speech)

install(TARGETS Pantheios.be.speech
	EXPORT project-targets
)


# ############################## end of file ############################# #

