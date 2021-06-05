#include <iostream>
#include <string.h>
using namespace std;
#define ASIZE 256 

void badC( string p , int badCShift []) {
    int i , m;
    m = p.length();

    for ( i = 0; i < ASIZE ; i ++)
        badCShift [ i ] = m;

    for ( i = 0; i < m -1; i ++)

    badCShift [( int ) p[ i ]] = m - i - 1;

}

int bmMatcher( string t , string p) {
    int i , j , m, n , badCShift [ ASIZE ] ;
    m = p.length();
    n = t.length();
    badC(p , badCShift );
    i = m -1;

    while ( i < n ) {
        j = 0;
        while ( j < m && t [ i-j ] == p [m- j -1]) j ++;
        if ( j == m) return ( i - m + 1);
        i = i + badCShift[( int ) t[i ]];
    }

    return -1;
}

int main() {
    cout << bmMatcher("ababababaababb", "ababb");
}