
set(FE_WINDOWSREGISTRY_SRC_DIR ../../../src/frontends)

file(GLOB FE_WINDOWSREGISTRY_SRCS
	${FE_WINDOWSREGISTRY_SRC_DIR}/fe.WindowsRegistry.cpp
)

add_library(Pantheios.fe.WindowsRegistry
	${FE_WINDOWSREGISTRY_SRCS}
)

target_link_libraries(Pantheios.fe.WindowsRegistry
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.fe.WindowsRegistry PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.fe.WindowsRegistry)


# ############################## end of file ############################# #

