
add_executable(test.unit.be.WindowsSyslog
	test.unit.be.WindowsSyslog.c
)

target_link_libraries(test.unit.be.WindowsSyslog
	Pantheios.util
)

target_link_libraries(test.unit.be.WindowsSyslog
	Pantheios.be.WindowsSyslog
)

target_link_libraries(test.unit.be.WindowsSyslog
	xTests::xTests.core
)

target_compile_options(test.unit.be.WindowsSyslog PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

