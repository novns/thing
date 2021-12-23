#include "main.h"


static const char *const log_levels[] = {
    "FATAL",
    "ERROR",
    "INFO",
    "TEST",
    "DEBUG",
};


void log_printf(int level, const char *format, ...)
{
    printf("%s  ", log_levels[level]);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    putchar('\n');
}
