# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten
define_automated_test_program(test.component.be.file.threading entry.cpp
	CORE
	FE Pantheios.fe.N
	BE Pantheios.be.N
	BEC Pantheios.bec.file
	LIB $<IF:$<BOOL:${_BUILD_AS_WIN32}>,Pantheios.bec.WindowsConsole,Pantheios.bec.AnsiConsole>
)
