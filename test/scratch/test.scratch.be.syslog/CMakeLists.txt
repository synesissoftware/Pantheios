
add_executable(test.scratch.be.syslog
	test.scratch.be.syslog.cpp
)

target_link_Pantheios_core(test.scratch.be.syslog)

target_link_libraries(test.scratch.be.syslog
	PRIVATE
		Pantheios.be.syslog
		Pantheios.bec.syslog
)

target_link_libraries(test.scratch.be.syslog
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.be.syslog)

target_link_STLSoft(test.scratch.be.syslog)

target_compile_options(test.scratch.be.syslog
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

