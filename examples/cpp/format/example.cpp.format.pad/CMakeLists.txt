
add_executable(example.cpp.format.pad
	example.cpp.format.pad.cpp
)

target_link_libraries(example.cpp.format.pad
	Pantheios.util
	Pantheios.core
)

target_link_libraries(example.cpp.format.pad
	Pantheios.fe.simple
)

if(UNIX)

	target_link_libraries(example.cpp.format.pad
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.cpp.format.pad
		pantheios_be_WindowsConsole
		pantheios_bec_WindowsConsole
	)
endif(WIN32)

target_compile_options(example.cpp.format.pad PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

