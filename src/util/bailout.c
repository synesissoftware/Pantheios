/* /////////////////////////////////////////////////////////////////////////
 * File:    src/util/bailout.c
 *
 * Purpose: Implementation file for low-level Pantheios bail out.
 *
 * Created: 21st June 2005
 * Updated: 15th July 2024
 *
 * Home:    http://www.pantheios.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
 * Copyright (c) 1999-2005, Synesis Software and Matthew Wilson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios header files
 *
 * NOTE: We do _not_ include pantheios/pantheios.hpp here, since we are
 *  not using any of the Application Layer.
 */
#include <pantheios/pantheios.h>
#include <pantheios/internal/lean.h>
#include <pantheios/backend.h>
#include <pantheios/frontend.h>

#include <pantheios/util/string/snprintf.h>

#include <pantheios/init_codes.h>
#include <pantheios/quality/contract.h>
#include <pantheios/internal/safestr.h>

/* STLSoft header files */

#include <stlsoft/stlsoft.h>
#ifdef PANTHEIOS_BAILOUT_NO_OPERATING_SYSTEM_SPECIFICS
# ifndef PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG
#  define PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG
# endif /* !PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG */
# ifndef PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG
#  define PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG
# endif /* !PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */
#else /* ? PANTHEIOS_BAILOUT_NO_OPERATING_SYSTEM_SPECIFICS */
# include <platformstl/platformstl.h>
#endif /* PANTHEIOS_BAILOUT_NO_OPERATING_SYSTEM_SPECIFICS */
#include <stlsoft/shims/access/string/std/c_string.h>
#include <stlsoft/string/c_string/strnchr.h>

/* Standard C header files */

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
# include <time.h>
# include <sys/time.h>
#endif /* PLATFORMSTL_OS_IS_UNIX */
#ifdef PANTHEIOS_USE_WIDE_STRINGS
# include <wchar.h>
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* Operating-system header files */

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG
#  include <syslog.h>
# endif /* !PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG
#  include <pantheios/util/severity/WindowsEventLog.h>
#  include <comstl/comstl.h>
# endif /* !PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */
#endif /* OS */


/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 */

#if (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1200)
# define _PANTHEIOS_COMPILER_REQUIRES_EXTERNCPP_DEFINITIONS
#endif /* compiler */

#if 0
#elif defined(STLSOFT_COMPILER_IS_BORLAND) || \
    defined(STLSOFT_COMPILER_IS_DMC) || \
    (   defined(STLSOFT_COMPILER_IS_INTEL) && \
        defined(_WIN32)) || \
    defined(STLSOFT_COMPILER_IS_MSVC) || \
    (   defined(STLSOFT_COMPILER_IS_MWERKS) && \
        defined(_WIN32)) || \
    defined(STLSOFT_COMPILER_IS_WATCOM)
# define PANTHEIOS_BAILOUT_USE_SEH
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * warning suppression
 */

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8080
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * string encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# define pan_strlen_w_                  wcslen
# define pan_strncpy_w_                 wcsncpy
# define pan_wsprintf_w_                wsprintfW
# define pan_OutputDebugString_w_       OutputDebugStringW
# define pan_ReportEvent_w_             ReportEventW
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

# define pan_strlen_m_                  strlen
# define pan_strncpy_m_                 strncpy
# define pan_wsprintf_m_                wsprintfA
# define pan_OutputDebugString_m_       OutputDebugStringA
# define pan_ReportEvent_m_             ReportEventA

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
namespace pantheios
{
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)

/* This needed, because there's a (soft) Windows-only runtime dependency
 * between Pantheios and Pantheios.COM, since bailout writes to the Windows
 * Event Log use message strings defined within the Pantheios.COM module.
 */
static int pantheios_util_onBailOut_canUseWarnMessage_(void);
#endif /* PLATFORMSTL_OS_IS_WINDOWS && !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */

static
int
pantheios_util_onBailOut_fopen_m_(
    char const*     path
,   char const*     mode
,   FILE**          phFile
);

#ifdef PANTHEIOS_USE_WIDE_STRINGS

