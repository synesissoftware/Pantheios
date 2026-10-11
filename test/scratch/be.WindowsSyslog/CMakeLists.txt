
add_executable(test.scratch.be.WindowsSyslog
	main.cpp
)

target_link_Pantheios_core(test.scratch.be.WindowsSyslog)

target_link_libraries(test.scratch.be.WindowsSyslog
	PRIVATE
		Pantheios.be.WindowsSyslog
		Pantheios.bec.WindowsSyslog
)

target_link_libraries(test.scratch.be.WindowsSyslog
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.be.WindowsSyslog)

target_link_STLSoft(test.scratch.be.WindowsSyslog)

define_target_compile_options(test.scratch.be.WindowsSyslog)


# ############################## end of file ############################# #

