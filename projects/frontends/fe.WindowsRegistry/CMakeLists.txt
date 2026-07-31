
set(FE_WINDOWSREGISTRY_SRC_DIR ../../../src/frontends)

file(GLOB FE_WINDOWSREGISTRY_SRCS
	${FE_WINDOWSREGISTRY_SRC_DIR}/fe.WindowsRegistry.cpp
)

add_library(Pantheios.fe.WindowsRegistry
	${FE_WINDOWSREGISTRY_SRCS}
)

target_link_STLSoft(Pantheios.fe.WindowsRegistry)

define_target_compile_options(Pantheios.fe.WindowsRegistry)

install(TARGETS Pantheios.fe.WindowsRegistry
	EXPORT project-targets
)

install_file(frontends fe.WindowsRegistry.h)


# ############################## end of file ############################# #

