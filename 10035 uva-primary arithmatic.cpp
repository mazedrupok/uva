#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main ()
{
   int x, y;
   char a[1000], b[1000];
   int carry, c, m, i, j;
   while (scanf (" %s %s", a, b) == 2) {
      x = strcmp (a, "0"); y = strcmp (b, "0");
      if (x == 0 && y == 0) break;
      carry = 0;
      c = 0;
      x = strlen (a); y = strlen (b);
      for (i = x-1, j = y-1; ; i--, j--) {
            if (i < 0 && j < 0) break;
            if (i < 0) m = b[j] + carry - 48;
            else if (j < 0) m = a[i] + carry - 48;
            else  m = a[i] + b[j] + carry - 96;
            carry = m / 10;
            if (m >= 10) c++;
      }
      if (c == 0) printf ("No carry operation.\n");
      else if (c == 1) printf ("%d carry operation.\n", c);
      else printf ("%d carry operations.\n", c);
   }
   return 0;
}
