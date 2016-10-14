#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define LL long long

int p, q, r, s, t, u;
double x, L, R;
double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
int main ()
{
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (f(0) * f(1) > 0) {
            cout << "No solution\n";
            continue;
        }
        L = 0; R = 1;
        int cnt = 100;
        while (cnt--) {
            x = (L+R) /2;
            if (f(x)*f(L) > 0) L = x;
            else R = x;
        }
        x = (L+R) /2;
        printf ("%.4f\n", x);
    }
    return 0;
}
