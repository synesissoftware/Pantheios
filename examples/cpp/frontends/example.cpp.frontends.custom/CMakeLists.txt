
add_executable(example.cpp.frontends.custom
	example.cpp.frontends.custom.cpp
)

target_link_libraries(example.cpp.frontends.custom
	Pantheios.util
	Pantheios.core
)

target_link_libraries(example.cpp.frontends.custom
	Pantheios.be.fprintf
	Pantheios.bec.fprintf
)

target_compile_options(example.cpp.frontends.custom PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

