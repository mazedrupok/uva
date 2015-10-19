#include <stdio.h>
#include <string.h>
int main ()
{
   char s[110][110];
   int i = 0, k, j, len, m = 0;
   //freopen ("in.txt", "r", stdin);
   while (gets (s[i])) {
      len = strlen (s[i]);
      if (m < len) m = len;
      i++;
   }
   for (k = 0; k < m; k++) {
      for (j = i-1; j >= 0; j--) {
         if (k >= strlen (s[j])) {printf (" "); continue;}
         printf ("%c", s[j][k]);
      }
      printf ("\n");
   }
   return 0;
}
