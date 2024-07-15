
add_executable(example.c.util.gethostname
	example.c.util.gethostname.c
)

target_link_libraries(example.c.util.gethostname
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.c.util.gethostname
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.c.util.gethostname
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(example.c.util.gethostname
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.c.util.gethostname PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

