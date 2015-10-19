#include <stdio.h>
/*long long rec (long long m) {
   if (m > 100) return (m - 10);
   else rec (m + 11);
}*/
int main ()
{
   long long n, m, i, j;
   while (scanf (" %lld", &n) == 1) {
      if (n == 0) break;
      //m = rec (n);
      if (n > 100) printf ("f91(%lld) = %lld\n", n, n - 10);
      else printf ("f91(%lld) = 91\n", n);
   }
}
