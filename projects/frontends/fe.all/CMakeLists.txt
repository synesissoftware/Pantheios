
set(FE_ALL_SRC_DIR ../../../src/frontends)

file(GLOB FE_ALL_SRCS
	${FE_ALL_SRC_DIR}/fe.all.c
)

add_library(pantheios_fe_all
	${FE_ALL_SRCS}
)

target_compile_options(pantheios_fe_all PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Werror -Wall -Wextra -pedantic
    #-Wno-missing-braces
    #-Wno-missing-field-initializers
	#-Wno-unused-parameter
    #-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

install(TARGETS pantheios_fe_all)


