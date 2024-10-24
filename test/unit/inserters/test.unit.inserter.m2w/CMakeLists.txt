
add_executable(test.unit.inserter.m2w
	test.unit.inserter.m2w.cpp
)

target_link_Pantheios_core(test.unit.inserter.m2w)

target_link_libraries(test.unit.inserter.m2w
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.unit.inserter.m2w
	PRIVATE
		Pantheios.fe.null
)

target_link_Pantheios_util(test.unit.inserter.m2w)

target_link_STLSoft(test.unit.inserter.m2w)

target_link_xTests(test.unit.inserter.m2w)

define_target_compile_options(test.unit.inserter.m2w)


# ############################## end of file ############################# #

