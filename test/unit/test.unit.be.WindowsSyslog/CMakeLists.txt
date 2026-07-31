
add_executable(test.unit.be.WindowsSyslog
	test.unit.be.WindowsSyslog.cpp
)

target_link_libraries(test.unit.be.WindowsSyslog
	PRIVATE
		Pantheios.be.WindowsSyslog
		Pantheios.bec.WindowsSyslog
)

target_link_Pantheios_util(test.unit.be.WindowsSyslog)

target_link_STLSoft(test.unit.be.WindowsSyslog)

if(shwild_FOUND)

	target_link_shwild(test.unit.be.WindowsSyslog)
endif(shwild_FOUND)

target_link_xTests(test.unit.be.WindowsSyslog)

target_link_libraries(test.unit.be.WindowsSyslog
	PRIVATE
		ws2_32
)

define_target_compile_options(test.unit.be.WindowsSyslog)


# ############################## end of file ############################# #

