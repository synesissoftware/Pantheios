list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED deprecated-declarations)
define_automated_test_program(test.performance.util.date_elements_to_string main.cpp
	CORE
	BE Pantheios.be.null
	FE Pantheios.fe.simple
)
