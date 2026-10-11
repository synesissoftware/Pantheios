
add_subdirectory(date_elements_to_string)
if(shwild_FOUND)

	add_subdirectory(getcurrenttime)
endif(shwild_FOUND)
add_subdirectory(gethostname)
if(shwild_FOUND)

	add_subdirectory(onbailout)
endif(shwild_FOUND)
add_subdirectory(parse_args)
add_subdirectory(snprintf)
add_subdirectory(strnlen)


# ############################## end of file ############################# #
