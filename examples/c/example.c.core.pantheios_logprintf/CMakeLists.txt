
add_executable(example.c.core.pantheios_logprintf
	example.c.core.pantheios_logprintf.c
)

target_link_libraries(example.c.core.pantheios_logprintf
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.c.core.pantheios_logprintf
	PRIVATE
		Pantheios.fe.simple
)

if(UNIX)

	target_link_libraries(example.c.core.pantheios_logprintf
		PRIVATE
			Pantheios.be.fprintf
			Pantheios.bec.fprintf
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.c.core.pantheios_logprintf
		PRIVATE
			Pantheios.be.WindowsConsole
			Pantheios.bec.WindowsConsole
	)
endif(WIN32)

target_compile_options(example.c.core.pantheios_logprintf PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

