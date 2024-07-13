
add_executable(example.cpp.misc.extended_severity_information
	example.cpp.misc.extended_severity_information.cpp
)

target_link_libraries(example.cpp.misc.extended_severity_information
	Pantheios.util
	Pantheios.core
)

target_link_libraries(example.cpp.misc.extended_severity_information
	Pantheios.fe.simple
)

target_compile_options(example.cpp.misc.extended_severity_information PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

