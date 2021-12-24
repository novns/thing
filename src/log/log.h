#pragma once

#include "main.h"


enum log_level {
    LOG_FATAL,
    LOG_ERROR,
    LOG_INFO,
    LOG_TEST,
    LOG_DEBUG,
};


void log_open_stream(int level_from, int level_to, FILE *stream);

void log_close();


#ifdef ENABLE_DEBUG

#define SOURCE_INFO_ARGS const char *si_func, const char *si_file, int si_line
#define SOURCE_INFO_FORMAT "%s  %s %d  "
#define SOURCE_INFO_VALUES __func__, __FILE__, __LINE__
#define SOURCE_INFO_VARS si_func, si_file, si_line

#else

#define SOURCE_INFO_ARGS const char *si_func
#define SOURCE_INFO_FORMAT "%s  "
#define SOURCE_INFO_VALUES __func__
#define SOURCE_INFO_VARS si_func

#endif


void log_printf(SOURCE_INFO_ARGS, int level, const char *format, ...);


#define log_fatal(...)                                          \
    {                                                           \
        log_printf(SOURCE_INFO_VALUES, LOG_FATAL, __VA_ARGS__); \
        exit(EXIT_FAILURE);                                     \
    }

#define log_error(...) log_printf(SOURCE_INFO_VALUES, LOG_ERROR, __VA_ARGS__)

#define log_info(...) log_printf(SOURCE_INFO_VALUES, LOG_INFO, __VA_ARGS__)

#define log_test(...) log_printf(SOURCE_INFO_VALUES, LOG_TEST, __VA_ARGS__)

#ifdef ENABLE_DEBUG
#define log_debug(...) log_printf(SOURCE_INFO_VALUES, LOG_DEBUG, __VA_ARGS__)
#else
#define log_debug(...) ((void)0)
#endif
