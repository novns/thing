#include "main.h"

#include <syslog.h>


void syslog_open(const char *ident, int facility)
{
    openlog(ident, 0, facility);
}


void syslog_close()
{
    closelog();
}
