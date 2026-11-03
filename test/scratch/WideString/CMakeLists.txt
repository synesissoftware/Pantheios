define_example_program(test.scratch.WideString main.cpp
	CORE
	FE Pantheios.fe.simple
	BE Pantheios.be.AnsiConsole
	BEC Pantheios.bec.AnsiConsole
)

if(b64_FOUND)

	target_link_Pantheios_inserters_b64(test.scratch.WideString)
endif(b64_FOUND)
