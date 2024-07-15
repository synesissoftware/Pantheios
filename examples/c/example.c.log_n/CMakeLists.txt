
add_executable(example.c.log_n
	example.c.log_n.c
)

target_link_libraries(example.c.log_n
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.c.log_n
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.c.log_n
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(example.c.log_n
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.c.log_n
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.c.log_n PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

