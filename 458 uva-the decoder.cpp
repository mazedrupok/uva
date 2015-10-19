#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main ()
{
   char  s[100000];
   int len, i;
   //freopen ("in.txt", "r", stdin);
   while (gets(s)) {
      len = strlen(s);
      for (i = 0; i < len; i++) {
         if (s[i] == ' ') continue;
         printf ("%c", s[i] -7);
      }
      printf ("\n");
   }

}
