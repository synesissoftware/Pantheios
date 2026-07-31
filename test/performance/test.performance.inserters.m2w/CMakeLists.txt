
add_executable(test.performance.inserters.m2w
	test.performance.inserters.m2w.cpp
)

target_link_Pantheios_core(test.performance.inserters.m2w)

target_link_libraries(test.performance.inserters.m2w
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.performance.inserters.m2w
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.performance.inserters.m2w)

target_link_STLSoft(test.performance.inserters.m2w)

if(shwild_FOUND)

	target_link_shwild(test.performance.inserters.m2w)
endif(shwild_FOUND)

target_link_xTests(test.performance.inserters.m2w)

define_target_compile_options(test.performance.inserters.m2w)


# ############################## end of file ############################# #

