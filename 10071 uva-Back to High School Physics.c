#include <stdio.h>
int main ()
{
   long long a, b, s;
   while (scanf (" %lld %lld", &a, &b) == 2) {
      s = a * b * 2;
      printf ("%lld\n", s);
   }
   return 0;
}
