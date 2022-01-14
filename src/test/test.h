#pragma once

#include "main.h"


extern bool test_assert_exit;
extern bool test_silent_pass;


void test_assert(SOURCE_INFO_ARGS, const char *expression, bool result);

#define ASSERT(value) test_assert(SOURCE_INFO_VALUES, (#value), (value))


void test_check(SOURCE_INFO_ARGS, const char *expression, bool result);

#define TEST(value) test_check(SOURCE_INFO_VALUES, (#value), (value))


void test_strcmp(SOURCE_INFO_ARGS,
                 const char *expression_1, const char *value_1,
                 const char *expression_2, const char *value_2);

#define TEST_STRCMP(value_1, value_2) \
    test_strcmp(SOURCE_INFO_VALUES, (#value_1), (value_1), (#value_2), (value_2))
