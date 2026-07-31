
add_executable(test.scratch.WideString
	test.scratch.WideString.cpp
)

target_link_Pantheios_core(test.scratch.WideString)

target_link_libraries(test.scratch.WideString
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.WideString
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.WideString)

target_link_STLSoft(test.scratch.WideString)

target_link_libraries(test.scratch.WideString
	PRIVATE
		$<$<BOOL:${b64_FOUND}>:b64::core>
)

define_target_compile_options(test.scratch.WideString)


# ############################## end of file ############################# #

