
add_executable(libver
	main.cpp
)

target_include_directories(libver
	PRIVATE
		${CMAKE_SOURCE_DIR}/include
)

target_link_STLSoft(libver)

if(b64_FOUND)

	target_link_libraries(libver
		PRIVATE
			b64::core
	)
endif(b64_FOUND)

if(shwild_FOUND)

	target_link_shwild(libver)
endif(shwild_FOUND)

if(xTests_FOUND)

	target_link_xTests(libver)
endif(xTests_FOUND)

define_target_compile_options(libver)


# ############################## end of file ############################# #
