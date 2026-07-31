
add_executable(test.unit.bec.COMErrorObject
	test.unit.bec.COMErrorObject.cpp
)

target_link_libraries(test.unit.bec.COMErrorObject
	PRIVATE
		Pantheios.bec.COMErrorObject
)

target_link_Pantheios_util(test.unit.bec.COMErrorObject)

target_link_STLSoft(test.unit.bec.COMErrorObject)

if(shwild_FOUND)

	target_link_shwild(test.unit.bec.COMErrorObject)
endif(shwild_FOUND)

target_link_xTests(test.unit.bec.COMErrorObject)

define_target_compile_options(test.unit.bec.COMErrorObject)


# ############################## end of file ############################# #

