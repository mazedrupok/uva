#include <stdio.h>
int main ()
{
   int cas, n, a, i, j;
   scanf (" %d", &cas);
   while (cas--) {
      scanf (" %d %d", &a, &n);
      while (n--) {
         for (i = 1; i <= a; i++) {
            for (j = i; j > 0; j--) printf ("%d", i);
            printf ("\n");
         }
         for (i = a-1; i > 0; i--) {
            for (j = i; j > 0; j--) printf ("%d", i);
            printf ("\n");
         }
         if (n == 0) continue;
         printf ("\n");
      }
      if (cas != 0) printf ("\n");
   }
   return 0;
}
