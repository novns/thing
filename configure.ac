AC_PREREQ([2.71])

AC_CONFIG_MACRO_DIRS([m4])

AC_INIT([Thing], [0.00], [nick.novikov@gmail.com])
AM_INIT_AUTOMAKE([foreign no-dist subdir-objects -Wall -Werror])


# Checks for programs

AC_PROG_CC
AC_PROG_MAKE_SET

AM_MISSING_PROG([GPERF], [gperf])


# Checks for libraries


# Checks for header files

AC_HEADER_STDBOOL

AC_CHECK_HEADERS([fcntl.h syslog.h unistd.h])


# Checks for typedefs, structures, and compiler characteristics

AC_C_INLINE

AC_TYPE_SIZE_T


# Checks for library functions

AC_FUNC_FSEEKO
AC_FUNC_REALLOC

AC_CHECK_FUNCS([atexit dup2 memset strdup strerror strrchr])


# Configuration

FEATURE_DISABLED(debug, DEBUG, [verbose debugging])


# Output

AC_CONFIG_FILES([
    Makefile
    src/Makefile
])

AC_CONFIG_HEADERS([config.h])

AC_OUTPUT
