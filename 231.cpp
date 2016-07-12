#include <bits/stdc++.h>
using namespace std;

#define mx 33000
int n; //array size
int value[mx];
int dp[mx], dir[mx];
int longest(int u) {
	if(dp[u] != -1) return dp[u];
	int maxi = 0;
	for(int v = u+1; v <= n; v++) {
		if(value[v] < value[u]) {
			if(longest(v) > maxi) {
				maxi = longest(v);
                //dir[u] = v;
			}
		}
	}
	return dp[u] = 1+maxi;
}
//void solution(int start) {
//	while(start != -1) {
//		printf("index %d value %d\n", start, value[start]);
//		start = dir[start];
//	}
//}
int main()
{
	//READ("in");
	int LIS = 0, start, cs = 0;
	int x, tem = 0;
	while (cin >> x) {
        if (x == -1) {
            if (tem == true) printf ("\n"); tem = true;
            memset(dp, -1, sizeof dp);
            LIS = 0;
            for(int i = 1; i <= n; i++) {
                //printf("longest path from index %d: %d\n", i, longest(i));
                if(longest(i) > LIS) {
                    LIS = longest(i);
                    //start = i;
                }
            }
            printf("Test #%d:\n  maximum possible interceptions: %d\n", ++cs, LIS);
            n = 0;
            cin >> x;
            if (x == -1) break;
        }
        value[++n] = x;
	}
    return 0;
}
