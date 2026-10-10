
add_executable(test.unit.bec.WindowsSyslog
	entry.cpp
)

target_link_libraries(test.unit.bec.WindowsSyslog
	PRIVATE
		Pantheios.bec.WindowsSyslog
)

target_link_Pantheios_util(test.unit.bec.WindowsSyslog)

target_link_STLSoft(test.unit.bec.WindowsSyslog)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.WindowsSyslog)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.WindowsSyslog)

target_link_libraries(test.unit.bec.WindowsSyslog
	PRIVATE
		ws2_32
)

define_target_compile_options(test.unit.bec.WindowsSyslog)


# ############################## end of file ############################# #

