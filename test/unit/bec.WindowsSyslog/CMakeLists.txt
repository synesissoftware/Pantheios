define_automated_test_program(test.unit.bec.WindowsSyslog entry.cpp
	BEC Pantheios.bec.WindowsSyslog
)

target_link_libraries(test.unit.bec.WindowsSyslog
	PRIVATE
		ws2_32
)
