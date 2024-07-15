
add_executable(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT.cpp
)

target_link_libraries(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	PRIVATE
		Pantheios.core
)

target_link_libraries(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

