#include "main.h"

#include "test/test.h"

#include <fcntl.h>
#include <time.h>
#include <unistd.h>


void tests_log()
{
    log_info("Testing log messages, stdout is disabled");


    fflush(stdout);

    int original_stdout = dup(STDOUT_FILENO);
    int empty_stdout = open("/dev/null", O_WRONLY);
    dup2(empty_stdout, STDOUT_FILENO);
    close(empty_stdout);


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


    fflush(stdout);

    dup2(original_stdout, STDOUT_FILENO);
    close(original_stdout);
}
