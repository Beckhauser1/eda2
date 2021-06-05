#include <iostream>
#include <string.h>
using namespace std;

int rkMatcher( char t [] , char p []) {
    long m , n , w = 1, vp = 0 , vt = 0 , s = 0, B = 256;
    const long q = 7919;
    m = strlen (p);
    n = strlen (t);

    for ( int i = 1; i < m; i ++)
        w = (w * B) % q;
    
    for ( int i = 0; i < m; i ++) {
        vp = (vp * B + p[ i ]) % q;
        vt = (vt * B + t[ i ]) % q;
    }

    while ( s <= n - m) {
        if ( vp == vt && strncmp ( p , t+s ,m) == 0 )
            return s ;
        
        s++;

        if ( s <= n - m) {
            vt = (B * (vt - t[s -1] * w) + t [ s + m - 1 ] )%q ;
            if (vt < 0) vt = vt + q;
        }
    }
 
    return -1;
}

int main() {
    char *t = "ababababaababb";
    char *p = "ababb";
    cout << rkMatcher(t, p);
}