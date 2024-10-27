
add_subdirectory(test.component.be.file.threading)
add_subdirectory(test.component.bec.fprintf)
add_subdirectory(test.component.core.getProcessIdentity)
add_subdirectory(test.component.core.initialisation_sequence)
add_subdirectory(test.component.core.pantheios_logprintf)
add_subdirectory(test.component.core.pantheios_logputs)
add_subdirectory(test.component.custom_severity)

add_subdirectory(test.component.details)

add_subdirectory(test.component.inserters.args)
#[====[
#]====]
if(b64_FOUND)

	add_subdirectory(test.component.inserters.b64)
endif(b64_FOUND)
add_subdirectory(test.component.inserters.boolean)
add_subdirectory(test.component.inserters.hostid)
add_subdirectory(test.component.inserters.integer)
if(PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.component.inserters.m2w)
endif(PANTHEIOS_USE_WIDE_STRINGS)
add_subdirectory(test.component.inserters.pad)
add_subdirectory(test.component.inserters.pointer)
add_subdirectory(test.component.inserters.processid)
add_subdirectory(test.component.inserters.real)
add_subdirectory(test.component.inserters.slice)
add_subdirectory(test.component.inserters.stream_character)
add_subdirectory(test.component.inserters.threadid)
if(WIN32)

	add_subdirectory(test.component.inserters.variant_bool)
endif(WIN32)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.component.inserters.w2m)
endif()
if(WIN32)

	add_subdirectory(test.component.inserters.windows.hive)
endif(WIN32)

add_subdirectory(test.component.log.1)
if(NOT PANTHEIOS_USE_WIDE_STRINGS)

	add_subdirectory(test.component.trace.1)
endif()

