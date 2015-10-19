#include <stdio.h>
int main ()
{
   long i, j, n, count, max, temp;
   long v1, v2;
   while (scanf (" %ld %ld", &i, &j) == 2) {
      max = 0;
      v1 = i;
      v2 = j;
      if (i > j) {
            temp = i;
            i = j;
            j = temp;
         }
      for (i ; i <= j; i++) {
         count = 1;
         for (n = i; n != 1; i) {
            if (n % 2) n = 3 * n + 1;
            else   n = n/2;
            count++;
         }
         if (count > max) max = count;
      }
      printf ("%ld %ld %ld\n", v1, v2, max);
   }
   return 0;
}
