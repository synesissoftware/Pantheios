
set(BE_COMERROROBJECT_SRC_DIR ../../../src/backends/be)

file(GLOB BE_COMERROROBJECT_SRCS
	${BE_COMERROROBJECT_SRC_DIR}/be.COMErrorObject.c
)

add_library(Pantheios.be.COMErrorObject
	${BE_COMERROROBJECT_SRCS}
)

target_link_libraries(Pantheios.be.COMErrorObject
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.be.COMErrorObject PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.be.COMErrorObject)


# ############################## end of file ############################# #

