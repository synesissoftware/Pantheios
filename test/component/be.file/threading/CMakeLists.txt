define_automated_test_program(test.component.be.file.threading entry.cpp
	CORE
	BE Pantheios.be.N
	BEC Pantheios.bec.file
	FE Pantheios.fe.N
	LIB $<IF:$<BOOL:${_BUILD_AS_WIN32}>,Pantheios.bec.WindowsConsole,Pantheios.bec.AnsiConsole>
)
