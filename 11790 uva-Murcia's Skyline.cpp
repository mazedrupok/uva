#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int lis (int h[], int w[], int n) {
   int dp[n]; int res = w[0];
   for (int i = 0; i < n; i++) {
      dp[i] = w[i];
      for (int j = 0; j < i; j++) {
         if (h[i] > h[j]) {
            dp[i] = max (dp[i], dp[j]+w[i] );
         }
      }
      res = max (res, dp[i]);
   }
   return res;
}
int main ()
{
   int n, tc, k = 0; cin >> tc;
   while (tc--) {
      cin >> n;
      int h[n], w[n];
      for (int i = 0; i < n; i++) cin >> h[i];
      for (int i = 0; i < n; i++) cin >> w[i];
      int t1 = lis (h, w, n);
      reverse (h, h+n); reverse (w, w+n);
      int t2 = lis (h, w, n);
      if (t1 >= t2) printf ("Case %d. Increasing (%d). Decreasing (%d).\n", ++k, t1, t2);
      else printf ("Case %d. Decreasing (%d). Increasing (%d).\n", ++k, t2, t1);
   }
   return 0;
}
