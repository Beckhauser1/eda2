#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <cstring>
#include <sys/time.h>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

#include "bm_matcher.h"
#include "kmp_matcher.h"
#include "str_matcher.h"
#include "rk_matcher.h"

using namespace std;

void printResult(string type, int result, auto begin, auto end)
{
    cout << type << ": " << result << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds" << endl;
}

int main()
{

    string txt_aux;
    string pat_aux;

    cin >> pat_aux;
    cin >> txt_aux;

    const char *txt;
    const char *pat;

    txt = txt_aux.c_str();
    pat = pat_aux.c_str();

    // begin = clock();
    // int defaultResult = txt.find(pat);
    // end = clock();

    // printResult("default", defaultResult, begin, end);

    // Brute Force

    auto begin = Clock::now();
    int bruteForceResult = strMatcher(txt, pat);
    auto end = Clock::now();

    printResult("bf", bruteForceResult, begin, end);

    // KMP
    begin = Clock::now();
    int kmpResult = kmpMatcher(txt, pat);
    end = Clock::now();

    printResult("kmp", kmpResult, begin, end);

    // Boyer Moore
    begin = Clock::now();
    int boyerMooreResult = bmMatcher(txt, pat);
    end = Clock::now();

    printResult("bm", boyerMooreResult, begin, end);

    // Rabin Karp
    begin = Clock::now();
    int rabinKarpResult = rkMatcher(txt, pat);
    end = Clock::now();

    printResult("rk", rabinKarpResult, begin, end);

    return 0;
}
