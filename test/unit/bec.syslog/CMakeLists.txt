
add_executable(test.unit.bec.syslog
	entry.cpp
)

target_link_libraries(test.unit.bec.syslog
	PRIVATE
		Pantheios.bec.syslog
)

target_link_Pantheios_util(test.unit.bec.syslog)

target_link_STLSoft(test.unit.bec.syslog)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.syslog)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.syslog)

define_target_compile_options(test.unit.bec.syslog)


# ############################## end of file ############################# #

