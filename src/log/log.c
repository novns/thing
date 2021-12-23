#include "main.h"

#include <errno.h>
#include <time.h>


static const char *const log_levels[] = {
    "FATAL",
    "ERROR",
    "INFO",
    "TEST",
    "DEBUG",
};


#define DATETIME_BUF_SIZE 20

void log_printf(SOURCE_INFO_ARGS, int level, const char *format, ...)
{
    // Save errno

    int err = errno;
    errno = 0;


    // Date & time

    time_t timestamp = time(NULL);
    struct tm *tm = gmtime(&timestamp);

    char datetime[DATETIME_BUF_SIZE];
    strftime(datetime, DATETIME_BUF_SIZE, "%F %T", tm);


    // Message

    printf("%s  %s  " SOURCE_INFO_FORMAT,
           datetime, log_levels[level], SOURCE_INFO_VARS);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (err)
        printf("  (%s)", strerror(err));

    putchar('\n');
}
