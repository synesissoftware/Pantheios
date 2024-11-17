
add_executable(test.component.inserters.b64
	test.component.inserters.b64.cpp
)

target_link_Pantheios_core(test.component.inserters.b64)

target_link_libraries(test.component.inserters.b64
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.b64
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.b64)

target_link_libraries(test.component.inserters.b64
	PRIVATE
		b64::core
)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.b64)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.b64)

target_compile_options(test.component.inserters.b64 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		#-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

