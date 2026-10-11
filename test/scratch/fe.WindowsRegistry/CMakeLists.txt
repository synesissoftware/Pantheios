define_example_program(test.scratch.fe.WindowsRegistry main.cpp
	CORE
	FE Pantheios.fe.WindowsRegistry
	BE Pantheios.be.WindowsConsole
	BEC Pantheios.bec.WindowsConsole
)

add_subdirectory(controller)
