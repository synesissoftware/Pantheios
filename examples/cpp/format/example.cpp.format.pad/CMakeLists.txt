
add_executable(example.cpp.format.pad
	example.cpp.format.pad.cpp
)

target_link_libraries(example.cpp.format.pad
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.format.pad
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(example.cpp.format.pad
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.format.pad
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.format.pad
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.format.pad PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

