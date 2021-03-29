
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

add_library(pantheios_core
	${CORE_SRCS}
	${INSERTER_SRCS}
	)

target_compile_options(pantheios_core PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Werror -Wall -Wextra -pedantic
    #-Wno-missing-braces
    #-Wno-missing-field-initializers
	#-Wno-unused-parameter
    #-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
    )

install(TARGETS pantheios_core)


