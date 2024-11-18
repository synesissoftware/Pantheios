
add_executable(test.unit.inserters.windows.sc
	test.unit.inserters.windows.sc.cpp
)

target_link_Pantheios_core(test.unit.inserters.windows.sc)

target_link_libraries(test.unit.inserters.windows.sc
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.unit.inserters.windows.sc
	PRIVATE
		Pantheios.fe.null
)

target_link_Pantheios_util(test.unit.inserters.windows.sc)

target_link_STLSoft(test.unit.inserters.windows.sc)

if(shwild_FOUND)

	target_link_shwild(test.unit.inserters.windows.sc)
endif(shwild_FOUND)

target_link_xTests(test.unit.inserters.windows.sc)

define_target_compile_options(test.unit.inserters.windows.sc)


# ############################## end of file ############################# #