static
int
pantheios_util_onBailOut_fopen_w_(
    wchar_t const*  path
,   wchar_t const*  mode
,   FILE**          phFile
);
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#ifndef PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE
# define PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE                (2048)
#endif /* !PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE */

#ifndef PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME
# define PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME                "logging-bailout.txt"
#endif /* !PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

# ifndef PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME_w
#  define PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME_w             PANTHEIOS_LITERAL_w_("logging-bailout.txt")
# endif /* !PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME_w */
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)

/* The following two are 'known' from pantheios.COM, v1.0.1-b3+. (They will
 * *not* be changed).
 */

# define BAILOUT_1PARAM_FAIL_MESSAGE_ID                     ((DWORD)1000)
# define BAILOUT_2PARAM_FAIL_MESSAGE_ID                     ((DWORD)1001)

/* The following two are 'known' from pantheios.COM, v1.0.1-b31+. (They will
 * *not* be changed).
 */

# define BAILOUT_1PARAM_WARN_MESSAGE_ID                     ((DWORD)1005)
# define BAILOUT_2PARAM_WARN_MESSAGE_ID                     ((DWORD)1006)
#endif /* PLATFORMSTL_OS_IS_WINDOWS && !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */


/* /////////////////////////////////////////////////////////////////////////
 * util API
 *
 * bailout - outputs:
 * ------------------
 *
 * 1. Debugger [Windows-only]
 * 2. Console (i.e. fprintf(stderr, ...))
 * 3. File (i.e. to "logging-bailout.txt")
 * 4. Event Log [Windows-only]
 * 5. Syslog [UNIX-only]
 */

PANTHEIOS_CALL(void)
pantheios_onBailOut6(
    int         severity
,   char const* message
,   char const* processId
,   char const* qualifier
,   char const* feName
,   char const* beName
)
{
    if (NULL == feName &&
        NULL == beName)
    {
        pantheios_onBailOut4(severity, message, processId, qualifier);

        return;
    }
    else
    {
        char            qualifier_[PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE] = { '\0' };
        size_t const    cchQualifier    =   (NULL == qualifier) ? 0u : pan_strlen_m_(qualifier);
        size_t const    cchFeName       =   (NULL == feName) ? 0u : pan_strlen_m_(feName);
        size_t const    cchBeName       =   (NULL == beName) ? 0u : pan_strlen_m_(beName);
        char*           p1              =   &qualifier_[0];
        char* const     end             =   &qualifier_[0] + STLSOFT_NUM_ELEMENTS(qualifier_);

#ifdef _DEBUG
        memset(&qualifier_[0], '~', sizeof(qualifier_));
#endif

        if (0 != cchFeName)
        {
            int r = 0;

            if (p1 < end)
            {
                p1[0] = '\0';

                r = pantheios_util_snprintf_a(p1, (end - p1), "fe=%.*s", (int)cchFeName, feName);
            }

            if (r < 0)
            {
                /* Some runtime libraries' snprintf() return -ve if write to end */
                if ('\0' != p1[0])
                {
                    r = 3 + stlsoft_static_cast(int, cchFeName);
                }
            }

            if (r > (end - p1))
            {
                p1 = end;
            }
            else
            if (r > 0)
            {
                p1 += r;
            }
        }
        if (0 != cchBeName)
        {
            int r = 0;

            if (p1 < end)
            {
                p1[0] = '\0';

                r = pantheios_util_snprintf_a(p1, (end - p1), &", be=%.*s"[(0 != cchFeName) ? 0 : 2], (int)cchBeName, beName);
            }

            if (r < 0)
            {
                /* Some runtime libraries' snprintf() return -ve if write to end */
                if ('\0' != p1[0])
                {
                    r = ((0 != cchFeName) ? 0 : 2) + 3 + stlsoft_static_cast(int, cchFeName);
                }
            }

            if (r > (end - p1))
            {
                p1 = end;
            }
            else
            if (r > 0)
            {
                p1 += r;
            }
        }
        if (0 != cchQualifier)
        {
            int r = 0;

            if (p1 < end)
            {
                p1[0] = '\0';

                r = pantheios_util_snprintf_a(p1, (end - p1), ": %.*s", (int)cchQualifier, qualifier);
            }

            if (r < 0)
            {
                /* Some runtime libraries' snprintf() return -ve if write to end */
                if ('\0' != p1[0])
                {
                    r = 2 + stlsoft_static_cast(int, cchFeName);
                }
            }

            if (r > (end - p1))
            {
                p1 = end;
            }
            else
            if (r > 0)
            {
                p1 += r;
            }

            STLSOFT_SUPPRESS_UNUSED(p1);
        }

        pantheios_onBailOut4(severity, message, processId, qualifier_);

        return;
    }
}

