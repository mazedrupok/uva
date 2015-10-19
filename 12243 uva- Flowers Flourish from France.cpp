#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;
int main ()
{
   string s;
   int i, j;
   bool t;
   char ch;
   //freopen ("input.txt", "r", stdin);
   for (j = 0; ;j++) {
      getline (cin , s);
      if (s == "*") break;
      for (i = 0; s[i]; i++) {
         if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
      }
      ch = s[0];
      t = true;
      for (i = 0; s[i]; i++) {
         if (s[i] == ' ')
            if (s[i+1] != ch) {t = false; break;}
      }
      if (t == false) cout << "N\n";
      else cout << "Y\n";
   }
}
