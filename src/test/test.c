#include "main.h"

#include "test.h"


#define RESULT_PASS "PASS"
#define RESULT_FAIL "FAIL"


bool test_assert_exit = true;
bool test_silent_pass = true;

static unsigned tests_passed = 0;
static unsigned tests_failed = 0;


static inline void stats_update(bool result)
{
    if (result)
        tests_passed++;
    else
        tests_failed++;
}


void test_assert(SOURCE_INFO_ARGS, const char *expression, bool result)
{
    stats_update(result);

    if (test_silent_pass && result)
        return;

    log_printf(LOG_TEST, SOURCE_INFO_VARS,
               "Assert `%s`: %s", expression, result ? RESULT_PASS : RESULT_FAIL);

    if (test_assert_exit && !result)
        exit(EXIT_FAILURE);
}


void test_check(SOURCE_INFO_ARGS, const char *expression, bool result)
{
    stats_update(result);

    if (test_silent_pass && result)
        return;

    log_printf(LOG_TEST, SOURCE_INFO_VARS,
               "Test `%s`: %s", expression, result ? RESULT_PASS : RESULT_FAIL);
}


void test_strcmp(SOURCE_INFO_ARGS,
                 const char *expression_1, const char *value_1,
                 const char *expression_2, const char *value_2)
{
    test_assert(SOURCE_INFO_VARS, expression_1, value_1);
    test_assert(SOURCE_INFO_VARS, expression_2, value_2);

    bool result = !strcmp(value_1, value_2);

    stats_update(result);

    if (test_silent_pass && result)
        return;

    log_printf(LOG_TEST, SOURCE_INFO_VARS,
               "Test `%s` is equal to `%s`: %s", expression_1, expression_2,
               result ? RESULT_PASS : RESULT_FAIL);
}
