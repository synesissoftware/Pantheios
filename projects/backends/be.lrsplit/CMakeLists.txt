
set(BE_LRSPLIT_SRC_DIR ../../../src/backends)

file(GLOB BE_LRSPLIT_SRCS
	${BE_LRSPLIT_SRC_DIR}/be.lrsplit.c
)

add_library(Pantheios.be.lrsplit
	${BE_LRSPLIT_SRCS}
)

target_link_libraries(Pantheios.be.lrsplit
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.be.lrsplit PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-unused-parameter
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.be.lrsplit)


# ############################## end of file ############################# #

