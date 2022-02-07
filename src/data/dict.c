#include "main.h"


struct dict {
    dict_item_t *items;

    size_t count;
    size_t iter;
};


dict_t *dict_new()
{
    return calloc(1, sizeof(dict_t));
}


void dict_free(dict_t *dict)
{
    if (!dict)
        log_fatal(ERROR_NULL);

    free(dict->items);
    free(dict);
}


size_t dict_count(dict_t *dict)
{
    if (!dict)
        log_fatal(ERROR_NULL);

    return dict->count;
}


void *dict_get(dict_t *dict, const char *key)
{
    if (!dict || !key)
        log_fatal(ERROR_NULL);

    dict_item_t *item = dict_get_item(dict, key);

    if (item)
        return item->data;

    return NULL;
}


dict_item_t *dict_get_item(dict_t *dict, const char *key)
{
    if (!dict || !key)
        log_fatal(ERROR_NULL);

    dict_item_t *item = NULL;

    size_t i = 0, l = 0, u = dict->count;

    while (l < u) {
        i = (l + u) / 2;
        item = dict->items + i;

        int cmp = strcmp(key, item->key);

        if (cmp < 0)
            u = i;

        else if (cmp > 0)
            l = i + 1;

        else
            return item;
    }

    return NULL;
}


dict_item_t *dict_iter(dict_t *dict)
{
    if (!dict)
        log_fatal(ERROR_NULL);

    if (dict->iter >= dict->count) {
        dict->iter = 0;
        return NULL;
    }

    return dict->items + dict->iter++;
}


void dict_set(dict_t *dict, const char *key, void *data)
{
    if (!dict || !key)
        log_fatal(ERROR_NULL);

    bool found = false;
    dict_item_t *item = NULL;

    size_t i = 0, l = 0, u = dict->count;

    while (l < u) {
        i = (l + u) / 2;
        item = dict->items + i;

        int cmp = strcmp(key, item->key);

        if (cmp < 0)
            u = i;

        else if (cmp > 0)
            l = i + 1;

        else {
            found = true;
            break;
        }
    }

    if (!found) {
        dict->count++;
        dict->items = realloc(dict->items, dict->count * sizeof(dict_item_t));

        item = dict->items + l;
        memmove(item + 1, item, sizeof(dict_item_t) * (dict->count - l - 1));

        item->key = key;
    }

    item->data = data;
}
