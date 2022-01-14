#include "main.h"

#include "test/test.h"

#include <time.h>


void tests_log()
{
    log_info("Testing log messages");


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
    log_dump(dump_test, 32);
#endif
}
