#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
int main ()
{
   char  s[100000];
   int len, i, count, t;
   //freopen ("in.txt", "r", stdin);
   while (gets(s)) {
      len = strlen(s);
      t = 0;
      count = 0;
      for (i = 0; i < len; i++) {
         if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            if (t == 0) count++;
            t = 1;
         }
         else t = 0;
      }
      printf ("%d\n", count);
   }

}
