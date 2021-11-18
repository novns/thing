SUBDIRS = src


.PHONY: indent

indent:
	find src -name "*.[ch]" | xargs clang-format -i --verbose
