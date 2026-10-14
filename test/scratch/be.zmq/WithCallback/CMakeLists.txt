
add_executable(test.scratch.be.zmq.WithCallback
	main.cpp
)

target_link_Pantheios_core(test.scratch.be.zmq.WithCallback)

target_link_libraries(test.scratch.be.zmq.WithCallback
	PRIVATE
		Pantheios.be.zmq
		Pantheios.bec.zmq.WithCallback
)

target_link_libraries(test.scratch.be.zmq.WithCallback
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(test.scratch.be.zmq.WithCallback)

target_link_STLSoft(test.scratch.be.zmq.WithCallback)

target_link_ZeroMQ(test.scratch.be.zmq.WithCallback)

if(Threads_FOUND)

	target_link_libraries(test.scratch.be.zmq.WithCallback
		PRIVATE
			Threads::Threads
	)
endif()

define_target_compile_options(test.scratch.be.zmq.WithCallback)


# ############################## end of file ############################# #
