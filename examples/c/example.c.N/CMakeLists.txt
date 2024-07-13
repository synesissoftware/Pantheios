
add_executable(example.c.N
	example.c.N.c
)

target_link_libraries(example.c.N
	Pantheios.util
	Pantheios.core
)

target_link_libraries(example.c.N
	Pantheios.fe.N
)

target_link_libraries(example.c.N
	Pantheios.be.N
	Pantheios.bec.file
	Pantheios.bec.fprintf
	Pantheios.bec.null
)

if(UNIX)

	target_link_libraries(example.c.N
		Pantheios.bec.syslog
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.c.N
		Pantheios.bec.WindowsSyslog
	)
endif(WIN32)

target_compile_options(example.c.N PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

