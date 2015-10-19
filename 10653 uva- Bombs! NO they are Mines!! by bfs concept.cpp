#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int ara[1005][1005];
int row, col;
int Dx[]= {-1, 1, 0, 0};
int Dy[]= {0, 0, 1, -1};

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
      queue <int > q;
      q.push (x1); q.push (x2);
      int visited[row][col];
      for (i = 0; i < row; i++)
         memset (visited[i], 0, sizeof (visited[i]));
      int level[row][col];
      level[x1][x2] = 0; visited[x1][x2] = 1;
      while (q.empty() == 0) {
         int u1 = q.front(); q.pop();
         int u2 = q.front(); q.pop();
         for (i = 0; i < 4; i++) {
            int v1 = u1 + Dx[i];
            int v2 = u2 + Dy[i];
            if (v1 >= 0 && v1 < row && v2 >= 0 && v2 < col && ara[v1][v2] == 0 && visited[v1][v2] == 0) {
               visited[v1][v2] = 1;
               level[v1][v2] = level[u1][u2] + 1;
               q.push (v1); q.push (v2);
            }
         }
      }
      printf ("%d\n", level[d1][d2]);
      //bfs (x1, x2, d1, d2);
   }
   return 0;
}

