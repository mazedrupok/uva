#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector <int > g[10000];
void bfs (int src) {
   queue <int > q;
   int visited[100000] = {0};
   int color[100000];
   q.push (src);
   color[src] = 1;  //source node color is 1..
   visited[src] = 1; // source is visited..
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < g[u].size(); i++) {
         int v = g[u][i];
         if (!visited[v]) {
            color[v] = color[u] * (-1); // if node is not visited, then we color it anti color by its previous u node.. which is visited previously..
            visited[v] = 1;
            q.push(v);
         }
         else if (color[v] == color[u]) { //if node is visited then, if we find same color between them..
            printf ("NOT BICOLORABLE.\n");
            return;
         }
      }
   }
   printf ("BICOLORABLE.\n");
}
int main()
{
   int vertex, edge,  x, y, src;
   //freopen ("in.txt", "r", stdin);
   while (cin >> vertex) {
      if (vertex == 0) break;
      cin >> edge;
      for (int i = 0; i < vertex; i++) g[i].clear();
      for (int i = 0; i < edge; i++) {
         cin >> x >> y;
         g[x].push_back (y);
         g[y].push_back (x);
         if (i == 0) src = x; //first node for source..
      }
      bfs (src);
   }
   return 0;
}
