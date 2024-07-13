
add_executable(example.cpp.inserter.xi
	example.cpp.inserter.xi.cpp
)

target_link_libraries(example.cpp.inserter.xi
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.cpp.inserter.xi
	PRIVATE
		Pantheios.fe.simple
)

if(UNIX)

	target_link_libraries(example.cpp.inserter.xi
		PRIVATE
			Pantheios.be.fprintf
			Pantheios.bec.fprintf
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(example.cpp.inserter.xi
		PRIVATE
			Pantheios.be.WindowsConsole
			Pantheios.bec.WindowsConsole
	)
endif(WIN32)

target_link_libraries(example.cpp.inserter.xi
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.inserter.xi PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

