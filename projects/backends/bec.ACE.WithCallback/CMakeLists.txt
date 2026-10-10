
set(BEC_ACE_SRC_DIR ../../../src/backends)

file(GLOB BEC_ACE_SRCS
	${BEC_ACE_SRC_DIR}/bec.ACE.cpp
)

add_library(Pantheios.bec.ACE.WithCallback
	${BEC_ACE_SRCS}
)

target_link_STLSoft(Pantheios.bec.ACE.WithCallback)

target_link_ACE(Pantheios.bec.ACE.WithCallback)

target_compile_options(Pantheios.bec.ACE.WithCallback
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

install(TARGETS Pantheios.bec.ACE.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #
