
set(BEC_FILE_SRC_DIR ../../../src/backends)

file(GLOB BEC_FILE_SRCS
	${BEC_FILE_SRC_DIR}/bec.file.cpp
    )

add_library(pantheios_bec_file
	${BEC_FILE_SRCS}
	)

target_compile_options(pantheios_bec_file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Werror -Wall -Wextra -pedantic
    #-Wno-missing-braces
    #-Wno-missing-field-initializers
	#-Wno-unused-parameter
    #-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
    )

install(TARGETS pantheios_bec_file)


