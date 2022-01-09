#include "main.h"

#include <time.h>


int main()
{
    log_open_stream(LOG_RANGE_STDOUT, stdout);
    log_open_stream(LOG_RANGE_STDERR, stderr);

    log_open_file(LOG_RANGE_FULL, "/tmp/" PACKAGE ".log");
    log_open_file(LOG_RANGE_ERROR, "/tmp/" PACKAGE "-error.log");
    log_open_file(LOG_RANGE_INFO, "/tmp/" PACKAGE "-info.log");
    log_open_file(LOG_RANGE_DEBUG, "/tmp/" PACKAGE "-debug.log");

    log_open_syslog(LOG_RANGE_SYSLOG, PACKAGE, SYSLOG_USER);


    log_info("Starting %s", PACKAGE_STRING);

#define exit(...)
#define log_close(...)
    log_fatal("Testing fatal message, exit() is disabled");
#undef exit
#undef log_close

    log_error("Testing error message");
    log_info("Testing info message");
    log_test("Testing test message");
    log_debug("Testing debug message");

#ifdef ENABLE_DEBUG
    srand(time(NULL));

    unsigned char dump_test[128];
    for (int i = 0; i < 128; i++)
        dump_test[i] = rand() % 256;

    log_dump(dump_test, 128);
#endif


    log_close();

    return EXIT_SUCCESS;
}
