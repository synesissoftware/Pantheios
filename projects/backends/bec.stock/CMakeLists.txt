
set(BEC_STOCK_SRC_DIR ../../../src/backends)

file(GLOB BEC_STOCK_SRCS_common
	${BEC_STOCK_SRC_DIR}/be.N.c
	${BEC_STOCK_SRC_DIR}/be.lrsplit.c
	${BEC_STOCK_SRC_DIR}/bec.fail.c
	${BEC_STOCK_SRC_DIR}/bec.file.cpp
	${BEC_STOCK_SRC_DIR}/bec.fprintf.cpp
	${BEC_STOCK_SRC_DIR}/bec.null.c
	${BEC_STOCK_SRC_DIR}/bec.test.cpp
)

set(BEC_STOCK_SRCS ${BEC_STOCK_SRCS_common})

if (HAS_ACE)

	file(GLOB BEC_STOCK_SRCS_ace
		${BEC_STOCK_SRC_DIR}/bec.ACE.cpp
	)

	set(BEC_STOCK_SRCS ${BEC_STOCK_SRCS} ${BEC_STOCK_SRCS_ace})
endif (HAS_ACE)

if (UNIX)

	file(GLOB BEC_STOCK_SRCS_unix
		${BEC_STOCK_SRC_DIR}/bec.syslog.c
	)

	set(BEC_STOCK_SRCS ${BEC_STOCK_SRCS} ${BEC_STOCK_SRCS_unix})
endif (UNIX)

if (WIN32)

	file(GLOB BEC_STOCK_SRCS_win32
		${BEC_STOCK_SRC_DIR}/bec.COMErrorObject.cpp
		${BEC_STOCK_SRC_DIR}/bec.WindowsConsole.cpp
		${BEC_STOCK_SRC_DIR}/bec.WindowsDebugger.cpp
		${BEC_STOCK_SRC_DIR}/bec.WindowsEventLog.cpp
		${BEC_STOCK_SRC_DIR}/bec.WindowsMessageBox.cpp
		${BEC_STOCK_SRC_DIR}/bec.WindowsSyslog.cpp
		${BEC_STOCK_SRC_DIR}/bec.speech.cpp
	)

	set(BEC_STOCK_SRCS ${BEC_STOCK_SRCS} ${BEC_STOCK_SRCS_win32})
endif (WIN32)

add_library(Pantheios.bec.stock
	${BEC_STOCK_SRCS}
)

target_compile_options(Pantheios.bec.stock PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.bec.stock)


# ############################## end of file ############################# #

