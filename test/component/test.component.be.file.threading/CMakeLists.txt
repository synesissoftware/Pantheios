
add_executable(test.component.be.file.threading
	test.component.be.file.threading.cpp
)

target_link_Pantheios_core(test.component.be.file.threading)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
)

target_link_libraries(test.component.be.file.threading
	PRIVATE
		Pantheios.fe.N
)

target_link_Pantheios_util(test.component.be.file.threading)

target_link_xTests(test.component.be.file.threading)

target_compile_options(test.component.be.file.threading
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-null-pointer-arithmetic
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

