#pragma once

#include "main.h"


typedef enum log_type {
    LOG_TYPE_STREAM,
    LOG_TYPE_FILE,
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
} log_output_t;
