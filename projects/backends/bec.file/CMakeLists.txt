
set(BEC_FILE_SRC_DIR ../../../src/backends)

file(GLOB BEC_FILE_SRCS
	${BEC_FILE_SRC_DIR}/bec.file.cpp
)

add_library(Pantheios.bec.file
	${BEC_FILE_SRCS}
)

target_link_libraries(Pantheios.bec.file
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bec.file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.file)


# ############################## end of file ############################# #

