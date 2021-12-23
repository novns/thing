#pragma once

#include "main.h"


enum log_level {
    LOG_FATAL,
    LOG_ERROR,
    LOG_INFO,
    LOG_TEST,
    LOG_DEBUG,
};


void log_printf(int level, const char *format, ...);


#define log_fatal(...)                      \
    {                                       \
        log_printf(LOG_FATAL, __VA_ARGS__); \
        exit(EXIT_FAILURE);                 \
    }

#define log_error(...) log_printf(LOG_ERROR, __VA_ARGS__)

#define log_info(...) log_printf(LOG_INFO, __VA_ARGS__)

#define log_test(...) log_printf(LOG_TEST, __VA_ARGS__)

#ifdef ENABLE_DEBUG
#define log_debug(...) log_printf(LOG_DEBUG, __VA_ARGS__)
#else
#define log_debug(...) ((void)0)
#endif
