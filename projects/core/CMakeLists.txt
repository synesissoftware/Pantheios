
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

target_link_STLSoft(Pantheios.core)

target_link_libraries(Pantheios.core
	PRIVATE
		$<$<BOOL:${b64_FOUND}>: b64::core >
)

define_target_compile_options(Pantheios.core)

install(TARGETS Pantheios.core
	EXPORT project-targets
)


# ############################## end of file ############################# #
