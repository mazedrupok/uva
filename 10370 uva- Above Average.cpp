#include <stdio.h>
int main ()
{
   int ara[1010];
   int i, j, n, m, c, cas;
   double average, perc;
   //freopen ("in.txt", "r" , stdin);
   scanf (" %d", &cas);
   while (cas--) {
      scanf (" %d", &n);
      m = 0;
      for (i = 0; i < n; i++) {scanf (" %d", &ara[i]); m += ara[i];}
      average = m / (double) n;
      c = 0;
      for (i = 0; i < n; i++) {
         if (ara[i] > average) c++;
      }
      perc = (c / (double) n) * 100;
      printf ("%.3lf%\n", perc);
   }
}
