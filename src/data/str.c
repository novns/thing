#include "main.h"

struct str {
    size_t alloc_size;
    size_t block_size;
    size_t data_size;

    char *data;
};


str_t *str_new(size_t block_size)
{
    str_t *str = calloc(1, sizeof(str_t));

    if (!str)
        log_fatal(ERROR_ALLOC, sizeof(str_t));

    str->block_size = block_size;

    return str;
}


void str_free(str_t *str)
{
    if (!str)
        log_fatal(ERROR_NULL);

    free(str->data);
    free(str);
}


static void str_grow(str_t *str)
{
    if (str->data_size + 1 <= str->alloc_size)
        return;

    str->alloc_size = ((str->data_size + 1) / str->block_size + 1) * str->block_size;
    str->data = realloc(str->data, str->alloc_size);

    if (!str->data)
        log_fatal(ERROR_ALLOC, str->alloc_size);
}


void str_enq_char(str_t *str, char c)
{
    if (!str)
        log_fatal(ERROR_NULL);

    str_grow(str);
    str->data[str->data_size++] = c;
}


void str_enq_string(str_t *str, char *s)
{
    if (!str || !s)
        log_fatal(ERROR_NULL);

    for (char *c = s; *c; c++)
        str_enq_char(str, *c);
}


char *str_get(str_t *str)
{
    if (!str)
        log_fatal(ERROR_NULL);

    str_grow(str);
    str->data[str->data_size++] = '\0';

    return str->data;
}


char *str_trim_get(str_t *str)
{
    if (!str)
        log_fatal(ERROR_NULL);

    char *left = str_get(str);
    char *right = left;

    bool ltrim = true;

    for (char *c = left; *c; c++) {
        if (*c == ' ')
            continue;

        if (ltrim) {
            left = c;
            ltrim = false;
        }

        right = c;
    }

    right[1] = '\0';

    return left;
}


char *str_deq(str_t *str)
{
    if (!str)
        log_fatal(ERROR_NULL);

    char *result = strdup(str_get(str));

    if (!result)
        log_fatal(ERROR_STRDUP);

    str->data_size = 0;

    return result;
}


char *str_trim_deq(str_t *str)
{
    if (!str)
        log_fatal(ERROR_NULL);

    char *result = strdup(str_trim_get(str));

    if (!result)
        log_fatal(ERROR_STRDUP);

    str->data_size = 0;

    return result;
}
