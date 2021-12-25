#pragma once

#include "main.h"


typedef enum log_type {
    LOG_TYPE_STREAM,
} log_type_t;


typedef struct log_output {
    log_type_t type;

    int level_from;
    int level_to;

    FILE *stream;
} log_output_t;
