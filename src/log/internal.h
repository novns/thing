#pragma once

#include "main.h"


#define LOG_NL_FORCE -2
#define LOG_NL_SKIP -1


typedef enum log_type {
    LOG_TYPE_FILE,
    LOG_TYPE_STREAM,
    LOG_TYPE_SYSLOG,
} log_type_t;


typedef struct log_output {
    log_type_t type;

    int level_from;
    int level_to;

    const char *file_path;
    char *file_base;
    char *file_ext;

    int file_yday;

    FILE *stream;
    bool stream_error;

    int nl_last_level;
} log_output_t;


void syslog_open(const char *ident, int facility);
void syslog_close();

void syslog_vprintf(SOURCE_INFO_ARGS, int level, int err, const char *format, va_list args);
void syslog_dump(size_t offset, const char *hex_buf);
