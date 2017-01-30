#include <bits/stdc++.h>
using namespace std;
#define N 100005
int H[N];
bool vis[N];
vector <int> g[N];
int high (int u) {
    if (vis[u] == 1) {
        return H[u];
    }
    vis[u] = 1;
    if (g[u].size() == 0) return H[u] = 1;
    int mx = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        mx = max (mx, 1+high(v));
    }
    return H[u] = mx;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n, e, u, v, res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &e);
        for (int i = 1; i <= n; i++) {
            H[i] = 0; vis[i] = 0;
            g[i].clear();
        }

        for (int i = 0; i < e; i++) {
            scanf (" %d %d", &u, &v);
            g[u].push_back (v);
        }
        res = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                res = max (res, high(i));
            }
        }
        printf ("Case %d: %d\n", ++cs, res);
    }

    return 0;
}
