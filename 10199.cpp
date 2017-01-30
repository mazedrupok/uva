#include <bits/stdc++.h>
using namespace std;
#define MAXN 1050
vector <int> g[MAXN];
vector <int> arPoint;
int timer = 1, start[MAXN], low[MAXN];
int root;
void dfs (int u) {
    bool flag = 0;
    int child = 0;
    start[u] = low[u] = timer; timer++;
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(start[v] == -1) {
            dfs(v);
            child++;
            low[u] = min(low[u], low[v]);
            if (low[v] >= start[u]) flag = true;
        }
        else low[u] = min(low[u], start[v]);
    }
    if((u == root && child > 1) || (u != root && flag)) arPoint.push_back (u); //u is an AP.
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
	int n, e, u, v, r, cs = 0;
	string s, t;
	bool test = 0;
	while (cin >> n) {
        if (n == 0) break;
        if (test == 1) printf ("\n"); test = 1;
        map <string, int> mp;
        string ara[200];
        for (int i = 1; i <= n; i++) {
            cin >> s;
            ara[i] = s;
            mp[s] = i;
        }
        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> s >> t;
            u = mp[s]; v = mp[t];
            g[u].push_back (v);
            g[v].push_back (u);
        }
        memset (start, -1, sizeof (start));
        timer = 1;
        for (int i = 1; i <= n; i++) {
            root = i;
            if (start[i] == -1) dfs (i);
        }
        printf ("City map #%d: %d camera(s) found\n", ++cs, arPoint.size());
        vector <string> vv;
        for (int i = 0; i < arPoint.size(); i++) {
            vv.push_back (ara[arPoint[i]]);
        }
        sort (vv.begin(), vv.end());
        for (int i = 0; i < vv.size(); i++) {
            cout << vv[i] << "\n";
        }
        for (int i = 0; i <= n; i++) g[i].clear();
        arPoint.clear();
	}
}
