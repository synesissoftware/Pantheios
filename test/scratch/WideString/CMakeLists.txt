define_example_program(test.scratch.WideString main.cpp
	CORE
	FE Pantheios.fe.simple
	BE Pantheios.be.AnsiConsole
	BEC Pantheios.bec.AnsiConsole
)

target_link_libraries(test.scratch.WideString
	PRIVATE
		$<$<BOOL:${b64_FOUND}>:b64::core>
)
