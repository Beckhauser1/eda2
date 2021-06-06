#include <string.h>

void computeLPSArray(const char *pat, int M, int *lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmpMatcher(const char *t, const char *p)
{
    int M = strlen(p);
    int N = strlen(t);

    int lps[M];

    computeLPSArray(p, M, lps);

    int i = 0;
    int j = 0;

    while (i < N)
    {
        if (p[j] == t[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            return i - j;
        }
        else if (i < N && p[j] != t[i])
        {
            if (j != 0)
            {

                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }

    return -1;
}
