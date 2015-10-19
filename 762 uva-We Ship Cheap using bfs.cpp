//762 	We Ship Cheap solved using bfs..
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
vector <int > g[100000];
string s[100000];
void bfs (int src, int des) {
   queue <int > q;
   int visited[100000] = {0};
   int level[100000];
   int parent[100000];
   visited[src] = 1; level[src] = 0; parent[des] = -1; parent[src] = -1; //for printing issue parent of src & des assign to -1..
   q.push (src);
   while (q.empty() == 0 ) {
      int u = q.front(); q.pop();
      for (int i = 0; i < g[u].size(); i++) {
         int v = g[u][i];
         if (visited[v] == 0) {
            visited[v] = 1;
            level[v] = level[u] + 1;
            parent[v] = u; //edge from every node to every node by using parent tacniq..
            q.push (v);
         }
      }
   }
   if (parent[des] == -1) cout << "No route\n"; //if no edge found for sourc to destination node
   else {
      stack <string> st; int v = des; st.push (s[des]); //edge from des to src: pushed in a stack..
      while (parent[v] != -1) {
         v = parent[v];
         st.push (s[v]);  // we push these string which mapped..
      }
      string t[100000];
      int i = 0;
      while (!st.empty()) {
         t[i++] = st.top(); st.pop();
      }
      t[i] = "stop print";        // for printinf issue.. it used for a boundary..
      for (int j = 0; j < i; j++) {
         if (t[j+1] == "stop print") break;
         cout << t[j] << " " << t[j+1] << endl;
      }
   }
}
int main ()
{
   int edge, asn = 0, k = 0;
   //freopen ("in.txt", "r", stdin);
   while (cin >> edge) {
      string s1, s2;
      map <string, int > mp;
      for (int i = 0; i < edge; i++) {
         cin >> s1 >> s2;
         if (mp.find(s1) == mp.end()) {mp[s1] = asn; s[asn] = s1; asn++;}
         if (mp.find(s2) == mp.end()) {mp[s2] = asn; s[asn] = s2; asn++;}
         g[mp[s1]].push_back(mp[s2]);
         g[mp[s2]].push_back(mp[s1]);
      }
      cin >> s1 >> s2;
      if (k != 0) cout << endl; // its used for test cases blank line..
      k = 1;
      bfs(mp[s1], mp[s2]);
      for (int i = 0; i < 100000; i++) {
         g[i].clear();
         s[i].clear();
      }
   }
   return 0;
}
