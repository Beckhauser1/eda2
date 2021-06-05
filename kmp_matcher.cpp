#include <iostream>
#include <string.h>
using namespace std;

void getPi(const char *p, int pi[])
{
    int i, j, m;
    m = strlen(p);

    if (m > 0)
        pi[0] = -1;
    if (m > 1)
        pi[1] = 0;

    for (i = 2; i < m; i++)
    {
        j = pi[i - 1];
        while (j >= 0 && p[i - 1] != p[j])
            j = pi[j];

        pi[i] = j + 1;
    }
    return;
}

int kmpMatcher(const char *t, const char *p)
{
    int i = 0, j = 0, m, n;
    n = strlen(t);
    m = strlen(p);
    int pi[m];

    getPi(p, pi);

    while (j < m && i < n)
    {

        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = pi[j];
            if (j <= 0)
            {
                j = 0;
                i++;
            }
        }
    }

    if (j == m)
        return (i - m);
    else
        return (-1);
}
