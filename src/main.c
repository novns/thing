#include "main.h"

#include "test/test.h"
#include "tests-hash.h"

#include <time.h>


void tests_test();


int main(int argc, char const *argv[])
{
    log_open_stream(LOG_RANGE_FULL, stdout);

    log_open_file(LOG_RANGE_FULL, "/tmp/" PACKAGE ".log");
    log_open_file(LOG_RANGE_ERROR, "/tmp/" PACKAGE "-error.log");
    log_open_file(LOG_RANGE_INFO, "/tmp/" PACKAGE "-info.log");
    log_open_file(LOG_RANGE_DEBUG, "/tmp/" PACKAGE "-debug.log");

    log_open_syslog(LOG_RANGE_SYSLOG, PACKAGE, SYSLOG_USER);


    log_info("Starting %s", PACKAGE_STRING);


    if (argc < 2)
        log_fatal("Usage: %s [all] [test]", argv[0]);


    for (int i = 1; i < argc; i++) {
        const struct test *test = in_tests(argv[i], strlen(argv[i]));

        if (!test) {
            log_error("Unknown test set '%s'", argv[i]);
            continue;
        }

        switch (test->value) {

        case TESTS_ALL:
            tests_test();
            break;

        case TESTS_TEST:
            tests_test();
            break;
        }
    }


    tests_summary();


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


    log_close();

    return EXIT_SUCCESS;
}
