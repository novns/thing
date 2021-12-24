AC_PREREQ([2.71])

AC_CONFIG_MACRO_DIRS([m4])

AC_INIT([Thing], [0.00], [nick.novikov@gmail.com])
AM_INIT_AUTOMAKE([foreign no-dist subdir-objects -Wall -Werror])


# Checks for programs

AC_PROG_CC
AC_PROG_MAKE_SET


# Checks for libraries


# Checks for header files


# Checks for typedefs, structures, and compiler characteristics

AC_C_INLINE


# Checks for library functions

AC_FUNC_REALLOC

AC_CHECK_FUNCS([memset strerror])


# Configuration

FEATURE_DISABLED(debug, DEBUG, [verbose debugging])


# Output

AC_CONFIG_FILES([
    Makefile
    src/Makefile
])

AC_CONFIG_HEADERS([config.h])

AC_OUTPUT
