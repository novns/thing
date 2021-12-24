#include "main.h"

#include "internal.h"


log_output_t *log_outputs = NULL;
int log_outputs_count = 0;


static log_output_t *log_outputs_add(int level_from, int level_to)
{
    log_outputs = realloc(log_outputs, ++log_outputs_count * sizeof(log_output_t));

    log_output_t *out = log_outputs + log_outputs_count - 1;
    memset(out, 0, sizeof(log_output_t));

    out->level_from = level_from;
    out->level_to = level_to;

    return out;
}


void log_open_stream(int level_from, int level_to, FILE *stream)
{
    log_output_t *out = log_outputs_add(level_from, level_to);
    out->stream = stream;
}


void log_close()
{
    free(log_outputs);

    log_outputs = NULL;
    log_outputs_count = 0;
}
