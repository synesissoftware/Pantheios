
set(BEC_FILE_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_FILE_WC_SRCS
	${BEC_FILE_WC_SRC_DIR}/bec.file.cpp
)

add_library(Pantheios.bec.file.WithCallback
	${BEC_FILE_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.file.WithCallback)

target_compile_options(Pantheios.bec.file.WithCallback
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

install(TARGETS Pantheios.bec.file.WithCallback
	EXPORT project-targets
)

install_file(backends bec.file.h)


# ############################## end of file ############################# #

