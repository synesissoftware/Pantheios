
set(BE_WINDOWSCONSOLE_SRC_DIR ../../../src/backends/be)

file(GLOB BE_WINDOWSCONSOLE_SRCS
	${BE_WINDOWSCONSOLE_SRC_DIR}/be.WindowsConsole.c
)

add_library(Pantheios.be.WindowsConsole
	${BE_WINDOWSCONSOLE_SRCS}
)

target_link_libraries(Pantheios.be.WindowsConsole
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.be.WindowsConsole PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.be.WindowsConsole)


# ############################## end of file ############################# #

