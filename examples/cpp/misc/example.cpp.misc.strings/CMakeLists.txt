
add_executable(example.cpp.misc.strings
	example.cpp.misc.strings.cpp
)

target_link_libraries(example.cpp.misc.strings
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.misc.strings
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(example.cpp.misc.strings
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.misc.strings
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.misc.strings
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.misc.strings PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

