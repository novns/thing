#include "main.h"

#include "test/test.h"


void tests_str()
{
    log_info("Testing str object");


    str_t *str = NULL;

    char *value = NULL;


    ASSERT(str = str_new(STR_DEFAULT_BLOCK_SIZE));

    TEST_STRCMP(str_get(str), "");
    TEST_STRCMP(value = str_deq(str), "");
    free(value);


    for (char *c = "Test chars"; *c; c++)
        str_enq_char(str, *c);

    TEST_STRCMP(str_get(str), "Test chars");
    TEST_STRCMP(value = str_deq(str), "Test chars");
    free(value);

    TEST_STRCMP(str_get(str), "");
    TEST_STRCMP(value = str_deq(str), "");
    free(value);


    str_enq_string(str, "Test string");

    TEST_STRCMP(str_get(str), "Test string");
    TEST_STRCMP(value = str_deq(str), "Test string");
    free(value);

    TEST_STRCMP(str_get(str), "");
    TEST_STRCMP(value = str_deq(str), "");
    free(value);


    str_enq_string(str, "  Test trim  ");

    TEST_STRCMP(str_trim_get(str), "Test trim");
    TEST_STRCMP(value = str_trim_deq(str), "Test trim");
    free(value);

    TEST_STRCMP(str_trim_get(str), "");
    TEST_STRCMP(value = str_trim_deq(str), "");
    free(value);


    str_free(str);
}
