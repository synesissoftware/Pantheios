
add_executable(test.unit.getversion
	test.unit.getversion.c
)

target_link_libraries(test.unit.getversion
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.unit.getversion
	PRIVATE
		Pantheios.fe.fail
		# Pantheios.fe.null
)

target_link_libraries(test.unit.getversion
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.unit.getversion
	PRIVATE
		STLSoft::STLSoft
		xTests::xTests.core
)

target_compile_options(test.unit.getversion PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

