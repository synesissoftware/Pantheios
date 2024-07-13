
add_executable(example.c.util.getcurrenttime
	example.c.util.getcurrenttime.c
)

target_link_libraries(example.c.util.getcurrenttime
	Pantheios.util
	Pantheios.core
)

target_link_libraries(example.c.util.getcurrenttime
	Pantheios.fe.simple
)

if(UNIX)

	target_link_libraries(example.c.util.getcurrenttime
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.c.util.getcurrenttime
		Pantheios.be.WindowsConsole
		Pantheios.bec.WindowsConsole
	)
endif(WIN32)

target_compile_options(example.c.util.getcurrenttime PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

