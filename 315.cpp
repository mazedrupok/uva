#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
vector <int> g[MAXN];
int timer = 1, start[MAXN], low[MAXN];
int cnt = 0;
void dfs(int u) {
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
    if((u == 1 && child > 1) || (u != 1 && flag)) cnt++; //u is an AP.
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
	int n, e, u, v;
	string s, t;
	while (cin >> n) {
        if (n == 0) break;
        while (getline (cin, s)) {
            if (s == "0") break;
            stringstream ss (s);
            ss >> u;
            while (ss >> v) {
                //cout << u << " " << v << endl;
                g[u].push_back (v);
                g[v].push_back (u);
            }
        }
        memset (start, -1, sizeof (start));
        cnt = 0;
        timer = 0;
        dfs (1);
        cout << cnt << endl;

        for (int i = 0; i <= n; i++) g[i].clear();
	}
}
