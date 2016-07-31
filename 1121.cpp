#include <bits/stdc++.h>
using namespace std;
int ara[100005];
int main ()
{
    int n, s;
    //freopen ("in.txt", "r", stdin);
    while (cin >> n >> s) {
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
        } ara[n] = 0;
        int lo = 0, hi = 0;
        int tem = 0, ans = n+5;
        while (hi <= n) {
            if (tem >= s) {
                ans = min (ans, hi-lo+1);
            }
            if (tem >= s && lo < hi) {
                tem -= ara[lo];
                lo++;
            }
            else  {
                tem += ara[hi];
                hi++;
            }
        }
        if (tem >= s && hi < n) ans = min (ans, hi-lo+1);
        ans--;
        if (ans > n) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
