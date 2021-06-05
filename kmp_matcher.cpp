#include <iostream>
#include <string.h>
using namespace std;

void getPi ( string p , int pi []) {
    int i , j , m;
    m = p.length();

    if (m > 0) pi [0] = -1;
    if (m > 1) pi [1] = 0;

    for ( i = 2; i < m; i ++) {
        j = pi [ i - 1];
        while ( j >= 0 && p [ i -1] != p [ j ] ) 
            j = pi [ j ];

        pi [ i ] = j +1;
    }
    return;
}




int kmpMatcher (string t , string p ) {
    int i = 0 , j = 0 , m, n ;
    n = t.length();
    m = p.length();
    int pi [m];
    
    getPi(p, pi);

    while ( j < m && i < n ) {
  
        if ( t [ i ] == p [ j ] ) {
            i ++; 
            j ++;
        } else {
            j = pi [ j ];
            if ( j <= 0) {
                j = 0; 
                i ++;
            }
        }
    }

    if ( j == m) return ( i - m);
    else return (-1);
}

    int main() {
       
        cout << kmpMatcher("12345", "34");

}