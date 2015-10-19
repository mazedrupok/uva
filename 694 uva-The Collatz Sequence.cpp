#include <stdio.h>
int main ()
{
   long long a, b, n, c;
   int tc = 0;
   while (scanf (" %lld %lld", &a, &b) == 2) {
      if (a == -1 && b == -1) break;
      c = 0;
      n = a;
      while (a <= b) {
         if (a == 1) {c++; break;}
         else if (a %2 == 0) {a /= 2; c++;}
         else if (a %2 == 1) {a = (3 * a) + 1; c++;}
      }
      printf ("Case %d: A = %lld, limit = %lld, number of terms = %lld\n", ++tc, n, b, c);
   }
   return 0;
}
