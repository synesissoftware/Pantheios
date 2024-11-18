
add_executable(test.component.core.getProcessIdentity
	test.component.core.getProcessIdentity.c
)

target_link_Pantheios_core(test.component.core.getProcessIdentity)

target_link_libraries(test.component.core.getProcessIdentity
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_Pantheios_util(test.component.core.getProcessIdentity)

target_link_STLSoft(test.component.core.getProcessIdentity)

if(shwild_FOUND)

	target_link_shwild(test.component.core.getProcessIdentity)
endif(shwild_FOUND)

target_link_xTests(test.component.core.getProcessIdentity)

define_target_compile_options(test.component.core.getProcessIdentity)


# ############################## end of file ############################# #

