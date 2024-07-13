
set(BEC_WINDOWSCONSOLE_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSCONSOLE_SRCS
	${BEC_WINDOWSCONSOLE_SRC_DIR}/bec.WindowsConsole.cpp
)

add_library(Pantheios.bec.WindowsConsole
	${BEC_WINDOWSCONSOLE_SRCS}
)

target_link_libraries(Pantheios.bec.WindowsConsole
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bec.WindowsConsole PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.WindowsConsole)


# ############################## end of file ############################# #

