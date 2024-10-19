
add_executable(test.scratch.util.onbailout
	test.scratch.util.onbailout.cpp
)

target_link_Pantheios_core(test.scratch.util.onbailout)

target_link_libraries(test.scratch.util.onbailout
	PRIVATE
		Pantheios.be.null
		Pantheios.bec.null
)

target_link_libraries(test.scratch.util.onbailout
	PRIVATE
		Pantheios.fe.all
)

target_link_Pantheios_util(test.scratch.util.onbailout)

target_link_STLSoft(test.scratch.util.onbailout)

define_target_compile_options(test.scratch.util.onbailout)


# ############################## end of file ############################# #

