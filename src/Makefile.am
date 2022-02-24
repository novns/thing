AM_CFLAGS = -std=c17 -Wall -Wextra -Werror


bin_PROGRAMS = thing-test


DATA_SOURCES = \
	data/dict.c data/dict.h \
	data/str.c data/str.h \
	data/tests-dict.c \
	data/tests-str.c


LOG_SOURCES = \
	log/dump.c \
	log/internal.h \
	log/log.c log/log.h \
	log/outputs.c \
	log/syslog.c \
	log/tests-log.c


TEST_SOURCES = \
	test/test.c test/test.h


thing_test_SOURCES = \
	$(DATA_SOURCES) \
	$(LOG_SOURCES) \
	$(TEST_SOURCES) \
	main.c main.h \
	tests-hash.h


BUILT_SOURCES = tests-hash.h
EXTRA_DIST = tests-hash.gperf

tests-hash.h: tests-hash.gperf
	$(GPERF) -C -S 1 -t -H test -N in_tests $< | clang-format > $@


check-local: thing-test
	./$< all
