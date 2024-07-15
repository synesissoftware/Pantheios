
add_executable(example.cpp.format.highres
	example.cpp.format.highres.cpp
)

target_link_libraries(example.cpp.format.highres
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.format.highres
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.format.highres
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf.WithCallback
)

target_link_libraries(example.cpp.format.highres
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.format.highres
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.format.highres PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

