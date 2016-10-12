#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define pb push_back
#define mkp make_pair
int dp[101][1001], last[101];
vector <int> g[101];
vector <int> cost[101];
int func (int u, int d) {
    if (d == 0) return 0;
    if (dp[u][d] != -1) return dp[u][d];
    int r = 0;
    if (d == 1) {
        for (int i = 0; i < g[u].size(); i++) {
            int v =  g[u][i];
            int w = cost[u][i];
            if (last[v] == 1) r = max (r, w);
        }
        return dp[u][d] = r;
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        int w = cost[u][i];
        r = max (r, w + func (v, d-1));
    }
    return dp[u][d] = r;
}
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0); //read("in.txt");
    int x, c, s, e, t;
    while (cin >> c >> s >> e >> t) {
        if (c == 0 && s == 0 && e == 0 && t == 0) break;
        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> x;
                g[i].push_back (j);
                cost[i].push_back (x);
            }
        }
        memset (last, 0, sizeof (last));
        for (int i = 0; i < e; i++) {
            cin >> x;
            last[x] = 1;
        }
        memset (dp, -1, sizeof (dp));
        cout << func (s, t) << endl;

        vector <int> tt[101], tc[101];
        swap (g, tt); swap (cost, tc);
    }

    return 0;
}
