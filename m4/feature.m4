# FEATURE_DISABLED(NAME, DEFINE, DESCRIPTION)

AC_DEFUN([FEATURE_DISABLED], [
    AH_TEMPLATE([ENABLE_$2], [Enable $3])

    AC_ARG_ENABLE([$1], AS_HELP_STRING([--enable-$1], [enable $3 (default: disabled)]))

    AS_VAR_IF([enable_$1], [yes], [
        AC_MSG_NOTICE([$3 is enabled])
        AC_DEFINE([ENABLE_$2])
    ], [
        AC_MSG_NOTICE([$3 is disabled])
    ])

    AM_CONDITIONAL([COND_$2], [test x$enableval = xyes])
])


# FEATURE_ENABLED(NAME, DEFINE, DESCRIPTION)

AC_DEFUN([FEATURE_ENABLED], [
    AH_TEMPLATE([ENABLE_$2], [Enable $3])

    AC_ARG_ENABLE([$1], AS_HELP_STRING([--disable-$1], [disable $3 (default: enabled)]))

    AS_VAR_IF([enable_$1], [no], [
        AC_MSG_NOTICE([$3 is disabled])
    ], [
        AC_MSG_NOTICE([$3 is enabled])
        AC_DEFINE([ENABLE_$2])
    ])

    AM_CONDITIONAL([COND_$2], [test x$enableval != xno])
])
