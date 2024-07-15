
add_executable(example.cpp.tracing.with_function
	example.cpp.tracing.with_function.cpp
)

target_link_libraries(example.cpp.tracing.with_function
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.tracing.with_function
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(example.cpp.tracing.with_function
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.tracing.with_function
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.tracing.with_function
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.tracing.with_function PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