PANTHEIOS_CALL(void)
pantheios_onBailOut4(
    int         severity
,   char const* message
,   char const* processId
,   char const* qualifier
)
{
    if (NULL == qualifier)
    {
        pantheios_onBailOut3(severity, message, processId);

        return;
    }
    else
    {
        size_t cchQualifier = pan_strlen_m_(qualifier);

        if (NULL == message)
        {
            pantheios_onBailOut3(severity, qualifier, processId);

            return;
        }
        else if (0 == cchQualifier)
        {
            pantheios_onBailOut3(severity, message, processId);

            return;
        }
        else
        {
            char            message_[PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE];
            const size_t    cchBuf      =   STLSOFT_NUM_ELEMENTS(message_) - 1;
            size_t          cchMessage  =   pan_strlen_m_(message);
            const char      sep[]       =   { ':', ' ', '\0' }; /* ": " */

            if (cchBuf < (cchMessage + 2 + cchQualifier))
            {
                /* Won't fit, so need to shrink message or qualifier or both
                 *
                 * - if qualifier is 1/3 buffer or less, then shrink message
                 * - if message is 2/3 buffer or less, then shrink qualifier
                 * - if both > buffer, then make each half buffer
                 */

                if (cchQualifier < (cchBuf - 2) / 3 &&
                    cchMessage > (cchBuf - 2) - cchQualifier)
                {
                    cchMessage = (cchBuf - 2) - cchQualifier;
                }
                else
                if (cchMessage < (cchBuf - 2) * 2 / 3 &&
                    cchQualifier > (cchBuf - 2) - cchMessage)
                {
                    cchQualifier = (cchBuf - 2) - cchMessage;
                }
                else
                if (cchMessage > (cchBuf - 2) &&
                    cchQualifier > (cchBuf - 2))
                {
                    cchMessage = (cchBuf - 2) / 2;
                    cchQualifier = (cchBuf - 2) / 2;
                }
                else
                {
                    /* At this point, the combined length is too large, but
                     * we've failed to trim on the above algorithms, so we
                     * do it in a coarse-grained manner: shrink the bigger
                     * one down to size
                     */
                    if (cchMessage > cchQualifier)
                    {
                        PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(cchQualifier < (cchBuf - 2));

                        cchMessage = (cchBuf - 2) - cchQualifier;
                    }
                    else
                    {
                        PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(cchMessage < (cchBuf - 2));

                        cchQualifier = (cchBuf - 2) - cchMessage;
                    }

                    PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION((cchMessage + 2 + cchQualifier) <= cchBuf);
                    PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(cchMessage <= cchBuf);
                    PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(cchQualifier <= cchBuf);
                }
            }

            PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(cchMessage <= cchBuf);
            PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(cchQualifier <= cchBuf);
            PANTHEIOS_CONTRACT_ENFORCE_ASSUMPTION(cchMessage + 2 + cchQualifier <= cchBuf);

            memcpy(&message_[0], message, cchMessage * sizeof(char));
            if (0 == cchQualifier)
            {
                message_[cchMessage] = '\0';
            }
            else
            {
                memcpy(&message_[cchMessage], sep, 2 * sizeof(char));
                memcpy(&message_[cchMessage + 2], qualifier, cchQualifier * sizeof(char));
                message_[cchMessage + 2 + cchQualifier] = '\0';
            }
            message_[cchBuf] = '\0';

            pantheios_onBailOut3(severity, message_, processId);
        }
    }
}

