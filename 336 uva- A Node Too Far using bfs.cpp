//UVA- 336 	A Node Too Far
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
vector <int > g[100000];
int ara[100000];
int k = 0;
void bfs (int src, int x, int ttl, int vertex) {
   queue <int > q;
   int visited[100000] = {0};
   int level[100000];
   int count = 1;
   visited[src] = 1;
   level[src] = 0;
   q.push (src);
   while (q.empty() == 0) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < g[u].size(); i++) {
         int v = g[u][i];
         if (visited[v] == 0) {
            visited[v] = 1;
            level[v] = level[u] + 1;
            q.push (v);
            if (level[v] <= ttl) count++;  //counting node in TTL ..
         }
      }
   }
   count = vertex - count;
   printf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++k, count, x, ttl);
}
int main ()
{
   int edge, x, y;
   //freopen ("in.txt", "r", stdin);
   while (cin >> edge) {
      if (edge == 0) break;
      map <int, int> m;
      int as = 0; int vertex = 0;
      for (int i = 0; i < edge; i++) {
         cin >> x >> y;
         if (m.find(x) == m.end()) { //stl mapping for big or negetive value..
            m[x] = as++;
            vertex++;  //counting total vertex..
         }
         if (m.find(y) == m.end()) {
            m[y] = as++;
            vertex++;
         }
         g[m[x]].push_back (m[y]);
         g[m[y]].push_back (m[x]);
      }

      while (cin >> x >> y) {
         if (x == 0 && y == 0) break;
         if (m.find(x) == m.end()) { //if source node not included in graph..
            printf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++k, vertex, x, y);
            continue;
         }
         bfs (m[x], x, y, vertex);
      }
      for (int i = 0; i < 100000; i++) g[i].clear();
   }
   return 0;
}
