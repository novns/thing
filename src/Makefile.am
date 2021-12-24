AM_CFLAGS = -std=c17 -Wall -Wextra -Werror


bin_PROGRAMS = thing-test


LOG_SOURCES = \
	log/internal.h \
	log/log.c log/log.h \
	log/outputs.c


thing_test_SOURCES = \
	$(LOG_SOURCES) \
	main.c main.h


check: thing-test
	./$<
