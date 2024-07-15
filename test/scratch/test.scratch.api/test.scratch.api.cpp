/* /////////////////////////////////////////////////////////////////////////
 * File:        test/scratch/test.scratch.api/test.scratch.api.cpp
 *
 * Purpose:     Implementation file for the test.scratch.api project.
 *
 * Created:     26th June 2005
 * Updated:     16th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef __GNUC__
# define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS
#endif

/* This inclusion required for suppressing warnings during NoX (No eXception-support) configurations. */
#include <pantheios/util/test/compiler_warnings_suppression.first_include.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/inserters/blob.hpp>
#include <pantheios/inserters/integer.hpp>
#include <pantheios/inserters/pointer.hpp>
#include <pantheios/inserters/real.hpp>
#include <pantheios/backends/be.lrsplit.h>
#include <pantheios/frontend.h>

/* STLSoft header files */
#include <stlsoft/memory/malloc_allocator.hpp>
#include <stlsoft/memory/new_allocator.hpp>
#include <stlsoft/string/shim_string.hpp>
#include <stlsoft/string/simple_string.hpp>

/* PlatformSTL header files */
#include <platformstl/platformstl.hpp>

#if defined(PLATFORMSTL_OS_IS_WINDOWS)
 /* WinSTL header files */
# include <winstl/error/error_desc.hpp>
# include <winstl/filesystem/findfile_sequence.hpp>
# include <winstl/memory/processheap_allocator.hpp>
# include <winstl/shims/access/string/time.hpp>
#else /* ? platform */
# include <stlsoft/shims/access/string/std/time.hpp>
#endif /* platform */

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C header files */
#include <time.h>

#include <pantheios/util/test/compiler_warnings_suppression.last_include.h>

/* ////////////////////////////////////////////////////////////////////// */

#ifdef PANTHEIOS_USE_WIDE_STRINGS

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.api");

/* The following allows this to be used with the Windows
 * EventLog back-end.
 */

PANTHEIOS_CALL(void) pantheios_be_WindowsEventLog_calcCategoryAndEventId(
    int                     /* backEndId */
,   int                     /* severity */
,   pantheios::uint16_t*    category
,   pantheios::uint32_t*    eventId
) /* throw() */;
PANTHEIOS_CALL(void) pantheios_be_WindowsEventLog_calcCategoryAndEventId(
    int                     /* backEndId */
,   int                     /* severity */
,   pantheios::uint16_t*    category
,   pantheios::uint32_t*    eventId
) /* throw() */
{
    // NOTE: A proper implementation would specify non-0 values here that
    // identify the requisite event identifier and category within the
    // associated message file(s)

    *eventId    =   0;
    *category   =   0;
}

int main()
{
        return 0;
}

#else /* ? PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static int main_(int /* argc */, char ** /*argv*/);
static void some_logging_with_using_namespace_directive();
static void some_logging_with_using_declarations();
static void some_logging_with_explicit_qualification();


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define P_STR   PANTHEIOS_LITERAL_STRING


/* /////////////////////////////////////////////////////////////////////////
 * string encoding compatibility
 */

#ifdef PANTHEIOS_USE_WIDE_STRINGS
# define pan_sprintf_s_                 swprintf_s
# define pan_sprintf_                   swprintf
# define c_str_data_t_                  c_str_data_w
# define c_str_len_t_                   c_str_len_w
#else /* ? PANTHEIOS_USE_WIDE_STRINGS */
# define pan_sprintf_s_                 sprintf_s
# define pan_sprintf_                   sprintf
# define c_str_data_t_                  c_str_data_a
# define c_str_len_t_                   c_str_len_a
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

class Thingy
{
};

namespace stlsoft
{
    inline stlsoft::basic_shim_string<pantheios::pan_char_t>
        c_str_data_t_(Thingy const &thingy)
    {
        stlsoft::basic_shim_string<pantheios::pan_char_t>   s(50);

        int cch = pan_sprintf_(s.data(), P_STR("0x%p"), static_cast<void const*>(&thingy));

        s.truncate(static_cast<size_t>(cch));

        return s;
    }