PANTHEIOS_CALL(void)
pantheios_onBailOut3(
    int         severity
,   char const* message
,   char const* processId
)
{
    size_t          cchMessage;
    char            message_[PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE];
    size_t          cchTime;
    size_t          cchTotal;
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    SYSTEMTIME      st;
# ifndef PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG
    HANDLE          hEventSrc;
# endif /* PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */
#else /* ? OS */
    struct timeval  tv;
    time_t          secs;
# ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
    struct tm       tm_;
# endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
    struct tm*      tm;
#endif /* OS */
    FILE*           hFile;

    severity &= 0x7;    /* Bailout ignores any custom severity information. */

    if (NULL == message)
    {
        message = "Unspecified failure";
    }

    cchMessage = pan_strlen_m_(message);

#if 0
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    GetLocalTime(&st);

# if defined(PANTHEIOS_MIN_CRT)
    cchTime = (size_t)  pan_wsprintf_m_( &message_[0]
# else /* ? min / safe CRT */
    cchTime = (size_t)  pantheios_util_snprintf_a(&message_[0], STLSOFT_NUM_ELEMENTS(message_)
# endif /* min / safe CRT */
                            ,   "%04u%02u%02u-%02u%02u%02u.%03u: "
                            ,   st.wYear
                            ,   st.wMonth
                            ,   st.wDay
                            ,   st.wHour
                            ,   st.wMinute
                            ,   st.wSecond
                            ,   st.wMilliseconds
                            );
#else /* ? OS */

    gettimeofday(&tv, NULL);
    secs = tv.tv_sec;
# ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
    tm = &tm_;
    localtime_s(tm, &secs);
# else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
    tm = localtime(&secs);
# endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */

    cchTime = (size_t)  pantheios_util_snprintf_a(&message_[0], STLSOFT_NUM_ELEMENTS(message_)
                            ,   "%04u%02u%02u-%02u%02u%02u.%03u: "
                            ,   tm->tm_year + 1900
                            ,   tm->tm_mon + 1
                            ,   tm->tm_mday
                            ,   tm->tm_hour
                            ,   tm->tm_min
                            ,   tm->tm_sec
                            ,   stlsoft_static_cast(int, tv.tv_usec / 1000)
                            );
#endif /* OS */

    PANTHEIOS_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL((cchTime < STLSOFT_NUM_ELEMENTS(message_) - 3), "time conversion overwrote the local buffer capacity");

    if ((cchTime + cchMessage) < (STLSOFT_NUM_ELEMENTS(message_) - 3))
    {
        cchTotal = cchTime + cchMessage;
    }
    else
    {
        cchTotal = STLSOFT_NUM_ELEMENTS(message_) - 3;
    }

# ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
    strncpy_s(&message_[cchTime], STLSOFT_NUM_ELEMENTS(message_) - cchTime, message, cchTotal - cchTime);
# else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
    pan_strncpy_m_(&message_[cchTime], message, cchTotal - cchTime);
# endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    message_[cchTotal    ] = '\r';
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
    message_[cchTotal + 1] = '\n';
    message_[cchTotal + 2] = '\0';

#if 0
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    /* /////////////////////////////////
     * 1. Debugger [Windows-only]
     */

    pan_OutputDebugString_m_(message_);

    /* /////////////////////////////////
     * 2. Console
     */

    fprintf(stderr, "%.*s\n", (int)cchTotal, message_);

    /* /////////////////////////////////
     * 3. File
     */

    if (0 == pantheios_util_onBailOut_fopen_m_(PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME, "a+", &hFile))
    {
        fprintf(hFile, "%.*s\n", (int)cchTotal, message_);

        fclose(hFile);
    }

    /* /////////////////////////////////
     * 4. Event Log [Windows-only]
     *
     * This uses a special event source registered by
     * Pantheios.COM. If that's not been installed, it
     * still works, but just not as neatly when viewing
     * the event log.
     */
# ifndef PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG

    hEventSrc = RegisterEventSourceA(NULL, "logging-bailout");

    if (NULL != hEventSrc)
    {
        char const* strings[2];
        WORD        type;
        DWORD       eventId;

        if (severity < PANTHEIOS_SEV_WARNING ||
            !pantheios_util_onBailOut_canUseWarnMessage_())
        {
            eventId = (NULL != processId) ? BAILOUT_2PARAM_FAIL_MESSAGE_ID : BAILOUT_1PARAM_FAIL_MESSAGE_ID;
        }
        else
        {
            eventId = (NULL != processId) ? BAILOUT_2PARAM_WARN_MESSAGE_ID : BAILOUT_1PARAM_WARN_MESSAGE_ID;
        }

        strings[0] = processId;
        strings[1] = message;

        type = pantheios_severity_to_WindowsEventLog_type(severity);

        pan_ReportEvent_m_(
                hEventSrc
            ,   type
            ,   0
            ,   eventId
            ,   NULL
            ,   STLSOFT_NUM_ELEMENTS(strings)
            ,   0
            ,   &strings[0]
            ,   NULL
            );

        DeregisterEventSource(hEventSrc);

        GetLastError();
    }
# else /* ? PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */

    STLSOFT_SUPPRESS_UNUSED(severity);
    STLSOFT_SUPPRESS_UNUSED(processId);
# endif /* PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */
#else /* ? OS */

    STLSOFT_SUPPRESS_UNUSED(processId);

    /* /////////////////////////////////
     * 2. Console
     */

    fprintf(stderr, "%.*s\n", (int)cchTotal, message_);

    /* /////////////////////////////////
     * 3. File
     */

    if (0 == pantheios_util_onBailOut_fopen_m_(PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME, "a+", &hFile))
    {
        fprintf(hFile, "%.*s\n", (int)cchTotal, message_);

        fclose(hFile);
    }

# if defined(PLATFORMSTL_OS_IS_UNIX)
#  ifndef PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG
    /* /////////////////////////////////
     * 5. Syslog [UNIX-only]
     */

    /* NOTE: will not be valid if widestring */
    syslog(LOG_EMERG | LOG_USER, "%s", message);
#  endif /* !PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG */
# endif /* OS */

#endif /* OS */
}

#ifdef PANTHEIOS_USE_WIDE_STRINGS

static
void
pantheios_onBailOut6_w_(
    int             severity
,   wchar_t const*  message
,   size_t          messageLen
,   wchar_t const*  processId
,   size_t          processIdLen
,   wchar_t const*  qualifier
,   size_t          qualifierLen
,   wchar_t const*  feName
,   size_t          feNameLen
,   wchar_t const*  beName
,   size_t          beNameLen
)
{
    static wchar_t const    colonSpace[]    =   L": ";

#ifdef _WIN32
    static size_t const     cchEolAndNull   =   2;
#else
    static size_t const     cchEolAndNull   =   1;
#endif

    wchar_t         fullMessage[PANTHEIOS_BAILOUT_STACK_BUFFER_SIZE];
    int             nfm;
    wchar_t const*  fmt;
    int             qualiferPrefixLen   =   (0 == qualifierLen) ? 0 : 2;
    size_t          cchTime;
    size_t          cchLimit;
    size_t          cchTotal;
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    SYSTEMTIME      st;
# ifndef PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG
    HANDLE          hEventSrc;
# endif /* PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */
#else /* ? OS */
    struct timeval  tv;
    time_t          secs;
# ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
    struct tm       tm_;
# endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
    struct tm*      tm;
#endif /* OS */
    FILE*           hFile;

    STLSOFT_ASSERT(0 == messageLen || NULL != message);
    STLSOFT_ASSERT(0 == processIdLen || NULL != processId);
    STLSOFT_ASSERT(0 == qualifierLen || NULL != qualifier);
    STLSOFT_ASSERT(0 == feNameLen || NULL != feName);
    STLSOFT_ASSERT(0 == beNameLen || NULL != beName);

    STLSOFT_SUPPRESS_UNUSED(processIdLen);

#ifdef _DEBUG
    memset(&fullMessage[0], '~', sizeof(fullMessage));
#endif

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    GetLocalTime(&st);

    cchTime = (size_t)pantheios_util_snprintf_w(
        &fullMessage[0], STLSOFT_NUM_ELEMENTS(fullMessage)
    ,   L"%04u%02u%02u-%02u%02u%02u.%03u: "
    ,   st.wYear
    ,   st.wMonth
    ,   st.wDay
    ,   st.wHour
    ,   st.wMinute
    ,   st.wSecond
    ,   st.wMilliseconds
    );
#else /* ? OS */

    gettimeofday(&tv, NULL);
    secs = tv.tv_sec;
# ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
    tm = &tm_;
    localtime_s(tm, &secs);
# else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
    tm = localtime(&secs);
# endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */

    cchTime = (size_t)pantheios_util_snprintf_w(
        &fullMessage[0], STLSOFT_NUM_ELEMENTS(fullMessage)
    ,   L"%04u%02u%02u-%02u%02u%02u.%03u: "
    ,   tm->tm_year + 1900
    ,   tm->tm_mon + 1
    ,   tm->tm_mday
    ,   tm->tm_hour
    ,   tm->tm_min
    ,   tm->tm_sec
    ,   stlsoft_static_cast(int, tv.tv_usec / 1000)
    );
#endif /* OS */

#ifdef _DEBUG
    memset(&fullMessage[0] + cchTime, '!', sizeof(fullMessage) - (sizeof(wchar_t) * cchTime));
#endif

    if (0 == feNameLen)
    {
        if (0 == beNameLen)
        {
            fmt = L"%.*s%.*s%.*s%.*s%.*s";
        }
        else
        {
            fmt = L"%.*s: %.*sbe=%.*s%.*s%.*s";
        }
    }
    else
    {
        if (0 == beNameLen)
        {
            fmt = L"%.*s: fe=%.*s%.*s%.*s%.*s";
        }
        else
        {
            fmt = L"%.*s: fe=%.*s, be=%.*s%.*s%.*s";
        }
    }

    cchLimit = STLSOFT_NUM_ELEMENTS(fullMessage) - (1 + cchEolAndNull);

    nfm = pantheios_util_snprintf_w(
        /* the +1 to allow sprintf to write the NUL that we will overwrite */
        &fullMessage[0] + cchTime, (cchLimit - cchTime) + 1
    ,   fmt
    ,   (int)messageLen, message
    ,   (int)feNameLen, feName
    ,   (int)beNameLen, beName
    ,   qualiferPrefixLen, colonSpace
    ,   (int)qualifierLen, qualifier
    );

    if (nfm < 0)
    {
        wchar_t const* const nul = stlsoft_C_wcsnchr(
            &fullMessage[0]
        ,   cchLimit
        ,   L'\0'
        );

        if (NULL == nul)
        {
            cchTotal = cchLimit;
        }
        else
        {
            cchTotal = (size_t)(nul - &fullMessage[0]);
        }
    }
    else
    {
        cchTotal = cchTime + (size_t)nfm;
    }

    STLSOFT_ASSERT(cchTotal < STLSOFT_NUM_ELEMENTS(fullMessage) - cchEolAndNull);

#ifdef _WIN32
    fullMessage[cchTotal++] = '\r';
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
    fullMessage[cchTotal++] = '\n';
    fullMessage[cchTotal  ] = '\0';


#if 0
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    /* /////////////////////////////////
     * 1. Debugger [Windows-only]
     */

    pan_OutputDebugString_w_(fullMessage);

    /* /////////////////////////////////
     * 2. Console
     */

    fwprintf(stderr, L"%.*s\n", (int)cchTotal - 2, fullMessage);

    /* /////////////////////////////////
     * 3. File
     */

    if (0 == pantheios_util_onBailOut_fopen_w_(PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME_w, L"a+", &hFile))
    {
        fwprintf(hFile, L"%.*s\n", (int)cchTotal - 2, fullMessage);

        fclose(hFile);
    }

    /* /////////////////////////////////
     * 4. Windows Event Log
     *
     * This uses a special event source registered by
     * Pantheios.COM. If that's not been installed, it
     * still works, but just not as neatly when viewing
     * the event log.
     */
# ifndef PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG

    hEventSrc = RegisterEventSourceW(NULL, L"logging-bailout");

    if (NULL != hEventSrc)
    {
        wchar_t const*  strings[2];
        WORD            type;
        DWORD           eventId;

        if (severity < PANTHEIOS_SEV_WARNING ||
            !pantheios_util_onBailOut_canUseWarnMessage_())
        {
            eventId = (0 != processIdLen) ? BAILOUT_2PARAM_FAIL_MESSAGE_ID : BAILOUT_1PARAM_FAIL_MESSAGE_ID;
        }
        else
        {
            eventId = (0 != processIdLen) ? BAILOUT_2PARAM_WARN_MESSAGE_ID : BAILOUT_1PARAM_WARN_MESSAGE_ID;
        }

        strings[0] = processId;
        strings[1] = message;

        type = pantheios_severity_to_WindowsEventLog_type(severity);

        pan_ReportEvent_w_(
                hEventSrc
            ,   type
            ,   0
            ,   eventId
            ,   NULL
            ,   STLSOFT_NUM_ELEMENTS(strings)
            ,   0
            ,   &strings[0]
            ,   NULL
            );

        DeregisterEventSource(hEventSrc);

        GetLastError();
    }
# else /* ? PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */

    STLSOFT_SUPPRESS_UNUSED(severity);
    STLSOFT_SUPPRESS_UNUSED(processId);
# endif /* PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */
#else /* ? OS */

    /* /////////////////////////////////
     * 1. Console
     */

    fwprintf(stderr, L"%.*s\n", (int)cchTotal - 2, fullMessage);

    /* /////////////////////////////////
     * 2. File
     */

    if (0 == pantheios_util_onBailOut_fopen_w_(PANTHEIOS_BAILOUT_BAILOUT_FILE_NAME_w, L"a+", &hFile))
    {
        fwprintf(hFile, L"%.*s\n", (int)cchTotal - 2, message_);

        fclose(hFile);
    }

# if defined(PLATFORMSTL_OS_IS_UNIX)
#  ifndef PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG
    /* /////////////////////////////////
     * 3. SysLog
     */

    /* NOTE: will not be valid if widestring */
    syslog(LOG_EMERG | LOG_USER, "%s", message);
#  endif /* !PANTHEIOS_BAILOUT_NO_UNIX_SYSLOG */
# endif /* OS */

#endif /* OS */
}

PANTHEIOS_CALL(void)
pantheios_onBailOut6_w(
    int             severity
,   wchar_t const*  message
,   wchar_t const*  processId
,   wchar_t const*  qualifier
,   wchar_t const*  feName
,   wchar_t const*  beName
)
{
#ifndef STLSOFT_NO_NAMESPACE
    using ::stlsoft::c_str_len_w;
    using ::stlsoft::c_str_ptr_w;
#endif

    pantheios_onBailOut6_w_(
        severity
    ,   c_str_ptr_w(message)
    ,   c_str_len_w(message)
    ,   c_str_ptr_w(processId)
    ,   c_str_len_w(processId)
    ,   c_str_ptr_w(qualifier)
    ,   c_str_len_w(qualifier)
    ,   c_str_ptr_w(feName)
    ,   c_str_len_w(feName)
    ,   c_str_ptr_w(beName)
    ,   c_str_len_w(beName)
    );
}

PANTHEIOS_CALL(void)
pantheios_onBailOut4_w(
    int             severity
,   wchar_t const*  message
,   wchar_t const*  processId
,   wchar_t const*  qualifier
)
{
#ifndef STLSOFT_NO_NAMESPACE
    using ::stlsoft::c_str_len_w;
    using ::stlsoft::c_str_ptr_w;
#endif

    pantheios_onBailOut6_w_(
        severity
    ,   c_str_ptr_w(message)
    ,   c_str_len_w(message)
    ,   c_str_ptr_w(processId)
    ,   c_str_len_w(processId)
    ,   c_str_ptr_w(qualifier)
    ,   c_str_len_w(qualifier)
    ,   L""
    ,   0
    ,   L""
    ,   0
    );
}

PANTHEIOS_CALL(void)
pantheios_onBailOut3_w(
    int             severity
,   wchar_t const*  message
,   wchar_t const*  processId
)
{
#ifndef STLSOFT_NO_NAMESPACE
    using ::stlsoft::c_str_len_w;
    using ::stlsoft::c_str_ptr_w;
#endif

    pantheios_onBailOut6_w_(
        severity
    ,   c_str_ptr_w(message)
    ,   c_str_len_w(message)
    ,   c_str_ptr_w(processId)
    ,   c_str_len_w(processId)
    ,   L""
    ,   0
    ,   L""
    ,   0
    ,   L""
    ,   0
    );
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG)

static int pantheios_util_onBailOut_canUseWarnMessage_x_(void)
{
/*
    read HKLM\SOFTWARE\Synesis Software\Logging Tools\Pantheios\Pantheios.COM@Version [DWORD]
*/
    int     canUseWarnMessage = 0;
    HKEY    key;

    if (0 == RegOpenKeyA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Synesis Software\\Logging Tools\\Pantheios\\Pantheios.COM", &key))
    {
        DWORD   actualVer;
        DWORD   cbData  =   sizeof(actualVer);

        if (0 == RegQueryValueExA(key, "Version", NULL, NULL, stlsoft_reinterpret_cast(LPBYTE, &actualVer), &cbData))
        {
            /* Check that version >= 1.0.1b31 */

            DWORD const requiredVer = 0x0100011f;

            if (actualVer >= requiredVer)
            {
                canUseWarnMessage = 1;
            }
        }

        RegCloseKey(key);
    }

    return canUseWarnMessage;
}

static int pantheios_util_onBailOut_canUseWarnMessage_(void)
{
    static DWORD    s_prevTickCount     =   0;
    DWORD           tickCount           =   GetTickCount();

    static int      s_canUseWarnMessage =   0;

    if (0 == s_prevTickCount ||
        0 == tickCount ||
        tickCount < s_prevTickCount ||
        (tickCount - s_prevTickCount) > (5 * 60 * 1000))
    {
        s_canUseWarnMessage =   pantheios_util_onBailOut_canUseWarnMessage_x_();
        s_prevTickCount     =   tickCount;
    }

    return s_canUseWarnMessage;
}
#endif /* PLATFORMSTL_OS_IS_WINDOWS && !defined(PANTHEIOS_BAILOUT_NO_WINDOWS_EVENTLOG */

static
int
pantheios_util_onBailOut_fopen_m_(
    char const*     path
,   char const*     mode
,   FILE**          phFile
)
{
    int r;

    STLSOFT_ASSERT(NULL != path);
    STLSOFT_ASSERT(NULL != mode);
    STLSOFT_ASSERT(NULL != phFile);

# ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS

    r = fopen_s(phFile, path, mode);
# else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */

    r = 0;

    *phFile = fopen(path, mode);


    if (NULL == *phFile)
    {
        r = errno;
    }
# endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */

    return r;
}

# ifdef PANTHEIOS_USE_WIDE_STRINGS

static
int
pantheios_util_onBailOut_fopen_w_(
    wchar_t const*  path
,   wchar_t const*  mode
,   FILE**          phFile
)
{
    int r;

    STLSOFT_ASSERT(NULL != path);
    STLSOFT_ASSERT(NULL != mode);
    STLSOFT_ASSERT(NULL != phFile);

# ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS

    r = _wfopen_s(phFile, path, mode);
# else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */

    r = 0;

    *phFile = _wfopen(path, mode);


    if (NULL == *phFile)
    {
        r = errno;
    }
# endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */

    return r;
}
# endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(PANTHEIOS_NO_NAMESPACE)
} /* namespace pantheios */
#endif /* !PANTHEIOS_NO_NAMESPACE */


/* ///////////////////////////// end of file //////////////////////////// */

