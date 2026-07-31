
#[====[
add_subdirectory(be.ACE)
#]====]
add_subdirectory(be.AnsiConsole)
if(WIN32)

	add_subdirectory(be.COMErrorObject)
endif(WIN32)
add_subdirectory(be.N)
if(WIN32)

	add_subdirectory(be.WindowsConsole)
	add_subdirectory(be.WindowsDebugger)
	add_subdirectory(be.WindowsEventLog)
	add_subdirectory(be.WindowsMessageBox)
	add_subdirectory(be.WindowsSyslog)
endif(WIN32)
add_subdirectory(be.fail)
add_subdirectory(be.file)
add_subdirectory(be.fprintf)
#[====[
add_subdirectory(be.loader)
#]====]
add_subdirectory(be.lrsplit)
add_subdirectory(be.null)
if(WIN32)

	add_subdirectory(be.speech)
endif(WIN32)
if(UNIX)

	add_subdirectory(be.syslog)
endif(UNIX)
add_subdirectory(be.test)

#[====[
add_subdirectory(bec.ACE)
add_subdirectory(bec.ACE.WithCallback)
#]====]
add_subdirectory(bec.AnsiConsole)
add_subdirectory(bec.AnsiConsole.WithCallback)
if(WIN32)

	add_subdirectory(bec.COMErrorObject)
	add_subdirectory(bec.COMErrorObject.WithCallback)
	add_subdirectory(bec.WindowsConsole)
	add_subdirectory(bec.WindowsConsole.WithCallback)
	add_subdirectory(bec.WindowsDebugger)
	add_subdirectory(bec.WindowsDebugger.WithCallback)
	add_subdirectory(bec.WindowsEventLog)
	add_subdirectory(bec.WindowsEventLog.WithCallback)
	add_subdirectory(bec.WindowsMessageBox)
	add_subdirectory(bec.WindowsMessageBox.WithCallback)
	add_subdirectory(bec.WindowsSyslog)
	add_subdirectory(bec.WindowsSyslog.WithCallback)
endif(WIN32)
add_subdirectory(bec.fail)
add_subdirectory(bec.fail.WithCallback)
add_subdirectory(bec.file)
add_subdirectory(bec.file.WithCallback)
add_subdirectory(bec.fprintf)
add_subdirectory(bec.fprintf.WithCallback)
#[====[
add_subdirectory(bec.loader)
add_subdirectory(bec.loader.WithCallback)
#]====]
add_subdirectory(bec.null)
add_subdirectory(bec.null.WithCallback)
if(WIN32)

	add_subdirectory(bec.speech)
	add_subdirectory(bec.speech.WithCallback)
endif(WIN32)
add_subdirectory(bec.stock)
add_subdirectory(bec.stock.WithCallback)
if(UNIX)

	add_subdirectory(bec.syslog)
	add_subdirectory(bec.syslog.WithCallback)
endif(UNIX)
add_subdirectory(bec.test)
add_subdirectory(bec.test.WithCallback)

#[====[
add_subdirectory(bel.ACE)
#]====]
add_subdirectory(bel.AnsiConsole)
if(WIN32)

	add_subdirectory(bel.COMErrorObject)
	add_subdirectory(bel.WindowsConsole)
	add_subdirectory(bel.WindowsDebugger)
	add_subdirectory(bel.WindowsEventLog)
	add_subdirectory(bel.WindowsMessageBox)
	add_subdirectory(bel.WindowsSyslog)
endif(WIN32)
add_subdirectory(bel.fail)
add_subdirectory(bel.file)
add_subdirectory(bel.fprintf)
#[====[
add_subdirectory(bel.loader)
#]====]
add_subdirectory(bel.null)
if(WIN32)

	add_subdirectory(bel.speech)
endif(WIN32)
if(UNIX)

	add_subdirectory(bel.syslog)
endif(UNIX)
add_subdirectory(bel.test)

#[====[
add_subdirectory(ber.ACE)
#]====]
add_subdirectory(ber.AnsiConsole)
if(WIN32)

	add_subdirectory(ber.COMErrorObject)
	add_subdirectory(ber.WindowsConsole)
	add_subdirectory(ber.WindowsDebugger)
	add_subdirectory(ber.WindowsEventLog)
	add_subdirectory(ber.WindowsMessageBox)
	add_subdirectory(ber.WindowsSyslog)
endif(WIN32)
add_subdirectory(ber.fail)
add_subdirectory(ber.file)
add_subdirectory(ber.fprintf)
#[====[
add_subdirectory(ber.loader)
#]====]
add_subdirectory(ber.null)
if(WIN32)

	add_subdirectory(ber.speech)
endif(WIN32)
if(UNIX)

	add_subdirectory(ber.syslog)
endif(UNIX)
add_subdirectory(ber.test)


# ############################## end of file ############################# #

