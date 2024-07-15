
add_executable(test.component.be.file.threading
	test.component.be.file.threading.cpp
)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.core
)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.fe.N
)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		xTests::core
)

target_compile_options(test.component.be.file.threading PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

