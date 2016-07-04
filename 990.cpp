#include <bits/stdc++.h>
using namespace std;
int T, W, n, depth[35], cost[35];
int dir[35][1005];
int dp[35][1005];
int knapsack (int i, int time) {
    if (i == n || time > T) return 0;
    if (dp[i][time] != -1) return dp[i][time];
    int v1 = 0, v2 = 0;
    if (time + 3*depth[i]*W <= T) v1 = cost[i] + knapsack(i+1, time + 3*depth[i]*W);
    v2 = knapsack (i+1, time);

    dir[i][time]=(v1>v2);
    return dp[i][time] = max (v1, v2);
}
void path() {
    bool mark[n];
    int cnt = 0, i = 0, j = 0;
    for (int v = 0; v < n; v++) mark[v] = 0;
    while(i < n){
        if(dir[i][j] ){
            mark[i] = 1;
            cnt++;
            j = j + 3*depth[i]*W;
        }
        i++;
    }
    printf("%d\n", cnt);
    for(i = 0; i < n; i++)
        if(mark[i]) printf("%d %d\n", depth[i], cost[i]);

}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    bool test = 0;
    while (scanf (" %d %d", &T, &W) == 2) { //total time & co-efficient
        if (test) printf ("\n"); test = 1;
        scanf (" %d", &n);          //number of treasures
        for(int i = 0; i < n; i++) //clear section
            for(int j = 0; j <= T; j++){
                dp[i][j] = -1;
                dir[i][j] = 0;
            }

        for (int i = 0; i < n; i++) scanf (" %d %d", &depth[i], &cost[i]);//depth & value of gold.
        printf ("%d\n", knapsack (0, 0));
        path ();
    }
    return 0;
}
