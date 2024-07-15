
add_executable(example.cpp.tracing.standard
	example.cpp.tracing.standard.cpp
)

target_link_libraries(example.cpp.tracing.standard
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.tracing.standard
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(example.cpp.tracing.standard
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.tracing.standard
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.tracing.standard
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.tracing.standard PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

