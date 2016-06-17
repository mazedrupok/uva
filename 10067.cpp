/**
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   problem: https://uva.onlinejudge.org/external/100/10067.pdf
   Catagory: BFS
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
    int a, b, c, d, cost;
    node (int e, int f, int g, int h, int i) {
        if (e == -1) e = 9;
        if (f == -1) f = 9;
        if (g == -1) g = 9;
        if (h == -1) h = 9;

        if (e == 10) e = 0;
        if (f == 10) f = 0;
        if (g == 10) g = 0;
        if (h == 10) h = 0;
        a = e; b = f; c = g; d = h; cost = i;
    }
    node () {}
    bool operator < (const node &p) const {
        if (a != p.a) return a < p.a;
        else {
            if (b != p.b) return b < p.b;
            else {
                if (c != p.c) return c < p.c;
                else return d < p.d;
            }
        }
    }
};
map <node, int> mp;
int bfs (node x, node y) {
    queue <node> q;
    x.cost = 0;
    q.push (x);
    while (q.empty() == 0) {
        node u = q.front(); q.pop();
        if (u.a == y.a && u.b == y.b && u.c == y.c && u.d == y.d) {
            return u.cost;
        }
        //cout << u.a << u.b << u.c << u.d << u.cost << endl;
        if (mp.find(u) == mp.end()) {
            q.push ( node(u.a +1, u.b, u.c, u.d, u.cost +1));
            q.push ( node(u.a -1, u.b, u.c, u.d, u.cost +1));

            q.push ( node(u.a, u.b +1, u.c, u.d, u.cost +1));
            q.push ( node(u.a, u.b -1, u.c, u.d, u.cost +1));

            q.push ( node(u.a, u.b, u.c +1, u.d, u.cost +1));
            q.push ( node(u.a, u.b, u.c -1, u.d, u.cost +1));

            q.push ( node(u.a, u.b, u.c, u.d +1, u.cost +1));
            q.push ( node(u.a, u.b, u.c, u.d -1, u.cost +1));
        }
        mp[node(u.a, u.b, u.c, u.d, u.cost) ] = 1;
    }
    return -1;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    node x, y, z; int n, tc;
    cin >> tc;
    while (tc--) {
        cin >> x.a >> x.b >> x.c >> x.d; x.cost = 0;
        cin >> y.a >> y.b >> y.c >> y.d; y.cost = 0;
        cin >> n;
        while (n--) {
            cin >> z.a >> z.b >> z.c >> z.d; z.cost = 0;
            mp[z] = 1;
        }
        cout << bfs (x, y) << endl;
        mp.clear();
    }
    return 0;
}
