
add_executable(test.unit.util.getcurrenttime
	test.unit.util.getcurrenttime.cpp
)

target_link_libraries(test.unit.util.getcurrenttime
	Pantheios.util
)

target_link_libraries(test.unit.util.getcurrenttime
	shwild::shwild.core
	xTests::xTests.core
)

target_compile_options(test.unit.util.getcurrenttime PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

