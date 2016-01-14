#include <bits/stdc++.h>
using namespace std;
vector <string > v;
void fibonacci () {
   v.push_back ("0");
   v.push_back ("1");
   v.push_back ("1");
   for (int i = 3; i < 5001; i++) {
      string s = "";
      int s1 = v[i-1].size();
      int s2 = v[i-2].size();
      int r = 0;
      for (int j = s1-1, k = s2-1; j >= 0 || k >= 0; j--, k--) {
         int t;
         if (j >= 0 && k >= 0) {
            t = v[i-1][j] + v[i-2][k] - 96 + r;
            r = t /10;
            s += (t %10 + 48);
         }
         else if (j < 0) {
            t = v[i-2][k] - 48 + r;
            r = t /10;
            s += (t %10 + 48);
         }
         else if (k < 0) {
            t = v[i-1][j] - 48 + r;
            r = t /10;
            s += (t %10 + 48);
         }
      }
      while (r != 0) {
         s += (r %10 + 48);
         r /= 10;
      }
      reverse (s.begin(), s.end());
      //cout << s << endl;
      v.push_back (s);
   }
}
int main ()
{
   fibonacci ();
   int n;
   while (scanf (" %d", &n) == 1) {
      printf ("The Fibonacci number for %d is ", n);
      cout << v[n] << endl;
   }
   return 0;
}
