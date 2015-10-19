#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
using namespace std;
int main ()
{
   int cas, i, j, n;
   char s[1000000];
   char c1, c2;
   map <char , char> m;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &cas);
   while (cas--) {
      cin >> s;
      cin >> n;
      for (i = 0; i <= 128; i++) {
         m[i] = i;
      }
      while (n--) {
         scanf (" %c %c", &c1, &c2);
         for (i = 'A'; i <= 'Z'; i++)
            if (m[i] == c2) m[i] = c1;
      }
      for (i = 0; s[i]; i++) {
         cout << m[s[i]];
      }
      puts("");
   }
   return 0;
}

