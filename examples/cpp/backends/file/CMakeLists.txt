define_example_program(example.cpp.backends.file main.cpp
	CORE
	BE Pantheios.be.file
	BEC Pantheios.bec.file
	FE Pantheios.fe.simple
)

add_subdirectory(callback)
add_subdirectory(lrsplit)