    inline size_t
        c_str_len_t_(Thingy const &/* thingy */)
    {
        const size_t    minLen  =   4;
        const size_t    maxLen  =   2 + sizeof(void*) * 2;

        return pantheios::pan_slice_t::get_lazy_length(minLen, maxLen);
    }


} /* namespace stlsoft */


std::string Thingy_to_string(Thingy const *thingy);
std::string Thingy_to_string(Thingy const *thingy)
{
    char sz[21];
    void const* pv = thingy;

    return std::string(sz, static_cast<size_t>(::sprintf(sz, "0x%p", pv)));
}

/* /////////////////////////////////////////////////////////////////////////
 * process identity
 *
 * This is defined for when we link with the pantheios.fe.simple front-end
 * library, which implements pantheios_fe_getProcessIdentity() in terms of this
 * externally defined array
 */

PANTHEIOS_EXTERN PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.api");

/* The following allows this to be used with the Windows
 * EventLog back-end.
 */

PANTHEIOS_CALL(void) pantheios_be_WindowsEventLog_calcCategoryAndEventId(
    int                     /* backEndId */
,   int                     /* severity */
,   pantheios::uint16_t*    category
,   pantheios::uint32_t*    eventId
) /* throw() */;
PANTHEIOS_CALL(void) pantheios_be_WindowsEventLog_calcCategoryAndEventId(
    int                     /* backEndId */
,   int                     /* severity */
,   pantheios::uint16_t*    category
,   pantheios::uint32_t*    eventId
) /* throw() */
{
    // NOTE: A proper implementation would specify non-0 values here that
    // identify the requisite event identifier and category within the
    // associated message file(s)

    *eventId    =   0;
    *category   =   0;
}

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char ** /*argv*/)
{
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
    cout << "test.scratch.api: " << STLSOFT_COMPILER_LABEL_STRING << endl;
#endif /* debug */

    some_logging_with_using_declarations();
    some_logging_with_explicit_qualification();
    some_logging_with_using_namespace_directive();

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
#if 0
    { for(size_t i = 0;0 != ++i;) {} }
#endif /* 0 */

    pantheios::log_DEBUG(P_STR("debug"));
    pantheios::log_INFORMATIONAL(P_STR("informational"));
    pantheios::log_NOTICE(P_STR("notice"));
    pantheios::log_WARNING(P_STR("warning"));
    pantheios::log_ERROR(P_STR("error"));
    pantheios::log_CRITICAL(P_STR("critical"));
    pantheios::log_ALERT(P_STR("alert"));
    pantheios::log_EMERGENCY(P_STR("emergency"));

    pantheios::log(pantheios::debug, P_STR("debug"));
    pantheios::log(pantheios::informational, P_STR("informational"));
    pantheios::log(pantheios::notice, P_STR("notice"));
    pantheios::log(pantheios::warning, P_STR("warning"));
    pantheios::log(pantheios::error, P_STR("error"));
    pantheios::log(pantheios::critical, P_STR("critical"));
    pantheios::log(pantheios::alert, P_STR("alert"));
    pantheios::log(pantheios::emergency, P_STR("emergency"));

    pantheios::log(pantheios::debug(10), P_STR("debug"));
    pantheios::log(pantheios::informational(10), P_STR("informational"));
    pantheios::log(pantheios::notice(10), P_STR("notice"));
    pantheios::log(pantheios::warning(10), P_STR("warning"));
    pantheios::log(pantheios::error(10), P_STR("error"));
    pantheios::log(pantheios::critical(10), P_STR("critical"));
    pantheios::log(pantheios::alert(10), P_STR("alert"));
    pantheios::log(pantheios::emergency(10), P_STR("emergency"));

#ifdef _DEBUGx
    { for(size_t i = 0; i != 200; ++i)
    {
        std::string s(i, '~');

        pantheios::log_DEBUG(s);
        pantheios::log_INFORMATIONAL(s);
        pantheios::log_NOTICE(s);
        pantheios::log_WARNING(s);
        pantheios::log_ERROR(s);
        pantheios::log_CRITICAL(s);
        pantheios::log_ALERT(s);
        pantheios::log_EMERGENCY(s);

        ::Sleep(5);
    }}
#endif /* _DEBUG */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#if !defined(STLSOFT_COMPILER_IS_GCC)
        {
            Thingy  thingy;

            pantheios::log_NOTICE(P_STR("Testing use of string min/max, with a Thingy instance: ["), thingy, P_STR("]"));
        }
#endif /* compiler */

#if 0
        {
            Thingy      thingy;

            pantheios::log_DEBUG("Testing custom type adaptation, with a Thingy instance: ", pantheios::insert(&thingy, Thingy_to_string));
        }
#endif /* 0 */

        {
  short         s     = 123;
  int           i     = 456;
  long          l     = 789;
  float         f     = static_cast<float>(0.123);
  double        d     = 0.456;
  long double   ld    = 0.789;
  void          *p    = reinterpret_cast<void*>(0x01230123);
  int           ar[2] = { 0x00112233, 0x44556677 };

  pantheios::log_INFORMATIONAL( P_STR("This string contains: ")
                              , P_STR("some integers ("), pantheios::integer(s), P_STR(", "), pantheios::integer(i, 4 | pantheios::fmt::zeroPad), P_STR(", "), pantheios::integer(l), P_STR("); ")
                              , P_STR("some real numbers ("), pantheios::real(f), P_STR(", "), pantheios::real(d), P_STR(", "), pantheios::real(ld), P_STR("); ")
                              , P_STR("a pointer ("), pantheios::pointer(p, pantheios::fmt::fullHex), P_STR("), ")
                              , P_STR("and a blob ("), pantheios::blob(ar, sizeof(ar), 2, P_STR("-"), 3, P_STR("\n\t")), P_STR("); "));
        }

        {
  using namespace pantheios;

  short         s   = 123;
  int           i   = 456;
  long          l   = 789;
  float         f   = static_cast<float>(0.123);
  double        d   = 0.456;
  long double   ld  = 0.789;
  void          *p  = reinterpret_cast<void*>(0x01230123);

  log_INFORMATIONAL( "This string contains: "
                   , "some integers (", integer(s), P_STR(", "), integer(i, 4 | fmt::zeroPad), P_STR(", "), integer(l), "); "
                   , "some real numbers (", real(f), P_STR(", "), real(d), P_STR(", "), real(ld), "); "
                   , "and a pointer (", pointer(p, fmt::fullHex), "); "
                   );
        }

        {
  using pantheios::log_INFORMATIONAL;
  using pantheios::integer;
  using pantheios::real;
  using pantheios::pointer;
  using pantheios::fmt;

  short         s   = 123;
  int           i   = 456;
  long          l   = 789;
  float         f   = static_cast<float>(0.123);
  double        d   = 0.456;
  long double   ld  = 0.789;
  void          *p  = reinterpret_cast<void*>(0x01230123);

  log_INFORMATIONAL( "This string contains: "
                   , "some integers (", integer(s), P_STR(", "), integer(i, 4 | fmt::zeroPad), P_STR(", "), integer(l), "); "
                   , "some real numbers (", real(f), P_STR(", "), real(d), P_STR(", "), real(ld), "); "
                   , "and a pointer (", pointer(p, fmt::fullHex), "); "
                   );
        }

        {
  void        *p  = reinterpret_cast<void*>(0x01234567);
  char        s[] = "abc";
  std::string str("def");

  pantheios::log(pantheios::notice, "s=", s, ", p=", pantheios::pointer(p, 8 | pantheios::fmt::fullHex), ", str=", str);
        }

        {
  double      d   = 123.456;
  char        s[] = "abc";
  std::string str("def");

  pantheios::log(pantheios::notice, "s=", s, ", d=", pantheios::real(d), ", str=", str);
        }

        {
  int         i   = 123;
  char        s[] = "abc";
  std::string str("def");

  pantheios::log(pantheios::notice, "s=", s, ", i=", pantheios::integer(i), ", str=", str);
        }

        return main_(argc, argv);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::exception &x)
    {
        cerr << "Unhandled error: " << x.what() << endl;
    }
    catch(...)
    {
        pantheios::pantheios_puts(pantheios::emergency, P_STR("Unhandled unknown error"));
    }

    return EXIT_FAILURE;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

