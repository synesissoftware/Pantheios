
set(BER_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BER_FPRINTF_SRCS
	${BER_FPRINTF_SRC_DIR}/ber/ber.fprintf.c
)

add_library(Pantheios.ber.fprintf
	${BER_FPRINTF_SRCS}
)

target_link_libraries(Pantheios.ber.fprintf
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.ber.fprintf PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.ber.fprintf)


# ############################## end of fprintf ############################# #

