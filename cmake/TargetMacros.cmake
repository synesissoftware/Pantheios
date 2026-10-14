# ######################################################################## #
# File:     /cmake/TargetMacros.cmake
#
# Purpose:  CMake target helper macros/functions for Pantheios
#
# Created:  29th March 2021
# Updated:  19th October 2026
#
# ######################################################################## #


# ##########################################################
# compile options


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


# ##########################################################
# link helpers


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
		PUBLIC
			$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
	)

	if(DEFINED STLSOFT_INCLUDE_DIR)

		get_filename_component(STLSOFT_INCLUDE_DIR "${STLSOFT_INCLUDE_DIR}" ABSOLUTE)

		target_include_directories(${target_name}
			PUBLIC
				${STLSOFT_INCLUDE_DIR}
		)
	endif()
endmacro(target_link_STLSoft)

macro(target_link_ACE target_name)

	if(TARGET ACE::ACE)

		target_link_libraries(${target_name}
			PUBLIC
				ACE::ACE
		)
	else()

		target_include_directories(${target_name}
			PUBLIC
				${ACE_INCLUDE_DIRS}
		)
		target_link_libraries(${target_name}
			PUBLIC
				${ACE_LIBRARIES}
		)
	endif()
endmacro(target_link_ACE)

macro(target_link_ZeroMQ target_name)

	# Prefer an imported target: our FindZeroMQ creates ZeroMQ::ZeroMQ;
	# upstream libzmq packages export libzmq / libzmq-static.
	if(TARGET ZeroMQ::ZeroMQ)

		target_link_libraries(${target_name}
			PUBLIC
				ZeroMQ::ZeroMQ
		)
	elseif(TARGET libzmq)

		target_link_libraries(${target_name}
			PUBLIC
				libzmq
		)
	elseif(TARGET libzmq-static)

		target_link_libraries(${target_name}
			PUBLIC
				libzmq-static
		)
	else()

		target_include_directories(${target_name}
			PUBLIC
				${ZeroMQ_INCLUDE_DIRS}
		)
		target_link_libraries(${target_name}
			PUBLIC
				${ZeroMQ_LIBRARIES}
		)
	endif()
endmacro(target_link_ZeroMQ)

macro(target_link_shwild target_name)

	target_link_libraries(${target_name}
		PRIVATE
			shwild::core
	)
endmacro(target_link_shwild)

macro(target_link_shwild_if_found target_name)

	if(shwild_FOUND)

		target_link_shwild(${target_name})
	endif(shwild_FOUND)
endmacro(target_link_shwild_if_found)

macro(target_link_xTests target_name)

	target_link_libraries(${target_name}
		PRIVATE
			$<IF:$<VERSION_LESS:${xTests_VERSION},"0.23">,xTests::xTests.core,xTests::core>
	)
endmacro(target_link_xTests)


# ##########################################################
# program helpers
#
# Pantheios programs select a frontend (FE) and backend (BE/BEC) in
# addition to the common util / STLSoft / (tests) stack. Use the gold
# names define_automated_test_program / define_example_program with
# optional keyword arguments:
#
#   CORE              - link Pantheios.core
#   NO_UTIL           - skip Pantheios.util (default: link util)
#   FE <target>       - link a frontend (e.g. Pantheios.fe.simple)
#   BE_TEST           - link Pantheios.be.test + Pantheios.bec.test
#   CONSOLE           - link Win/Ansi console be + bec (via _BUILD_AS_WIN32)
#   BE <target>       - link a backend wrapper (e.g. Pantheios.be.file)
#   BEC <target>      - link a backend callback (e.g. Pantheios.bec.file)
#   LIB <target>...   - link additional stock libs (e.g. unit-under-test)
#
# Call-site convention: write FE above BE / BE_TEST / CONSOLE / BEC
# (cmake_parse_arguments does not care about order). Link order inside
# the helper remains CORE, then BE/BEC, then FE, then LIB — matching
# the historical leaf lists for static-link stability.
#
# Examples:
#
#   define_automated_test_program(test.unit.util.strnlen entry.cpp)
#
#   define_automated_test_program(test.unit.fe.simple entry.c
#     FE Pantheios.fe.simple
#   )
#
#   define_automated_test_program(test.component.inserters.boolean entry.cpp
#     CORE
#     FE Pantheios.fe.all
#     BE_TEST
#   )
#
#   define_example_program(example.cpp.misc.101 main.cpp
#     CORE
#     FE Pantheios.fe.simple
#     CONSOLE
#   )
#
# CTest is not registered here: Pantheios discovers binaries via
# run_all_*.sh / .cmd (same as before these helpers).
#
# SIS:AUTO_GENERATED: pure stock leaves that are only a define_* call
# (including kwargs forms) carry the eyecatcher on line 1. Leaves with
# trailing target_link_libraries, add_subdirectory, or warning-list
# appends must omit it. Pantheios has no in-tree generate_cmakelists.rb
# yet; do not run a 2-arg-only generator against kwargs leaves or it
# will drop CORE/FE/BE/BEC/LIB/CONSOLE/BE_TEST.


