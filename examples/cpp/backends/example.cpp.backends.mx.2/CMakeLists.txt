
add_executable(example.cpp.backends.mx.2
	example.cpp.backends.mx.2.cpp
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.be.N
)

if(UNIX)

	target_link_libraries(example.cpp.backends.mx.2
		PRIVATE
			Pantheios.bec.fprintf
			Pantheios.bec.syslog
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.cpp.backends.mx.2
		PRIVATE
			Pantheios.bec.WindowsConsole
			Pantheios.bec.WindowsSyslog
	)

	target_link_libraries(example.cpp.backends.mx.2
		PRIVATE
			ws2_32
	)
endif(WIN32)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.backends.mx.2 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

