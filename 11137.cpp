/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MMM   MMM AA     AA ZZZZZZZ EEEEEEE DDDDD
   
 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok
 problem: https://uva.onlinejudge.org/external/111/11137.pdf
 Catagory: Coin Change
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int coin[22];
int n = 21, make;
LL dp[22][10001];
LL coinChange (int i, int amount) {
    if (i == 21) {
        if (amount == 0) return 1;
        else return 0;
    }
    if (dp[i][amount] != -1) return dp[i][amount];
    LL v1 = 0, v2 = 0;
    if (amount - coin[i] >= 0)
        v1 = coinChange (i, amount - coin[i]);
    v2 = coinChange (i+1, amount);

    return dp[i][amount] = (v1+v2);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	memset (dp, -1, sizeof (dp));
	for (int i = 1; i <= 21; i++) coin[i-1] = i*i*i;

	while (scanf (" %d", &make) != EOF) {
        printf ("%lld\n", coinChange (0, make) );
	}
    return 0;
}
