
add_executable(example.c.N
	example.c.N.c
)

target_link_libraries(example.c.N
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.c.N
	PRIVATE
		Pantheios.fe.N
)

target_link_libraries(example.c.N
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		Pantheios.bec.fprintf
		Pantheios.bec.null
)

target_link_libraries(example.c.N
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsSyslog,Pantheios.bec.syslog>
)

target_link_libraries(example.c.N
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.c.N
	PRIVATE
		STLSoft::STLSoft
)

if(WIN32)

	target_link_libraries(example.c.N
		PRIVATE
			ws2_32
	)
endif(WIN32)

target_compile_options(example.c.N PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

