
set(BEC_STOCK_WC_SRC_DIR ../../../src/backends)

file(GLOB BEC_STOCK_WC_SRCS_common
	${BEC_STOCK_WC_SRC_DIR}/bec.fail.c
	${BEC_STOCK_WC_SRC_DIR}/bec.file.cpp
	${BEC_STOCK_WC_SRC_DIR}/bec.fprintf.cpp
	${BEC_STOCK_WC_SRC_DIR}/bec.null.c
	${BEC_STOCK_WC_SRC_DIR}/bec.test.cpp
)

set(BEC_STOCK_WC_SRCS ${BEC_STOCK_WC_SRCS_common})

if(HAS_ACE)

	file(GLOB BEC_STOCK_WC_SRCS_ace
		${BEC_STOCK_WC_SRC_DIR}/bec.ACE.cpp
	)

	set(BEC_STOCK_WC_SRCS ${BEC_STOCK_WC_SRCS} ${BEC_STOCK_WC_SRCS_ace})
endif(HAS_ACE)

if(UNIX)

	file(GLOB BEC_STOCK_WC_SRCS_unix
		${BEC_STOCK_WC_SRC_DIR}/bec.syslog.c
	)

	set(BEC_STOCK_WC_SRCS ${BEC_STOCK_WC_SRCS} ${BEC_STOCK_WC_SRCS_unix})
endif(UNIX)

if(WIN32)

	file(GLOB BEC_STOCK_WC_SRCS_win32
		${BEC_STOCK_WC_SRC_DIR}/bec.COMErrorObject.cpp
		${BEC_STOCK_WC_SRC_DIR}/bec.WindowsConsole.cpp
		${BEC_STOCK_WC_SRC_DIR}/bec.WindowsDebugger.cpp
		${BEC_STOCK_WC_SRC_DIR}/bec.WindowsEventLog.cpp
		${BEC_STOCK_WC_SRC_DIR}/bec.WindowsMessageBox.cpp
		${BEC_STOCK_WC_SRC_DIR}/bec.WindowsSyslog.cpp
		${BEC_STOCK_WC_SRC_DIR}/bec.speech.cpp
	)

	set(BEC_STOCK_WC_SRCS ${BEC_STOCK_WC_SRCS} ${BEC_STOCK_WC_SRCS_win32})
endif(WIN32)

add_library(Pantheios.bec.stock.WithCallback
	${BEC_STOCK_WC_SRCS}
)

target_link_STLSoft(Pantheios.bec.stock.WithCallback)

target_compile_options(Pantheios.bec.stock.WithCallback
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-unused-function
			-Wno-unused-private-field # this (temporarily) for bec.test.cpp

			-DPANTHEIOS_BE_USE_CALLBACK
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			-DPANTHEIOS_BE_USE_CALLBACK
		>
)

install(TARGETS Pantheios.bec.stock.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

