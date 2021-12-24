#pragma once

#include "main.h"


typedef struct log_output {
    int level_from;
    int level_to;

    FILE *stream;
} log_output_t;
