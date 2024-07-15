
set(BE_WINDOWSSYSLOG_SRC_DIR ../../../src/backends/be)

file(GLOB BE_WINDOWSSYSLOG_SRCS
	${BE_WINDOWSSYSLOG_SRC_DIR}/be.WindowsSyslog.c
)

add_library(Pantheios.be.WindowsSyslog
	${BE_WINDOWSSYSLOG_SRCS}
)

target_link_libraries(Pantheios.be.WindowsSyslog
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(Pantheios.be.WindowsSyslog PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.be.WindowsSyslog)


# ############################## end of file ############################# #

