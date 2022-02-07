#include "main.h"

#include "test/test.h"


void tests_dict()
{
    log_info("Testing dict object");


    dict_t *dict;

    ASSERT(dict = dict_new());

    TEST(!dict_get(dict, "wrong key"));
    TEST(dict_count(dict) == 0);


    dict_set(dict, "key 1", "wrong value 1");
    dict_set(dict, "key 2", "wrong value 2");
    dict_set(dict, "key 3", "wrong value 3");

    dict_set(dict, "key 1", "value 1");
    dict_set(dict, "key 2", "value 2");
    dict_set(dict, "key 3", "value 3");


    TEST(dict_count(dict) == 3);

    TEST(!dict_get_item(dict, "wrong key"));
    TEST(!dict_get(dict, "wrong key"));

    TEST_STRCMP(dict_get(dict, "key 1"), "value 1");
    TEST_STRCMP(dict_get(dict, "key 2"), "value 2");
    TEST_STRCMP(dict_get(dict, "key 3"), "value 3");


    dict_item_t *item = NULL;

    ASSERT(dict_iter(dict));
    ASSERT(dict_iter(dict));

    ASSERT(item = dict_iter(dict));
    TEST_STRCMP(item->data, "value 3");

    TEST(!dict_iter(dict));


    dict_free(dict);
}
