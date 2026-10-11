define_example_program(test.scratch.be.file main.cpp
	CORE
	FE Pantheios.fe.simple
	BE Pantheios.be.lrsplit
	BEC Pantheios.bec.file
	LIB Pantheios.bel.file Pantheios.ber.file
)

#[====[
add_subdirectory(rolling)
#]====]
