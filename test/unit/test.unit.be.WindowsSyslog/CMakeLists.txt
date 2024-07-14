
add_executable(test.unit.be.WindowsSyslog
	test.unit.be.WindowsSyslog.cpp
)

target_link_libraries(test.unit.be.WindowsSyslog
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.be.WindowsSyslog
	PRIVATE
		Pantheios.be.WindowsSyslog
		Pantheios.bec.WindowsSyslog
)

target_link_libraries(test.unit.be.WindowsSyslog
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_link_libraries(test.unit.be.WindowsSyslog
	PRIVATE
		ws2_32
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

