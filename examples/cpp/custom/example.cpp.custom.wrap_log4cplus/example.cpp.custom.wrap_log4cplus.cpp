/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/custom/example.cpp.custom.wrap_log4cplus/example.cpp.custom.wrap_log4cplus.cpp
 *
 * Purpose: C++ example program for Pantheios. Demonstrates:
 *
 *            - use of a custom back-end to wrap the log4cxx library
 *            - interaction between log4cxx constructs and Pantheios log
 *              statements
 *            - use of pantheios::logputs() in bail-out conditions
 *
 * Created: 16th August 2006
 * Updated: 28th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS // Faster compilation

/* Pantheios header files */
#include <pantheios/pantheios.hpp>          // Pantheios C++ main header
#include <pantheios/backend.h>
#include <pantheios/init_codes.h>

/* log4cxx header files */
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>

/* Standard C/C++ header files */
#include <exception>                        // for std::exception
#include <new>                              // for std::bad_alloc
#include <string>                           // for std::string
#include <stdlib.h>                         // for exit codes

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  pragma warning(disable : 4702)
# endif /* compiler */
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
  try
  {
    using namespace std;
    using namespace log4cplus;
    using namespace log4cplus::helpers;

    // A normal log statement

    pantheios::log_DEBUG("debug stmt");
    pantheios::log_INFORMATIONAL("informational stmt");
    pantheios::log_NOTICE("notice stmt");
    pantheios::log_WARNING("warning stmt");
    pantheios::log_ERROR("error stmt");
    pantheios::log_CRITICAL("critical stmt");
    pantheios::log_ALERT("alert stmt");
    pantheios::log_EMERGENCY("emergency stmt");


    // Now we push a context ...
//    NDC::push(_T("trivial context"));

    // ... log ...
    pantheios::log_INFORMATIONAL("stmt#2");

    // ... pop ...
//    NDC::pop();

    // ... and log again
    pantheios::log_INFORMATIONAL("stmt#3");



    return EXIT_SUCCESS;
  }
  catch (std::bad_alloc&)
  {
    pantheios::log(pantheios::alert, "out of memory");
  }
  catch (std::exception& x)
  {
    pantheios::log_CRITICAL("Exception: ", x);
  }
  catch (...)
  {
    pantheios::logputs(pantheios::emergency, "Unexpected unknown error");
  }

  return EXIT_FAILURE;
}


/* /////////////////////////////////////////////////////////////////////////
 * front-end
 */

PANTHEIOS_CALL(int) pantheios_fe_init(
  int     /* reserved */
, void**  /* ptoken */
)
{
  return PANTHEIOS_INIT_RC_SUCCESS; // Successful initialisation
}

PANTHEIOS_CALL(void) pantheios_fe_uninit(void* /* token */)
{}

PANTHEIOS_CALL(char const*) pantheios_fe_getProcessIdentity(void* /* token */)
{
  return "example.cpp.custom.wrap_log4cplus";
}

PANTHEIOS_CALL(int) pantheios_fe_isSeverityLogged(
  void* /* token */
, int severity
, int /* backEndId */
)
{
  using namespace std;
  using namespace log4cplus;
  using namespace log4cplus::helpers;

  LogLevel  level;

  switch (severity & 0x0f)
  {
    case  PANTHEIOS_SEV_EMERGENCY:
    case  PANTHEIOS_SEV_ALERT:
      level = FATAL_LOG_LEVEL;
      break;
    case  PANTHEIOS_SEV_CRITICAL:
    case  PANTHEIOS_SEV_ERROR:
      level = ERROR_LOG_LEVEL;
      break;
    case  PANTHEIOS_SEV_WARNING:
      level = WARN_LOG_LEVEL;
      break;
    case  PANTHEIOS_SEV_NOTICE:
    case  PANTHEIOS_SEV_INFORMATIONAL:
      level = INFO_LOG_LEVEL;
      break;
    case  PANTHEIOS_SEV_DEBUG:
      level = DEBUG_LOG_LEVEL;
      break;
  }

  Logger root = Logger::getRoot();

  return root.isEnabledFor(level);
}


/* /////////////////////////////////////////////////////////////////////////
 * back-end
 */

PANTHEIOS_CALL(int) pantheios_be_init(
  char const* processIdentity
, void*       /* reserved */
, void**      /* ptoken */
)
{
  using namespace std;
  using namespace log4cplus;
  using namespace log4cplus::helpers;

  try
  {
    BasicConfigurator::doConfigure();
  }
  catch (std::bad_alloc&)
  {
    pantheios::util::onBailOut(PANTHEIOS_SEV_ALERT, "failed to initialise back-end", processIdentity, "out of memory");

    return PANTHEIOS_INIT_RC_OUT_OF_MEMORY
  }
  catch (std::exception& x)
  {
    pantheios::util::onBailOut(PANTHEIOS_SEV_ALERT, "failed to initialise back-end", processIdentity, x.what());

    return PANTHEIOS_INIT_RC_UNSPECIFIED_EXCEPTION;
  }

  return PANTHEIOS_INIT_RC_SUCCESS; // Successful initialisation
}

PANTHEIOS_CALL(void) pantheios_be_uninit(void* /* token */)
{}

PANTHEIOS_CALL(int) pantheios_be_logEntry(
  void*       /* feToken */
, void*       /* beToken */
, int         severity
, char const* entry
, size_t      cchEntry
)
{
  using namespace std;
  using namespace log4cplus;
  using namespace log4cplus::helpers;

  severity &= 0x07;

  Logger root = Logger::getRoot();

  switch (severity)
  {
    case  PANTHEIOS_SEV_EMERGENCY:
    case  PANTHEIOS_SEV_ALERT:
      LOG4CPLUS_FATAL(root, entry);
      break;
    case  PANTHEIOS_SEV_CRITICAL:
    case  PANTHEIOS_SEV_ERROR:
      LOG4CPLUS_ERROR(root, entry);
      break;
    case  PANTHEIOS_SEV_WARNING:
      LOG4CPLUS_WARN(root, entry);
      break;
    case  PANTHEIOS_SEV_NOTICE:
    case  PANTHEIOS_SEV_INFORMATIONAL:
      LOG4CPLUS_INFO(root, entry);
      break;
    case  PANTHEIOS_SEV_DEBUG:
      LOG4CPLUS_DEBUG(root, entry);
      break;
  }

  return cchEntry;
}


/* ///////////////////////////// end of file //////////////////////////// */