/* ////////////////////////////////////////////////////////////////////// */

static void some_logging_with_using_namespace_directive()
{
    using namespace pantheios;

    log(PANTHEIOS_SEV_DEBUG, "some_logging_with_using_namespace_directive()");

    short                   s       =   123;
    int                     i       =   456;
    long                    l       =   789;
    float                   f       =   static_cast<float>(0.123);
    double                  d       =   0.456;
    long double             ld      =   0.789;
    void                    *p      =   &l;
    char const              *lstr   =   "{a pointer to a C-style string}";
    std::string             str     =   "{an instance of std::string}";
#if 1
# if 0
    stlsoft::simple_string  sstr    =   "{an instance of stlsoft::simple_string}";
# else /* ? 0 */
    std::basic_string<  char
                    ,   std::char_traits<char>
                    ,   stlsoft::new_allocator<char>
                    >       sstr    =   "{an instance of stlsoft::simple_string}";
# endif /* 0 */
#else /* ? 0 */
    stlsoft::basic_simple_string<   char
# if 1
                                ,   stlsoft::char_traits<char>
                                ,   winstl::processheap_allocator<char>
# else /* ? 0 */
                                ,   std::char_traits<char>
                                ,   stlsoft::new_allocator<char>
# endif /* 0 */
                                >   sstr    =   "{an instance of stlsoft::simple_string}";
#endif /* 0 */



#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    SYSTEMTIME              tm;

    ::GetLocalTime(&tm);
#else /* ? PLATFORMSTL_OS_IS_???? */
    time_t                  t       =   ::time(NULL);
    struct tm const         *tm     =   ::localtime(&t);
#endif /* PLATFORMSTL_OS_IS_???? */

    log_INFORMATIONAL(  "This is a (hopefully) typical error string, containing: "
                    ,   "some integers (", integer(s), P_STR(", "), integer(i), P_STR(", "), integer(l), "); "
                    ,   "some real numbers (", real(f), P_STR(", "), real(d), P_STR(", "), real(ld), "); "
                    ,   "a pointer (", pointer(p, fmt::hex), "); "
                    ,   "some strings (", lstr, P_STR(", "), str, P_STR(", "), sstr, "); "
                    ,   "and a converted time value (", tm, ")"
                    );
}

