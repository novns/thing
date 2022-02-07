/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -C -S 1 -t -H test -N in_tests tests-hash.gperf  */
/* Computed positions: -k'1' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35)        \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40)    \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44)     \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48)     \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52)     \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56)     \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60)     \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65)     \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69)     \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73)     \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77)     \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81)     \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85)     \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89)     \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93)    \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98)     \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102)  \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

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
        ARG_VERBOSE,

        TESTS_ALL,
        TESTS_TEST,

        TESTS_DATA,
        TESTS_DATA_DICT,

        TESTS_LOG,
    } value;
};

#define TOTAL_KEYWORDS 6
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 9
#define MIN_HASH_VALUE 2
#define MAX_HASH_VALUE 14
/* maximum key range = 13, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
    static unsigned int
    test(register const char *str, register size_t len)
{
    static const unsigned char asso_values[] = {
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 0, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 5, 15, 15,
        5, 15, 15, 15, 15, 15, 15, 15, 0, 15,
        15, 15, 15, 15, 15, 15, 0, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15
    };
    return len + asso_values[(unsigned char)str[0]];
}

const struct test *
in_tests(register const char *str, register size_t len)
{
    static const struct test wordlist[] = {
#line 28 "tests-hash.gperf"
        { "-v", ARG_VERBOSE },
#line 33 "tests-hash.gperf"
        { "log", TESTS_LOG },
#line 30 "tests-hash.gperf"
        { "test", TESTS_TEST },
#line 29 "tests-hash.gperf"
        { "all", TESTS_ALL },
#line 31 "tests-hash.gperf"
        { "data", TESTS_DATA },
#line 32 "tests-hash.gperf"
        { "data-dict", TESTS_DATA_DICT }
    };

    if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH) {
        register unsigned int key = test(str, len);

        if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE) {
            register const struct test *resword;

            switch (key - 2) {
            case 0:
                resword = &wordlist[0];
                goto compare;
            case 1:
                resword = &wordlist[1];
                goto compare;
            case 2:
                resword = &wordlist[2];
                goto compare;
            case 6:
                resword = &wordlist[3];
                goto compare;
            case 7:
                resword = &wordlist[4];
                goto compare;
            case 12:
                resword = &wordlist[5];
                goto compare;
            }
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
#line 34 "tests-hash.gperf"


#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
