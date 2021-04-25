
set(FE_SIMPLE_SRC_DIR ../../../src/frontends)

file(GLOB FE_SIMPLE_SRCS
	${FE_SIMPLE_SRC_DIR}/fe.simple.c
)

add_library(pantheios_fe_simple
	${FE_SIMPLE_SRCS}
)

target_compile_options(pantheios_fe_simple PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Werror -Wall -Wextra -pedantic
    #-Wno-missing-braces
    #-Wno-missing-field-initializers
	#-Wno-unused-parameter
    #-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

install(TARGETS pantheios_fe_simple)


