#pragma once

#include "main.h"


typedef struct dict_item {
    const char *key;
    void *data;
} dict_item_t;

typedef struct dict dict_t;


dict_t *dict_new();

void dict_free(dict_t *dict);


size_t dict_count(dict_t *dict);


void *dict_get(dict_t *dict, const char *key);

dict_item_t *dict_get_item(dict_t *dict, const char *key);

dict_item_t *dict_iter(dict_t *dict);


void dict_set(dict_t *dict, const char *key, void *data);
