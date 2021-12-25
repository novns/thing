#include "main.h"


int main()
{
    log_open_stream(LOG_RANGE_STDOUT, stdout);
    log_open_stream(LOG_RANGE_STDERR, stderr);

    log_info("Starting %s", PACKAGE_STRING);

#define exit(...)
    log_fatal("Testing fatal message, exit() is disabled");
#undef exit

    log_error("Testing error message");
    log_info("Testing info message");
    log_test("Testing test message");
    log_debug("Testing debug message");

    log_close();

    return EXIT_SUCCESS;
}
