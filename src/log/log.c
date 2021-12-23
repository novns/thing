#include "main.h"

#include <time.h>


static const char *const log_levels[] = {
    "FATAL",
    "ERROR",
    "INFO",
    "TEST",
    "DEBUG",
};


#define DATETIME_BUF_SIZE 20

void log_printf(int level, const char *format, ...)
{
    // Date & time

    time_t timestamp = time(NULL);
    struct tm *tm = gmtime(&timestamp);

    char datetime[DATETIME_BUF_SIZE];
    strftime(datetime, DATETIME_BUF_SIZE, "%F %T", tm);


    // Message

    printf("%s  %s  ", datetime, log_levels[level]);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    putchar('\n');
}
