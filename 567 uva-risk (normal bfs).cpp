#include <bits/stdc++.h>
using namespace std;
vector <int > g[100];
void bfs (int src, int des) {
   queue <int > q;
   int visited[100] = {0};
   int level[100]; int parent[100];
   visited[src] = 1;
   level[src] = 0;
   q.push(src);
   while (q.empty() == 0) {
      int u = q.front(); q.pop();
      for (int i = 0; i < g[u].size(); i++) {
         int v = g[u][i];
         if (visited[v] == 0) {
            visited[v] = 1;
            level[v] = level[u] + 1;
            parent[v] = u;
            q.push(v);
         }
      }
   }
   printf ("%2d to %2d: %d\n", src, des, level[des]);
}
int main ()
{
   int n, x, src, des, k = 0;
   //freopen ("in.txt", "r", stdin);
   while (cin >> n ) {
      for (int i = 0; i <= 20; i++) {
         g[i].clear();
      }
      while (n--) {cin >> x; g[1].push_back(x); g[x].push_back(1);}
      for (int i = 2; i <= 19; i++) {
         cin >> n;
         while (n--) {cin >> x; g[i].push_back(x); g[x].push_back(i);}
      }
      cin >> n;
      printf ("Test Set #%d\n", ++k);
      while (n--) {cin >> src >> des; bfs(src, des);}
      printf ("\n");
   }
}
