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

    bool test_args = false;

    for (int i = 1; i < argc; i++) {
        const struct test *test = in_tests(argv[i], strlen(argv[i]));

        if (!test) {
            log_error("Unknown test set '%s'", argv[i]);
            continue;
        }

        test_args = test_args || test->value;

        switch (test->value) {

        case ARG_VERBOSE:
            test_silent_pass = !test_silent_pass;
            break;

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

    if (!test_args)
        log_fatal("Usage: %s [-v]  [all] [test]  [log]", argv[0]);


    tests_summary();

    return EXIT_SUCCESS;
}
