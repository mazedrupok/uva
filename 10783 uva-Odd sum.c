#include <stdio.h>
int main ()
{
   int a, b, i, sum, cas, tc = 0;
   scanf (" %d", &cas);
   while (cas--) {
      scanf (" %d %d", &a, &b);
      if (a %2 == 0) a++;
      sum = 0;
      for (i = a; i <= b; i += 2) sum += i;
      printf ("Case %d: %d\n", ++tc, sum);
   }
   return 0;
}
