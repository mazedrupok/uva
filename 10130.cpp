#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1005
#define sc(a) scanf(" %d", &a)
#define sc2(a,b) scanf(" %d %d", &a, &b)
#define f(a,b) for(int i = a; i < b; i++)
int n, CAP;
int dp[MAX_N][32]; //capacity not greater than 30
int weight[MAX_N];
int cost[MAX_N];
int func (int i, int w) {
    if (i > n) return 0;
    if (dp[i][w] != -1) return dp[i][w];
    int profit1 = 0, profit2 = 0;
    if (w+weight[i] <= CAP) profit1 = cost[i] + func(i+1, w+weight[i]);
    profit2 = func(i+1, w);
    dp[i][w] = max (profit1, profit2);
    return dp[i][w];
}
int main()
{
	//freopen("in.txt", "r", stdin);
    int tc;
    sc(tc);
    while (tc--) {
        sc(n);
        f(1,n+1) sc2(cost[i], weight[i]);
        int people, sum = 0;
        sc(people);
        while (people--) {
            sc(CAP);
            memset (dp, -1, sizeof (dp));
            sum += func(0,0);
        }
        printf ("%d\n", sum);
    }
    return 0;
}
