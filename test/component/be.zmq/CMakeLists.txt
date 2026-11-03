
define_automated_test_program(test.component.be.zmq entry.cpp
	CORE
	FE Pantheios.fe.simple
	BE Pantheios.be.zmq
	BEC Pantheios.bec.zmq.WithCallback
)

target_link_ZeroMQ(test.component.be.zmq)

if(Threads_FOUND)

	target_link_libraries(test.component.be.zmq
		PRIVATE
			Threads::Threads
	)
endif()


# ############################## end of file ############################# #
