
add_executable(test.scratch.be.N.with.custom.fe
	test.scratch.be.N.with.custom.fe.cpp
)

target_link_libraries(test.scratch.be.N.with.custom.fe
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.scratch.be.N.with.custom.fe
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(test.scratch.be.N.with.custom.fe
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.scratch.be.N.with.custom.fe
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(test.scratch.be.N.with.custom.fe PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

