/**
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   problem link: https://uva.onlinejudge.org/external/119/11953.pdf
   Catagory: Graph (DFS)

*/
#include <bits/stdc++.h>
using namespace std;
#define MX 10005
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char str[105][105];
int n;
void dfs (int i, int j) {
   if (i < 0 || j < 0 || i > n-1 || j > n-1 || str[i][j] == '.') return;
   str[i][j] = '.';
   for (int k = 0; k < 4; k++) {
      dfs (i+dx[k], j+dy[k]);
   }
}
int main ()
{
   //read ("in.txt");
   int tc, cs = 0;
   cin >> tc;
   while (tc--) {
      cin >> n;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) cin >> str[i][j];
      }
      int cnt = 0;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (str[i][j] == 'x') {cnt++; dfs(i, j);}
         }
      }
      printf ("Case %d: ", ++cs);
      cout << cnt << endl;
   }
   return 0;
}

