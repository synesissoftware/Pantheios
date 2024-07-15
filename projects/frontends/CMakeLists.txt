
add_subdirectory(fe.N)
add_subdirectory(fe.N.WithCallback)
add_subdirectory(fe.all)
add_subdirectory(fe.all.WithCallback)
add_subdirectory(fe.fail)
add_subdirectory(fe.fail.WithCallback)
add_subdirectory(fe.null)
add_subdirectory(fe.null.WithCallback)
add_subdirectory(fe.simple)
add_subdirectory(fe.simple.WithCallback)
if(WIN32)

	add_subdirectory(fe.WindowsRegistry)
	add_subdirectory(fe.WindowsRegistry.WithCallback)
endif(WIN32)


# ############################## end of file ############################# #

