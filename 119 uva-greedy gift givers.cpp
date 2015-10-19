#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int main ()
{
    string s[15];
    string t;
    int ara[15];
    int n, i, j, k, a, q, f, d, r = 0;
    //freopen ("in.txt", "r", stdin);
    while (scanf (" %d", &n) != EOF) {
        for (i = 0; i < n; i++) cin >> s[i];
        for (j = 0; j < n; j++) ara[j] = 0;
        for (i = 0; i < n; i++) {
            cin >> t;
            for (j = 0; j < n; j++) if (s[j] == t) {k = j; break;}

            scanf (" %d %d", &a, &q);
            if (q == 0) {continue;}
            d = a / q;
            f = d * q;
            ara[k] -= f;
            while (q-- ) {
                cin >> t;
                for (j = 0; j < n; j++) if (s[j] == t) {k = j; break;}
                ara[k] += d;
            }
        }
        if (r == 0) r = 1;
        else printf ("\n");
        for (j = 0; j < n; j++) {
            cout << s[j];
            printf (" %d\n", ara[j]);
        }
    }
    return 0;
}
