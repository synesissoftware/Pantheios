
add_executable(test.unit.bec.COMErrorObject
	test.unit.bec.COMErrorObject.cpp
)

target_link_libraries(test.unit.bec.COMErrorObject
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.bec.COMErrorObject
	PRIVATE
		Pantheios.bec.COMErrorObject
)

target_link_libraries(test.unit.bec.COMErrorObject
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.bec.COMErrorObject PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

