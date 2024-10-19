
add_executable(test.component.inserters.processid
	test.component.inserters.processid.cpp
)

target_link_Pantheios_core(test.component.inserters.processid)

target_link_libraries(test.component.inserters.processid
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.processid
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.processid)

target_link_xTests(test.component.inserters.processid)

target_compile_options(test.component.inserters.processid
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

