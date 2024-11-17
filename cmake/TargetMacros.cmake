
macro(define_target_compile_options target_name)

	set(X_GCC_CUSTOM_WARNINGS_ "")

	if(X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
		foreach(warning ${X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

			list(APPEND X_GCC_CUSTOM_WARNINGS_ "-Wno-${warning}")
		endforeach()
	endif()

	set(X_MSVC_CUSTOM_WARNINGS_ "")

	if(X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
			foreach(warning ${X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

					list(APPEND X_MSVC_CUSTOM_WARNINGS_ "/wd${warning}")
			endforeach()
	endif()

	target_compile_options(${target_name}
		PRIVATE
			$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
				-Werror -Wall -Wextra -pedantic

			${X_GCC_CUSTOM_WARNINGS_}
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			${X_MSVC_CUSTOM_WARNINGS_}
		>
	)
endmacro(define_target_compile_options)

macro(target_link_Pantheios_core target_name)

	target_link_libraries(${target_name}
		PRIVATE
			Pantheios.core
	)
endmacro(target_link_Pantheios_core)

macro(target_link_Pantheios_util target_name)

	target_link_libraries(${target_name}
		PRIVATE
			Pantheios.util
	)
endmacro(target_link_Pantheios_util)

macro(target_link_STLSoft target_name)

	target_link_libraries(${target_name}
		PRIVATE
			$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
	)
endmacro(target_link_STLSoft)

macro(target_link_shwild target_name)

	target_link_libraries(${target_name}
		PRIVATE
			shwild::core
	)
endmacro(target_link_shwild)

macro(target_link_xTests target_name)

	target_link_libraries(${target_name}
		PRIVATE
			$<IF:$<VERSION_LESS:${xTests_VERSION},"0.23">,xTests::xTests.core,xTests::core>
	)
endmacro(target_link_xTests)

function(define_simple_console_example_c program_and_main_source_stem)

	add_executable(${program_and_main_source_stem}
		${program_and_main_source_stem}.c
	)

	target_link_Pantheios_core(${program_and_main_source_stem})

	target_link_libraries(${program_and_main_source_stem}
		PRIVATE
			$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
			$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
	)

	target_link_libraries(${program_and_main_source_stem}
		PRIVATE
			Pantheios.fe.simple
	)

	target_link_libraries(${program_and_main_source_stem}
		PRIVATE
			Pantheios.util
	)

	target_link_STLSoft(${program_and_main_source_stem})

	if(b64_FOUND)

		target_link_libraries(${program_and_main_source_stem}
			PRIVATE
				b64::core
		)
	endif(b64_FOUND)

	set(X_GCC_CUSTOM_WARNINGS_ "")

	if(X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
		foreach(warning ${X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

			list(APPEND X_GCC_CUSTOM_WARNINGS_ "-Wno-${warning}")
		endforeach()
	endif()

	set(X_MSVC_CUSTOM_WARNINGS_ "")

	if(X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
			foreach(warning ${X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

					list(APPEND X_MSVC_CUSTOM_WARNINGS_ "/wd${warning}")
			endforeach()
	endif()

	target_compile_options(${program_and_main_source_stem}
		PRIVATE
			$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
				-Werror -Wall -Wextra -pedantic

				${X_GCC_CUSTOM_WARNINGS_}
			>
			$<$<CXX_COMPILER_ID:MSVC>:
				/WX /W4

				${X_MSVC_CUSTOM_WARNINGS_}
			>
	)
endfunction(define_simple_console_example_c)

function(define_simple_console_example_cpp program_and_main_source_stem)

	add_executable(${program_and_main_source_stem}
		${program_and_main_source_stem}.cpp
	)

	target_link_Pantheios_core(${program_and_main_source_stem})

	target_link_libraries(${program_and_main_source_stem}
		PRIVATE
			$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.be.WindowsConsole,Pantheios.be.fprintf>
			$<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>,Pantheios.bec.WindowsConsole,Pantheios.bec.fprintf>
	)

	target_link_libraries(${program_and_main_source_stem}
		PRIVATE
			Pantheios.fe.simple
	)

	target_link_libraries(${program_and_main_source_stem}
		PRIVATE
			Pantheios.util
	)

	if(b64_FOUND)

		target_link_libraries(${program_and_main_source_stem}
			PRIVATE
				b64::core
		)
	endif(b64_FOUND)

	target_link_STLSoft(${program_and_main_source_stem})

	set(X_GCC_CUSTOM_WARNINGS_ "")

	if(X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
		foreach(warning ${X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

			list(APPEND X_GCC_CUSTOM_WARNINGS_ "-Wno-${warning}")
		endforeach()
	endif()

	set(X_MSVC_CUSTOM_WARNINGS_ "")

	if(X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED)
			foreach(warning ${X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED})

					list(APPEND X_MSVC_CUSTOM_WARNINGS_ "/wd${warning}")
			endforeach()
	endif()

	target_compile_options(${program_and_main_source_stem}
		PRIVATE
			$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
				-Werror -Wall -Wextra -pedantic

				${X_GCC_CUSTOM_WARNINGS_}
			>
			$<$<CXX_COMPILER_ID:MSVC>:
				/WX /W4

				${X_MSVC_CUSTOM_WARNINGS_}
			>
	)
endfunction(define_simple_console_example_cpp)

macro(install_file subdir file_list)

	install(
		FILES
			${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${subdir}/${file_list}
		DESTINATION include/${PROJECT_NAME_LOWER}/${subdir}/
	)
endmacro(install_file)


# ############################## end of file ############################# #

