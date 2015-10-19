#include <stdio.h>
#include <string.h>
int main ()
{
   char s[100000], ch;
   int i, j, k, n, m;
   //freopen ("in.txt", "r", stdin);
   //freopen ("out.txt", "w", stdout);
   while (gets (s)) {
      //if (strcmp (s, " ") == 0) {printf (" \n"); continue;}
      for (i = 0; s[i]; i++) {
         if (s[i] == '!') printf ("\n");
         else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '*') {
            j = i - 1;
            m = 0;
            while (s[j] >= '1' && s[j] <= '9') {
               m += (s[j] - 48);
               j--;
               if (j < 0) break;
            }
            while (m--) {
               if (s[i] == 'b') printf (" ");
               else printf ("%c", s[i]);
            }

         }
      }
      printf ("\n");
   }
   return 0;
}
