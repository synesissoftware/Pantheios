
#include <pantheios/pan.hpp>
#include <pantheios/inserters/i.hpp>

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.scratch.showPlus.integer");


int main()
{
				pan::log_INFORMATIONAL("log -10:");
				pan::log_INFORMATIONAL("without showPlus: '", pan::i(-10), "'");
				pan::log_INFORMATIONAL("with    showPlus: '", pan::i(-10, 0, pan::fmt::showPlus), "'");
				pan::log_INFORMATIONAL("----------\n");

				pan::log_INFORMATIONAL("log +10:");
				pan::log_INFORMATIONAL("without showPlus: '", pan::i(+10), "'");
				pan::log_INFORMATIONAL("with    showPlus: '", pan::i(+10, 0, pan::fmt::showPlus), "'");
				pan::log_INFORMATIONAL("----------\n");


				pan::log_INFORMATIONAL("log -10 into 10-width:");
				pan::log_INFORMATIONAL("without showPlus: '", pan::i(-10, 10, 0), "'");
				pan::log_INFORMATIONAL("with    showPlus: '", pan::i(-10, 10, pan::fmt::showPlus), "'");
				pan::log_INFORMATIONAL("----------\n");

				pan::log_INFORMATIONAL("log +10 into 10-width:");
				pan::log_INFORMATIONAL("without showPlus: '", pan::i(+10, 10, 0), "'");
				pan::log_INFORMATIONAL("with    showPlus: '", pan::i(+10, 10, pan::fmt::showPlus), "'");
				pan::log_INFORMATIONAL("----------\n");


				pan::log_INFORMATIONAL("log -10 into 10-width left-justified:");
				pan::log_INFORMATIONAL("without showPlus: '", pan::i(-10, -10, 0), "'");
				pan::log_INFORMATIONAL("with    showPlus: '", pan::i(-10, -10, pan::fmt::showPlus), "'");
				pan::log_INFORMATIONAL("----------\n");

				pan::log_INFORMATIONAL("log +10 into 10-width left-justified:");
				pan::log_INFORMATIONAL("without showPlus: '", pan::i(+10, -10, 0), "'");
				pan::log_INFORMATIONAL("with    showPlus: '", pan::i(+10, -10, pan::fmt::showPlus), "'");
				pan::log_INFORMATIONAL("----------\n");


				return 0;
}

/* ///////////////////////////// end of file //////////////////////////// */

