
add_executable(example.c.N
	example.c.N.c
)

target_link_Pantheios_core(example.c.N)

target_link_libraries(example.c.N
	PRIVATE
		Pantheios.be.N
		Pantheios.bec.file
		Pantheios.bec.fprintf
		Pantheios.bec.null
)

target_link_libraries(example.c.N
	PRIVATE
		Pantheios.fe.N
)

target_link_libraries(example.c.N
	PRIVATE
		$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsSyslog,Pantheios.bec.syslog>
)

target_link_Pantheios_util(example.c.N)

target_link_STLSoft(example.c.N)

if(WIN32)

	target_link_libraries(example.c.N
		PRIVATE
			ws2_32
	)
endif(WIN32)

define_target_compile_options(example.c.N)


# ############################## end of file ############################# #

