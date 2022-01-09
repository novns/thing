#include "main.h"

#include <errno.h>
#include <syslog.h>


static const int syslog_levels[] = {
    0, // LOG_FATAL -> emerg
    3, // LOG_ERROR -> err
    6, // LOG_INFO -> info
    6, // LOG_TEST -> info
    7, // LOG_DEBUG -> debug
    7, // LOG_DUMP -> debug
};


void syslog_open(const char *ident, int facility)
{
    openlog(ident, 0, facility);
}


void syslog_close()
{
    closelog();
}


#define BUF_SIZE 1024

void syslog_vprintf(SOURCE_INFO_ARGS, int level, int err, const char *format, va_list args)
{
    static char buf[BUF_SIZE];

    vsnprintf(buf, BUF_SIZE, format, args);

    errno = err;
    syslog(syslog_levels[level],
           err ? SOURCE_INFO_FORMAT "%s  (%m)" : SOURCE_INFO_FORMAT "%s",
           SOURCE_INFO_VARS, buf);
    errno = 0;
}


void syslog_dump(size_t offset, const char *hex_buf)
{
    syslog(7, "%8zu    %s", offset, hex_buf);
}
