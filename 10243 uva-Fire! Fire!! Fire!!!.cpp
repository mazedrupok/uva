/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Catagory: Graph (Minimum Vertex Cover)
   Comment:  MVC by using DP technique.

*/
#include <bits/stdc++.h>
using namespace std;
#define MX  10002
vector <int> g[MX];
int par[MX];
int dp[MX][2];
int MVC (int u, bool guard) { //current node u, and this node have guard or not.
   if (g[u].size() == 0) return 0;
   if (dp[u][guard] != -1) return dp[u][guard]; //already optimized.
   int sum = 0;
   for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (v != par[u]) { //prevent going back.
         par[v] = u;
      //current node have no guard, so next node must have a guard.
      //or current node have a guard, so next node may have guard or not.
         if (guard == 0) sum += MVC (v, 1);
         else sum += min (MVC(v, 0), MVC(v, 1));
      }
   }
   return dp[u][guard] = sum + guard; //if current node have a guard, we must add 1.
}
int main ()
{
   int n, e, u, v, tc, cs = 0;
   //freopen ("in.txt", "r", stdin);
   while (cin >> n) {
      if (n == 0) break;
      memset (dp, -1, sizeof (dp));
      memset (par, -1, sizeof (par));
      for (int i = 1; i <= n; i++) {
         cin >> v;
         while (v--) {
            cin >> u;
            g[i].push_back (u);
            //g[u].push_back (i);
         }
      }
      if (n == 1) {cout << "1\n"; continue;}
      int ans = min (MVC(1, 0), MVC(1, 1));
      //cout << "Minimum Vertex Cover is: " << ans << endl;
      cout << ans << endl;
      vector <int> t[MX]; swap (t, g);
   }
   return 0;
}
