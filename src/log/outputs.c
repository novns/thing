#include "main.h"

#include "internal.h"


log_output_t *log_outputs = NULL;
int log_outputs_count = 0;


static log_output_t *log_outputs_add(log_type_t type, int level_from, int level_to)
{
    log_outputs = realloc(log_outputs, ++log_outputs_count * sizeof(log_output_t));

    log_output_t *out = log_outputs + log_outputs_count - 1;
    memset(out, 0, sizeof(log_output_t));

    out->type = type;
    out->level_from = level_from;
    out->level_to = level_to;
    out->nl_last_level = LOG_NL_SKIP;

    return out;
}


void log_open_file(int level_from, int level_to, const char *path)
{
    log_output_t *out = log_outputs_add(LOG_TYPE_FILE, level_from, level_to);

    out->file_path = path;
    out->file_base = strdup(path);

    char *file_ext = strrchr(out->file_base, '/');
    file_ext = strrchr(file_ext ? file_ext : out->file_base, '.');

    if (file_ext) {
        out->file_ext = strdup(file_ext);
        *file_ext = '\0';
    }
}


void log_open_stream(int level_from, int level_to, FILE *stream)
{
    log_output_t *out = log_outputs_add(LOG_TYPE_STREAM, level_from, level_to);
    out->stream = stream;
}


void log_open_syslog(int level_from, int level_to, const char *ident, int facility)
{
    log_outputs_add(LOG_TYPE_SYSLOG, level_from, level_to);
    syslog_open(ident, facility);
}


void log_close()
{
    log_output_t *out = log_outputs;

    for (int i = 0; i < log_outputs_count; i++, out++) {
        switch (out->type) {

        case LOG_TYPE_FILE:
            if (out->stream)
                fclose(out->stream);

            free(out->file_base);
            free(out->file_ext);

            break;

        case LOG_TYPE_SYSLOG:
            syslog_close();
            break;

        default:
            break;
        }
    }

    free(log_outputs);

    log_outputs = NULL;
    log_outputs_count = 0;
}
