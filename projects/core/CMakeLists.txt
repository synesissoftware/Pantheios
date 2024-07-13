
set(CORE_SRC_DIR ../../src/core)
set(INSERTER_SRC_DIR ../../src/inserters)

file(GLOB CORE_SRCS
	${CORE_SRC_DIR}/*.c
	${CORE_SRC_DIR}/*.cpp
)

file(GLOB INSERTER_SRCS
	${INSERTER_SRC_DIR}/*.cpp
)

if(NOT b64_FOUND)

	list(FILTER INSERTER_SRCS EXCLUDE REGEX "b64")
endif()
if(PANTHEIOS_USE_WIDE_STRINGS)

	list(FILTER INSERTER_SRCS EXCLUDE REGEX "w2m")
else(PANTHEIOS_USE_WIDE_STRINGS)

	list(FILTER INSERTER_SRCS EXCLUDE REGEX "m2w")
endif(PANTHEIOS_USE_WIDE_STRINGS)

add_library(Pantheios.core
	${CORE_SRCS}
	${INSERTER_SRCS}
)

target_link_libraries(Pantheios.core
	PRIVATE
		STLSoft::STLSoft
		$<$<BOOL:${b64_FOUND}>: b64::core>
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

# INSERTER_SRCS=C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/args.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/b64.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/blob.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/boolean.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/exception.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/hostid.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/integer.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/interval.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/m2w.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/pointer.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/processid.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/real.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/slice.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/stream_character.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/threadid.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/w2m.cpp


# CMake Warning at projects/core/CMakeLists.txt:22 (message):

#   INSERTER_SRCS=C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/args.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/b64.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/blob.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/boolean.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/exception.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/hostid.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/integer.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/interval.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/pointer.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/processid.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/real.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/slice.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/stream_character.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/threadid.cpp;C:/Users/mwsis/dev/forks/synesissoftware/Pantheios/Pantheios/projects/core/../../src/inserters/w2m.cpp
