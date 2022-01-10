#include "main.h"

#include "internal.h"

#include <errno.h>
#include <limits.h>
#include <time.h>


static const char *const log_levels[] = {
    "FATAL",
    "ERROR",
    "INFO",
    "TEST",
    "DEBUG",
    "DUMP",
};


static inline bool reopen(log_output_t *out, struct tm *tm)
{
    // File status

    if (out->stream_error)
        return false;

    if (out->stream) {
        if (out->file_yday == tm->tm_yday)
            return true;

        fclose(out->stream);
    }

    // File name

    char file_path[PATH_MAX];

    snprintf(file_path, PATH_MAX, "%s.%04u-%02u-%02u%s",
             out->file_base, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
             out->file_ext ? out->file_ext : "");

    // Open file

    out->stream = fopen(file_path, "a");

    if (out->stream) {
        out->file_yday = tm->tm_yday;
        out->nl_last_level = ftello(out->stream) ? LOG_NL_FORCE : LOG_NL_SKIP;

        log_debug("Open log file '%s'", file_path);

        return true;
    }

    // Error

    out->stream_error = true;
    log_error("Cannot open log file '%s'", file_path);

    return false;
}


#define DATETIME_BUF_SIZE 20

void log_printf(int level, SOURCE_INFO_ARGS, const char *format, ...)
{
    // Save and reset errno

    int err = errno;
    errno = 0;

    // Date & time

    static time_t time_cache = 0;

    static struct tm tm = { 0 };
    static char datetime[DATETIME_BUF_SIZE] = "";

    time_t time_stamp = time(NULL);

    if (time_stamp != time_cache) {
        time_cache = time_stamp;

        gmtime_r(&time_stamp, &tm);
        strftime(datetime, DATETIME_BUF_SIZE, "%F %T", &tm);
    }

    // Outputs

    extern log_output_t *log_outputs;
    extern int log_outputs_count;

    va_list args;
    log_output_t *out = log_outputs;

    for (int i = 0; i < log_outputs_count; i++, out++) {
        if (level < out->level_from || level > out->level_to)
            continue;

        // Output type

        switch (out->type) {

        case LOG_TYPE_FILE:
            if (!reopen(out, &tm))
                continue;

            break;

        case LOG_TYPE_SYSLOG:
            va_start(args, format);
            syslog_vprintf(SOURCE_INFO_VARS, level, err, format, args);
            va_end(args);
            continue;

            break;

        default:
            break;
        }

        // Additional new line

        if (level != out->nl_last_level) {
            if (out->nl_last_level != LOG_NL_SKIP)
                putc('\n', out->stream);

            out->nl_last_level = level;
        }

        // Message

        fprintf(out->stream, "%s  %s  " SOURCE_INFO_FORMAT,
                datetime, log_levels[level], SOURCE_INFO_VARS);

        va_start(args, format);
        vfprintf(out->stream, format, args);
        va_end(args);

        if (err)
            fprintf(out->stream, "  (%s)", strerror(err));

        putc('\n', out->stream);

        fflush(out->stream);
    }
}
