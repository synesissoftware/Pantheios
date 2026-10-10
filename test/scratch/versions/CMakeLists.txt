
add_executable(test.scratch.versions
	main.cpp
)

target_include_directories(test.scratch.versions
	PRIVATE
		${CMAKE_SOURCE_DIR}/include
)

target_link_STLSoft(test.scratch.versions)

if(b64_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			b64::core
	)
endif(b64_FOUND)

if(shwild_FOUND)

	target_link_shwild(test.scratch.versions)
endif(shwild_FOUND)

define_target_compile_options(test.scratch.versions)


# ############################## end of file ############################# #
