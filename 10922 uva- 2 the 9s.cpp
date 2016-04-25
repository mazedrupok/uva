#include <bits/stdc++.h>
using namespace std;
int main ()
{
   int n, sum, cnt, temp;
   char s[1500];
   while (cin >> s) {
      if (s[0] == '0' && !s[1]) break;
      sum = 0;
      for (int i = 0; s[i]; i++) {
         sum += (s[i] - 48);
      }
      if (sum %9 != 0) printf ("%s is not a multiple of 9.\n", s);
      else {
         cnt = 1;
         while (sum > 9) {
            temp = 0;
            while (sum) {
               temp += (sum %10);
               sum /= 10;
            }
            sum = temp;
            cnt++;
         }
         printf("%s is a multiple of 9 and has 9-degree %d.\n", s, cnt);
      }
   }
   return 0;
}
