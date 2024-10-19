
add_executable(example.cpp.misc.extended_severity_information
	example.cpp.misc.extended_severity_information.cpp
)

target_link_Pantheios_core(example.cpp.misc.extended_severity_information)

target_link_libraries(example.cpp.misc.extended_severity_information
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.misc.extended_severity_information)

target_link_STLSoft(example.cpp.misc.extended_severity_information)

define_target_compile_options(example.cpp.misc.extended_severity_information)


# ############################## end of file ############################# #

