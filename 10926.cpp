#include <bits/stdc++.h>
using namespace std;
vector <int> g[101];
int n, cnt;
bool visit[101];
void dfs (int u) {
    visit[u] = 1;
    cnt++;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (visit[v] == 0) dfs (v);
    }
}
int main ()
{
    //freopen ("in.txt", "r" , stdin);
    int t, x, mx, index;
    while (cin >> n && n != 0) {
        for (int i = 1; i <= n; i++) {
            cin >> t;
            while (t--) {
                cin >> x;
                g[i].push_back (x);
            }
        }
        mx = 0; index = 0;
        for (int i = 1; i <= n; i++) {
            memset (visit, 0, sizeof (visit)); cnt = 0;
            dfs (i);
            if (cnt > mx) {mx = cnt; index = i;}
            else if (cnt == mx && i < index) index = i;
        }
        //cout << mx << endl;
        cout << index << endl;
        vector <int> tt[101]; swap (tt, g);
    }
}
