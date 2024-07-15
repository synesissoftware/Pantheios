
add_executable(example.cpp.backends.mx.1
	example.cpp.backends.mx.1.cpp
)

target_link_libraries(example.cpp.backends.mx.1
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.cpp.backends.mx.1
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.backends.mx.1
	PRIVATE
		Pantheios.be.N
)

target_link_libraries(example.cpp.backends.mx.1
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsSyslog,Pantheios.bec.syslog>
)

if(WIN32)

	target_link_libraries(example.cpp.backends.mx.1
		PRIVATE
			ws2_32
	)
endif(WIN32)

target_link_libraries(example.cpp.backends.mx.1
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.backends.mx.1 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

