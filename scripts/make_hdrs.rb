#! /usr/bin/env ruby

# ######################################################################### #
# File:     make_hdrs.rb
#
# Purpose:  Generates the Pantheios logging API N-param functions
#
# Created:  21st June 2005
# Updated:  6th February 2024
#
# Author:   Matthew Wilson
#
############################################################


# ##########################################################
# imports

begin require 'synsoft/srcutil'; rescue LoadError; end

require 'libclimate'
require 'recls'

require 'date'

# ##########################################################
# includes

# ##########################################################
# constants

PROGRAM_VER_MAJOR               =   2
PROGRAM_VER_MINOR               =   3
PROGRAM_VER_REVISION            =   1

# ##########################################################
# functions

def current_date

  if defined? SrcUtil

    return SrcUtil.currentDate
  end

  DateTime.now.strftime('%d/%m/%Y')
end # current_date()

def declare_template_parameter_list(f, i)

  if false

    f << 'template< typename T0' << ENDL
    (1 ... i).each do |j|

      f << "        , typename T#{j}" << ENDL
    end
    f << '        >' << ENDL
  else

    s = 'template<typename T0';
    (1 ... i).each do |j|

      s = s + ", typename T#{j}"
    end
    s = s + '>'
    f << s << ENDL
  end
end # declare_template_parameter_list()

def declare_function_parameter_list(f, from, to)

  if false

    (from ... to).each do |j|

      f << ", T#{j} const    &v#{j}" << ENDL
    end
    f << ')' << ENDL
  else

    s = ''
    (from ... to).each do |j|

      s = s + ", T#{j} const& v#{j}"
    end
    f << s << ENDL
    f << ')' << ENDL
  end
end # declare_function_parameter_list()

def round_up(n, granularity)

  ((n + (granularity - 1)) / granularity) * granularity
end # round_up()

############################################################
# command-line processing

options   = {}
numParams = 32

climate = LibCLImate::Climate.new do |climate|

  climate.add_option('--number-of-parameters', alias: '-n', help: 'specifies the (maximum) number of parameters') do |o|

    begin

      numParams = Integer(o.value, 10)
    rescue ArgumentError

      climate.abort "invalid number '#{o.value}'; use --help for usage"
    end
  end

  climate.info_lines = [

    'Pantheios N-ary function template generator script',
    'Copyright Synesis Software Pty Ltd (c) 2005-2016',
    :version,
    '',
  ]
  climate.version = [ PROGRAM_VER_MAJOR, PROGRAM_VER_MINOR, PROGRAM_VER_REVISION ]

  trap 'SIGINT' do

    climate.abort 'processing cancelled ...', exit: 130
  end
end

r = climate.run ARGV

climate.abort "too many values; use --help for usage" unless ARGV.empty?

############################################################
# main()

NUM_PARAMS        = numParams
PARAM_RANGE       = (1 .. NUM_PARAMS)
TAB_SIZE          = 1 #4
TAB               = ' ' * TAB_SIZE
SHORT_ARG_LMARGIN = 2

USE_USING_DECLARATION = true
USE_SHIM_PAIR_MACRO   = true
USE_SHORT_ARG_LMARGIN = true

INITIALISERS_INLINE   = true
#CALL_LMARGIN          = '                        '
#CALL_LMARGIN          = '      '
CALL_LMARGIN          = "#{TAB}#{TAB}"

PARAMS_LIMIT_SYMBOL   = 'PANTHEIOS_APPL_PARAMS_LIMIT'

SEVERITY_LEVELS       = %w{ EMERGENCY ALERT CRITICAL ERROR WARNING NOTICE INFORMATIONAL DEBUG }

############################################################

d = Recls::stat('.')

if d.fileName == 'scripts'

  d = Recls::stat('../include/pantheios')
end

if !d or d.fileName != 'pantheios'

  abort "Not running in the correct directory; needs to be /???/include/pantheios"
end

SEP   = Recls::pathNameSeparator
ENDL  = "\n"

