
set(BEC_COMERROROBJECT_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_COMERROROBJECT_WC_SRCS
	${BEC_COMERROROBJECT_WC_SRC_DIR}/bec.COMErrorObject.cpp
)

add_library(Pantheios.bec.COMErrorObject.WithCallback
	${BEC_COMERROROBJECT_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.COMErrorObject.WithCallback)

target_compile_options(Pantheios.bec.COMErrorObject.WithCallback
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

install(TARGETS Pantheios.bec.COMErrorObject.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

