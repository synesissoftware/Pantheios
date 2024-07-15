
set(BEC_COMERROROBJECT_SRC_DIR ../../../src/backends)

file(GLOB BEC_COMERROROBJECT_SRCS
	${BEC_COMERROROBJECT_SRC_DIR}/bec.COMErrorObject.cpp
)

add_library(Pantheios.bec.COMErrorObject
	${BEC_COMERROROBJECT_SRCS}
)

target_link_libraries(Pantheios.bec.COMErrorObject
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bec.COMErrorObject PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.COMErrorObject)


# ############################## end of file ############################# #

