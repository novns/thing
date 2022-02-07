#include "main.h"


struct dict {
};


dict_t *dict_new()
{
    return NULL;
}


void dict_free(dict_t *dict)
{
    (void)dict;
}


size_t dict_count(dict_t *dict)
{
    (void)dict;

    return 0;
}


void *dict_get(dict_t *dict, const char *key)
{
    (void)dict;
    (void)key;

    return NULL;
}


dict_item_t *dict_get_item(dict_t *dict, const char *key)
{
    (void)dict;
    (void)key;

    return NULL;
}


dict_item_t *dict_iter(dict_t *dict)
{
    (void)dict;

    return NULL;
}


void dict_set(dict_t *dict, const char *key, void *data)
{
    (void)dict;
    (void)key;
    (void)data;
}
