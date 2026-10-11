list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED null-pointer-arithmetic)
define_automated_test_program(test.unit.be.N entry.c
	BE Pantheios.be.N
	FE Pantheios.fe.simple
)

add_subdirectory(filtering)
