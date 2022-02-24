#pragma once

#include "main.h"


#define STR_DEFAULT_BLOCK_SIZE 64


typedef struct str str_t;


str_t *str_new(size_t block_size);

void str_free(str_t *str);


void str_enq_char(str_t *str, char c);

void str_enq_string(str_t *str, char *s);


char *str_get(str_t *str);
char *str_trim_get(str_t *str);

char *str_deq(str_t *str);
char *str_trim_deq(str_t *str);
