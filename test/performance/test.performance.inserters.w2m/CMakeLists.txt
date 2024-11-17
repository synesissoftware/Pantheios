
add_executable(test.performance.inserters.w2m
	test.performance.inserters.w2m.cpp
)

target_link_Pantheios_core(test.performance.inserters.w2m)

target_link_libraries(test.performance.inserters.w2m
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.performance.inserters.w2m
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.performance.inserters.w2m)

target_link_STLSoft(test.performance.inserters.w2m)

if(shwild_FOUND)

	target_link_shwild(test.performance.inserters.w2m)
endif(shwild_FOUND)

target_link_xTests(test.performance.inserters.w2m)

define_target_compile_options(test.performance.inserters.w2m)


# ############################## end of file ############################# #

