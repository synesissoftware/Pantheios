
add_executable(test.scratch.be.N
	test.scratch.be.N.cpp
)

target_link_Pantheios_core(test.scratch.be.N)

target_link_libraries(test.scratch.be.N
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		Pantheios.bec.fprintf
)

if(UNIX)

	target_link_libraries(test.scratch.be.N
		PRIVATE
			Pantheios.bec.syslog
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(test.scratch.be.N
		PRIVATE
			Pantheios.bec.WindowsDebugger.WithCallback
			Pantheios.bec.WindowsSyslog
	)
endif(WIN32)

target_link_libraries(test.scratch.be.N
	PRIVATE
		Pantheios.fe.N
)

target_link_Pantheios_util(test.scratch.be.N)

target_link_STLSoft(test.scratch.be.N)

target_compile_options(test.scratch.be.N
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-deprecated-copy-with-user-provided-copy
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ############################## end of file ############################# #

