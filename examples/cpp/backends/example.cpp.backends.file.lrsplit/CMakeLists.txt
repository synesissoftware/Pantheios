
add_executable(example.cpp.backends.file.lrsplit
	example.cpp.backends.file.lrsplit.cpp
)

target_link_libraries(example.cpp.backends.file.lrsplit
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(example.cpp.backends.file.lrsplit
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.backends.file.lrsplit
	PRIVATE
		Pantheios.be.file
		Pantheios.bec.file
		Pantheios.bel.file
		Pantheios.ber.file
)

target_link_libraries(example.cpp.backends.file.lrsplit
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.backends.file.lrsplit PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

