
add_executable(example.c.extended_severity
	example.c.extended_severity.c
)

target_link_libraries(example.c.extended_severity
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.c.extended_severity
	PRIVATE
		Pantheios.fe.simple
)

if(UNIX)

	target_link_libraries(example.c.extended_severity
		PRIVATE
			Pantheios.be.fprintf
			Pantheios.bec.fprintf
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.c.extended_severity
		PRIVATE
			Pantheios.be.WindowsConsole
			Pantheios.bec.WindowsConsole
	)
endif(WIN32)

target_compile_options(example.c.extended_severity PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