GENERATED_HEADER_DIRECTORY                = 'generated'
GENERATED_IMPL_DIRECTORY                  = 'internal/generated'

C_LOG_FUNCTIONS_HEADER_NAME               = GENERATED_HEADER_DIRECTORY + '/log_functions.h'
C_LOG_FUNCTIONS_IMPL_NAME                 = GENERATED_IMPL_DIRECTORY + '/log_functions.inl'
C_LOG_DISPATCH_FUNCTIONS_HEADER_NAME      = GENERATED_HEADER_DIRECTORY + '/log_dispatch_functions.h'
Cpp_LOG_DISPATCH_FUNCTIONS_HEADER_NAME    = GENERATED_HEADER_DIRECTORY + '/log_dispatch_functions.hpp'
Cpp_LOG_FUNCTIONS_HEADER_NAME             = GENERATED_HEADER_DIRECTORY + '/log_functions.hpp'
Cpp_LOG_SEV_FUNCTIONS_HEADER_NAME         = GENERATED_HEADER_DIRECTORY + '/log_sev_functions.hpp'

C_LOG_FUNCTIONS_HEADER                    = "#{d.path}#{SEP}" + C_LOG_FUNCTIONS_HEADER_NAME.gsub('/', SEP)
C_LOG_FUNCTIONS_IMPL                      = "#{d.path}#{SEP}" + C_LOG_FUNCTIONS_IMPL_NAME.gsub('/', SEP)
C_LOG_DISPATCH_FUNCTIONS_HEADER           = "#{d.path}#{SEP}" + C_LOG_DISPATCH_FUNCTIONS_HEADER_NAME.gsub('/', SEP)
Cpp_LOG_DISPATCH_FUNCTIONS_HEADER         = "#{d.path}#{SEP}" + Cpp_LOG_DISPATCH_FUNCTIONS_HEADER_NAME.gsub('/', SEP)
Cpp_LOG_FUNCTIONS_HEADER                  = "#{d.path}#{SEP}" + Cpp_LOG_FUNCTIONS_HEADER_NAME.gsub('/', SEP)
Cpp_LOG_SEV_FUNCTIONS_HEADER              = "#{d.path}#{SEP}" + Cpp_LOG_SEV_FUNCTIONS_HEADER_NAME.gsub('/', SEP)

num_pantheios_log_N_declarations          = 0
num_pantheios_log_N_no_test_declarations  = 0
num_pantheios_log_N_no_test_definitions   = 0
num_pantheios_log_N_definitions           = 0
num_log_dispatch_N_definitions            = 0
num_log_definitions                       = 0
num_log_sev_definitions                   = 0

############################################################
# C_LOG_FUNCTIONS_HEADER_NAME
puts C_LOG_FUNCTIONS_HEADER_NAME

f = File::new(C_LOG_FUNCTIONS_HEADER, 'w')

f << '/* /////////////////////////////////////////////////////////////////////////' << '' << ENDL
f << ' * File:        pantheios/' << C_LOG_FUNCTIONS_HEADER_NAME << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Purpose:     Declarations of the pantheios_log_<N>() functions' << ENDL
f << ' *' << '' << ENDL
f << " * Generated:   #{current_date}" << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Status:      This file is auto-generated: DO NOT EDIT!' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Copyright:   The copyright restrictions of the Pantheios library,' << '' << ENDL
f << ' *              enumerated in the header file <pantheios/pantheios.h>,' << '' << ENDL
f << ' *              apply to this file' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * ////////////////////////////////////////////////////////////////////// */' << '' << ENDL
f << '' << ENDL
# f << "/** \\file pantheios/#{C_LOG_FUNCTIONS_HEADER_NAME} [C, C++] INTERNAL, AUTO-GENERATED FILE: Do not include directly */" << ENDL
f << '' << ENDL

f << '#ifndef PANTHEIOS_INCLUDING_C_API_FUNCTIONS' << '' << ENDL
f << '# error This file is included by the Pantheios API, and cannot be included directly' << '' << ENDL
f << '#endif /* !PANTHEIOS_INCLUDING_C_API_FUNCTIONS */' << '' << ENDL
f << '' << ENDL

