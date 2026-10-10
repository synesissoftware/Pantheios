
add_executable(test.scratch.be.WindowsSyslog.WithCallback
	test.scratch.be.WindowsSyslog.WithCallback.cpp
)

target_link_Pantheios_core(test.scratch.be.WindowsSyslog.WithCallback)

target_link_libraries(test.scratch.be.WindowsSyslog.WithCallback
	PRIVATE
		Pantheios.be.WindowsSyslog
		Pantheios.bec.WindowsSyslog.WithCallback
)

target_link_libraries(test.scratch.be.WindowsSyslog.WithCallback
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.be.WindowsSyslog.WithCallback)

target_link_STLSoft(test.scratch.be.WindowsSyslog.WithCallback)

define_target_compile_options(test.scratch.be.WindowsSyslog.WithCallback)


# ############################## end of file ############################# #

