
set(CORE_SRC_DIR ../../src/core)
set(INSERTER_SRC_DIR ../../src/inserters)

file(GLOB CORE_SRCS
	${CORE_SRC_DIR}/*.c
	${CORE_SRC_DIR}/*.cpp
)

file(GLOB INSERTER_SRCS
	${INSERTER_SRC_DIR}/*.cpp
)

if(DEFINED ENV{PANTHEIOS_NO_B64})

	list(FILTER INSERTER_SRCS EXCLUDE REGEX "b64")
endif()
list(FILTER INSERTER_SRCS EXCLUDE REGEX "m2w")

add_library(Pantheios.core
	${CORE_SRCS}
	${INSERTER_SRCS}
)

target_compile_options(Pantheios.core PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.core)


# ############################## end of file ############################# #

