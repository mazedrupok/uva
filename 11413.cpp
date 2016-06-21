/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MM     MM AA     AA ZZZZZZZ EEEEEEE DDDDD

 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok
 category: Binary Search
*/
#include <bits//stdc++.h>
using namespace std;
#define MX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
/****************************** END OF TEMPLATE ******************************/

int main ()
{
    int n, m;
    LL mx, sum;
    while (cin >> n >> m) {
        sum = 0; mx = 0;
        LL ara[n];
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
            if (ara[i] > mx) mx = ara[i];
            sum += ara[i];
        }
        LL lo = mx, hi = sum, mid, ans = sum, temp;
        while (lo <= hi) {
            temp = 0;
            mid = (lo+hi) >> 1;
            for (int i = 0, cnt = 0; i < n; i++) {
                cnt++; if (cnt > m) break;
                sum = 0;
                while (i < n && sum+ara[i] <= mid) {
                    sum += ara[i]; i++;
                } i--;
                if (i == n-1) {
                    if (mid < ans) ans = mid;
                    hi = mid -1; temp = 1;
                }
            }
            if (temp == 0) lo = mid+1;
        }
        cout << ans << endl;
    }

    return 0;
}
