#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{
   char s[210], t[210], temp, r[210];
   int cas, tc = 0, i, j, k, carry, len1, len2, len;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &cas);
   while (cas--) {
      scanf (" %s %s", s, t);
      len1 = strlen (s);
      len2 = strlen (t);
      for (i = 0, j = len1-1; i < len1/2; i++, j--) {
         if (len1 == 1) break;
         temp = s[i];
         s[i] = s[j];
         s[j] = temp;
      }
      //printf ("%s %s\n", s, t);
      for (i = 0, j = len2-1; i < len2/2; i++, j--) {
         if (len2 == 1) break;
         temp = t[i];
         t[i] = t[j];
         t[j] = temp;
      }
      //printf ("%s %s\n", s, t);
      carry = 0; k = 0;
      for (i = len1-1, j = len2-1; i >= 0 || j >= 0; i--, j--) {
         if (i < 0) {i = 0; s[i] = '0';}
         else if (j < 0) {j = 0; t[j] = '0';}
         carry = s[i] + t[j] - 96 + carry;
         r[k++] = (carry %10) + 48;
         carry /= 10;
      }
      if (carry != 0) r[k++] = carry + 48;
      carry = 0;
      for (i = 0; i < k; i++) {
         if (r[i] != '0' || carry == 1) {
            printf ("%c", r[i]);
            carry = 1;
         }
      }
      printf ("\n");
   }
   return 0;
}
