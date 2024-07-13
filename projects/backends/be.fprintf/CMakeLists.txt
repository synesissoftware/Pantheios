
set(BE_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BE_FPRINTF_SRCS
	${BE_FPRINTF_SRC_DIR}/be/be.fprintf.c
)

add_library(Pantheios.be.fprintf
	${BE_FPRINTF_SRCS}
)

target_link_libraries(Pantheios.be.fprintf
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.be.fprintf PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.be.fprintf)


