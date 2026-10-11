define_example_program(example.cpp.backends.file main.cpp
	CORE
	FE Pantheios.fe.simple
	BE Pantheios.be.file
	BEC Pantheios.bec.file
)

add_subdirectory(callback)
add_subdirectory(lrsplit)
