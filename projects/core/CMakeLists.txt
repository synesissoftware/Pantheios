
set(CORE_SRC_DIR ../../src/core)
set(INSERTER_SRC_DIR ../../src/inserters)

file(GLOB CORE_SRCS
	${CORE_SRC_DIR}/*.c
	${CORE_SRC_DIR}/*.cpp
)

file(GLOB INSERTER_SRCS
	${INSERTER_SRC_DIR}/*.cpp
)

if(NOT b64_FOUND)

	list(FILTER INSERTER_SRCS EXCLUDE REGEX "b64")
endif()
if(PANTHEIOS_USE_WIDE_STRINGS)

	list(FILTER INSERTER_SRCS EXCLUDE REGEX "w2m")
else(PANTHEIOS_USE_WIDE_STRINGS)

	list(FILTER INSERTER_SRCS EXCLUDE REGEX "m2w")
endif(PANTHEIOS_USE_WIDE_STRINGS)

add_library(Pantheios.core
	${CORE_SRCS}
	${INSERTER_SRCS}
)

target_include_directories(Pantheios.core
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_STLSoft(Pantheios.core)

target_link_libraries(Pantheios.core
	PRIVATE
		$<$<BOOL:${b64_FOUND}>: b64::core >
)

define_target_compile_options(Pantheios.core)

install(TARGETS Pantheios.core
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME_LOWER}
)

foreach(ITEM
	generated
	inserters
)

	install(
		DIRECTORY ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${ITEM}/
		DESTINATION include/${PROJECT_NAME_LOWER}/${ITEM}/
		FILES_MATCHING
		PATTERN "*.h*"
	)
endforeach()

install_file(internal/generated log_functions.inl)

install_file("" "inserters.hpp")


# ############################## end of file ############################# #
