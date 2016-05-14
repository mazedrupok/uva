/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Problem: Graph (Topological Sort)
   Comment: Topological sort works for directed acyclic graph.
            Here I used in-degree technique :)
*/
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

string a;
map <string, int> mm;
map <int, string> nn;
vector <int> gr[110];
char s1[110], s2[110];
int ans[110], indeg[110];

int main()
{
    int i, j, k, m, n, cnt = 0, x, y;
    //freopen ("in.txt", "r", stdin);
    while(scanf("%d", &n) == 1) {
        memset(indeg, 0, sizeof(indeg));
        mm.clear();
        nn.clear();
        for(i = 1; i <= n; ++i) {
            scanf("%s", s1);
            a = s1;
            mm[a] = i;
            nn[i] = a;
        }
        scanf("%d", &m);
        for(i = 0; i < m; ++i) {
            scanf("%s %s", s1, s2);
            gr[mm[s1]].push_back(mm[s2]);
            ++indeg[mm[s2]];
        }
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j) {
                if( indeg[j] == 0 ) {
                    --indeg[j];
                    ans[i] = j;
                    for(k = 0; k < gr[j].size(); ++k)
                        indeg[gr[j][k]]--;
                    gr[j].clear();
                    break;
                }
            }

        printf("Case #%d: Dilbert should drink beverages in this order:", ++cnt);
        for(j = 1; j <= n; ++j) cout << " " << nn[ans[j]];
        printf(".\n\n");
    }
    return 0;
}
