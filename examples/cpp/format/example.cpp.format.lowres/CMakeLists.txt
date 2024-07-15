
add_executable(example.cpp.format.lowres
	example.cpp.format.lowres.cpp
)

target_link_libraries(example.cpp.format.lowres
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.format.lowres
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.format.lowres
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(example.cpp.format.lowres
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.format.lowres
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.format.lowres PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

