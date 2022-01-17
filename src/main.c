#include "main.h"

#include "test/test.h"
#include "tests-hash.h"


void tests_log();
void tests_test();


int main(int argc, char const *argv[])
{
    atexit(log_close);

    log_open_stream(LOG_RANGE_FULL, stdout);

    log_open_file(LOG_RANGE_FULL, "/tmp/" PACKAGE ".log");
    log_open_file(LOG_RANGE_ERROR, "/tmp/" PACKAGE "-error.log");
    log_open_file(LOG_RANGE_INFO, "/tmp/" PACKAGE "-info.log");
    log_open_file(LOG_RANGE_DEBUG, "/tmp/" PACKAGE "-debug.log");

    log_open_syslog(LOG_RANGE_SYSLOG, PACKAGE, SYSLOG_USER);


    log_info("Starting %s", PACKAGE_STRING);

    if (argc < 2)
        log_fatal("Usage: %s [all] [log] [test]", argv[0]);


    for (int i = 1; i < argc; i++) {
        const struct test *test = in_tests(argv[i], strlen(argv[i]));

        if (!test) {
            log_error("Unknown test set '%s'", argv[i]);
            continue;
        }

        switch (test->value) {

        case TESTS_ALL:
            tests_test();
            tests_log();
            break;

        case TESTS_LOG:
            tests_log();
            break;

        case TESTS_TEST:
            tests_test();
            break;
        }
    }


    tests_summary();

    return EXIT_SUCCESS;
}
