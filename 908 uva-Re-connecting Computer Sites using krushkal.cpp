#include <bits//stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
   int u, v, w;
   node (int a, int b, int c) {u = a; v = b; w = c;}
   bool operator < (const node& p) const {return w < p.w;}
};
vector <node > edge;
int par[1000000];
int find (int r) {
   return (r == par[r]) ? r : find (par[r]);
}
int mst (int n) {
   sort (edge.begin(), edge.end());
   for (int i = 1; i <= n; i++) par[i] = i; //creating disjoint set..
   int count = 0, s = 0;
   for (int i = 0; i < (int ) edge.size(); i++) {
      int u = find (edge[i].u); int v = find (edge[i].v);
      if (u != v) {
         par[u] = v;
         count++; s += edge[i].w;
         if (count == n-1) break;
      }
   }
   //memset (par, 0, sizeof (par));
   return s;
}
int main ()
{
   int n, e, temp = 0;
   //freopen ("in.txt", "r", stdin);
   while (cin >> n) {
      if (temp == 1) cout << endl; temp = 1;
   for (int i = 0; i < n-1; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edge.push_back (node(u, v, w));
   }
   cout << mst(n) << endl;
   int k, m;
   cin >> k;
   for (int i = 0; i < k; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edge.push_back (node (u, v, w));
   }
   cin >> m;
   for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edge.push_back (node (u, v, w));
   }
   cout << mst (n) << endl;
   edge.clear();
   }
   return 0;
}
