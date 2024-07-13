
add_executable(example.cpp.misc.no_namespace
	example.cpp.misc.no_namespace.cpp
)

target_link_libraries(example.cpp.misc.no_namespace
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.cpp.misc.no_namespace
	PRIVATE
		Pantheios.fe.simple
)

if(UNIX)

	target_link_libraries(example.cpp.misc.no_namespace
		PRIVATE
			Pantheios.be.fprintf
			Pantheios.bec.fprintf
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.cpp.misc.no_namespace
		PRIVATE
			Pantheios.be.WindowsConsole
			Pantheios.bec.WindowsConsole
	)
endif(WIN32)

target_link_libraries(example.cpp.misc.no_namespace
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.misc.no_namespace PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

