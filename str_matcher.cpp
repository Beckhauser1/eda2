#include <iostream>
#include <string.h>
using namespace std;

int strMatcher(char *t, char *p)
{

    int i, j, m, n;
    n = strlen(t);
    m = strlen(p);

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (p[j] != t[i + j])
                break;
        }

        if (j == m)
            return (i);
    }
    return (-1);
}
