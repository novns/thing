#include "main.h"

#include "internal.h"

#include <errno.h>
#include <time.h>


static const char *const log_levels[] = {
    "FATAL",
    "ERROR",
    "INFO",
    "TEST",
    "DEBUG",
};


static inline bool reopen(log_output_t *out)
{
    if (out->stream_error)
        return false;

    if (out->stream || (out->stream = fopen(out->file_path, "a")))
        return true;

    out->stream_error = true;
    log_error("Cannot open log file '%s'", out->file_path);

    return false;
}


static inline void log_vfprintf(FILE *stream,
                                const char *datetime, int level, SOURCE_INFO_ARGS, int err,
                                const char *format, va_list args)
{
    fprintf(stream, "%s  %s  " SOURCE_INFO_FORMAT,
            datetime, log_levels[level], SOURCE_INFO_VARS);

    vfprintf(stream, format, args);

    if (err)
        fprintf(stream, "  (%s)", strerror(err));

    putc('\n', stream);

    fflush(stream);
}


#define DATETIME_BUF_SIZE 20

void log_printf(int level, SOURCE_INFO_ARGS, const char *format, ...)
{
    // Save and reset errno

    int err = errno;
    errno = 0;


    // Date & time

    time_t timestamp = time(NULL);
    struct tm *tm = gmtime(&timestamp);

    char datetime[DATETIME_BUF_SIZE];
    strftime(datetime, DATETIME_BUF_SIZE, "%F %T", tm);


    // Message

    extern log_output_t *log_outputs;
    extern int log_outputs_count;

    log_output_t *out = log_outputs;
    va_list args;

    for (int i = 0; i < log_outputs_count; i++, out++) {
        if (level < out->level_from || level > out->level_to)
            continue;

        if (out->type == LOG_TYPE_FILE && !reopen(out))
            continue;

        va_start(args, format);
        log_vfprintf(out->stream, datetime, level, SOURCE_INFO_VARS, err, format, args);
        va_end(args);
    }
}
