/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -C -S 1 -t -H test -N in_tests tests-hash.gperf  */
/* Computed positions: -k'' */

#line 1 "tests-hash.gperf"

#pragma once

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#line 11 "tests-hash.gperf"
struct test {
    char *name;

    enum {
        TESTS_ALL,
    } value;
};

#define TOTAL_KEYWORDS 1
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 3
#define MIN_HASH_VALUE 0
#define MAX_HASH_VALUE 0
/* maximum key range = 1, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
    /*ARGSUSED*/
    static unsigned int
    test(register const char *str, register size_t len)
{
    return 0;
}

const struct test *
in_tests(register const char *str, register size_t len)
{
    static const struct test wordlist[] = {
#line 20 "tests-hash.gperf"
        { "all", TESTS_ALL }
    };

    if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH) {
        register unsigned int key = test(str, len);

        if (key <= MAX_HASH_VALUE) {
            register const struct test *resword;

            resword = &wordlist[0];
            goto compare;
            return 0;
        compare : {
            register const char *s = resword->name;

            if (*str == *s && !strcmp(str + 1, s + 1))
                return resword;
        }
        }
    }
    return 0;
}
#line 21 "tests-hash.gperf"

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
