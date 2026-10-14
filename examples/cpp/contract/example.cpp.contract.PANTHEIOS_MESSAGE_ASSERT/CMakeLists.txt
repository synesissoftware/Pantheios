
add_executable(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT.cpp
)

target_link_Pantheios_core(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT)

target_link_libraries(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT)

target_link_STLSoft(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT)

define_target_compile_options(example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT)


# ############################## end of file ############################# #