f << "#define PANTHEIOS_APPL_PARAMS_LIMIT_MAX_GENERATED   (#{NUM_PARAMS})" << '' << ENDL
f << '' << ENDL


PARAM_RANGE.each do |i|

  sig = "PANTHEIOS_CALL(int) pantheios_log_#{i}("
  if USE_SHORT_ARG_LMARGIN

    len = SHORT_ARG_LMARGIN
  else

    len = round_up(sig.length, TAB_SIZE)
  end
  len0    = len - TAB_SIZE
  sig     = sig.ljust(len)
  plural  = (i > 1) ? 's' : ''

  # Documentation comment

  f << "/** Logs #{i} parameter#{plural}, subject to external (not in \\ref group__core_library) severity-level filtering" << ENDL
  f << " * \\ingroup group__application_layer_interface__generated" << ENDL
  f << ' */' << ENDL


  # Function signature

  f << "#{sig}pan_sev_t severity" << ENDL
  (0 ... i). each do |j|

    f << ''.ljust(len0) + ", pantheios_char_t const* p#{j}, int l#{j} /* -1 => 'strlen(p#{j})' */" << ENDL
  end
  f << ');' << ENDL;
  f << '' << ENDL

  num_pantheios_log_N_declarations = 1 + num_pantheios_log_N_declarations
end

f.close()
f = nil

############################################################
# C_LOG_FUNCTIONS_IMPL_NAME
puts C_LOG_FUNCTIONS_IMPL_NAME

f = File::new(C_LOG_FUNCTIONS_IMPL, 'w')

f << '/* /////////////////////////////////////////////////////////////////////////' << '' << ENDL
f << ' * File:        pantheios/' << C_LOG_FUNCTIONS_IMPL_NAME << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Purpose:     Definitions of the pantheios_log_<N>() and' << ENDL
f << ' *              pantheios_log_<N>_no_test() functions' << ENDL
f << ' *' << '' << ENDL
f << " * Generated:   #{current_date}" << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Status:      This file is auto-generated: DO NOT EDIT!' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Copyright:   The copyright restrictions of the Pantheios library,' << '' << ENDL
f << ' *              enumerated in the header file <pantheios/pantheios.h>,' << '' << ENDL
f << ' *              apply to this file' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * ////////////////////////////////////////////////////////////////////// */' << '' << ENDL
f << '' << ENDL
# f << "/** \\file pantheios/#{C_LOG_FUNCTIONS_IMPL_NAME} [C++ only] INTERNAL, AUTO-GENERATED FILE: Do not include directly */" << ENDL
f << '' << ENDL

f << '#ifndef __cplusplus' << ENDL
f << '# error This file cannot be used independently, nor as part of a C compilation unit. It should only be included from within pantheios_core.cpp' << ENDL
f << '#endif /* __cplusplus */' << ENDL
f << '' << ENDL
f << '' << ENDL

PARAM_RANGE.each do |i|

  sig = "PANTHEIOS_CALL(int) pantheios_log_#{i}_no_test("
  if USE_SHORT_ARG_LMARGIN

    len = SHORT_ARG_LMARGIN
  else

    len = round_up(sig.length, TAB_SIZE)
  end
  len0  = len - TAB_SIZE
  sig   = sig.ljust(len)

  f << "#{sig}pan_sev_t severity" << ENDL
  (0 ... i). each do |j|

    f << ''.ljust(len0) + ", pan_slice_t const& slice#{j}" << ENDL
  end
  f << ')' << ENDL
  f << '{' << ENDL
  f << "#{TAB}pan_slice_t const slices[#{i}] =" << ENDL
  f << "#{TAB}{" << ENDL
  if INITIALISERS_INLINE

    f << "#{TAB}#{TAB}slice0"
    (1 ... i). each do |j|

      f << ", slice#{j}"
    end
    f << '' << ENDL
  else

    f << "#{TAB}#{TAB}  slice0" << ENDL
    (1 ... i). each do |j|

      f << "#{TAB}#{TAB}, slice#{j}" << ENDL
    end
  end
  f << "#{TAB}};" << ENDL
  f << '' << ENDL
  f << "#{TAB}return pantheios_log_n(severity, STLSOFT_NUM_ELEMENTS(slices), slices);" << ENDL
  f << '}' << ENDL
  f << '' << ENDL

  num_pantheios_log_N_no_test_definitions = 1 + num_pantheios_log_N_no_test_definitions
