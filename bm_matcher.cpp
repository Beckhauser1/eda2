#include <iostream>
#include <string.h>
using namespace std;
#define ASIZE 256

void badC(const char *p, int badCShift[])
{
    int i, m;
    m = strlen(p);

    for (i = 0; i < ASIZE; i++)
        badCShift[i] = m;

    for (i = 0; i < m - 1; i++)

        badCShift[(int)p[i]] = m - i - 1;
}

int bmMatcher(const char *t, const char *p)
{
    int i, j, m, n, badCShift[ASIZE];
    m = strlen(p);
    n = strlen(t);
    badC(p, badCShift);
    i = m - 1;

    while (i < n)
    {
        j = 0;
        while (j < m && t[i - j] == p[m - j - 1])
            j++;
        if (j == m)
            return (i - m + 1);
        i = i + badCShift[(int)t[i]];
    }

    return -1;
}
