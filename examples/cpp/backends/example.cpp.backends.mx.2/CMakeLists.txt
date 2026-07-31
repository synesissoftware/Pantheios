
add_executable(example.cpp.backends.mx.2
	example.cpp.backends.mx.2.cpp
)

target_link_Pantheios_core(example.cpp.backends.mx.2)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.be.N
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsSyslog,Pantheios.bec.syslog>
)

target_link_libraries(example.cpp.backends.mx.2
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.backends.mx.2)

target_link_STLSoft(example.cpp.backends.mx.2)

if(WIN32)

	target_link_libraries(example.cpp.backends.mx.2
		PRIVATE
			ws2_32
	)
endif(WIN32)

define_target_compile_options(example.cpp.backends.mx.2)


# ############################## end of file ############################# #