end

PARAM_RANGE.each do |i|

  sig = "PANTHEIOS_CALL(int) pantheios_log_#{i}("
  if USE_SHORT_ARG_LMARGIN

    len = SHORT_ARG_LMARGIN
  else

    len = round_up(sig.length, TAB_SIZE)
  end
  len0  = len - TAB_SIZE
  sig   = sig.ljust(len)
  f << "#{sig}pan_sev_t severity" << ENDL
  (0 ... i - 1). each do |j|

    f << ''.ljust(len0) + ", pantheios_char_t const* p#{j}, int l#{j}" << ENDL
  end
  f << ''.ljust(len0) + ", pantheios_char_t const* p#{i - 1}, int l#{i - 1})" << ENDL
  f << '{' << ENDL
  f << "#{TAB}if(!pantheios_isSeverityLogged(severity))" << ENDL
  f << "#{TAB}{" << ENDL
  f << "#{TAB}#{TAB}#{TAB}return 0;" << ENDL
  f << "#{TAB}}" << ENDL
  f << "#{TAB}else" << ENDL
  f << "#{TAB}{" << ENDL
  f << "#{TAB}#{TAB}pan_slice_t const slices[#{i}] =" << ENDL
  f << "#{TAB}#{TAB}{" << ENDL
  if INITIALISERS_INLINE

    f << "#{TAB}#{TAB}#{TAB}pan_slice_t(l0, p0)"
  else

    f << "#{TAB}#{TAB}#{TAB}pan_slice_t(l0, p0)" << ENDL
  end
  (1 ... i). each do |j|

    if INITIALISERS_INLINE

      f << ", pan_slice_t(l#{j}, p#{j})"
    else

      f << "#{TAB}#{TAB}#{TAB}, pan_slice_t(l#{j}, p#{j})" << ENDL
    end
  end
  if INITIALISERS_INLINE

    f << '' << ENDL
  end
  f << "#{TAB}#{TAB}};" << ENDL
  f << '' << ENDL
  f << "#{TAB}#{TAB}return pantheios_log_n(severity, STLSOFT_NUM_ELEMENTS(slices), slices);" << ENDL
  f << "#{TAB}}" << ENDL
  f << '}' << ENDL
  f << '' << ENDL

  num_pantheios_log_N_definitions = 1 + num_pantheios_log_N_definitions
end

f.close()
f = nil

############################################################
# C_LOG_DISPATCH_FUNCTIONS_HEADER_NAME
puts C_LOG_DISPATCH_FUNCTIONS_HEADER_NAME

f = File::new(C_LOG_DISPATCH_FUNCTIONS_HEADER, 'w')

f << '/* /////////////////////////////////////////////////////////////////////////' << '' << ENDL
f << ' * File:        pantheios/' << C_LOG_DISPATCH_FUNCTIONS_HEADER_NAME << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Purpose:     Declarations of the pantheios_log_<N>_no_test() functions' << ENDL
f << ' *' << '' << ENDL
f << " * Generated:   #{current_date}" << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Status:      This file is auto-generated: DO NOT EDIT!' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Copyright:   The copyright restrictions of the Pantheios library,' << '' << ENDL
f << ' *              enumerated in the header file <pantheios/pantheios.h>,' << '' << ENDL
f << ' *              apply to this file' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * ////////////////////////////////////////////////////////////////////// */' << '' << ENDL
f << '' << ENDL
# f << "/** \\file pantheios/#{C_LOG_DISPATCH_FUNCTIONS_HEADER_NAME} [C, C++] INTERNAL, AUTO-GENERATED FILE: Do not include directly */" << ENDL
f << '' << ENDL

