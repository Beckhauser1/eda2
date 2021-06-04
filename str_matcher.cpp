#include <iostream>
#include <string.h>
using namespace std;



int strMatcher ( string t , string p) {

    int i , j , m, n ;
    n = t.length();
    m = p.length();

    for ( i = 0; i <= n - m ; i ++) {
        for ( j = 0; j < m; j++) {
            if ( p [ j ] != t [ i+j ] ) break ;
        }

        if ( j == m) return (i);
    }
    return (-1) ;
}

int main() {
  cout << strMatcher("ababababaababb", "ababb");
}