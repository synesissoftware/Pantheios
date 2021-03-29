
set(BE_NULL_SRC_DIR ../../../src/backends)

file(GLOB BE_NULL_SRCS
	${BE_NULL_SRC_DIR}/be/be.null.c
    )

add_library(pantheios_be_null
	${BE_NULL_SRCS}
	)

target_compile_options(pantheios_be_null PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Werror -Wall -Wextra -pedantic
    #-Wno-missing-braces
    #-Wno-missing-field-initializers
	#-Wno-unused-parameter
    #-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
    )