f << '#ifndef PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS' << '' << ENDL
f << '# error This file is included by the Pantheios API, and cannot be included directly' << '' << ENDL
f << '#endif /* !PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS */' << '' << ENDL
f << '' << ENDL
f << '' << ENDL

PARAM_RANGE.each do |i|

  sig = "PANTHEIOS_CALL(int) pantheios_log_#{i}_no_test("
  if USE_SHORT_ARG_LMARGIN

    len = SHORT_ARG_LMARGIN
  else

    len = round_up(sig.length, TAB_SIZE)
  end
  len0  = len - TAB_SIZE
  sig   = sig.ljust(len)

  # Template parameter list

  # Function signature

  f << "#{sig}" << ENDL
  f << ''.ljust(len0) + '  pan_sev_t severity' << ENDL
  (0 ... i). each do |j|

    f << ''.ljust(len0) + ", pan_slice_t const& s#{j}" << ENDL
  end
  f << ');' << ENDL

  f << '' << ENDL

  num_pantheios_log_N_no_test_declarations = 1 + num_pantheios_log_N_no_test_declarations
end

f.close()
f = nil

############################################################
# Cpp_LOG_DISPATCH_FUNCTIONS_HEADER_NAME
puts Cpp_LOG_DISPATCH_FUNCTIONS_HEADER_NAME

f = File::new(Cpp_LOG_DISPATCH_FUNCTIONS_HEADER, 'w')

f << '/* /////////////////////////////////////////////////////////////////////////' << '' << ENDL
f << ' * File:        pantheios/' << Cpp_LOG_DISPATCH_FUNCTIONS_HEADER_NAME << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Purpose:     Inline definitions of the log_dispatch_<N>() functions' << ENDL
f << ' *' << '' << ENDL
f << " * Generated:   #{current_date}" << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Status:      This file is auto-generated: DO NOT EDIT!' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Copyright:   The copyright restrictions of the Pantheios library,' << '' << ENDL
f << ' *              enumerated in the header file <pantheios/pantheios.h>,' << '' << ENDL
f << ' *              apply to this file' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * ////////////////////////////////////////////////////////////////////// */' << '' << ENDL
f << '' << ENDL
# f << "/** \\file pantheios/#{Cpp_LOG_DISPATCH_FUNCTIONS_HEADER_NAME} [C++ only] INTERNAL, AUTO-GENERATED FILE: Do not include directly */" << ENDL
f << '' << ENDL

f << '#ifndef PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS' << '' << ENDL
f << '# error This file is included by the Pantheios API, and cannot be included directly' << '' << ENDL
f << '#endif /* !PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS */' << '' << ENDL
f << '' << ENDL
f << '' << ENDL

PARAM_RANGE.each do |i|

  sig = "inline int log_dispatch_#{i}("
  if USE_SHORT_ARG_LMARGIN

    len = SHORT_ARG_LMARGIN
  else

    len = round_up(sig.length, TAB_SIZE)
  end
  len0    = len - TAB_SIZE
  sig     = sig.ljust(len)
  plural  = (i > 1) ? 's' : ''

  # Pre-processor limits
  f << "#if #{PARAMS_LIMIT_SYMBOL} >= #{i}" << ENDL << ENDL

  # Template parameter list

  # Function signature

  f << "#{sig}pan_sev_t severity" << ENDL
  (0 ... i). each do |j|

    f << ''.ljust(len0) + ", size_t l#{j}, pantheios_char_t const* p#{j}" << ENDL
  end
  f << ')' << ENDL
  f << '{' << ENDL
  stm = "  return pantheios_log_#{i}_no_test("
  if USE_SHORT_ARG_LMARGIN

    len = SHORT_ARG_LMARGIN
  else

    len = round_up(sig.length, TAB_SIZE)
  end
  len0  = len - TAB_SIZE
  stm   = stm.ljust(len)
  f << "#{stm}severity" << ENDL
  (0 ... i).each do |j|

    f << ''.ljust(len0) + ", pan_slice_t(p#{j}, l#{j})" << ENDL
  end
  f << ''.ljust(len0) + ');' << ENDL
  f << '}' << ENDL
  f << '' << ENDL

  num_log_dispatch_N_definitions = 1 + num_log_dispatch_N_definitions
