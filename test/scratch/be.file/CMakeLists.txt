define_example_program(test.scratch.be.file main.cpp
	CORE
	BE Pantheios.be.lrsplit
	BEC Pantheios.bec.file
	FE Pantheios.fe.simple
	LIB Pantheios.bel.file Pantheios.ber.file
)

#[====[
add_subdirectory(rolling)
#]====]
