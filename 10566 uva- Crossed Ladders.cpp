#include <bits/stdc++.h>
int main ()
{
    double x, y, c, mid, c1;
    while (scanf (" %lf %lf %lf", &x, &y, &c) == 3) {
        double l = 0, r = y;
        for (int i = 1; ; i++) {
            mid = (l+r) /2;
            c1 = (sqrt(x*x-mid*mid) * sqrt(y*y-mid*mid)) / (sqrt(x*x-mid*mid) + sqrt(y*y-mid*mid));
            if (fabs(c1-c) <= 0.000001) break;
            if (c1 > c) l = mid;
            else r = mid;
        }
        printf ("%lf\n", mid);
    }
    return 0;
}