end
PARAM_RANGE.each { |i| f << "#endif /* #{PARAMS_LIMIT_SYMBOL} >= #{NUM_PARAMS - i + 1} */" << ENDL }

f.close()
f = nil

############################################################
# Cpp_LOG_FUNCTIONS_HEADER_NAME
puts Cpp_LOG_FUNCTIONS_HEADER_NAME

f = File::new(Cpp_LOG_FUNCTIONS_HEADER, 'w')

f << '/* /////////////////////////////////////////////////////////////////////////' << '' << ENDL
f << ' * File:        pantheios/' << Cpp_LOG_FUNCTIONS_HEADER_NAME << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Purpose:     Definitions of the log() functions' << ENDL
f << ' *' << '' << ENDL
f << " * Generated:   #{current_date}" << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Status:      This file is auto-generated: DO NOT EDIT!' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Copyright:   The copyright restrictions of the Pantheios library,' << '' << ENDL
f << ' *              enumerated in the header file <pantheios/pantheios.h>,' << '' << ENDL
f << ' *              apply to this file' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * ////////////////////////////////////////////////////////////////////// */' << '' << ENDL
f << '' << ENDL
# f << "/** \\file pantheios/#{Cpp_LOG_FUNCTIONS_HEADER_NAME} [C++ only] INTERNAL, AUTO-GENERATED FILE: Do not include directly */" << ENDL
f << '' << ENDL

f << '#ifndef PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS' << '' << ENDL
f << '# error This file is included by the Pantheios API, and cannot be included directly' << '' << ENDL
f << '#endif /* !PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS */' << '' << ENDL
f << '' << ENDL
f << '' << ENDL

PARAM_RANGE.each do |i|

  plural  = (i > 1) ? 's' : ''

  # Pre-processor limits
  f << "#if #{PARAMS_LIMIT_SYMBOL} >= #{i}" << ENDL << ENDL

  # Documentation comment

  f << "/** Logs #{i} object#{plural} of arbitrary type, subject to severity-level filtering" << ENDL
  f << " * \\ingroup group__application_layer_interface__generated" << ENDL
  f << " * \\note The \\c c_str_data_a() and \\c c_str_len_a() string access shims are applied to each parameter, to form a string slice" << ENDL
  f << ' */' << ENDL

  # Template parameter list

  declare_template_parameter_list(f, i)

  # Function signature

  f << "inline int log(" << ENDL
  f << "  pan_sev_t severity" << ENDL
  declare_function_parameter_list(f, 0, i)

  # Function body

  f << '{' << ENDL

  # isSeverityLogged() test

  f << "#{TAB}if(!pantheios_isSeverityLogged(severity))" << ENDL
  f << "#{TAB}{" << ENDL
  f << "#{TAB}#{TAB}return 0;" << ENDL
  f << "#{TAB}}" << ENDL
  f << "#{TAB}else" << ENDL
  f << "#{TAB}{" << ENDL

  # log_dispatch_N() call

  if USE_USING_DECLARATION

    f << "#{TAB}#{TAB}PANTHEIOS_DECLARE_SHIM_PAIR_();" << ENDL
    f << ENDL
  end

  f << '#ifndef PANTHEIOS_FORCE_ALLOW_FUNDAMENTAL_ARGUMENTS' << ENDL;
  f << "#{TAB}#{TAB}// NOTE: if one of the following lines causes a compile error," << ENDL;
  f << "#{TAB}#{TAB}// you have passed a fundamental type to the log() statement." << ENDL;
  (0 ... i).each do |j|

    f << "#{TAB}#{TAB}PANTHEIOS_VALIDATE_TYPE_NOT_FUNDAMENTAL_(T#{j});" << ENDL;
  end
  f << '#endif /* PANTHEIOS_FORCE_ALLOW_FUNDAMENTAL_ARGUMENTS */' << ENDL;
  f << ENDL

  f << "#{TAB}#{TAB}return internal::log_dispatch_#{i}(severity" << ENDL
  (0 ... i).each do |j|

    if USE_SHIM_PAIR_MACRO

      f << "#{CALL_LMARGIN}, PANTHEIOS_INVOKE_SHIM_PAIR_(v#{j})" << ENDL
    elsif USE_USING_DECLARATION

      f << "#{CALL_LMARGIN}, c_str_len_a(v#{j}), c_str_data_a(v#{j})" << ENDL
    else

      f << "#{CALL_LMARGIN}, ::stlsoft::c_str_len_a(v#{j}), ::stlsoft::c_str_data_a(v#{j})" << ENDL
    end
  end
  f << "#{TAB}#{TAB});" << ENDL
  f << "#{TAB}}" << ENDL
  f << '}' << ENDL
  f << '' << ENDL

  num_log_definitions = 1 + num_log_definitions
