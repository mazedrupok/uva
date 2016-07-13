#include <bits/stdc++.h>
using namespace std;
#define mx 110
vector <int> G[mx];
void bfs (int src, int &maxi, int &dest) {
    queue <int> q;
    int level[110] = {0};
    q.push(src);
    maxi = 0; dest = src;
    while (q.empty() == 0) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (level[u]+1 > level[v]) {
                q.push(v);
                level[v] = level[u] + 1;
                if (level[v] > maxi) {
                    maxi = level[v];
                    dest = v;
                }
                else if (level[v] == maxi) {
                    if (v < dest) dest = v;
                }
            }
        }
    }
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int p, q, start, cs = 0, n, dest, maxi;
	while (cin >> n) {
        if (n == 0) break;
        cin >> start;
        while (cin >> p >> q) {
            if (p == 0 && q == 0) break;
            G[p].push_back (q);
        }
        bfs(start, maxi, dest);
        printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cs, start, maxi, dest);
        vector <int> tt[mx]; swap (G, tt);
	}
    return 0;
}
