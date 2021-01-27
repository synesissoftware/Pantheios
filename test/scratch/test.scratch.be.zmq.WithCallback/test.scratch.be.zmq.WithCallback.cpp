/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.be.zmq.WithCallback/test.scratch.be.zmq.WithCallback.cpp
 *
 * Purpose:     Implementation file for the test.scratch.be.zmq.WithCallback project.
 *
 * Created:     25th March 2015
 * Updated:     25th March 2015
 *
 * Status:      Hand generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/inserters/args.hpp>
#include <pantheios/backends/bec.zmq.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h> /* STLSOFT_ASSERT */

/* Standard C++ header files */
#include <exception>
#include <vector>
#include <string>
#include <thread>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ZeroMQ header */
#include <zmq.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


#define PSTR        PANTHEIOS_LITERAL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */

PANTHEIOS_EXTERN_C const PAN_CHAR_T PANTHEIOS_FE_PROCESS_IDENTITY[] = PSTR("test.scratch.be.zmq.WithCallback");

PANTHEIOS_CALL(void) pantheios_be_zmq_getAppInit(
    int                     backEndId
,   pan_be_zmq_init_t*      init
) {
    init->sleep_microsecs_at_start          = 500000; // Need to wait because this is PUB/SUB queue.
    init->zmq_socket.socket_type            = ZMQ_PUB;
    init->zmq_socket.socket_attach_method   = PANTHEIOS_BE_ZMQ_SOCKET_METHOD_BIND;
    init->zmq_socket.socket_addr            = const_cast<pantheios::pan_char_t*>(PSTR("tcp://127.0.0.1:5551"));
}
/* /////////////////////////////////////////////////////////////////////////
 * Constants & definitions
 */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/* ////////////////////////////////////////////////////////////////////// */

static bool keepRecording = true;
static std::vector<std::string> recordedLogs;

static void recorder() { // Thread Recorder
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket( context, ZMQ_SUB );
    const char* socket_addr = "tcp://127.0.0.1:5551";
    int rc = zmq_connect( subscriber, socket_addr );
    if (rc == -1) {
        printf ("E: connnect failed: %s\n", strerror (errno));
        exit(-1);
    }
    const char *filter = "";
    // assert( printf("Asserts active!\n") );
    rc = zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE, filter, strlen (filter));
    assert (rc == 0);
    int nrMsgReceived = 0;
    char buffer [256];
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    sleep_time.tv_nsec = 100;
    while( keepRecording ) {
        // Check for messages, record if get any, then sleep.
        int size = zmq_recv (subscriber, buffer, 255, ZMQ_DONTWAIT);
         if( size > -1 ) {
             if(size > 255) { size = 255; buffer[size] = '\0'; } // End string properly.
             recordedLogs.push_back(buffer);
             ++nrMsgReceived;
         }
         nanosleep(&sleep_time, NULL);
    }
    // Collect rest of the messages from the queue.
     while( int size = zmq_recv (subscriber, buffer, 255, ZMQ_DONTWAIT) ) {
         if( size > -1 ) {
             if(size > 255) { size = 255; buffer[size] = '\0'; } // End string properly.
             recordedLogs.push_back(buffer);
         } else {
             // No messages left in the queue. Break!
             break;
         }
     }
    zmq_close (subscriber);
    zmq_ctx_destroy (context);
}

static void player() { // Thread Player
    pantheios::log_NOTICE("stmt 1");
    pantheios::log_NOTICE("stmt 2");
    pantheios::log_NOTICE("stmt 3");
    pantheios::log_NOTICE("stmt 4");
    pantheios::log_NOTICE("stmt 5");
    pantheios::log_NOTICE("stmt 6");
    pantheios::log_NOTICE("stmt 7");
}

static int main_(int argc, char **argv)
{
    {
        struct timespec sleep_time;
        sleep_time.tv_sec = 0;
        sleep_time.tv_nsec = 100000000;
        // Spawn two threads:
        // Player: send log messages.
        // Recorder: read log messages.
        std::thread th_rec( recorder );
        nanosleep(&sleep_time, NULL); // Wait so Recorder is definately ready to record.
        std::thread th_play( player );

        // Wait until (join) Player is finished with writing to log.
        th_play.join();

        // Signal Receiver to finish and wait until it stops (join).
        keepRecording = false;
        th_rec.join();

        // Verify recordings.
        // for_each( recordedLogs.begin(), recordedLogs.end(), [](std::string& s) {
        //         printf("Rec'd: '%s'.\n", s.c_str()); });
        STLSOFT_ASSERT( 7 == recordedLogs.size() );
        // pantheios::log_NOTICE(PSTR("stmt 1"));
    }
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

    try
    {
        res = main_(argc, argv);
    }
    catch(std::exception &x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ////////////////////////////////////////////////////////////////////// */
