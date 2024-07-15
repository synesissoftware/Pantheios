
add_executable(example.cpp.inserter.m2w
	example.cpp.inserter.m2w.cpp
)

target_link_libraries(example.cpp.inserter.m2w
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.inserter.m2w
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.inserter.m2w
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(example.cpp.inserter.m2w
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.inserter.m2w
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.inserter.m2w PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