end
PARAM_RANGE.each { |i| f << "#endif /* #{PARAMS_LIMIT_SYMBOL} >= #{NUM_PARAMS - i + 1} */" << ENDL }

f.close()
f = nil

############################################################
# Cpp_LOG_SEV_FUNCTIONS_HEADER_NAME
puts Cpp_LOG_SEV_FUNCTIONS_HEADER_NAME

f = File::new(Cpp_LOG_SEV_FUNCTIONS_HEADER, 'w')

f << '/* /////////////////////////////////////////////////////////////////////////' << '' << ENDL
f << ' * File:        pantheios/' << Cpp_LOG_SEV_FUNCTIONS_HEADER_NAME << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Purpose:     Definitions of the log_<LEVEL>() functions' << ENDL
f << ' *' << '' << ENDL
f << " * Generated:   #{current_date}" << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Status:      This file is auto-generated: DO NOT EDIT!' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * Copyright:   The copyright restrictions of the Pantheios library,' << '' << ENDL
f << ' *              enumerated in the header file <pantheios/pantheios.h>,' << '' << ENDL
f << ' *              apply to this file' << '' << ENDL
f << ' *' << '' << ENDL
f << ' * ////////////////////////////////////////////////////////////////////// */' << '' << ENDL
f << '' << ENDL
# f << "/** \\file pantheios/#{Cpp_LOG_SEV_FUNCTIONS_HEADER_NAME} [C++ only] INTERNAL, AUTO-GENERATED FILE: Do not include directly */" << ENDL

f << '' << ENDL
f << '#ifndef PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS' << '' << ENDL
f << '# error This file is included by the Pantheios API, and cannot be included directly' << '' << ENDL
f << '#endif /* !PANTHEIOS_INCL_PANTHEIOS_HPP_PANTHEIOS */' << '' << ENDL
f << '' << ENDL
f << '' << ENDL