static void some_logging_with_using_declarations()
{
    using pantheios::log_CRITICAL;
    using pantheios::log;

    log(PANTHEIOS_SEV_DEBUG, "some_logging_with_using_declarations()");

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
        throw std::out_of_range("Eeep!");
    }
    catch(std::exception &x)
    {
        log_CRITICAL("Something really bad has happened! Details: \"", x, "\"");
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

static void some_logging_with_explicit_qualification()
{
    pantheios::log(PANTHEIOS_SEV_DEBUG, "some_logging_with_explicit_qualification()");

    pantheios::log_WARNING( "We're sure there're likely to be >"
                        ,   pantheios::integer(1000000, 20 | pantheios::fmt::zeroPad)
                        ,   " satisfied users of Pantheios"
                        );
}

/* ////////////////////////////////////////////////////////////////////// */

#ifdef WINSTL_FINDVOLUME_API_NOT_DECLARED

# include <winstl/dl/dl_call.hpp>

HANDLE WINAPI FindFirstVolumeA(
  LPSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
)
{
    return winstl::dl_call<HANDLE>("KERNEL32", "S:FindFirstVolumeA", lpszVolumeName, cchBufferLength);
}

HANDLE WINAPI FindFirstVolumeW(
  LPWSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

BOOL WINAPI FindNextVolumeA(
  HANDLE hFindVolume,      // volume search handle
  LPSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
)
{
    return winstl::dl_call<BOOL>("KERNEL32", "S:FindNextVolumeA", hFindVolume, lpszVolumeName, cchBufferLength);
}

BOOL WINAPI FindNextVolumeW(
  HANDLE hFindVolume,      // volume search handle
  LPWSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

BOOL WINAPI FindVolumeClose(
    HANDLE hFindVolume
    )
{
    return winstl::dl_call<BOOL>("KERNEL32", "S:FindVolumeClose", hFindVolume);
}

#endif /* WINSTL_FINDVOLUME_API_NOT_DECLARED */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* ///////////////////////////// end of file //////////////////////////// */

