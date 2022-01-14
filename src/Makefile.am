AM_CFLAGS = -std=c17 -Wall -Wextra -Werror


bin_PROGRAMS = thing-test


LOG_SOURCES = \
	log/internal.h log/log.h \
	log/dump.c \
	log/log.c \
	log/outputs.c \
	log/syslog.c


thing_test_SOURCES = \
	$(LOG_SOURCES) \
	main.c main.h \
	tests-hash.h


BUILT_SOURCES = tests-hash.h
EXTRA_DIST = tests-hash.gperf

tests-hash.h: tests-hash.gperf
	$(GPERF) -C -S 1 -t -H test -N in_tests $< | clang-format > $@


check-local: thing-test
	./$< all
