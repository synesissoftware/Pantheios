
define_example_program(example.cpp.linking.N_with_stock main.cpp
	CORE
	FE Pantheios.fe.simple
	BE Pantheios.be.N
	BEC Pantheios.bec.stock
)

if(_BUILD_AS_WIN32)

	target_link_libraries(example.cpp.linking.N_with_stock
		PRIVATE
			ws2_32
	)
endif(_BUILD_AS_WIN32)


# ############################## end of file ############################# #
