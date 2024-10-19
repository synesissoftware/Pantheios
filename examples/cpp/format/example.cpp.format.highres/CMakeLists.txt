
add_executable(example.cpp.format.highres
	example.cpp.format.highres.cpp
)

target_link_Pantheios_core(example.cpp.format.highres)

target_link_libraries(example.cpp.format.highres
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf.WithCallback
)

target_link_libraries(example.cpp.format.highres
	PRIVATE
		Pantheios.fe.simple
)

target_link_Pantheios_util(example.cpp.format.highres)

target_link_STLSoft(example.cpp.format.highres)

define_target_compile_options(example.cpp.format.highres)


# ############################## end of file ############################# #

