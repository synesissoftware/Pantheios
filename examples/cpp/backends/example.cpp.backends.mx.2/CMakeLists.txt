
add_executable(example.cpp.backends.mx.2
	example.cpp.backends.mx.2.cpp
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.be.N
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsSyslog,Pantheios.bec.syslog>
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		STLSoft::STLSoft
)

if(WIN32)

	target_link_libraries(example.cpp.backends.mx.2
		PRIVATE
			ws2_32
	)
endif(WIN32)

target_compile_options(example.cpp.backends.mx.2 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

