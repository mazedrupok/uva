#include <stdio.h>
int main ()
{
   long long n, i, j, p = 6227020800;
   //freopen ("in.txt", "r", stdin);
   while (scanf (" %lld", &n) == 1) {
      j = 1;
      if (n < 0 && n %2 == 0) {printf ("Underflow!\n"); continue;}
      else if (n < 0 && n %2 != 0) {printf ("Overflow!\n"); continue;}
      while (n > 1) {
         j *= n;
         n--;
         if (j > p) {
            printf ("Overflow!\n");
            break;
         }
      }
      if (j < 10000) printf ("Underflow!\n");
      else if (j >= 10000 && j <= p) printf ("%lld\n", j);
   }
   return 0;
}
