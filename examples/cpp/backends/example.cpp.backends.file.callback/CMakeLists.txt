
add_executable(example.cpp.backends.file.callback
	example.cpp.backends.file.callback.cpp
)

target_link_Pantheios_core(example.cpp.backends.file.callback)

target_link_libraries(example.cpp.backends.file.callback
	PRIVATE
		Pantheios.be.file
		Pantheios.bec.file.WithCallback
)

target_link_libraries(example.cpp.backends.file.callback
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.backends.file.callback)

target_link_STLSoft(example.cpp.backends.file.callback)

target_compile_options(example.cpp.backends.file.callback
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			/wd4996
		>
)


# ############################## end of file ############################# #

