#include <stdio.h>
int main ()
{
   int cas, tc = 0, n, m, i, j, b;
   int juice, mile;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &cas);
   while (cas--) {
      scanf (" %d", &n);
      mile = 0; juice = 0;
      for (i = 0; i < n; i++) {
         scanf (" %d", &m);
         b = 0;
         for (j = 0; b < m; j++) {
            mile += 10;
            if (j == 0) b += 29;
            else b += 30;
         }
         b = 0;
         for (j = 0; b < m; j++) {
            juice += 15;
            if (j == 0) b += 59;
            else b += 60;
         }
      }
      if (mile == juice) printf ("Case %d: Mile Juice %d\n", ++tc, mile);
      else if (mile < juice ) printf ("Case %d: Mile %d\n", ++tc, mile);
      else if (mile > juice ) printf ("Case %d: Juice %d\n", ++tc, juice);
   }
}