SEVERITY_LEVELS.each do |severityLevel|

  PARAM_RANGE.each do |i|

    plural = (i > 1) ? 's' : ''

    # Pre-processor limits
    f << "#if #{PARAMS_LIMIT_SYMBOL} >= #{i}" << ENDL << ENDL

    # Documentation comment

    f << "/** Logs #{i} object#{plural} of arbitrary type, subject to severity-level filtering, at severity level \\link pantheios::SEV_#{severityLevel} #{severityLevel}\\endlink" << ENDL
    f << " * \\ingroup group__application_layer_interface__generated" << ENDL
    f << " * \\note The \\c c_str_data_a() and \\c c_str_len_a() string access shims are applied to each parameter, to form a string slice" << ENDL
    f << ' */' << ENDL

    # Template parameter list
    declare_template_parameter_list(f, i)

    # Function signature

    if i == 1

      f << "inline int log_#{severityLevel}(T0 const& v0)" << ENDL
    else

      sig   = "inline int log_#{severityLevel}("
      len   = ((sig.length + 3) / TAB_SIZE) * TAB_SIZE
      len0  = len - 2
      sig   = sig.ljust(len)

      f << "#{sig}T0 const  &v0" << ENDL
      declare_function_parameter_list(f, 1, i)
    end

    # Function body

    f << '{' << ENDL

    # isSeverityLogged() test

    f << "#{TAB}if(!pantheios_isSeverityLogged(PANTHEIOS_SEV_#{severityLevel}))" << ENDL
    f << "#{TAB}{" << ENDL
    f << "#{TAB}#{TAB}return 0;" << ENDL
    f << "#{TAB}}" << ENDL
    f << "#{TAB}else" << ENDL
    f << "#{TAB}{" << ENDL

    # log_dispatch_N() call

    if USE_USING_DECLARATION

      f << "#{TAB}#{TAB}PANTHEIOS_DECLARE_SHIM_PAIR_();" << ENDL
      f << ENDL
    end

    f << '#ifndef PANTHEIOS_FORCE_ALLOW_FUNDAMENTAL_ARGUMENTS' << ENDL;
    f << "#{TAB}#{TAB}// NOTE: if one of the following lines causes a compile error," << ENDL;
    f << "#{TAB}#{TAB}// you have passed a fundamental type to the log_#{severityLevel}() statement." << ENDL;
    (0 ... i).each do |j|

      f << "#{TAB}#{TAB}PANTHEIOS_VALIDATE_TYPE_NOT_FUNDAMENTAL_(T#{j});" << ENDL;
    end
    f << '#endif /* PANTHEIOS_FORCE_ALLOW_FUNDAMENTAL_ARGUMENTS */' << ENDL;
    f << ENDL

    f << "#{TAB}#{TAB}return internal::log_dispatch_#{i}(PANTHEIOS_SEV_#{severityLevel}" << ENDL

    (0 ... i).each do |j|

      if USE_SHIM_PAIR_MACRO

        f << "#{CALL_LMARGIN}, PANTHEIOS_INVOKE_SHIM_PAIR_(v#{j})" << ENDL
      elsif USE_USING_DECLARATION


        f << "#{CALL_LMARGIN}, c_str_len_a(v#{j}), c_str_data_a(v#{j})" << ENDL
      else

        f << "#{CALL_LMARGIN}, ::stlsoft::c_str_len_a(v#{j}), ::stlsoft::c_str_data_a(v#{j})" << ENDL
      end
    end
    f << "#{TAB}#{TAB});" << ENDL;

    f << "#{TAB}}" << ENDL
    f << '}' << ENDL
    f << '' << ENDL

    num_log_sev_definitions = 1 + num_log_sev_definitions
  end
  PARAM_RANGE.each { |i| f << "#endif /* #{PARAMS_LIMIT_SYMBOL} >= #{NUM_PARAMS - i + 1} */" << ENDL }
  f << ENDL;
end

f.close()
f = nil

puts

puts "# of pantheios_log_N() declarations:         #{num_pantheios_log_N_declarations}"
puts "# of pantheios_log_N_no_test() declarations: #{num_pantheios_log_N_no_test_declarations}"
puts "# of pantheios_log_N_no_test() definitions:  #{num_pantheios_log_N_no_test_definitions}"
puts "# of pantheios_log_N() definitions:          #{num_pantheios_log_N_definitions}"
puts "# of log_dispatch_N() definitions:           #{num_log_dispatch_N_definitions}"
puts "# of log() definitions:                      #{num_log_definitions}"
puts "# of log_SEV() definitions:                  #{num_log_sev_definitions}"

puts "--------------------------------------------"
puts "# of function declarations:                  #{num_pantheios_log_N_declarations + num_pantheios_log_N_no_test_declarations}"
puts "# of function definitions:                   #{num_pantheios_log_N_no_test_definitions + num_pantheios_log_N_definitions + num_log_dispatch_N_definitions + num_log_definitions + num_log_sev_definitions}"

# ############################## end of file ############################## #

