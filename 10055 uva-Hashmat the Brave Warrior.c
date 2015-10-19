
#include <stdio.h>
int main ()
{
   long long a, b;
   while (scanf (" %lld %lld", &a, &b) == 2) {
      a = a - b;
      if (a < 0) a *= (-1);
      printf ("%lld\n", a);
   }
   return 0;
}