function(_pantheios_configure_program program_name)

	cmake_parse_arguments(ARG
		"CORE;BE_TEST;CONSOLE;NO_UTIL;XTESTS"
		"FE;BE;BEC"
		"LIB"
		${ARGN}
	)

	if(ARG_UNPARSED_ARGUMENTS)

		message(FATAL_ERROR
			"_pantheios_configure_program(${program_name}): unexpected arguments: ${ARG_UNPARSED_ARGUMENTS}"
		)
	endif()

	if(ARG_BE_TEST AND ARG_CONSOLE)

		message(FATAL_ERROR
			"_pantheios_configure_program(${program_name}): BE_TEST and CONSOLE are mutually exclusive"
		)
	endif()

	if(ARG_BE_TEST AND (ARG_BE OR ARG_BEC))

		message(FATAL_ERROR
			"_pantheios_configure_program(${program_name}): BE_TEST cannot be combined with BE/BEC"
		)
	endif()

	if(ARG_CONSOLE AND (ARG_BE OR ARG_BEC))

		message(FATAL_ERROR
			"_pantheios_configure_program(${program_name}): CONSOLE cannot be combined with BE/BEC"
		)
	endif()

	if(ARG_CORE)

		target_link_Pantheios_core(${program_name})
	endif()

	if(ARG_BE_TEST)

		target_link_libraries(${program_name}
			PRIVATE
				Pantheios.be.test
				Pantheios.bec.test
		)
	elseif(ARG_CONSOLE)

		target_link_libraries(${program_name}
			PRIVATE
				$<IF:$<BOOL:${_BUILD_AS_WIN32}>,Pantheios.be.WindowsConsole,Pantheios.be.AnsiConsole>
				$<IF:$<BOOL:${_BUILD_AS_WIN32}>,Pantheios.bec.WindowsConsole,Pantheios.bec.AnsiConsole>
		)
	else()

		if(ARG_BE)

			target_link_libraries(${program_name}
				PRIVATE
					${ARG_BE}
			)
		endif()

		if(ARG_BEC)

			target_link_libraries(${program_name}
				PRIVATE
					${ARG_BEC}
			)
		endif()
	endif()

	if(ARG_FE)

		target_link_libraries(${program_name}
			PRIVATE
				${ARG_FE}
		)
	endif()

	if(ARG_LIB)

		target_link_libraries(${program_name}
			PRIVATE
				${ARG_LIB}
		)
	endif()

	if(NOT ARG_NO_UTIL)

		target_link_Pantheios_util(${program_name})
	endif()

	target_link_STLSoft(${program_name})

	if(ARG_XTESTS)

		target_link_shwild_if_found(${program_name})

		target_link_xTests(${program_name})
	endif()

	define_target_compile_options(${program_name})
endfunction(_pantheios_configure_program)


function(define_automated_test_program program_name entry_point_source_name)

	add_executable(${program_name}
		${entry_point_source_name}
	)

	_pantheios_configure_program(${program_name}
		XTESTS
		${ARGN}
	)
endfunction(define_automated_test_program)


function(define_example_program program_name entry_point_source_name)

	add_executable(${program_name}
		${entry_point_source_name}
	)

	_pantheios_configure_program(${program_name}
		${ARGN}
	)
endfunction(define_example_program)


function(define_simple_console_example_c program_stem)

	define_example_program(${program_stem} main.c
		CORE
		FE Pantheios.fe.simple
		CONSOLE
	)

	if(b64_FOUND)

		target_link_libraries(${program_stem}
			PRIVATE
				b64::core
		)
	endif(b64_FOUND)
endfunction(define_simple_console_example_c)

function(define_simple_console_example_cpp program_stem)

	define_example_program(${program_stem} main.cpp
		CORE
		FE Pantheios.fe.simple
		CONSOLE
	)

	if(b64_FOUND)

		target_link_libraries(${program_stem}
			PRIVATE
				b64::core
		)
	endif(b64_FOUND)

	if(Threads_FOUND)

		target_link_libraries(${program_stem}
			PRIVATE
				Threads::Threads
		)
	endif(Threads_FOUND)
endfunction(define_simple_console_example_cpp)


# ##########################################################
# install helpers


macro(install_file subdir file_list)

	install(
		FILES
			${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${subdir}/${file_list}
		DESTINATION include/${PROJECT_NAME_LOWER}/${subdir}/
	)
endmacro(install_file)


# ############################## end of file ############################# #

