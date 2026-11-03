/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/be.zmq/entry.cpp
 *
 * Purpose: Component test for the be.zmq back-end (PUB/SUB round-trip).
 *
 * Created: 12th October 2026
 * Updated: 19th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/backends/bec.zmq.h>
#include <pantheios/frontends/stock.h>

/* STLSoft header files */
#include <platformstl/synch/sleep_functions.h>
#include <stlsoft/stlsoft.h>

/* ZeroMQ header files */
#include <zmq.h>

/* Standard C++ header files */
#include <atomic>
#include <string>
#include <thread>
#include <vector>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || \
    defined(_WIN64)

# include <process.h>
#else /* ? OS */

# include <unistd.h>
#endif /* OS */

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#define PSTR(x)                                             PANTHEIOS_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PSTR("test.component.be.zmq");

namespace
{

char const* const k_payloads[] =
{
	"pantheios.be.zmq.component.stmt.1",
	"pantheios.be.zmq.component.stmt.2",
	"pantheios.be.zmq.component.stmt.3",
	"pantheios.be.zmq.component.stmt.4",
	"pantheios.be.zmq.component.stmt.5",
	"pantheios.be.zmq.component.stmt.6",
	"pantheios.be.zmq.component.stmt.7",
};

char g_socket_addr[128];

std::atomic<bool> g_keep_recording(true);
std::vector<std::string> g_recorded;

int
pan_get_pid_()
{
#if defined(_WIN32) || \
    defined(_WIN64)

	return static_cast<int>(_getpid());
#else /* ? OS */

	return static_cast<int>(::getpid());
#endif /* OS */
}

void
initialise_socket_addr_()
{
	/* Prefer an ipc endpoint on UNIX to avoid TCP port clashes under
	 * parallel test runners; fall back to a pid-keyed localhost TCP port
	 * on Windows.
	 */
#if defined(_WIN32) || \
    defined(_WIN64)

	unsigned const port = 40000u + static_cast<unsigned>(pan_get_pid_() % 20000);

	snprintf(g_socket_addr, sizeof(g_socket_addr), "tcp://127.0.0.1:%u", port);
#else /* ? OS */

	snprintf(
		g_socket_addr
	,	sizeof(g_socket_addr)
	,	"ipc:///tmp/pantheios.test.component.be.zmq.%d"
	,	pan_get_pid_()
	);
#endif /* OS */
}

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * application-defined back-end callback
 */

PANTHEIOS_CALL(void) pantheios_be_zmq_getAppInit(
	int                  /* backEndId */
,	pan_be_zmq_init_t*   init
)
{
	initialise_socket_addr_();

	/* Slow-joiner allowance so a SUB started around the same time as the
	 * PUB bind can still see the first published statements.
	 */
	init->sleep_microsecs_at_start        = 250000;
	init->zmq_socket.socket_type          = ZMQ_PUB;
	init->zmq_socket.socket_attach_method = PANTHEIOS_BE_ZMQ_SOCKET_METHOD_BIND;
	init->zmq_socket.socket_addr          = g_socket_addr;
}


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_be_zmq_PUB_SUB_round_trip();


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

static void
recorder_()
{
	void* context = zmq_ctx_new();
	XTESTS_TEST_BOOLEAN_TRUE(NULL != context);

	void* subscriber = zmq_socket(context, ZMQ_SUB);
	XTESTS_TEST_BOOLEAN_TRUE(NULL != subscriber);

	int rc = zmq_connect(subscriber, g_socket_addr);
	XTESTS_TEST_INTEGER_EQUAL(0, rc);

	char const* filter = "";
	rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, filter, strlen(filter));
	XTESTS_TEST_INTEGER_EQUAL(0, rc);

	char buffer[1024];

	while (g_keep_recording.load())
	{
		int const size = zmq_recv(subscriber, buffer, sizeof(buffer), ZMQ_DONTWAIT);

		if (size > 0)
		{
			g_recorded.push_back(std::string(buffer, static_cast<size_t>(size)));
		}

		platformstl::micro_sleep(1000);
	}

	for (;;)
	{
		int const size = zmq_recv(subscriber, buffer, sizeof(buffer), ZMQ_DONTWAIT);

		if (size > 0)
		{
			g_recorded.push_back(std::string(buffer, static_cast<size_t>(size)));
		}
		else
		{
			break;
		}
	}

	zmq_close(subscriber);
	zmq_ctx_destroy(context);
}


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if (XTESTS_START_RUNNER("test.component.be.zmq", verbosity))
	{
		XTESTS_RUN_CASE(TEST_be_zmq_PUB_SUB_round_trip);

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

	return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test cases
 */

static void TEST_be_zmq_PUB_SUB_round_trip()
{
	initialise_socket_addr_();

	g_keep_recording.store(true);
	g_recorded.clear();

	std::thread th_rec(recorder_);

	/* Allow the SUB to connect before the first publish. The backend also
	 * sleeps in getAppInit / init for the slow-joiner window.
	 */
	platformstl::micro_sleep(100000);

	{ for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(k_payloads); ++i)
	{
		pantheios::log_NOTICE(k_payloads[i]);
	}}

	/* Give the PUB a moment to flush into the SUB queue. */
	platformstl::micro_sleep(100000);

	g_keep_recording.store(false);
	th_rec.join();

	XTESTS_TEST_INTEGER_EQUAL(
		STLSOFT_NUM_ELEMENTS(k_payloads)
	,	g_recorded.size()
	);

	{ for (size_t i = 0; i != STLSOFT_NUM_ELEMENTS(k_payloads); ++i)
	{
		bool found = false;

		{ for (size_t j = 0; j != g_recorded.size(); ++j)
		{
			if (g_recorded[j].find(k_payloads[i]) != std::string::npos)
			{
				found = true;
				break;
			}
		}}

		XTESTS_TEST_BOOLEAN_TRUE(found);
	}}
}


/* ///////////////////////////// end of file //////////////////////////// */
