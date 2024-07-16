
set(BEC_WINDOWSSYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSSYSLOG_SRCS
	${BEC_WINDOWSSYSLOG_SRC_DIR}/bec.WindowsSyslog.cpp
)

add_library(Pantheios.bec.WindowsSyslog
	${BEC_WINDOWSSYSLOG_SRCS}
)

target_link_libraries(Pantheios.bec.WindowsSyslog
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.bec.WindowsSyslog PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.WindowsSyslog)


# ############################## end of file ############################# #

