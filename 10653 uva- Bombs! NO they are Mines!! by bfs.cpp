#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
struct node {int p; int q;};
int ara[1005][1005];
int row, col;
int Dx[]= {-1, 1, 0, 0};
int Dy[]= {0, 0, 1, -1};
void bfs (int x1, int x2, int d1, int d2) {
   queue <node > qu;
   bool visited[row][col];
   for (int i = 0; i < row; i++)
      memset (visited[i], 0, sizeof (visited[i]));
   int level[row][col];
   node u;
   u.p = x1; u.q = x2;
   qu.push (u);
   visited[u.p][u.q] = 1;
   level[x1][x2] = 0;
   while (qu.empty() == 0) {
      u = qu.front(); qu.pop();
      //printf ("Out: %d %d\n", u.p, u.q);
      for (int i = 0; i < 4; i++) {
         node v;
         v.p = u.p + Dx[i];
         v.q = u.q + Dy[i];
         if (v.p >= 0 && v.p < row && v.q >= 0 && v.q < col && !visited[v.p][v.q]  && !ara[v.p][v.q]) {
            //printf ("In: %d %d\n", v.p, v.q);
            visited[v.p][v.q] = 1;
            level[v.p][v.q] = level[u.p][u.q] + 1;
            qu.push (v);
         }
      }
   }
   printf ("%d\n", level[d1][d2]);
}
int main ()
{
   int x1, x2, d1, d2, bombrow, i, j, n;
   //freopen ("in.txt", "r", stdin);
   while (cin >> row >> col) {
      if (!row && !col) break;
      for (i = 0; i < 1005; i++)
         memset (ara[i], 0, sizeof (ara[i]));
      cin >> bombrow;
      for (int k = 0; k < bombrow; k++) {
         cin >> i >> n;
         for (int l = 0; l < n; l++) {
            cin >> j;
            ara[i][j] = 1;
         }
      }
      cin >> x1 >> x2 >> d1 >> d2;
      bfs (x1, x2, d1, d2);
   }
   return 0;
}
