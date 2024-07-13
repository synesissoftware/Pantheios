
add_executable(test.scratch.be.N
	test.scratch.be.N.cpp
)

target_link_libraries(test.scratch.be.N
	Pantheios.util
	Pantheios.core
)

target_link_libraries(test.scratch.be.N
	Pantheios.fe.N
)

target_link_libraries(test.scratch.be.N
	Pantheios.be.N
	Pantheios.bec.file
	Pantheios.bec.fprintf
)

if(UNIX)

	target_link_libraries(test.scratch.be.N
		Pantheios.bec.syslog
	)
endif(UNIX)

if(WIN32)

	target_link_libraries(test.scratch.be.N
		Pantheios.bec.WindowsDebugger.WithCallback
		Pantheios.bec.WindowsSyslog
	)
endif(WIN32)

target_compile_options(test.scratch.be.N PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

