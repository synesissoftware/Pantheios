
add_executable(test.component.inserters.hostid
	test.component.inserters.hostid.cpp
)

target_link_Pantheios_core(test.component.inserters.hostid)

target_link_libraries(test.component.inserters.hostid
	PRIVATE
		Pantheios.be.test
		Pantheios.bec.test
)

target_link_libraries(test.component.inserters.hostid
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.component.inserters.hostid)

target_link_STLSoft(test.component.inserters.hostid)

if(shwild_FOUND)

	target_link_shwild(test.component.inserters.hostid)
endif(shwild_FOUND)

target_link_xTests(test.component.inserters.hostid)

define_target_compile_options(test.component.inserters.hostid)


# ############################## end of file ############################# #

