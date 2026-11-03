
set(INSERTERS_B64_SRC_DIR ../../../src/inserters)

add_library(Pantheios.inserters.b64
	${INSERTERS_B64_SRC_DIR}/b64.cpp
)

target_include_directories(Pantheios.inserters.b64
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_STLSoft(Pantheios.inserters.b64)

# Core supplies pantheios_inserterAllocate / Deallocate; b64 supplies the
# encode API and (via PUBLIC) the <b64/b64.h> include path that
# pantheios/inserters/b64.hpp requires. Prefer a plain
# target_link_libraries() over a generator expression so the exported
# interface records `$<LINK_ONLY:b64::core>` cleanly (static lib).
target_link_libraries(Pantheios.inserters.b64
	PRIVATE
		Pantheios.core
	PUBLIC
		b64::core
)

define_target_compile_options(Pantheios.inserters.b64)

install(TARGETS Pantheios.inserters.b64
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


# ############################## end of file ############################# #
