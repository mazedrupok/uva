#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define pb push_back
#define mkp make_pair
int dp[101][201], e;
vector <int> g[101];

bool func (int u, int d) {
    if (d == 0) {
        if (u == e) return dp[u][d] = 1;
        else return dp[u][d] = 0;
    }
    if (dp[u][d] != -1) return dp[u][d];

    bool r = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        r = r | func (v, d-1);
        if (r == 1) break;
    }
    return dp[u][d] = r;
}
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0); //read("in.txt");
    int a, b, c, s, d, L;
    while (cin >> c >> L) {
        if (c == 0 && L == 0) break;
        for (int i = 0; i < L; i++) {
            cin >> a >> b;
            g[a].push_back (b);
            g[b].push_back (a);
        }
        cin >> s >> e >> d;

        memset (dp, -1, sizeof (dp));
        bool test = func (s, d);
        if (test == 1) cout << "Yes, Teobaldo can travel.\n";
        else cout << "No, Teobaldo can not travel.\n";

        vector <int> tt[101]; swap (g, tt);
    }

    return 0;
}
