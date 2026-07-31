
add_executable(test.component.inserters.threadid
	test.component.inserters.threadid.cpp
)

target_link_Pantheios_core(test.component.inserters.threadid)

target_link_libraries(test.component.inserters.threadid
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.threadid
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.threadid)

target_link_STLSoft(test.component.inserters.threadid)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.threadid)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.threadid)

define_target_compile_options(test.component.inserters.threadid)


# ############################## end of file ############################# #

