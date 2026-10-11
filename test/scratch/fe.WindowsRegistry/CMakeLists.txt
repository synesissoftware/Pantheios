define_example_program(test.scratch.fe.WindowsRegistry main.cpp
	CORE
	BE Pantheios.be.WindowsConsole
	BEC Pantheios.bec.WindowsConsole
	FE Pantheios.fe.WindowsRegistry
)

add_subdirectory(controller)
