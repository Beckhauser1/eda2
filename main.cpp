#include <stdio.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <cstring>
#include <sys/time.h>

#include "bm_matcher.h"
#include "kmp_matcher.h"
#include "str_matcher.h"
#include "rk_matcher.h"

void printResult(int result, clock_t begin, clock_t end)
{
    printf("%d %d\n", result, int(end - begin));
}

int main(int argc, char *argv[])
{

    clock_t begin, end;
    char *txt = "ababababaababb";
    char *pat = "ababb";

    // begin = clock();
    // // int benchmarkResult = txtStr.find(patStr);
    // end = clock();

    // printResult(benchmarkResult, begin, end);

    // Brute Force
    begin = clock();
    int bruteForceResult = strMatcher(txt, pat);
    end = clock();

    printResult(bruteForceResult, begin, end);

    // KMP
    begin = clock();
    int kmpResult = kmpMatcher(txt, pat);
    end = clock();

    printResult(kmpResult, begin, end);

    // Boyer Moore
    begin = clock();
    int boyerMooreResult = bmMatcher(txt, pat);
    end = clock();

    printResult(boyerMooreResult, begin, end);

    // Rabin Karp
    begin = clock();
    int rabinKarpResult = rkMatcher(txt, pat);
    end = clock();

    printResult(rabinKarpResult, begin, end);

    return 0;
}
