
set(FE_NULL_SRC_DIR ../../../src/frontends)

file(GLOB FE_NULL_SRCS
	${FE_NULL_SRC_DIR}/fe.null.c
)

add_library(pantheios_fe_null
	${FE_NULL_SRCS}
)

target_compile_options(pantheios_fe_null PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
		#-Wno-missing-braces
		#-Wno-missing-field-initializers
		#-Wno-unused-parameter
		#-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>:
	    /WX /W4
	>
)

install(TARGETS pantheios_fe_null)


