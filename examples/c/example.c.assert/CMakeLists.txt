
add_executable(example.c.assert
	example.c.assert.c
)

target_link_libraries(example.c.assert
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.c.assert
	PRIVATE
		Pantheios.fe.simple
)

if(UNIX)

	target_link_libraries(example.c.assert
		PRIVATE
			Pantheios.be.fprintf
			Pantheios.bec.fprintf
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.c.assert
		PRIVATE
			Pantheios.be.WindowsConsole
			Pantheios.bec.WindowsConsole
	)
endif(WIN32)

target_compile_options(example.c.assert PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

