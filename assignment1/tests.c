#include <stdbool.h>
#include <stdio.h>

#include "implementation.h"


bool testEmpty()
{
    char str[] = "";
    Result r = getLargestConsecutiveChar(str);

    return r.c == '\0' && r.length == 1;
}

bool testSimple()
{
    char str[] = "aabbbcc";
    Result r = getLargestConsecutiveChar(str);

    return r.c == 'b' && r.length == 3;
}

bool testSameLength()
{
    char str[] = "aabbbcccb";
    Result r = getLargestConsecutiveChar(str);

    return r.c == 'b' && r.length == 3;
}

#define CHECK(f)                   \
    if (f())                       \
        printf("Passed %s\n", #f); \
    else                           \
        printf("Failed %s\n", #f);
#define TESTS         \
    CHECK(testEmpty)  \
    CHECK(testSimple) \
    CHECK(testSameLength)

int main()
{
    TESTS
    return 0;
}