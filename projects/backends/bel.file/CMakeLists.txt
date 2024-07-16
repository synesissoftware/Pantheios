
set(BEL_FILE_SRC_DIR ../../../src/backends)

file(GLOB BEL_FILE_SRCS
	${BEL_FILE_SRC_DIR}/bel/bel.file.c
)

add_library(Pantheios.bel.file
	${BEL_FILE_SRCS}
)

target_link_libraries(Pantheios.bel.file
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bel.file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bel.file)


# ############################## end of file ############################# #

