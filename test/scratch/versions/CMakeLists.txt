
add_executable(versions
	main.cpp
)

target_include_directories(versions
	PRIVATE
		${CMAKE_SOURCE_DIR}/include
)

target_link_STLSoft(versions)

if(b64_FOUND)

	target_link_libraries(versions
		PRIVATE
			b64::core
	)
endif(b64_FOUND)

if(shwild_FOUND)

	target_link_shwild(versions)
endif(shwild_FOUND)

if(xTests_FOUND)

	target_link_xTests(versions)
endif(xTests_FOUND)

define_target_compile_options(versions)


# ############################## end of file ############################# #
