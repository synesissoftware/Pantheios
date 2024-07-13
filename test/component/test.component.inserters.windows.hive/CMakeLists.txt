
add_executable(test.component.inserters.windows.hive
	test.component.inserters.windows.hive.cpp
)

target_link_libraries(test.component.inserters.windows.hive
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.component.inserters.windows.hive
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.component.inserters.windows.hive
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.windows.hive
	PRIVATE
		xTests::xTests.core
)

target_compile_options(test.component.inserters.windows.hive PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

