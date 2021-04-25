
set(BEC_NULL_SRC_DIR ../../../src/backends)

file(GLOB BEC_NULL_SRCS
	${BEC_NULL_SRC_DIR}/bec.null.c
)

add_library(pantheios_bec_null
	${BEC_NULL_SRCS}
)

target_compile_options(pantheios_bec_null PRIVATE
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

install(TARGETS pantheios_bec_null)


