
add_executable(test.component.core.getProcessIdentity
	test.component.core.getProcessIdentity.c
)

target_link_libraries(test.component.core.getProcessIdentity
	Pantheios.util
	Pantheios.core
)

target_link_libraries(test.component.core.getProcessIdentity
	Pantheios.be.null
	Pantheios.bec.null
)

target_link_libraries(test.component.core.getProcessIdentity
	xTests::xTests.core
)

target_compile_options(test.component.core.getProcessIdentity PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-unused-parameter
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

