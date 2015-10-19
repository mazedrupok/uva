#include <bits/stdc++.h>
using namespace std;
struct node {int p; int q;};
char s1[10], s2[10];
int Dx[]= {-2,-1, 1, 2, 2,1,-1,-2};
int Dy[]= {-1,-2,-2,-1, 1,2, 2, 1};
void bfs (int x1, int x2, int d1, int d2) {
   queue <node > qu;
   bool visited[100][100] = {0};
   int level[100][100];
   node u, v;
   u.p = x1; u.q = x2;
   qu.push (u);
   visited[u.p][u.q] = 1;
   level[x1][x2] = 0;
   while (qu.empty() == 0) {
      u = qu.front(); qu.pop();
      if (u.p == d1 && u.q== d2) {
         printf ("To get from %s to %s takes %d knight moves.\n", s1, s2, level[u.p][u.q]);
         return;
      }
      for (int i = 0; i < 8; i++) {
         node v;
         v.p = u.p + Dx[i];
         v.q = u.q + Dy[i];
         if ((v.p > 0 && v.p < 9) && (v.q > 0 && v.q < 9) && !visited[v.p][v.q] ) {
            visited[v.p][v.q] = 1;
            level[v.p][v.q] = level[u.p][u.q] + 1;
            qu.push (v);
         }
      }
   }
}
int main ()
{
   int x1, x2, d1, d2;
   while (cin >> s1 >> s2) {
      x1 = s1[0] - 96;
      x2 = s1[1] - 48;
      d1 = s2[0] - 96;
      d2 = s2[1] - 48;
      bfs (x1, x2, d1, d2);
   }
   return 0;
}
